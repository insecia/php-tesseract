--TEST--
Tests the usage of a different page segmentation mode.

--SKIPIF--
<?php ?>

--FILE--
<?php
$tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg');
echo $tesseract->setPageSegMode(\Tesseract\PageSegMode\SINGLE_WORD)->getText();
?>

--EXPECTF--
Seitelvonl