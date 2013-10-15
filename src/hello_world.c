#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x1C, 0x6F, 0x8E, 0x35, 0xE0, 0xE0, 0x4D, 0x51, 0x9F, 0xBD, 0x63, 0x7E, 0xEF, 0x79, 0xF1, 0x25 }
PBL_APP_INFO(MY_UUID,
             "Hola mundo", "ebr bots",
             1, 2, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
TextLayer hello_layer;
TextLayer world_layer;

void handle_init(AppContextRef ctx) {

  window_init(&window, "Ventana principal");
  window_stack_push(&window, true /* Animated */);

  text_layer_init(&hello_layer, GRect(0, 35, 144, 30));
  text_layer_set_text_alignment(&hello_layer, GTextAlignmentCenter);
  text_layer_set_text(&hello_layer, "¡Hola");
  text_layer_set_font(&hello_layer, fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD));
  layer_add_child(&window.layer, &hello_layer.layer);

  text_layer_init(&world_layer, GRect(0, 65, 144, 30));
  text_layer_set_text_alignment(&world_layer, GTextAlignmentCenter);
  text_layer_set_text(&world_layer, "mundo!");
  text_layer_set_font(&world_layer, fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD));
  layer_add_child(&window.layer, &world_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
