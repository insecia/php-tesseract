--TEST--
Tests the creation of a tesseract instance from a image in a string.

--SKIPIF--
<?php ?>

--FILE--
<?php
$fileContent = file_get_contents('tests/test.jpg');
$tesseract = \Tesseract\Tesseract::fromString($fileContent);
echo $tesseract->getText();
?>

--EXPECTF--
Seite 1 von 1