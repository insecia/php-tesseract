#include "php_tess.h"

zend_class_entry *tesseract_ce;

#define Z_OBJECT_TESSERACT(zo) (tesseract::php::Tesseract::fetch_object(zo))
#define Z_OBJECT_TESSERACT_P(zo) (tesseract::php::Tesseract::fetch_object(Z_OBJ_P(zo)))

#include "php_tesseract.h"

PHP_MINIT_FUNCTION(tesseract)
{
    init_tesseract_ce();

    REGISTER_STRING_CONSTANT(
        "Tesseract\\Language\\GERMAN",
        const_cast<char*>(tesseract::php::Tesseract::LANGUAGE_GERMAN),
        CONST_PERSISTENT | CONST_CS
    );
    REGISTER_STRING_CONSTANT(
        "Tesseract\\Language\\ENGLISH",
        const_cast<char*>(tesseract::php::Tesseract::LANGUAGE_ENGLISH),
        CONST_PERSISTENT | CONST_CS
    );

    return SUCCESS;
}

zend_module_entry tesseract_module_entry = {

#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_TESSERACT_EXTNAME,
    NULL,                  /* Functions */
    PHP_MINIT(tesseract),
    NULL,                  /* MSHUTDOWN */
    NULL,                  /* RINIT */
    NULL,                  /* RSHUTDOWN */
    NULL,                  /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_TESSERACT_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_TESSERACT
extern "C" {
ZEND_GET_MODULE(tesseract)
}
#endif
