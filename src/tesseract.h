#pragma once

extern "C" {
#include <php.h>
}

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

namespace tesseract { namespace php {

    class Tesseract
    {
    public:
        tesseract::TessBaseAPI* tesseract_api;
        char* out_text;
        zend_object std;

        static zend_object_handlers handler_tesseract;
        static zend_object* create_object(zend_class_entry* ce TSRMLS_CC);
        static Tesseract* fetch_object(zend_object* obj);

        Tesseract(Pix* image);
        ~Tesseract();

        char* get_text();
    };

}}
