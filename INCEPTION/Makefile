# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:44:42 by lrondia           #+#    #+#              #
#    Updated: 2023/04/10 12:44:13 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR = srcs

all: up

dir:
	mkdir -p /home/lrondia/data/wp
	mkdir -p /home/lrondia/data/db

up: dir
	docker-compose --project-directory $(DIR) up -d

build: dir
	docker-compose --project-directory $(DIR) up -d --build

down:
	docker-compose --project-directory $(DIR) down

prune:
	docker system prune -fa --volumes

destroy:
	./destroy.sh

re: down prune build

.PHONY: all clean fclean re test
