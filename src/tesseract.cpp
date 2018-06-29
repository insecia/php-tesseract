#include "tesseract.h"

namespace tesseract { namespace php {

    zend_object_handlers Tesseract::handler_tesseract = zend_object_handlers();

    zend_object* Tesseract::create_object(zend_class_entry* ce TSRMLS_CC)
    {
        Tesseract* intern = (Tesseract*)ecalloc(1, sizeof(Tesseract) + zend_object_properties_size(ce));

        zend_object_std_init(&intern->std, ce TSRMLS_CC);

        intern->std.handlers = &Tesseract::handler_tesseract;
        return &intern->std;
    }

    Tesseract* Tesseract::fetch_object(zend_object* obj)
    {
        return (Tesseract *)((char *)obj - XtOffsetOf(Tesseract, std));
    }


    Tesseract::Tesseract(Pix* image)
    {
        this->tesseract_api = new tesseract::TessBaseAPI();

        if (this->tesseract_api->Init(NULL, "deu")) {
            fprintf(stderr, "Could not initialize tesseract.\n");
            exit(1);
        }

        this->tesseract_api->SetImage(image);
    }

    Tesseract::~Tesseract()
    {
        this->tesseract_api->End();

        if (this->out_text) {
            delete [] this->out_text;
        }
    }

    char* Tesseract::get_text()
    {
        this->out_text = this->tesseract_api->GetUTF8Text();
        return this->out_text;
    }
}}
