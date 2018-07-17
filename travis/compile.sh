phpize
./configure
make all -j4
sudo make install

echo "extension=tesseract.so" >> `php --ini | grep "Loaded Configuration" | sed -e "s|.*:\s*||"`
