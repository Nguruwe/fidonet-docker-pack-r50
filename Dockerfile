FROM debian:bookworm

LABEL maintainer=Nguruwe

RUN    apt update && \
       apt install -y \
        zip \
        git \
        bash \
        curl \
        wget \
        acl \
        attr \
        g++ \
        make \
        libperl-dev \
        zlib1g \
        texinfo \
        ncurses-base \
        ncurses-bin \
        libmodule-build-perl \
        libtest-simple-perl \
        libz-dev \
        libncurses-dev \
        libncurses5 \
        sudo \
        supervisor

RUN    export FIDOCONFIG="/etc/fido/config/config.cfg"

RUN    mkdir /var/log/fido

RUN adduser --disabled-password --shell /bin/bash --gecos "User" fido
RUN    cd /home/fido && \
         sudo -u fido wget https://raw.githubusercontent.com/huskyproject/huskybse/master/script/init_build && \
         chmod 0755 init_build && \
         sudo -u fido ./init_build && \
         cd /home/fido/husky && \
         sudo -u fido ./build.sh && \
         make -j install

RUN    cd /tmp && \
        git clone https://github.com/pgul/binkd && \
        cd binkd && \
        cp mkfls/unix/* . && \
        ./configure && \
        make && \
        make install && \
        cd .. && \
        rm -rf binkd

RUN    cd /home/fido && \
        wget https://github.com/golded-plus/golded-plus/releases/download/golded-plus-1.1.5-20180707-1/golded-plus-1.1.5-20180707-Linux.x86_64.deb && \
        dpkg -i golded-plus-1.1.5-20180707-Linux.x86_64.deb

RUN mkdir -p /var/log/supervisor

CMD /usr/bin/supervisord -c /etc/supervisor/conf.d/supervisord.conf

# set bash comman prompt colors
RUN echo 'PS1="\[\033]0;\u@\h:\w\007\]\[\033[01;31m\]\u@\h\[\033[01;34m\] \w \$\[\033[00m\]"' >> /root/.bashrc
