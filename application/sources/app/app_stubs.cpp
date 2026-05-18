#include "app_eeprom.h"
#include "app.h"

// Define globals expected by other modules
ar_game_setting_t settingdata;
ar_game_score_t gamescore;
int ar_game_state = GAME_OFF;

// Provide empty handlers for archery-related tasks (stubs)
void ar_game_meteoroid_handle(ak_msg_t* msg) { (void)msg; }
void ar_game_border_handle(ak_msg_t* msg) { (void)msg; }
void ar_game_archery_handle(ak_msg_t* msg) { (void)msg; }
void ar_game_arrow_handle(ak_msg_t* msg) { (void)msg; }
void ar_game_bang_handle(ak_msg_t* msg) { (void)msg; }
// Screen handler stub
void scr_archery_game_handle(ak_msg_t* msg) { (void)msg; }
