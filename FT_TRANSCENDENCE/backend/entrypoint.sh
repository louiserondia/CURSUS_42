#!/bin/sh

npx prisma migrate deploy
npx prisma generate
npm run build
exec "$@"
