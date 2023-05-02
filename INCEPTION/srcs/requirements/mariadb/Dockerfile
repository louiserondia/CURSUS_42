













FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server moreutils gettext && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /run/mysqld; \
    chown -R mysql:mysql /run/mysqld

COPY . /

RUN chmod +x /entrypoint.sh

ENTRYPOINT [ "/entrypoint.sh" ]
