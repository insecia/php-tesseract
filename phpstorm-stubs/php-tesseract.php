<?php

namespace Tesseract {
    class Tesseract {
        /**
         * @param string $filePath
         * @param array $languages
         * @return Tesseract
         */
        public static function fromFile(string $filePath, array $languages = []): self
        {
        }

        /**
         * @param string $fileContent
         * @param array $languages
         * @return Tesseract
         */
        public static function fromString(string $fileContent, array $languages = []): self
        {
        }

        /**
         * @return string
         */
        public function getText(): string
        {
        }

        /**
         * @param int $left
         * @param int $top
         * @param int $width
         * @param int $height
         * @return Tesseract
         */
        public function getRectangle(int $left, int $top, int $width, int $height): self
        {
        }

        /**
         * @param int $mode
         * @return Tesseract
         */
        public function setPageSegMode(int $mode): self
        {
        }
    }
}

namespace Tesseract\Language {

}

namespace Tesseract\PageSegMode {

}
