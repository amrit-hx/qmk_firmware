#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _FUNC,
    _NUM
};

enum custom_keycodes {
    HX = SAFE_RANGE,
    SNIP
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        
    /* Keymap (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BS  |Del |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  {|  }| Ent |Mute|
     * |------------------------------------------------------.    |----|
     * |Num   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|    |VolU|
     * |----------------------------------------------------------------|
     * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |VolD|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |          SpaceFn      |Alt |Ctrl|  |Lef|Dow|Rig |
     * `------------------------------------------------'  `------------'
     */
    [_QWERTY] = LAYOUT_all(
        KC_ESC,           KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_DEL, 
        KC_TAB,           KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,       KC_VOLU, 
        TG(_NUM), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,             KC_VOLD, 
        KC_LSFT, KC_NUBS,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,         KC_UP,        KC_MUTE, 
        KC_LCTL, KC_LGUI, KC_LALT,  LT(_FUNC,KC_SPC),   LT(_FUNC,KC_SPC),  LT(_FUNC,KC_SPC), KC_LALT, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN,      KC_RGHT),

    /* Keymap Fn Layer
     * ,----------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |Ins |
     * |----------------------------------------------------------------|
     * |     |   |   |PUp|   |   |   |   |Prt|SLk|Pau|   |   |     |Play|
     * |------------------------------------------------------.    |----|
     * |      |   |Hom|PDn|End|   |hx |   |   |   |   |   |   |    |Next|
     * |----------------------------------------------------------------|
     * |       |   |   |snp|    |   |   |   |   |   |   |      |PUp|Prev|
     * |----------------------------------------------------------------|
     * |     |Reset|    |                    |AltGr|Menu|  |Hom|PDn|End |
     * `------------------------------------------------'  `------------'
     */
    [_FUNC] = LAYOUT_all(
         KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,_______,KC_INS, 
         _______,   _______, _______, KC_PGUP, _______, _______, _______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,_______,      KC_MPLY, 
         _______,     _______, KC_HOME, KC_PGDN,  KC_END, _______,      HX,_______,_______,_______,_______,_______,      _______,      KC_MNXT, 
         _______,_______,_______,   SNIP,_______,_______,_______,_______,_______,_______,_______,_______,_______,        KC_PGUP,KC_MPRV, 
         _______,RESET  ,_______,          _______,         _______,        _______,     KC_RALT,KC_APP, _______,KC_HOME,KC_PGDN,KC_END),
       
    /* Keymap Numpad Layer
     * ,----------------------------------------------------------------.
     * |   |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  /|   |       |    |
     * |----------------------------------------------------------------|
     * |     |   |   |Up |   |   |   |  4|  5|  6|  *|   |   |     |    |
     * |------------------------------------------------------.    |----|
     * |      |   |Lef|Dow|Rig|   |   |  1|  2|  3|  -|   |   |    |    |
     * |----------------------------------------------------------------|
     * |     |  |NLk|   |   |   |   |   |  0|   |   |  +|      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |   |   |    |
     * `------------------------------------------------'  `------------'
     */
    [_NUM] = LAYOUT_all(
        _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_SLASH, _______, _______, _______, _______, 
        _______, _______, _______, KC_UP  , _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, _______, _______, _______, _______, 
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS, _______, _______,             _______, 
        _______, _______, KC_NLCK, _______, _______, _______, _______, _______, KC_KP_0, _______, _______, KC_KP_PLUS, _______,   _______, _______, 
        _______, _______, _______,       _______,        _______,         _______,          _______, _______, XXXXXXX, _______, _______, _______),
    };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case HX:
        if (record->event.pressed) {
            // press
            SEND_STRING("hyperexponential");
        } else {
            // release
        }
        break;
        
    case SNIP:
        if (record->event.pressed) {
            // press
            SEND_STRING(SS_LWIN(SS_LSFT("s")));
        } else {
            // release
        }
        break;
    }
    return true;
}

void matrix_init_user(void) {
    
}

void matrix_scan_user(void) {
    
}

void led_set_user(uint8_t usb_led) {

}