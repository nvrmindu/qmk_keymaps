#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  FN1,
  FN2,
  FN3,
};

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

// layouts
/*#define L_QS DF(_QWERTY_SIMPLE)*/
/*#define L_QC DF(_QWERTY)*/
/*#define L_WM DF(_WORKMAN)*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐  ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_H,       KC_H,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        SFTCAPS, GUI_A,   ALT_S,   SHFT_D,  CTL_F,   FN3G,      KC_O,       KC_O,      KC_H,    CTL_J,   SHFT_K,  ALT_L,   GUI_SCL, SFTQUOT,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_GESC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,       KC_N,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
//     └────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┘
                          KC_NO,   KC_NO,   FN1,     FN2SPC,    KC_BSPC,    KC_NO,     FN3ENT,  FN2BS,   FN1ESC,   RESET
//                       └────────┴────────┴────────┴────────┘ └────────┘  └────────┘ └────────┴────────┴────────┴────────┘
    ),

    [_FN1] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐  ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,     _______,    _______,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  _______,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LPRN, _______, _______, KC_HOME, KC_PGUP,   _______,    _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RPRN, _______,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_GRAVE,KC_LBRC, KC_F11,  KC_F12,  KC_END,  KC_PGDN,   _______,    _______,   KC_EQL,  KC_MINS, _______, _______, KC_RBRC, _______,
//     └────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_INS,  KC_DEL,    _______,    _______,   _______, _______, _______, _______
//                       └────────┴────────┴────────┴────────┘ └────────┘  └────────┘ └────────┴────────┴────────┴────────┘
    ),

    [_FN2] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐  ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      _______,    _______,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   _______,    _______,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_1,    _______, _______, _______, _______,   _______,    _______,   KC_PLUS, KC_UNDS, _______, _______, KC_0,    _______,
//     └────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______,   _______,    _______,   _______, _______, _______, _______
//                       └────────┴────────┴────────┴────────┘ └────────┘  └────────┘ └────────┴────────┴────────┴────────┘
    ),

    [_FN3] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┐  ┌────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_VOLU, KC_BRIU, _______, RGB_HUI, RGB_HUD, RGB_TOG,   _______,    _______,   KC_NO,   KC_BTN1, KC_MS_U, KC_BTN3, KC_NO,   KC_MPRV,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_VOLD, KC_BRID, _______, RGB_SAI, RGB_SAD, _______,   _______,    _______,   KC_NO,   KC_MS_L, KC_NO,   KC_MS_R, KC_BTN2, KC_MNXT,
//     ├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_MUTE, _______, _______, RGB_VAI, RGB_VAD, RGB_MOD,   _______,    _______,   KC_NO,   KC_BTN1, KC_MS_D, KC_NO,   KC_NO,   KC_MPLY,
//     └────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┤  ├────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______,   _______,    _______,   _______, _______, _______, _______
//                       └────────┴────────┴────────┴────────┘ └────────┘  └────────┘ └────────┴────────┴────────┴────────┘
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
        update_tri_layer(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN1);
        update_tri_layer(_FN1, _FN2, _FN3);
      }
      return false;
      break;
    case FN2:
      if (record->event.pressed) {
        layer_on(_FN2);
        update_tri_layer(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN2);
        update_tri_layer(_FN1, _FN2, _FN3);
      }
      return false;
      break;
    case FN3:
      if (record->event.pressed) {
        layer_on(_FN3);
      } else {
        layer_off(_FN3);
      }
      return false;
      break;
  }
  return true;
}
