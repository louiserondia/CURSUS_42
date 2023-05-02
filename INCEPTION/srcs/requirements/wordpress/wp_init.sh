#!/bin/sh

# Download and install WP-CLI
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# Download and install WordPress
wp core download \
    --path=/var/www/html \
    --allow-root

# Create the wp-config.php file
wp config create \
    --path=/var/www/html \
    --dbhost=$DB_HOST \
    --dbname=$DB_NAME \
    --dbuser=$DB_USER \
    --dbpass=$DB_PASSWORD \
    --allow-root

# Install WordPress
wp core install \
    --path=/var/www/html \
    --url=$WP_URL \
    --title=$WP_TITLE \
    --admin_user=$WP_ROOT_USER \
    --admin_password=$WP_ROOT_PASSWORD \
    --admin_email=$WP_ROOT_EMAIL \
    --allow-root

# Create random user
wp user create \
    $WP_USER $WP_USER_EMAIL \
    --role=author \
    --user_pass=$WP_USER_PASSWORD \
    --allow-root \
    --path=/var/www/html
