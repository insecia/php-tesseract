FROM php:7.2-alpine

RUN buildDeps=' \
    bash \
    git \
    g++ \
    make \
    cmake \
    libstdc++ \
    libssl1.0 \
    boost-dev \
    curl-dev \
    openssl \
    openssl-dev \
    libc-dev \
    pcre-dev \
    autoconf \
    ' \
    && apk add --update $buildDeps \
    && docker-php-source extract

RUN apk add --update \
    tesseract-ocr \
    tesseract-ocr-dev

RUN wget https://github.com/tesseract-ocr/tessdata/raw/3.04.00/eng.traineddata && \
    mv -v eng.traineddata /usr/share/tessdata && \
    wget https://github.com/tesseract-ocr/tessdata/raw/3.04.00/deu.traineddata && \
    mv -v deu.traineddata /usr/share/tessdata

WORKDIR /app
VOLUME ["/app"]

RUN apk add --update bash \
        boost-system \
        boost-thread \
    && rm -rf /tmp/*

ENTRYPOINT []
CMD bash -c "cd /app && phpize && ./configure && make all -j4 --always-make"
