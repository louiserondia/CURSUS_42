FROM debian:buster
RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y nginx

COPY my-nginx.conf /etc/nginx/sites-enabled/default

CMD ["nginx", "-g", "daemon off;"]
