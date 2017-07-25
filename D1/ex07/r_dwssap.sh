#!/usr/bin/env sh

cat /etc/passwd | grep -v "#" | awk "NR % 2==0" | cut -d ":" -f-1 | rev | sort -r  | sed -n $FT_LINE1","$FT_LINE2"p" | tr "\n" ","  | cut -c1- | rev | sed "s/,/./" | rev | tr -d "\n" | sed "s/,/, /g"
