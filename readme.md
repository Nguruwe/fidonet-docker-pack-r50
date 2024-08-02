Fidonet software pack in docker, r50 cp866 charset
(No any automation yet)

Dependencies:
docker (rootless)
luit (need for session KOI8-R charset translation)
make (need for console commands)

Usage:

cp ./MySecData.example MySecData
Fill necessary fields

make build - build docker image

make up - run container
make down - stop container

make fido - run container console
    poll - poll uplink
    hpt pack - pack outbound netmail
    hpt toss - toss echomail
    hpt scan - scan and pack outbound echomail
    hptutil - does not work, core dumped :-((
make golded - open golded session in docker container
