/* Libdiscord and other includes */
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

/* Commands */
#include "commands.h"

/* Prefix for Bot*/
#define PREFIX "!"
#define MAX_CMD_LEN 16
#define BOT_CMDS 2

/* Global Command Variable */
char command[MAX_CMD_LEN];
char commands[BOT_CMDS][MAX_CMD_LEN] = {
  {"!ping"},
  {"!botinfo"}
};

/* Command wrappers and methods */
void get_cmd(message_t msg) {
  int len = 0;
  for(int i = 0; i < MAX_CMD_LEN; i++){
    if(msg.content[i] == ' ' 
          || msg.content[i] == '\0') {break;} 
    command[i] = msg.content[i];
  }
}

void clean_cmd() {
  memset(command, 0, 16);
}


void match_command( bot_t* bot, message_t msg) {
  /* Get command and store in local variable and then flush global variable */
  get_cmd(msg);
  char local_cmd[MAX_CMD_LEN];
  strcpy(local_cmd, command);
  clean_cmd();

  /* Match commands now */
  int cmd_index = -1;
  for (int i = 0; i < BOT_CMDS; i++) {
    if(strcmp(local_cmd, commands[i]) == 0){
      cmd_index = i;
      break;  
    }
  }

  /* execute command based on index */
  switch(cmd_index){
    case 0: cmd_ping(bot, msg); break;

    case 1: cmd_botinfo(bot, msg); break;
  }

}

/* Checks for prefix in message */
int check_prefix(char* prefix, char* msg) {
  if (msg[0] == *prefix){
      return 1;
  } else {
      return 0;
  }
}

/* Libcord main */
void msg(bot_t* bot, message_t msg) {
  int prefix_status = check_prefix(PREFIX, msg.content);
  if(prefix_status){
    match_command(bot, msg);
  }
}

int main(){
  /* Get bot token */
  char* token;
  if(getenv("TOKEN") == 0) {
    token = getenv("TOKEN");
  }else {
    puts("Could not load bot TOKEN");
  }

  /* Create a new bot instance*/
  bot_t* bot = make_bot(token, GUILD_MESSAGES);

  bot->on_msg = msg;
  run(bot);

  /* Free the bot instance */
  free_bot(bot);
  return 0;
}