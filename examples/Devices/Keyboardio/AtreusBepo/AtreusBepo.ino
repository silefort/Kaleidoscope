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
#define BUILD_INFORMATION "Bepo V1"
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
#include "Kaleidoscope-HostOS.h"
#include "Kaleidoscope-Unicode.h"
#include "Kaleidoscope-MagicCombo.h"




#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  CHANGE_OS
};

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO,
  KEY_EACUTE,
  KEY_EGRAVE,
  KEY_COMMA,
  KEY_AGRAVE,
  KEY_DOT,
  KEY_CCEDILLA,
  KEY_CIRCUMFLEX,
  KEY_OELIG,
  KEY_AELIG,
  KEY_UGRAVE,
  KEY_UMLAUT,
  KEY_TRIPLEDOT,
  KEY_OPENQUOTE,
  KEY_CLOSEQUOTE,
  KEY_APOSTROPHE
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
  QWERTY,
  FUN,
  UPPER,
  BEPO,
  ALT_GR,
  LEFT_LAYER,
  RIGHT_LAYER
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W   ,Key_E       ,Key_R         ,Key_T
      ,Key_A   ,Key_S   ,Key_D       ,Key_F         ,Key_G
      ,Key_Z   ,Key_X   ,Key_C       ,Key_V         ,Key_B, Key_Backtick
      ,Key_Esc ,Key_Tab ,Key_LeftGui ,Key_LeftShift ,Key_Backspace ,Key_LeftControl

                     ,Key_Y     ,Key_U      ,Key_I     ,Key_O      ,Key_P
                     ,Key_H     ,Key_J      ,Key_K     ,Key_L      ,Key_Semicolon
       ,Key_Backslash,Key_N     ,Key_M      ,Key_Comma ,Key_Period ,Key_Slash
       ,Key_LeftAlt  ,Key_Space ,MO(FUN)    ,Key_Minus ,Key_Quote  ,Key_Enter
  ),

  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,Key_UpArrow   ,Key_Dollar           ,Key_Percent
      ,Key_LeftParen   ,Key_LeftArrow    ,Key_DownArrow ,Key_RightArrow       ,Key_RightParen
      ,Key_LeftBracket ,Key_RightBracket ,Key_Hash      ,Key_LeftCurlyBracket ,Key_RightCurlyBracket ,Key_Caret
      ,TG(UPPER)       ,Key_Insert       ,Key_LeftGui   ,Key_LeftShift        ,Key_Delete         ,Key_LeftControl

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
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,MoveToLayer(BEPO)      ,___           ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),

   [BEPO] = KEYMAP_STACKED
  (
       Key_B          ,M(KEY_EACUTE)  ,Key_P       ,Key_O         ,M(KEY_EGRAVE)
      ,Fr_A           ,Key_U          ,Key_I       ,Key_E         ,M(KEY_COMMA)
      ,M(KEY_AGRAVE)  ,Key_Y          ,Key_X       ,M(KEY_DOT)    ,Key_K         ,M(KEY_CCEDILLA)
      ,Key_Esc        ,Key_Tab        ,Key_LeftGui ,Key_LeftShift ,Key_Backspace ,Fr_W

                      ,M(KEY_CIRCUMFLEX)  ,Key_V          ,Key_D            ,Key_L         ,Key_J
                      ,Key_C              ,Key_T          ,Key_S            ,Key_R         ,Key_N
       ,Key_W         ,M(KEY_APOSTROPHE)  ,Key_A          ,Key_G            ,Key_H         ,Key_F
       ,Fr_M          ,Key_Space          ,Key_6   ,MoveToLayer(QWERTY)     ,Fr_At         ,Key_Enter
   ),

   [ALT_GR] = KEYMAP_STACKED
  (
       Fr_Pipe          ,___            ,Fr_Ampersand     ,M(KEY_OELIG)      ,___
      ,M(KEY_AELIG)     ,M(KEY_UGRAVE)  ,M(KEY_UMLAUT)    ,Fr_Euro           ,Fr_Quote
      ,Fr_Backslash     ,Fr_LeftCurly   ,Fr_RightCurly    ,M(KEY_TRIPLEDOT)  ,Fr_Tilde       ,___
      ,___              ,___            ,___              ,___                ,Fr_Underscore  ,___

               ,___    ,___                ,___     ,___      ,___
               ,___    ,Key_LeftShift      ,___     ,___      ,___
       ,___    ,___    ,___                ,___     ,___      ,___
       ,___    ,___    ,___                ,___     ,___      ,___
   ),

  [LEFT_LAYER] = KEYMAP_STACKED
  (
       Key_Keypad1         ,Key_Keypad2            ,Key_Keypad3        ,Key_Keypad4      ,Key_Keypad5
      ,Fr_Asterisk         ,Fr_Hash                ,Fr_LeftParen       ,Fr_RightParen    ,___
      ,LSHIFT(Key_Period)  ,Fr_Dollar              ,Fr_LeftBracket     ,Fr_RightBracket  ,___            ,___
      ,___                 ,___                    ,___                ,___              ,Key_Backspace  ,Key_Delete

               ,___    ,___            ,Key_UpArrow     ,___             ,___
               ,___    ,Key_LeftArrow  ,Key_DownArrow   ,Key_RightArrow  ,Key_LeftShift
       ,___    ,___    ,___            ,___             ,___             ,___
       ,___    ,___    ,___            ,___             ,___             ,___
   ),

   [RIGHT_LAYER] = KEYMAP_STACKED
  (
       ___   ,___   ,___   ,___            ,___
      ,___   ,___   ,___   ,Key_LeftShift  ,___
      ,___   ,___   ,___   ,___            ,___    ,___
      ,___   ,___   ,___   ,___            ,___    ,___

             ,Key_Keypad6  ,Key_Keypad7         ,Key_Keypad8          ,Key_Keypad9                    ,Key_Keypad0
             ,___          ,Fr_LessThan         ,Fr_GreaterThan       ,Fr_DoubleQuote                 ,Fr_Equals
      ,___   ,___          ,M(KEY_OPENQUOTE)    ,M(KEY_CLOSEQUOTE)    ,LSHIFT(Key_RightBracket)       ,Fr_Percent
      ,___   ,___          ,___                 ,___                  ,___                            ,___
   )  
)
/* *INDENT-ON* */

