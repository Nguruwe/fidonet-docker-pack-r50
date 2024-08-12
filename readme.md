## Fidonet software pack in docker
### Features:
- Fidoconfig support
- Z2R50 cp866 charset
- No any automation yet
- Only Fidonet point system tested
- One password for session, packages, etc.
- amd64 arch support

### Software
- [binkd mailer](https://github.com/pgul/binkd)
- [hpt tosser](https://github.com/huskyproject)
- [GoldEd+ msg editor](https://github.com/golded-plus/golded-plus)

### Requirements:
- [docker (rootless)](https://docs.docker.com/engine/security/rootless/)
- luit (need for session KOI8-R charset translation)
- make (need for console commands)

### Usage:

- cp ./MySecData.example MySecData
- Fill necessary fields (your name, Fidonet address, uplink session parameters, etc.)
- Run 'make build' to build docker image
- Run 'make up' to start container
- Run 'make down' to stop container

- Run 'make fido' to access container console, example commands:
	- poll - poll uplink
	- hpt pack - pack outbound netmail
	- hpt toss - toss echomail
	- hpt scan - scan and pack outbound echomail
	- hptutil - does not work, core dumped :-(( Use sqpack to purge/pack bases
	- sqpack - purge/pack bases, eg: sqpack dupe netmail
- Run 'make golded' to open golded session in docker container

### Known issues:
- GoldED+ crashes widescreen terminal session if try nodelist access on Netmail area.

### Links:
- [Binkd FAQ](https://github.com/pgul/binkd/blob/master/binkdfaq-en.txt)
- [Fidoconfig docs](http://www.textfiles.com/fidonet-on-the-internet/husky/fidoconf.htm)
- [GoldED+ FAQ](https://github.com/golded-plus/golded-plus/blob/master/docs/rusfaq_utf8.txt)
- [GoldED config](https://fidopedia.fido.de/index.php?title=Golded_cfg)
- [GoldED manual (RU)](https://sabini.ch/fidonet/rukovodstvo-polzovatelya-golded.html)