PHP_ARG_ENABLE(tesseract,
    [Whether to enable the "tesseract" extension],
    [  --enable-tesseract      Enable "tesseract" extension support])

if test $PHP_TESSERACT != "no"; then
    for i in /usr /usr/local; do
      if test -f $i/include/tesseract/baseapi.h; then
        TESSERACT_INCLUDE_DIR=$i
        AC_MSG_RESULT(found tesseract includes in $i)
        break
      fi
    done

    for i in /usr /usr/local; do
      if test -f $i/lib/libtesseract.a; then
        TESSERACT_LIB_DIR=$i
        AC_MSG_RESULT(found tesseract lib in $i)
        break
      fi
    done

    PHP_ADD_INCLUDE($TESSERACT_INCLUDE_DIR)

    CXXFLAGS="-std=c++11"
    PHP_REQUIRE_CXX()

    PHP_SUBST(TESSERACT_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, TESSERACT_SHARED_LIBADD)
    PHP_ADD_LIBRARY_WITH_PATH(tesseract, $TESSERACT_LIB_DIR, TESSERACT_SHARED_LIBADD)
    PHP_NEW_EXTENSION(tesseract, php_tess.cpp src/tesseract.cpp, $ext_shared)
fi
