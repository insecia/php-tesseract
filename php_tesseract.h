#pragma once

extern "C" {
#include <php.h>
#include <Zend/zend_interfaces.h>
}

#include <new>
#include "src/tesseract.h"

namespace {

    PHP_METHOD(Tesseract, fromFile)
    {
        char* file_path;
        size_t len;

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &file_path, &len) == FAILURE) {
            return;
        }

        Pix *image = pixRead(file_path);

        object_init_ex(return_value, tesseract_ce);
        auto intern = Z_OBJECT_TESSERACT(Z_OBJ_P(return_value));
        new (intern) tesseract::php::Tesseract(image);
    }

    PHP_METHOD(Tesseract, fromString)
    {
        char* file_content;
        size_t len;

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &file_content, &len) == FAILURE) {
            return;
        }

        Pix* image = pixReadMem(reinterpret_cast<l_uint8*>(file_content), len);

        object_init_ex(return_value, tesseract_ce);
        auto intern = Z_OBJECT_TESSERACT(Z_OBJ_P(return_value));
        new (intern) tesseract::php::Tesseract(image);
    }

    PHP_METHOD(Tesseract, getText)
    {
        if (zend_parse_parameters_none() == FAILURE) {
            return;
        }

        auto intern = Z_OBJECT_TESSERACT_P(getThis());

        RETURN_STRING(intern->get_text());
    }

    PHP_METHOD(Tesseract, getHocrText)
    {
        if (zend_parse_parameters_none() == FAILURE) {
            return;
        }

        auto intern = Z_OBJECT_TESSERACT_P(getThis());

        RETURN_STRING(intern->get_hocr_text());
    }

    PHP_METHOD(Tesseract, getRectangle)
    {
        long left, top, width, height;

        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "llll", &left, &top, &width, &height) == FAILURE) {
            return;
        }

        auto intern = Z_OBJECT_TESSERACT_P(getThis());
        intern->set_rectangle(left, top, width, height);

        RETURN_ZVAL(getThis(), 1, 0);
    }

    ZEND_BEGIN_ARG_INFO_EX(tesseract_tesseract_void, 0, 0, 0)
    ZEND_END_ARG_INFO()

    ZEND_BEGIN_ARG_INFO_EX(tesseract_tesseract_from_file, 0, 0, 0)
        ZEND_ARG_INFO(0, file_path)
    ZEND_END_ARG_INFO()

    ZEND_BEGIN_ARG_INFO_EX(tesseract_tesseract_from_string, 0, 0, 0)
        ZEND_ARG_INFO(0, file_content)
    ZEND_END_ARG_INFO()

    ZEND_BEGIN_ARG_INFO_EX(tesseract_tesseract_get_rectangle, 0, 0, 0)
        ZEND_ARG_INFO(0, left)
        ZEND_ARG_INFO(0, top)
        ZEND_ARG_INFO(0, width)
        ZEND_ARG_INFO(0, height)
    ZEND_END_ARG_INFO()

    zend_function_entry tesseract_methods[] = {
        PHP_ME(Tesseract, fromFile, tesseract_tesseract_from_file, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
        PHP_ME(Tesseract, fromString, tesseract_tesseract_from_string, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
        PHP_ME(Tesseract, getText, tesseract_tesseract_void, ZEND_ACC_PUBLIC)
        PHP_ME(Tesseract, getHocrText, tesseract_tesseract_void, ZEND_ACC_PUBLIC)
        PHP_ME(Tesseract, getRectangle, tesseract_tesseract_get_rectangle, ZEND_ACC_PUBLIC)
        PHP_FE_END
    };

    void init_tesseract_ce()
    {
        zend_class_entry ce;

        INIT_CLASS_ENTRY(ce, "Tesseract\\Tesseract", tesseract_methods);
        tesseract_ce = zend_register_internal_class(&ce TSRMLS_CC);
        tesseract_ce->create_object = tesseract::php::Tesseract::create_object;

        memcpy(&tesseract::php::Tesseract::handler_tesseract, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
        tesseract::php::Tesseract::handler_tesseract.offset = XtOffsetOf(tesseract::php::Tesseract, std);
    }
}