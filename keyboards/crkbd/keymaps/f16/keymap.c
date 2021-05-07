#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _WORKMAN,
  _FN1,
  _FN2,
  _FN3
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN1,
  FN2,
  FN3,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};
// shortcuts
#define SFTQUOT RSFT_T(KC_QUOT)
#define SFTCAPS LSFT_T(KC_CAPS)
#define FN2SPC LT(_FN2,KC_SPC)
#define FN2BS LT(_FN2,KC_BSLS)
#define FN3ENT LT(_FN3,KC_ENT)
#define FN1ESC LT(_FN1,KC_ESC)
#define FN3G LT(_FN3,KC_G)

// modifiers on homerow
// left hand
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SHFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
// right hand
#define CTL_J RCTL_T(KC_J)
#define SHFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)
// workman letf
#define SHFT_H LSFT_T(KC_H)
#define C_T LCTL_T(KC_T)
// workman right
#define CTL_N RCTL_T(KC_N)
#define SHFT_E RSFT_T(KC_E)
#define ALT_O LALT_T(KC_O)
#define GUI_I RGUI_T(KC_I)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(\
//┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   SFTCAPS, GUI_A,   ALT_S,   SHFT_D,  CTL_F,   FN3G,         KC_H,    CTL_J,   SHFT_K,  ALT_L,   GUI_SCL, SFTQUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GESC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
//└────────┴────────┴────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┴────────┘
                              FN1,     FN2SPC,  KC_BSPC,      FN3ENT,  FN2BS,   FN1ESC
//                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
),

[_WORKMAN] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,         KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, GUI_A,   ALT_S,   SHFT_H,  C_T,     KC_G,         KC_Y,    CTL_N,   SHFT_E,  ALT_O,   GUI_I,   _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,         KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, _______,
//└────────┴────────┴────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┴────────┘
                              _______, _______, _______,      _______, _______, _______
                          // └────────┴────────┴────────┘    └────────┴────────┴────────┘
  ),

[_FN1] = LAYOUT(\
//┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,  
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_LPRN, _______, _______, KC_HOME, KC_PGUP,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RPRN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_GRAVE,KC_F11,  KC_F12,  _______, KC_END,  KC_PGDN,      KC_EQL,  KC_MINS, _______, _______, _______, RESET,
//└────────┴────────┴────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┴────────┘
                              _______, KC_INS,  KC_DEL,       _______, _______, _______
//                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
),

[_FN2] = LAYOUT(\
//┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,  
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, KC_1,    _______, _______, _______, _______,      KC_PLUS, KC_UNDS, _______, _______, KC_0,    _______,
//└────────┴────────┴────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┴────────┘
                              _______, _______, _______,      _______, _______, _______
//                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
),

[_FN3] = LAYOUT(\
//┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
   RGBRST,  RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,      KC_NO,   KC_BTN1, KC_MS_U, KC_BTN3, KC_NO,   _______,  
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,_______,      KC_NO,   KC_MS_L, KC_NO,   KC_MS_R, KC_BTN2, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
   EEP_RST, _______, _______, _______, DF(_QWERTY),DF(_WORKMAN),      KC_NO,   KC_BTN1, KC_MS_D, KC_NO,   KC_NO,   _______,
//└────────┴────────┴────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┴────────┘
                              _______, _______, _______,      _______, _______, _______
//                           └────────┴────────┴────────┘    └────────┴────────┴────────┘
)

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting FN3 layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
        update_tri_layer_RGB(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN1);
        update_tri_layer_RGB(_FN1, _FN2, _FN3);
      }
      return false;
    case FN2:
      if (record->event.pressed) {
        layer_on(_FN2);
        update_tri_layer_RGB(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN2);
        update_tri_layer_RGB(_FN1, _FN2, _FN3);
      }
      return false;
    case FN3:
        if (record->event.pressed) {
          layer_on(_FN3);
        } else {
          layer_off(_FN3);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