void change_os(uint8_t combo_index) {
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      HostOS.os(kaleidoscope::hostos::WINDOWS);
    }
    else {
      HostOS.os(kaleidoscope::hostos::LINUX);
    }
}

USE_MAGIC_COMBOS([CHANGE_OS] = {.action = change_os, .keys = {R3C0, R3C3}});

KALEIDOSCOPE_INIT_PLUGINS(
  HostOS,
  EEPROMSettings,
  EEPROMKeymap,
  Qukeys,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  OneShot,
  SpaceCadet,
  MouseKeys,
  MagicCombo,
  Macros
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  case KEY_EGRAVE:
     if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), D(RightAlt), T(7), U(RightAlt));
      else
        return MACRODOWN(I(15), T(7));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad2), T(Keypad0), T(Keypad0), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), T(7));
    }
    break;
  case KEY_EACUTE:
     if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), D(RightAlt), T(2), U(RightAlt));
      else
        return MACRODOWN(I(15), T(2));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad4), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), T(2));
    }
    break;
  case KEY_COMMA:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
      return MACRODOWN(I(15), U(LeftShift), T(Comma), D(LeftShift));
    else
      return MACRODOWN(I(15), T(M));
    break;
  case KEY_AGRAVE:
     if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), D(RightAlt), T(0), U(RightAlt));
      else
        return MACRODOWN(I(15), T(0));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad9), T(Keypad2), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), T(0));
    }
    break;
  case KEY_DOT:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
      return MACRODOWN(I(15), U(LeftShift), T(Period), U(LeftShift));
    else
      return MACRODOWN(I(15), D(LeftShift), T(Comma), U(LeftShift));
    break;
  case KEY_CCEDILLA:
     if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), D(RightAlt), T(9), U(RightAlt));
      else
        return MACRODOWN(I(15), T(9));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad9), T(Keypad9), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), T(9));
    }
    break;
  case KEY_CIRCUMFLEX:
    if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
     return MACRODOWN(I(15), U(LeftShift), T(Slash), D(LeftShift));
    else
     return MACRODOWN(T(LeftBracket));
    break;
  case KEY_OELIG:
    if (HostOS.os() == kaleidoscope::hostos::LINUX)  
      return MACRODOWN(I(15), D(RightAlt), T(O), U(RightAlt));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad4), T(Keypad0), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad5), T(Keypad6), U(LeftAlt));
    }
    break;
  case KEY_AELIG:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) 
      return MACRODOWN(I(15), D(RightAlt), T(Q), U(RightAlt));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad6), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad5), U(LeftAlt));
    }
    break;
  case KEY_UGRAVE:
      if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), D(RightAlt), T(Quote), U(RightAlt));
      else
        return MACRODOWN(I(15), T(Quote));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad2), T(Keypad1), T(Keypad7), U(LeftAlt), D(LeftShift));
      else
        return MACRODOWN(I(15), T(Quote));
    }
    break;
  case KEY_UMLAUT:
    return MACRODOWN(I(15), D(LeftShift), T(LeftCurlyBracket), U(LeftShift));
    break;
  case KEY_TRIPLEDOT:
      if (HostOS.os() == kaleidoscope::hostos::LINUX)
        return MACRODOWN(I(15), D(LeftShift), D(RightAlt), T(M), U(RightAlt), U(LeftShift));
    else 
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad3), T(Keypad3), U(LeftAlt));
    break;
  case KEY_APOSTROPHE:
     if (HostOS.os() == kaleidoscope::hostos::LINUX)
       if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), T(M));
      else
        return MACRODOWN(I(15), D(RightAlt), T(G), U(RightAlt));
    else {
      if (kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift))
        return MACRODOWN(I(15), T(M));
      else
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad4), T(Keypad6), U(LeftAlt));
    }
    break;
  case KEY_OPENQUOTE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX)
        return MACRODOWN(I(15), D(RightAlt), T(Z), U(RightAlt));
    else 
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad1), T(Keypad7), T(Keypad4), U(LeftAlt));
    break;
  case KEY_CLOSEQUOTE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX)
        return MACRODOWN(I(15), D(RightAlt), T(X), U(RightAlt));
    else 
        return MACRODOWN(I(15), D(LeftAlt),  T(Keypad1), T(Keypad7), T(Keypad5), U(LeftAlt));
    break;
  default:
    break;
  }
  return MACRO_NONE;
}

void setup() {
  EEPROMKeymap.setup(10);

  QUKEYS(
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 3), Key_LeftShift),             // E/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 8), Key_LeftShift),             // T/shift
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(1, 11), Key_LeftControl),          // N/ctrl
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(3, 6), ShiftToLayer(ALT_GR)),      // M/layer-shift (on `alt_gr`)
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(3, 7), ShiftToLayer(LEFT_LAYER)),  // Space/layer-shift (on `left_layer`)
    kaleidoscope::plugin::Qukey(BEPO, KeyAddr(3, 4), ShiftToLayer(RIGHT_LAYER))  // Backspace/layer-shift (on `right_layer`)
  )

  Qukeys.setHoldTimeout(1000);
  Qukeys.setOverlapThreshold(80);
  Qukeys.activate();

  HostOS.os(kaleidoscope::hostos::WINDOWS);
  
  Kaleidoscope.setup();
  SpaceCadet.disable();
}

void loop() {
  Kaleidoscope.loop();
}
