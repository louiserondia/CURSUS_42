FROM debian:buster
RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y nginx openssl && \
	rm -rf /var/lib/apt/lists/*

COPY my-nginx.conf /etc/nginx/sites-enabled/default

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/lrondia.key -out /etc/nginx/ssl/lrondia.crt -subj "/CN=lrondia"

# openssl req: Commande pour les demandes de certificat X.509.
# -x509: Indique la création d'un certificat auto-signé.
# -nodes: Indique que la clé privée ne sera pas cryptée par une phrase de passe.
# -days 365: Indique la durée de validité du certificat.
# -newkey rsa:2048: Indique la création d'une nouvelle clé RSA de 2048 bits.
# -keyout /etc/nginx/ssl/lrondia.key: Indique le chemin pour stocker la clé privée.
# -out /etc/nginx/ssl/lrondia.crt: Indique le chemin pour stocker le certificat.
# -subj "/CN=lrondia": Indique le nom commun du certificat.


CMD ["nginx", "-g", "daemon off;"]
