#!/usr/bin/env sh

ifconfig | grep ether | sed "s/ether//" | tr -d '\t' | tr -d ' '$
