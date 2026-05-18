#include "scr_menu_game.h"
#include "screens.h"

static const char* menu_items[] = { "Idle", "Dino", "Charts", "Settings" };
static int menu_count = sizeof(menu_items) / sizeof(menu_items[0]);
static int menu_index = 0;

static void view_scr_menu();

view_dynamic_t dyn_view_item_menu_game = {
    { .item_type = ITEM_TYPE_DYNAMIC },
    view_scr_menu
};

view_screen_t scr_menu_game = {
    &dyn_view_item_menu_game,
    ITEM_NULL,
    ITEM_NULL,
    .focus_item = 0,
};

static void view_scr_menu() {
    view_render.clear();
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);
    for (int i = 0; i < menu_count; i++) {
        int y = 10 + i * 14;
        if (i == menu_index) {
            view_render.fillRect(2, y - 2, 124, 12, WHITE);
            view_render.setTextColor(BLACK);
            view_render.setCursor(6, y);
            view_render.print(menu_items[i]);
            view_render.setTextColor(WHITE);
        } else {
            view_render.setCursor(6, y);
            view_render.print(menu_items[i]);
        }
    }
}

void scr_menu_game_handle(ak_msg_t* msg) {
    switch (msg->sig) {
    case SCREEN_ENTRY: {
        view_render.initialize();
        view_render_display_on();
        menu_index = 0;
        view_scr_menu();
    } break;

    case AC_DISPLAY_BUTTON_UP_RELEASED: {
        if (menu_index > 0) menu_index--;
        else menu_index = menu_count - 1;
        view_scr_menu();
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
    } break;

    case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
        menu_index = (menu_index + 1) % menu_count;
        view_scr_menu();
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
    } break;

    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        BUZZER_PlaySound(BUZZER_SOUND_CLICK);
        switch (menu_index) {
        case 0:
            SCREEN_TRAN(scr_idle_handle, &scr_idle);
            break;
        case 1:
            SCREEN_TRAN(scr_dino_run_handle, &scr_dino_run);
            break;
        case 2:
            SCREEN_TRAN(scr_charts_game_handle, &scr_charts_game);
            break;
        case 3:
            SCREEN_TRAN(scr_game_setting_handle, &scr_game_setting);
            break;
        default:
            break;
        }
    } break;

    default:
        break;
    }
}
