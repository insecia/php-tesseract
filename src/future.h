#pragma once

extern "C" {
#include <php.h>
}

#include <future>

namespace tesseract { namespace php {

    class Future
    {
    public:
        std::shared_future<char*> future;
        zend_object std;

        static zend_object_handlers handler_future;
        static zend_object* create_object(zend_class_entry* ce TSRMLS_CC);
        static Future* fetch_object(zend_object* obj);

        Future(std::shared_future<char*> future);
        char* get();
    };
}}
