#ifndef PHP_TESSERACT_H
#define PHP_TESSERACT_H

#define PHP_TESSERACT_EXTNAME  "tesseract"
#define PHP_TESSERACT_EXTVER   "0.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

extern "C" {
#include <php.h>
}

extern zend_module_entry tesseract_module_entry;
#define phpext_tesseract_ptr &tesseract_module_entry;

#endif /* PHP_TESSERACT_H */
