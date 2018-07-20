--TEST--
Tests the creation of a tesseract instance for German and English

--SKIPIF--
<?php ?>

--FILE--
<?php
/*
Note: For some reason the tesseract library prints "Using default language params\n" to the console when ran
under Ubuntu (14.04). I was not able to find the reason yet but this neither happens under Alpine nor Debian.
As soon as the problem is found and fixed the %r...%r below can be removed.
*/

$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg', ['eng', 'deu']);
echo $tesseract->getText();

$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg', [
    \Tesseract\Language\GERMAN,
    \Tesseract\Language\ENGLISH
]);
echo $tesseract->getText();
?>

--EXPECTF--
%r(Using default language params\n)?%rSeite 1 von 1

%r(Using default language params\n)?%rSeite 1 von 1