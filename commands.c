#include "commands.h"
#include <libdiscord/rest.h>
#include <libdiscord/types.h>

void cmd_ping(bot_t* bot, message_t msg) {
  create_message(bot, "Pong!", msg.channel_id, NULL, NULL);
}

void cmd_botinfo(bot_t *bot, message_t msg){
  embed_t* emd =
    make_embed("Agustus Github Page", "Augustus is written in C with the help of libcord discord library."
              "\n\n"
              "**Created on May 19, 2021.**\n\n"
              "Currently, Work in progress ",NULL, "https://github.com/sysgrammer/Augustus", NULL, 0x12e0d3);
    
    create_message(bot, " ", msg.channel_id, emd, NULL);
    free_embed(emd);
}