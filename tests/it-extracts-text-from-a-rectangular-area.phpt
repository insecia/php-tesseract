--TEST--
Tests the extraction of text from a certain rectangular area only.

--SKIPIF--
<?php ?>

--FILE--
<?php
$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg');
echo $tesseract->getRectangle(0, 0, 180, 120)->getText();
?>

--EXPECTF--
Seite