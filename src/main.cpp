#include <Arduino.h>
#include <esp32_smartdisplay.h>
// #include <lvgl.h>

// #if LV_USE_TFT_ESPI
// #include <TFT_eSPI.h>
// #endif

void setup()
{
  smartdisplay_init();

  auto display = lv_display_get_default();
   lv_display_set_rotation(display, LV_DISPLAY_ROTATION_90);
  // lv_display_set_rotation(display, LV_DISPLAY_ROTATION_180);
  // lv_display_set_rotation(display, LV_DISPLAY_ROTATION_270);

    /*Change the active screen's background color*/
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);

    /*Create a white label, set its text and align it to the center*/
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &lv_font_montserrat_14); // <--- you have to enable other font sizes in menuconfig
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Hallo Annika und Julian <3");
    lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_add_style(label, &style, 0);  // <--- obj is the label
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

auto lv_last_tick = millis();

void loop()
{
    auto const now = millis();
    // Update the ticker
    lv_tick_inc(now - lv_last_tick);
    lv_last_tick = now;
    // Update the UI
    lv_timer_handler();
}