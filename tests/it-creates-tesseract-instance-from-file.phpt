--TEST--
Tests the creation of a tesseract instance from a file path.

--SKIPIF--
<?php ?>

--FILE--
<?php
$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg');
echo $tesseract->getText();
?>

--EXPECTF--
Seite 1 von 1