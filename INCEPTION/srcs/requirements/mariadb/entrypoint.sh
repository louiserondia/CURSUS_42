
















#!/bin/sh
envsubst < /init.sql | sponge /init.sql
mysqld --init-file /init.sql