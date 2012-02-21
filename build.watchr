watch('src/(.*)\.[ch]') { system("make") }
watch('.*Makefile.am') { system("./bootstrap.sh") }
