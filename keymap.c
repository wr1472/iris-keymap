#include QMK_KEYBOARD_H
#include "keymap_uk.h"


#define _QWERTY 0
#define _RS 1  // RAISE
#define _LW 2  // LOWER
// #define _AJ 3  // ADJUST

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LW,
  RS,
//   AJ,
  ALT_TAB,
  ALT_SFT_TAB
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,                             KC_LBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,                             KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                             KC_LGUI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT, KC_BSPC,          KC_MUTE, KC_RSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, RS,      KC_SPC,                    KC_ENT,  LW,      KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     UK_TILD, UK_HASH, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,                            KC_MINS, KC_EQL,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     UK_BSLS, KC_UP,   KC_INS,  KC_HOME, KC_PGUP, ALT_SFT_TAB,                        TO(_RS), TO(_LW), KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN, ALT_TAB,                            _______, UK_SCLN, KC_P1,   KC_P2,   KC_P3,   KC_PAST,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     UK_PIPE, UK_AT,   KC_QUOT, UK_DQUO, UK_DOT,  _______, KC_DEL,           _______, _______, UK_COLN, KC_P0,   KC_PENT, KC_PDOT, KC_PSLS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
 
  [_LW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                            _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     BL_TOGG, BL_STEP, BL_BRTG, _______, _______, _______,                            TO(_RS), TO(_LW), KC_PSCR, KC_CAPS, KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            KC_TAB,  UK_RABK, UK_QUES, KC_APP,  KC_WSTP, KC_WREF,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   DEBUG,   RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,          _______, _______, UK_LABK, UK_NOT,  KC_CALC, KC_WBAK, KC_WFWD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )//,

//   [_AJ] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
//   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
//                                     _______, _______, _______,                   _______, _______, _______
//                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
//   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        rgblight_setrgb(RGB_BLUE);
      }
      return false;
      break;
    case LW:
      if (record->event.pressed) {
        layer_on(_LW);
        rgblight_setrgb(RGB_RED);
        // update_tri_layer(_LW, _RS, _AJ);
      } else {
        layer_off(_LW);
        rgblight_setrgb(RGB_BLUE);
        // update_tri_layer(_LW, _RS, _AJ);
      }

      return false;
      break;
    case RS:
      if (record->event.pressed) {
        layer_on(_RS);
        rgblight_setrgb(RGB_GREEN);
        // update_tri_layer(_LW, _RS, _AJ);
      } else {
        layer_off(_RS);
        rgblight_setrgb(RGB_BLUE);
        // update_tri_layer(_LW, _RS, _AJ);
      }

      return false;
      break;
    // case AJ:
    //   if (record->event.pressed) {
    //     layer_on(_AJ);
    //   } else {
    //     layer_off(_AJ);
    //   }

    //   return false;
    //   break;
   case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }

      break;
   case ALT_SFT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
          register_code(KC_LSFT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }

      break;
  }

  return true;
}

void matrix_init_user(void)
{
    rgblight_mode(1);
	rgblight_setrgb(RGB_BLUE);
}

void matrix_scan_user(void) {
  if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);

      is_alt_tab_active = false;
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        switch(biton32(layer_state)){
            case _LW:
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                break;
            case _RS:
                clockwise ? tap_code(KC_RGHT) : tap_code(KC_LEFT);
                break;
            default:
                clockwise ? tap_code(KC_DOWN) : tap_code(KC_UP);
                break;
        }
    }
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//    switch (get_highest_layer(state)) {
//       case _RS:
//         rgblight_setrgb (RGB_GREEN);
//         break;
//       case _LW:
//         rgblight_setrgb (RGB_ORANGE);
//         break;
//    //  case _PL:
//    //      rgblight_setrgb (0x00,  0xFF, 0x00);
//    //      break;
//     //   case _AJ:
//     //     rgblight_setrgb (0x7A,  0x00, 0xFF);
//     //     break;
//       default: //  for any other layers, or the default layer
//         rgblight_setrgb (RGB_WHITE);
//         break;
//    }

//   return state;
// }
