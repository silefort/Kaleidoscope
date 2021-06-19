/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "kaleidoscope/lang/fr_azerty.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"



#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)
#define ML(n) MoveToLayer(n)

enum {
  MACRO_AZERTY,
  MACRO_VERSION_INFO,
  BEPO_EAIGU,
  BEPO_EGRAVE,
  BEPO_AGRAVE,
  BEPO_COMMA,
  BEPO_PERIOD,
  BEPO_QUOTE,
  BEPO_CIRCUMFLEX,
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

enum {
  AZERTY,
  BEPO,
  COL_12,
  NUMPAD,
  NAVIGATION,
};

/* *INDENT-OFF* */
KEYMAPS(
  [AZERTY] = KEYMAP_STACKED
  (
       Fr_A   ,Fr_Z   ,Fr_E       ,Fr_R         ,Fr_T
      ,Fr_Q   ,Fr_S   ,Fr_D       ,Fr_F         ,Fr_G
      ,Fr_W   ,Fr_X   ,Fr_C       ,Fr_V         ,Fr_B, Fr_LessThan
      ,Fr_Esc ,Fr_Tab ,Fr_LeftGui ,Fr_LeftShift ,Fr_Backspace ,Fr_LeftControl

                     ,Fr_Y     ,Fr_U      ,Fr_I     ,Fr_O      ,Fr_P
                     ,Fr_H     ,Fr_J      ,Fr_K     ,Fr_L      ,Fr_M
       ,Key_Backslash,Fr_N     ,Fr_Comma   ,Fr_Semicolon   ,Fr_Colon ,Fr_Equals
       ,Fr_LeftAlt  ,Fr_Space ,ML(BEPO)    ,Fr_RightParen ,Fr_UGrave  ,Fr_Enter
  ),

  [BEPO] = KEYMAP_STACKED
  (
       Fr_B   ,M(BEPO_EAIGU)   ,Fr_P       ,Fr_O         ,M(BEPO_EGRAVE)
      ,Fr_A   ,Fr_U   ,Fr_I       ,Fr_E         ,M(BEPO_COMMA)
      ,M(BEPO_AGRAVE)   ,Fr_Y   ,Fr_X       ,M(BEPO_PERIOD)         ,Fr_K ,Fr_Tab
      ,ML(AZERTY) ,Fr_Tab ,Fr_LeftControl ,Fr_LeftShift ,Fr_Backspace ,Fr_LeftGui

                     ,M(BEPO_CIRCUMFLEX)     ,Fr_V      ,Fr_D     ,Fr_L      ,Fr_J
                     ,Fr_C     ,Fr_T      ,Fr_S     ,Fr_R      ,Fr_N
       ,Fr_Enter         ,M(BEPO_QUOTE)     ,Fr_Q   ,Fr_G   ,Fr_H ,Fr_F
       ,Fr_Space   ,Fr_Space ,___    ,___ ,Fr_W  ,Fr_RightAlt
  ),
  [COL_12] = KEYMAP_STACKED
  (
       Fr_W         ,Fr_Asterisk   ,___    ,Fr_Underscore      ,Fr_Slash
      ,Fr_CCedille  ,Fr_LeftBracket   ,Fr_LeftCurly    ,Fr_LeftParen      ,Fr_LessThan
      ,___          ,Fr_UGrave    ,___   ,Fr_Euro    ,Fr_Tilde      ,___
      ,___          ,___    ,___   ,___    ,___      ,___

                    ,Fr_Backslash   ,Fr_Minus    ,Fr_Dollar    ,Fr_Plus ,Fr_Z
                    ,Fr_GreaterThan   ,Fr_RightParen    ,Fr_RightCurly    ,Fr_RightBracket ,Fr_M
               ,___ ,Fr_DoubleQuote   ,Fr_Pipe    ,Fr_Ampersand    ,Fr_Arobase , Fr_Pound
               ,___ ,___   ,___    ,___    ,___ ,___
  ),
  [NUMPAD] = KEYMAP_STACKED
  (
      Fr_Esc  ,___    ,___   ,___    ,___
      ,Fr_Tab  ,___    ,___   ,___    ,___
      ,___  ,___    ,___   ,___    ,___      ,___
      ,___  ,___    ,___   ,___    ,___      ,___

                    ,Fr_Minus ,Fr_7   ,Fr_8    ,Fr_9 ,___
                    ,Fr_Comma ,Fr_4   ,Fr_5    ,Fr_6 ,Fr_Percent
               ,___ ,Fr_Period ,Fr_1   ,Fr_2    ,Fr_3 ,Fr_0
               ,___ ,Fr_Equals ,Fr_Plus   ,Fr_Minus    ,Fr_Asterisk ,Fr_Slash
  ),
  [NAVIGATION] = KEYMAP_STACKED
  (
      Fr_Esc  ,___    ,___   ,___    ,___
      ,Fr_Tab  ,___    ,___   ,___    ,___
      ,___  ,___    ,___   ,___    ,___      ,___
      ,___  ,___    ,___   ,___    ,___      ,___

                    ,___ ,___   ,ML(BEPO)    ,___ ,___
                    ,Fr_LeftArrow ,Fr_DownArrow   ,Fr_UpArrow    ,Fr_RightArrow ,___
               ,___ ,___ ,___ ,___ ,___ ,___
               ,___ ,___ ,___ ,___ ,___ ,___
  ),

)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  /*case MACRO_AZERTY:*/
    /*// This macro is currently unused, but is kept around for compatibility*/
    /*// reasons. We used to use it in place of `MoveToLayer(AZERTY)`, but no*/
    /*// longer do. We keep it so that if someone still has the old layout with*/
    /*// the macro in EEPROM, it will keep working after a firmware update.*/
    /*Layer.move(AZERTY);*/
    /*break;*/
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  case BEPO_EAIGU:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), D(LeftAlt), D(LeftShift), T(1), U(LeftShift), U(LeftAlt), D(LeftShift),T(E), U(LeftShift));
    } else {
      return MACRODOWN(I(2), T(2));
    }
    break;
  case BEPO_EGRAVE:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), T(Backslash), D(LeftShift), T(E), U(LeftShift));

    } else {
      return MACRODOWN(I(2), T(7));
    }
    break;
  case BEPO_AGRAVE:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), T(Backslash), D(LeftShift), T(Q), U(LeftShift));

    } else {
      return MACRODOWN(I(2), T(0));
    }
    break;
  case BEPO_COMMA:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), T(Comma));

    } else {
      return MACRODOWN(I(2), U(LeftShift), T(M));
    }
    break;
  case BEPO_PERIOD:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), T(Period));
    } else {
      return MACRODOWN(I(2), D(LeftShift), T(Comma), U(LeftShift));
    }
    break;
  case BEPO_QUOTE:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), D(LeftShift), T(M), U(LeftShift));
    } else {
      return MACRODOWN(I(2), U(LeftShift), T(4));
    }
    break;
  case BEPO_CIRCUMFLEX:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(2), U(LeftShift), T(8));
    } else {
      return MACRODOWN(I(2), U(LeftShift), T(LeftBracket));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  EEPROMKeymap.setup(10);

  QUKEYS(
    /*kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 9), ShiftToLayer(SYMBOL_LAYER)),      // A/layer-shift (on `num_pad`)*/
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 0), Key_LeftShift),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 11), Key_LeftShift),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 3), ShiftToLayer(COL_12)),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 8), ShiftToLayer(COL_12)),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 4), ShiftToLayer(NUMPAD)),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 1), Key_LeftControl),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 10), Key_LeftControl),             // E/shift
    kaleidoscope::plugin::Qukey(AZERTY, KeyAddr(1, 1), Key_LeftControl),             // E/shift
    kaleidoscope::plugin::Qukey(AZERTY, KeyAddr(1, 10), Key_LeftControl),             // E/shift
  )

  Qukeys.setHoldTimeout(1000);
  Qukeys.setOverlapThreshold(80);
  Qukeys.activate();

  Kaleidoscope.setup();
  SpaceCadet.disable();
}

void loop() {
  Kaleidoscope.loop();
}
