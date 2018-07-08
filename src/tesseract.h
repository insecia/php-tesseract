#pragma once

extern "C" {
#include <php.h>
}

#include <string>

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

        Tesseract(Pix* image, std::string languages = "eng");
        ~Tesseract();

        char* get_text();
        char* get_hocr_text();
        void set_rectangle(int left, int top, int width, int height);
    };

}}
