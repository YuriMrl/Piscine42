#!/usr/bin/env sh

ldapsearch -xLLL 'sn=*bon*' | grep 'sn:' | wc -l | sed 's/ //g'
