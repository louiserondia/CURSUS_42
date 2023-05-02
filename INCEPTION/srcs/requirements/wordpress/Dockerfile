













FROM debian:buster

RUN apt-get update && apt-get install -y php-fpm php-mysql curl net-tools mariadb-client && \
    mkdir /run/php && \
    sed -i 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' /etc/php/7.3/fpm/php.ini && \
    sed -i 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g' /etc/php/7.3/fpm/pool.d/www.conf

COPY . /

RUN chmod +x /*.sh

ENTRYPOINT [ "/entrypoint.sh" ]
