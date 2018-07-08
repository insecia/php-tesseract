--TEST--
Tests the creation of a tesseract instance for German and English

--SKIPIF--
<?php ?>

--FILE--
<?php
$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg', ['eng', 'deu']);
echo $tesseract->getText();

$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg', [
    \Tesseract\Language\GERMAN,
    \Tesseract\Language\ENGLISH
]);
echo $tesseract->getText();
?>

--EXPECTF--
Seite 1 von 1

Seite 1 von 1