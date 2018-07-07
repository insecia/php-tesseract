# php-tesseract
This extension is currently under development. 
## Installation
### Initial Setup
```
$ git clone https://github.com/insecia/php-tesseract.git
$ cd php-tesseract
$ docker-compose build extension-builder
```
### Compile Extension
```
$ docker-compose run --rm extension-builder
$ docker-compose build php 
```
### Run Tests
```
$ docker-compose run --rm php make test
```
### Run Script
```
$ docker-compose run --rm php php script_name.php
```

## Usage
### Basic usage
```php
$tesseract = \Tesseract\Tesseract::fromFile('image.jpg');
$textContent = $tesseract->getText();
```
It's also possible to define a certain rectangular area of the image from
which the tesseract lib should extract text. 
```php
$tesseract = \Tesseract\Tesseract::fromFile('image.jpg');
$textContent = $tesseract->getRectangle(500, 500, 1000, 1000)->getText();
```
A tesseract instance can also be created from a string that contains the binary content 
of an image. This has the advantage of not requiring the creation of a temporary file. 
```php
$textContent = \Tesseract\Tesseract::fromString($imageContent)->getText();
``` 
