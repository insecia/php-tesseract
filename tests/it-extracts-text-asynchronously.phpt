--TEST--
Tests the ability to extract text asynchronously.

--SKIPIF--
<?php ?>

--FILE--
<?php

$futures = [];
for ($i = 0; $i < 5; $i++) {
    $tesseract = \Tesseract\Tesseract::fromFile('tests/test.jpg');
    $futures[] = $tesseract->getTextAsync();
}

foreach ($futures as $future) {
    echo trim($future->get()) . PHP_EOL;
}

?>

--EXPECTF--
Seite 1 von 1
Seite 1 von 1
Seite 1 von 1
Seite 1 von 1
Seite 1 von 1
