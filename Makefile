build: main.c commands.c commands.h
	gcc main.c commands.c -g -o bot-ar -lssl -lcrypto -ljansson -lpthread -ldiscord -lcurl

