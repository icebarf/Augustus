#include <libdiscord/gateway.h>
#include <libdiscord/wsc.h>
#include <libdiscord/bot.h>
#include <libdiscord/rest.h>
#include <libdiscord/types.h>
#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>


void cmd_ping(bot_t* bot, message_t msg);
void cmd_botinfo(bot_t* bot, message_t msg);