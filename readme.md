## Fidonet software pack in docker
### Features:
- r50 cp866 charset
- (No any automation yet)

### Software
- [Fidoconfig support](http://www.textfiles.com/fidonet-on-the-internet/husky/fidoconf.htm)
- [binkd mailer](https://github.com/pgul/binkd)
- [hpt tosser](https://github.com/huskyproject)
- [golded+ msg editor](https://github.com/golded-plus/golded-plus)


### Dependencies:
- [docker (rootless)](https://docs.docker.com/engine/security/rootless/)
- luit (need for session KOI8-R charset translation)
- make (need for console commands)

### Usage:

- cp ./MySecData.example MySecData
- Fill necessary fields
- Run make build to build docker image
- Run make up to start container
- Run make down to stop container

- make fido to access container console
	- poll - poll uplink
	- hpt pack - pack outbound netmail
	- hpt toss - toss echomail
	- hpt scan - scan and pack outbound echomail
	- hptutil - does not work, core dumped :-(( Use sqpack to purge/pack bases
	- sqpack - purge/pack bases, eg: sqpack dupe netmail
- make golded - open golded session in docker container
