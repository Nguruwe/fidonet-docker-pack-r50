#
# Define a link:
#       node [[z:]n/]n[.p][@domain] [-nr|-nd] [-md] [-hc|-nohc] [-ip|-sip] [-bw <send_rate>[/<recv_rate>]] [-4|-6] [{hosts|-} [{<inpwd>[,[<pktpwd>][,<outpwd>]]|-} [flavour [{obox|-} [{ibox|-}]]]]]
#
# * All non-"-" fields will redefine the values specified for the same node
#   earlier in config.
# * The meaning of <inpwd>, <pktpwd> and <outpwd> is the same as in
#   the description of the "passwords" token. Any password is one word
#   without spaces or tabs. If <pktpwd> or <outpwd> is omitted, it is
#   assumed equal to <inpwd>.
# * Flavour is one of i, c, d, -, h; and is the flavour for the outbound
#   filebox ("obox").
# * Binkd sends from obox all non-dir entries NOT matching ".*" wildcard.
#   EVERY TIME YOU PUT A FILE INTO OBOX CHECK IF BINKD WILL BE ABLE TO
#   UNLINK IT. Otherwise, the session will never end.
# * Default for ibox is inbound or inbound-nosecure depending on the pwd field.
# * Default for port is oport.
# * `-nr' stands for `Not Reliable Link', this works only on outbound calls
#   with another binkp/1.1 mailer. The option solves the only problem with
#   binkd having no enough time to start receiving of a file from
#   non-zero offset before IP link's down, so don't use it unless you
#   have this problem -- really not effective
# * `-nd' means "No Dupe Mode", this works only on outbound calls with
#   another binkd 0.9.3 or higher. The option solves problem with
#   duplicating files while losts carrier but link is a bit slower
#   then with "-nr" option
# * `-md' means "Must have CRAM-MD5". This works only with nodes with
#       binkd or argus supported this method. Do not set it if your link
#       can use the old version of binkd.
# * `-nomd' - do not use CRAM-MD5 for this node (send plain text password)
# * `-hc' enables check of sender address in pkt header for this node/aka
#       (overrides the setting of the 'check-pkthdr' statement)
# * `-nohc' disables check of sender address in pkt header for this node/aka
#       (overrides the setting of the 'check-pkthdr' statement)
# * `-ip' means "Remote IP check". In this case the node will be
#       rejected, if it comes not from one of its IP-addresses.
#       Remote AKAs with bad IP-address will be dropped on outgoing calls.
# * `-sip' means "Strict remote IP check". Like "-ip", but node will be
#       rejected, if no IP-addresses allowed ("-" or not resolved).
#       Remote AKAs with bad IP-address will be dropped on outgoing calls.
# * `-bw' specifies bandwidth (rate) limit for this node
#       if one value is specified, it's used as both send and recv limit
#       if two values are specified, first is for send and second - for recv
#       rate values are expected to be in format `<rate>[kM%]|-'
#       (see limit-rate keyword for detailed description)
# * `-noproxy' disables usage of proxy/socks server when calling this node
#       (node expected to be inside local network)
# * `-4' only connect via IPv4
# * `-6' only connect via IPv6
# * Hosts is a list in form
#       host1[:port1][;host2[:port2]] ...
# * Asterisk (`*') in the host list forces Binkd to perform
#       1:2/3.4 --> p4.f3.n2.z1.binkp.net translation for a node's
#       Fido-address and lookup IP for the resulting FQDN in DNS.
#       Root domain part ("binkp.net") can be changed with root-domain
#       keyword.
#
#node 5047/888 - password
#node 5047/999 hostname;* password i c:\\bbs\\boxes\\to999 c:\\bbs\\boxes\\from999

# You can write here, but better way is get data from fidoconfig at /var/config/binkd.inc (included in top of binkd.cfg)
