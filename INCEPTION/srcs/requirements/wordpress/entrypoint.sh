#!/bin/sh

envsubst < /wp_init.sh | sponge /wp_init.sh

if [ ! -f /var/www/html/wp-config.php ]; then
    /wp_init.sh
fi

php-fpm7.3 -F
