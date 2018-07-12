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

    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\OSD_ONLY", 0, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\AUTO_OSD", 1, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\AUTO_ONLY", 2, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\AUTO", 3, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_COLUMN", 4, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_BLOCK_VERT_TEXT", 5, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_BLOCK", 6, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_LINE", 7, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_WORD", 8, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\CIRCLE_WORD", 9, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SINGLE_CHAR", 10, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SPARSE_TEXT", 11, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\SPARSE_TEXT_OSD", 12, CONST_PERSISTENT | CONST_CS);
    REGISTER_LONG_CONSTANT("Tesseract\\PageSegMode\\RAW_LINE", 13, CONST_PERSISTENT | CONST_CS);

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
