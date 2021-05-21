build: main.c commands.c commands.h
	gcc main.c commands.c -g -o bot -lssl -lcrypto -ljansson -lpthread -ldiscord -lcurl

clean:
	rm bot