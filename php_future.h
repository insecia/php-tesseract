#pragma once

extern "C" {
#include <php.h>
#include <Zend/zend_interfaces.h>
}

#include <new>
#include "src/future.h"

namespace {

    PHP_METHOD(Future, get)
    {
        if (zend_parse_parameters_none() == FAILURE) {
            return;
        }

        auto intern = Z_OBJECT_FUTURE_P(getThis());

        RETURN_STRING(intern->get());
    }

    ZEND_BEGIN_ARG_INFO_EX(tesseract_future_void, 0, 0, 0)
    ZEND_END_ARG_INFO()

    zend_function_entry future_methods[] = {
        PHP_ME(Future, get, tesseract_future_void, ZEND_ACC_PUBLIC)
        PHP_FE_END
    };

    void init_future_ce()
    {
        zend_class_entry ce;

        INIT_CLASS_ENTRY(ce, "Tesseract\\Future", future_methods);
        future_ce = zend_register_internal_class(&ce TSRMLS_CC);
        future_ce->create_object = tesseract::php::Future::create_object;

        memcpy(&tesseract::php::Future::handler_future, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
        tesseract::php::Future::handler_future.offset = XtOffsetOf(tesseract::php::Future, std);
    }
}