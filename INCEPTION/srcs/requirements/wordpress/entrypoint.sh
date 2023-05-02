#!/bin/sh

mkdir -p /var/www/html
curl -o /tmp/latest.tar.gz -fSL "https://wordpress.org/latest.tar.gz"; \
tar -xzf /tmp/latest.tar.gz -C /usr/src/; \
rm /tmp/latest.tar.gz; \
mv /usr/src/wordpress/* /var/www/html/; \
rm -rf /usr/src/wordpress;\
chown -R www-data:www-data /var/www/html\
&& chmod -R 755 /var/www/html

php-fpm7.3 -F