#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void write_err(char *msg) {
	write (2, msg, strlen(msg));
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}

typedef struct client_s {
	int id;
	int size;
	char *acc;
}	t_client;

client_t client_create() {
	static int	id;
	client_t	c = {0};
	c.id = id++;
	c.acc = malloc(1000000);
	return c;
}

void	broadcast(int fd, char *msg, fd_set *wfds) {
	for (int i = 0; i < FD_SETSIZE; i++) {
		if (i != fd && FD_ISSET(i, wfsd)) {
			send(i, msg, strlen(msg), 0);
		}
	}
}


int main(int argc, char **argv) {
	if (argc != 2)
		write_err("Wrong number of arguments");

// 1 - SOCKET
// 2 - STRUCT ADDR
// 3 - BIND
// 4 - LISTEN
// 5 - CREER MES FDs
// 6 - TABLEAU CLIENTS + msg

	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
		write_err("Fatal error");

    struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	if (bind(fd, (struct sockaddr *) &addr, sizeof(addr)) == -1)
		write_err("Fatal error");

	if (listen(fd, 100) == -1)
		write_err("Fatal error");

	fd_set	fds;
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	client_t clients[FD_SETSIZE] = {0};
	char msg[65000];

// WHILE :

// 1 - CREER FDS LECTURE ET ECRITURE
// 2 - SELECT ATTEND
// 3 - NV CLIENT (accepter le nv fd, creer client, ajouter a fds et broadcast)
// 4 - LIT SUR TOUS LES FDS (recv)
// 5 - CLIENT PART (broadcast, dree, close, retirer fd)
// 6 - LIRE MSG (copier lettres, broadcastn size = 0)

	while (1) {

		fd_set	rfds = fds;
		fd_set	wfds = fds;
		FD_CLR(fd, &wfds);

		select(FD_SETSIZE, &rfds, &wfds, NULL, NULL);
		
		if (FD_ISSET(fd, &rfds)) { // NOUVEAU CLIENT
			int cfd = accept(fd, NULL, NULL);
			clients[cfd] = client_create();
			FD_SET(cfd, &fds);

			sprintf(msg, "client %d arrived", cliend[cfd].id);
			broadcast(cfd, msg, &wfds);
			continue;
		}

		// on lit sur tous les fds à part le notre et ceux qui sont pas dans rfds
		for (int i = 0; i < FD_SETSIZE; i++) {
			if (i == fd || !FD_ISSET(fd, &rfds)) continue;

		// on lit depuis fd (i) sur le buffer
			char buff[1024];
			ssize_t n = recv(i, buff, sizeof buff, 0);

			if (n <= 0) { // CLIENT PART
				sprintf(msg, "client %d left\n", clients[i].id);
				broadcast(i, msg, &wfds);
				free(clients[i].acc);
				close(i);
				FD_CLR(i, &fds);
				continue;
			}

	// On reçoit, on ajoute une lettre a la fois puis on broadcast et remet size à 0
			for ( int j = 0; j < n; j++) {
				client_t    *c = clients + i; // on pourrait pas mettre ça avant la boucle ?
				c->acc[c->size++] = buff[j];
				if (buff[i] == '\n') {
					c->acc[c->size] = '\0';
					sprintf(msg, "client %d: %s\n", c->id, c->acc);
					broadcast(i, msg, &wfds),
					c->size = 0;
				}
			}
		}
	}
}

// les copyrights vont à vrogiste