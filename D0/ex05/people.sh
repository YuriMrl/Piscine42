ldapsearch -xLL "uid=z*" cn | grep cn | cut -c 5- | sort -rf
