#!/bin/sh
envsubst < /init.sql | sponge /init.sql
mysqld --bind-address 0.0.0.0 --init-file /init.sql