SHELL := /bin/bash

fido:
	docker exec -i -t --privileged fido bash

golded:
	luit -encoding KOI8-R docker exec -i -t --privileged fido bash -c "/usr/local/sbin/fido/makeGoldedConfig && golded -C/var/config/golded.cfg"

up:
	docker compose up -d

down:
	docker compose down

build:
	docker compose build

#workers:
#	. .env; docker exec -i -t --user $${APP_USER} $${PROJECT_NAME}-worker bash

#workers-root:
#	. .env; docker exec -i -t --privileged $${PROJECT_NAME}-worker bash
