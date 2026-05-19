#include "scr_game_setting.h"
#include "app_eeprom.h"
#include "screens.h"

static uint8_t selected_item = 0; // 0 = speed, 1 = sound

static void view_scr_game_setting();

view_dynamic_t dyn_view_item_game_setting = {
    { .item_type = ITEM_TYPE_DYNAMIC },
    view_scr_game_setting
};

view_screen_t scr_game_setting = {
    &dyn_view_item_game_setting,
    ITEM_NULL,
    ITEM_NULL,
    .focus_item = 0,
};

static void view_scr_game_setting() {
    view_render.clear();
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);
    view_render.setCursor(6, 8);
    view_render.print("Settings");

    view_render.setCursor(6, 24);
    view_render.print(selected_item == 0 ? "> " : "  ");
    view_render.print("Dino speed: ");
    view_render.print(settingdata.meteoroid_speed);

    view_render.setCursor(6, 40);
    view_render.print(selected_item == 1 ? "> " : "  ");
    view_render.print("Sound: ");
    view_render.print(settingdata.silent ? "Off" : "On");

    view_render.setCursor(6, 54);
    view_render.print("Up/Down=Change");
    view_render.update();
}

static void clamp_and_save() {
    if (settingdata.meteoroid_speed < AR_GAME_SETTING_METEOROID_SPEED_MIN) {
        settingdata.meteoroid_speed = AR_GAME_SETTING_METEOROID_SPEED_MIN;
    }
    if (settingdata.meteoroid_speed > AR_GAME_SETTING_METEOROID_SPEED_MAX) {
        settingdata.meteoroid_speed = AR_GAME_SETTING_METEOROID_SPEED_MAX;
    }
    settingdata.silent = settingdata.silent ? 1 : 0;
    ar_game_setting_write(&settingdata);
}

void scr_game_setting_handle(ak_msg_t* msg) {
    switch (msg->sig) {
    case SCREEN_ENTRY: {
        view_render.initialize();
        view_render_display_on();
        ar_game_setting_read(&settingdata);
        selected_item = 0;
        view_scr_game_setting();
    } break;

    case AC_DISPLAY_BUTTON_UP_RELEASED: {
        if (selected_item == 0) {
            if (settingdata.meteoroid_speed < AR_GAME_SETTING_METEOROID_SPEED_MAX) {
                settingdata.meteoroid_speed++;
                ar_game_setting_write(&settingdata);
            }
        } else {
            settingdata.silent = !settingdata.silent;
            clamp_and_save();
        }
        view_scr_game_setting();
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
    } break;

    case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
        if (selected_item == 0) {
            if (settingdata.meteoroid_speed > AR_GAME_SETTING_METEOROID_SPEED_MIN) {
                settingdata.meteoroid_speed--;
                ar_game_setting_write(&settingdata);
            }
        } else {
            settingdata.silent = !settingdata.silent;
            clamp_and_save();
        }
        view_scr_game_setting();
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
    } break;

    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        if (selected_item == 0) {
            selected_item = 1;
            view_scr_game_setting();
            BUZZER_PlaySound(BUZZER_SOUND_CLICK);
        } else {
            SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game);
            BUZZER_PlaySound(BUZZER_SOUND_CLICK);
        }
    } break;

    case AC_DISPLAY_BUTTON_MODE_LONG_PRESSED: {
        SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game);
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
    } break;

    default:
        break;
    }
}
