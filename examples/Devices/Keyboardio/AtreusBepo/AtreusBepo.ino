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
  MACRO_VERSION_INFO
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
  FUN,
  UPPER,
  BEPO
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
       ,Fr_Backslash,Fr_N     ,Fr_Comma   ,Fr_Semicolon   ,Fr_Colon ,Fr_Equals
       ,Fr_LeftAlt  ,Fr_Space ,MO(FUN)    ,Fr_RightParen ,Fr_UGrave  ,Fr_Enter
  ),

  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,Key_UpArrow   ,Key_Dollar           ,Key_Percent
      ,Key_LeftParen   ,Key_LeftArrow    ,Key_DownArrow ,Key_RightArrow       ,Key_RightParen
      ,Key_LeftBracket ,Key_RightBracket ,Key_Hash      ,Key_LeftCurlyBracket ,Key_RightCurlyBracket ,Key_Caret
      ,TG(UPPER)       ,TG(BEPO)       ,Key_LeftGui   ,Key_LeftShift        ,Key_Delete         ,Key_LeftControl

                   ,Key_PageUp   ,Key_7 ,Key_8      ,Key_9 ,Key_Backspace
                   ,Key_PageDown ,Key_4 ,Key_5      ,Key_6 ,___
      ,Key_And     ,Key_Star     ,Key_1 ,Key_2      ,Key_3 ,Key_Plus
      ,Key_LeftAlt ,Key_Space    ,___   ,Key_Period ,Key_0 ,Key_Equals
   ),

  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,ML(AZERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,ML(AZERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),

  [BEPO] = KEYMAP_STACKED
  (
       Fr_B   ,Fr_EAigu   ,Fr_P       ,Fr_O         ,Fr_EGrave
      ,Fr_A   ,Fr_U   ,Fr_I       ,Fr_E         ,Fr_Comma
      ,Fr_AGrave   ,Fr_Y   ,Fr_X       ,Fr_Period         ,Fr_K ,Fr_CCedille
      ,ML(AZERTY) ,Fr_Tab ,Fr_LeftGui ,Fr_LeftShift ,Fr_Backspace ,Fr_LeftControl

                     ,Fr_Circumflex     ,Fr_V      ,Fr_D     ,Fr_L      ,Fr_J
                     ,Fr_C     ,Fr_T      ,Fr_S     ,Fr_R      ,Fr_N
       ,Fr_M,Fr_Quote     ,Fr_Q   ,Fr_G   ,Fr_H ,Fr_F
       ,Fr_LeftAlt  ,Fr_Space ,MO(FUN)    ,Fr_Z ,Fr_W  ,Fr_Enter
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
  case MACRO_AZERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(AZERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(AZERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  EEPROMKeymap.setup(10);
}

void loop() {
  Kaleidoscope.loop();
}
