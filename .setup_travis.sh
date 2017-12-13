#!/bin/bash

# install rust beta
curl -sSf https://build.travis-ci.org/files/rustup-init.sh | sh -s -- --default-toolchain=beta -y

# install crystal
#apt-key adv --keyserver keys.gnupg.net --recv-keys 09617FD37CC06B54
# echo "deb https://dist.crystal-lang.org/apt crystal main" | tee -a /etc/apt/sources.list.d/crystal.list
# apt-get update
# apt-get install crystal -y
