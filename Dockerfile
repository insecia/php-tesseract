FROM extension-builder

COPY modules/tesseract.so /tmp

RUN echo "extension=tesseract.so" > /usr/local/etc/php/conf.d/tesseract.ini \
    && mv /tmp/tesseract.so $(php-config --extension-dir)
