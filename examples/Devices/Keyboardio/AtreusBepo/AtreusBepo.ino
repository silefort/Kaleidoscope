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
#include "Kaleidoscope-TapDance.h"
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
  KEY_APOSTROPHE,
  COPY_LINE,
  CMD_TAB,
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
  BEPOCUSTO,
  FUN,
  UPPER,
  BEPO,
  ALT_GR,
  COMBO_LAYER_1,
  COMBO_LAYER_2,
  SYMBOL_LAYER
};

/* *INDENT-OFF* */
KEYMAPS(
  [AZERTY] = KEYMAP_STACKED
  (
       Fr_A      ,Fr_Z     ,Fr_E       ,Fr_R          ,Fr_T
      ,Fr_Q      ,Fr_S     ,Fr_D       ,Fr_F          ,Fr_G
      ,Fr_LeftGui      ,Fr_X     ,Fr_C       ,Fr_V          ,Fr_B          ,Key_Backtick
      ,MoveToLayer(BEPOCUSTO) ,Fr_Tab   ,Fr_LeftGui ,Fr_LeftShift  ,Fr_Backspace  ,M(CMD_TAB)

                      ,M(COPY_LINE)        ,Fr_U      ,MoveToLayer(BEPOCUSTO)      ,Fr_O       ,Fr_P
                      ,Key_LeftArrow        ,Key_DownArrow      ,Key_UpArrow      ,Key_RightArrow       ,Fr_M
       ,Key_Backslash ,Fr_N        ,Fr_Comma  ,Key_Comma ,Key_Period ,Key_Slash
       ,Fr_LeftAlt   ,Fr_Spacebar  ,MO(FUN)   ,Key_Minus ,Key_Quote  ,Fr_Enter
  ),

  [BEPOCUSTO] = KEYMAP_STACKED
  (
       Fr_B           ,M(KEY_EACUTE)  ,Fr_P        ,Fr_O          ,M(KEY_EGRAVE)
      ,Fr_A           ,Fr_U           ,Fr_I        ,Fr_E          ,M(KEY_COMMA)
      ,M(KEY_AGRAVE)  ,Fr_Y           ,Fr_X        ,M(KEY_DOT)    ,Fr_K          , Fr_W
      ,MoveToLayer(AZERTY)      ,Fr_Tab         ,Fr_LeftControl  ,Fr_LeftShift  ,Fr_Backspace  ,Fr_LeftGui

                      ,M(KEY_CIRCUMFLEX)  ,Fr_V           ,Fr_D               ,Fr_L          ,Fr_J
                      ,Fr_C               ,Fr_T           ,Fr_S               ,Fr_R          ,Fr_N
       ,M(KEY_CIRCUMFLEX),M(KEY_APOSTROPHE)  ,Fr_Q           ,Fr_G               ,Fr_H          ,Fr_F
       ,Fr_Enter          ,Fr_Spacebar        ,MO(FUN)   ,MoveToLayer(AZERTY)    ,Fr_W         ,Fr_Z
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
      ,MoveToLayer(AZERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,MoveToLayer(BEPO)      ,___           ,MoveToLayer(AZERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),

   [BEPO] = KEYMAP_STACKED
  (
       Fr_B           ,M(KEY_EACUTE)  ,Fr_P        ,Fr_O          ,M(KEY_EGRAVE)
      ,Fr_A           ,Fr_U           ,Fr_I        ,Fr_E          ,M(KEY_COMMA)
      ,M(KEY_AGRAVE)  ,Fr_Y  
         ,Fr_X        ,M(KEY_DOT)    ,Fr_K          ,M(KEY_CCEDILLA)
      ,Fr_Escape      ,Fr_Tab         ,Fr_LeftGui  ,Fr_LeftShift  ,Fr_Backspace  ,Fr_W

                      ,M(KEY_CIRCUMFLEX)  ,Fr_V           ,Fr_D               ,Fr_L          ,Fr_J
                      ,Fr_C               ,Fr_T           ,Fr_S               ,Fr_R          ,Fr_N
       ,Fr_Z          ,M(KEY_APOSTROPHE)  ,Fr_Q           ,Fr_G               ,Fr_H          ,Fr_F
       ,Fr_M          ,Fr_Spacebar        ,Fr_Minus   ,MoveToLayer(AZERTY)    ,Fr_At         ,Fr_Enter
   ),

   [ALT_GR] = KEYMAP_STACKED
  (
       Fr_Pipe          ,___            ,Fr_Ampersand     ,M(KEY_OELIG)      ,___
      ,M(KEY_AELIG)     ,M(KEY_UGRAVE)  ,M(KEY_UMLAUT)    ,Fr_Euro           ,Fr_Quote
      ,Fr_Backslash     ,Fr_LeftCurly   ,Fr_RightCurly    ,M(KEY_TRIPLEDOT)  ,Fr_Tilde       ,___
      ,___              ,___            ,___              ,___               ,Fr_Underscore  ,___

               ,___    ,___                ,___     ,___      ,___
               ,M(KEY_CCEDILLA)    ,Fr_LeftShift       ,___     ,___      ,___
       ,___    ,___    ,___                ,___     ,___      ,___
       ,___    ,___    ,___                ,___     ,___      ,___
   ),

  /*[LEFT_LAYER] = KEYMAP_STACKED*/
  /*(*/
       /*Fr_1           ,Fr_2                   ,Fr_3               ,Fr_4             ,Fr_5*/
      /*,Fr_Asterisk    ,Fr_Hash                ,Fr_LeftParen       ,Fr_RightParen    ,___*/
      /*,Fr_Slash       ,Fr_Dollar              ,Fr_LeftBracket     ,Fr_RightBracket  ,___            ,___*/
      /*,___            ,___                    ,___                ,Key_LeftShift    ,Fr_Backspace   ,Fr_Delete*/

               /*,___    ,Fr_Home        ,Fr_UpArrow     ,Fr_End          ,___*/
               /*,___    ,Fr_LeftArrow   ,Fr_DownArrow   ,Fr_RightArrow   ,Fr_LeftShift*/
       /*,___    ,___    ,___            ,___            ,___             ,___*/
       /*,___    ,___    ,___            ,___            ,___             ,___*/
   /*),*/

   /*[RIGHT_LAYER] = KEYMAP_STACKED*/
  /*(*/
       /*___   ,___   ,___   ,___            ,Fr_F5*/
      /*,___   ,___   ,___   ,Key_LeftShift  ,___*/
      /*,___   ,___   ,___   ,___            ,___    ,___*/
      /*,___   ,___   ,___   ,___            ,___    ,___*/

             /*,Fr_6         ,Fr_7                ,Fr_8                 ,Fr_9                 ,Fr_0*/
             /*,___          ,Fr_LessThan         ,Fr_GreaterThan       ,Fr_DoubleQuote       ,Fr_Equals*/
      /*,___   ,___          ,M(KEY_OPENQUOTE)    ,M(KEY_CLOSEQUOTE)    ,Fr_Pound             ,Fr_Percent*/
      /*,___   ,___          ,___                 ,___                  ,___                  ,___*/
   /*),*/

  [COMBO_LAYER_1] = KEYMAP_STACKED
  (
       ___   ,___   ,___   ,Fr_Escape   ,___
      ,___   ,___   ,___   ,Fr_Tab   ,___
      ,___   ,___   ,___   ,M(KEY_CIRCUMFLEX)  ,___    ,___
      ,___   ,___   ,___   ,___   ,___    ,___

             ,___   ,Fr_7   ,Fr_8   ,Fr_9    ,Fr_Z
             ,Fr_Comma   ,Fr_4   ,Fr_5   ,Fr_6    ,Fr_M
      ,___   ,Fr_Period   ,Fr_1   ,Fr_2   ,Fr_3    ,Fr_0
      ,___ ,Fr_Equals   ,Fr_Plus   ,Fr_Minus   ,Fr_Asterisk   ,Fr_Slash
  ),

  [COMBO_LAYER_2] = KEYMAP_STACKED
  (
       ___   ,___   ,___   ,Fr_Escape   ,___
      ,___   ,___   ,___   ,Fr_Tab   ,___
      ,___   ,___   ,___   ,M(KEY_CIRCUMFLEX)  ,___    ,___
      ,___   ,___   ,___   ,___   ,___    ,___

             ,___   ,Fr_7   ,Fr_8   ,Fr_9 ,Fr_W
             ,Fr_Comma   ,Fr_4   ,Fr_5   ,Fr_6 ,M(KEY_CCEDILLA)
      ,___   ,Fr_Period   ,Fr_1   ,Fr_2   ,Fr_3    ,Fr_0
      ,___ ,Fr_Equals   ,Fr_Plus   ,Fr_Minus   ,Fr_Asterisk   ,Fr_Slash
  ),

  [SYMBOL_LAYER] = KEYMAP_STACKED
  (
       Fr_Asterisk   ,Fr_Quote    ,Fr_Underscore ,Fr_Slash   ,___
      ,Fr_LessThan   ,Fr_LeftCurly   ,Fr_LeftBracket   ,Fr_LeftParen   ,___
      ,___   ,___   ,___   ,___   ,___    ,___
      ,___   ,___   ,___   ,___   ,___    ,___

             ,___   ,Fr_Backslash   ,Fr_Minus    ,Fr_DoubleQuote    ,Fr_Plus
             ,___   ,Fr_RightParen   ,Fr_RightBracket   ,Fr_RightCurly    ,___
      ,___   ,___   ,___   ,___   ,___    ,___
      ,___   ,___   ,___   ,___   ,___    ,___
   ),
)
/* *INDENT-ON* */

void change_os(uint8_t combo_index) {
  if (HostOS.os() == kaleidoscope::hostos::LINUX) {
    HostOS.os(kaleidoscope::hostos::WINDOWS);
  } else {
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
  TapDance,
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
    Layer.move(AZERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  case KEY_EGRAVE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), D(RightAlt), T(7), U(RightAlt));
      } else {
        return MACRODOWN(I(15), T(7));
      }
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad2), T(Keypad0), T(Keypad0), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), T(7));
      }
    }
    break;
  case KEY_EACUTE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), D(RightAlt), T(2), U(RightAlt));
      } else {
        return MACRODOWN(I(15), T(2));
      }
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad4), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), T(2));
      }
    }
    break;
  case KEY_COMMA:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(15), U(LeftShift), T(Comma), D(LeftShift));
    } else {
      return MACRODOWN(I(15), T(M));
    }
    break;
  case KEY_AGRAVE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), D(RightAlt), T(0), U(RightAlt));
      } else {
        return MACRODOWN(I(15), T(0));
      }
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad9), T(Keypad2), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), T(0));
      }
    }
    break;
  case KEY_DOT:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(15), U(LeftShift), T(Period), U(LeftShift));
    } else {
      return MACRODOWN(I(15), D(LeftShift), T(Comma), U(LeftShift));
    }
    break;
  case KEY_CCEDILLA:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), D(RightAlt), T(9), U(RightAlt));
      } else {
        return MACRODOWN(I(15), T(9));
      }
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad9), T(Keypad9), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), T(9));
      }
    }
    break;
  case KEY_CIRCUMFLEX:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(15), U(LeftShift), T(Slash), D(LeftShift));
    } else {
      return MACRODOWN(T(LeftBracket));
    }
    break;
  case KEY_OELIG:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      return MACRODOWN(I(15), D(RightAlt), T(O), U(RightAlt));
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad4), T(Keypad0), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad5), T(Keypad6), U(LeftAlt));
      }
    }
    break;
  case KEY_AELIG:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      return MACRODOWN(I(15), D(RightAlt), T(Q), U(RightAlt));
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad6), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), D(LeftAlt), T(Keypad1), T(Keypad4), T(Keypad5), U(LeftAlt));
      }
    }
    break;
  case KEY_UGRAVE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), D(RightAlt), T(Quote), U(RightAlt));
      } else {
        return MACRODOWN(I(15), T(Quote));
      }
    } else {
      if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
        return MACRODOWN(I(15), U(LeftShift), D(LeftAlt), T(Keypad0), T(Keypad2), T(Keypad1), T(Keypad7), U(LeftAlt), D(LeftShift));
      } else {
        return MACRODOWN(I(15), T(Quote));
      }
    }
    break;
  case KEY_UMLAUT:
    return MACRODOWN(I(15), D(LeftShift), T(LeftCurlyBracket), U(LeftShift));
    break;
  case KEY_TRIPLEDOT:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      return MACRODOWN(I(15), D(LeftShift), D(RightAlt), T(M), U(RightAlt), U(LeftShift));
    } else {
      return MACRODOWN(I(15), D(LeftAlt), T(Keypad0), T(Keypad1), T(Keypad3), T(Keypad3), U(LeftAlt));
    }
    break;
  case KEY_APOSTROPHE:
    if (Kaleidoscope.hid().keyboard().wasModifierKeyActive(Key_LeftShift)) {
      return MACRODOWN(I(15), T(M));
    } else {
      return MACRODOWN(I(15), T(4));
    }
    break;
  case KEY_OPENQUOTE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      return MACRODOWN(I(15), D(RightAlt), T(Z), U(RightAlt));
    } else {
      return MACRODOWN(I(15), D(LeftAlt), T(Keypad1), T(Keypad7), T(Keypad4), U(LeftAlt));
    }
    break;
  case KEY_CLOSEQUOTE:
    if (HostOS.os() == kaleidoscope::hostos::LINUX) {
      return MACRODOWN(I(15), D(RightAlt), T(X), U(RightAlt));
    } else {
      return MACRODOWN(I(15), D(LeftAlt),  T(Keypad1), T(Keypad7), T(Keypad5), U(LeftAlt));
    }
    break;
  case CMD_TAB:
    /*return MACRODOWN(I(15), D(RightAlt), T(X), U(RightAlt));*/
    return MACRODOWN(I(15), D(LeftGui), T(Tab), U(LeftGui));
    /*return MACRODOWN(I(15), D(LeftCtrl), T(A), U(LeftCtrl), D(LeftShift), D(LeftCtrl), T(E), U(LeftShift), U(LeftCtrl));*/
    /*return MACRODOWN(I(15), D(LeftCtrl), T(Q));*/
    break;
  case COPY_LINE:
    return MACRODOWN(I(15), D(LeftControl), T(A), U(LeftControl), D(LeftShift), D(LeftControl), T(E), U(LeftShift), U(LeftControl));
    /*return MACRODOWN(I(15), D(LeftCtrl), T(Q));*/
    break;
  default:
    break;
  }
  return MACRO_NONE;
}

void tapDanceAction(uint8_t tap_dance_index, KeyAddr key_addr, uint8_t tap_count, kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  switch (tap_dance_index) {
  case 0:
    return tapDanceActionKeys(tap_count, tap_dance_action, Fr_A, Fr_Y);
  /*case TD_A:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, LSHIFT(Key_de_A), LSHIFT(Key_de_AUml));*/
  /*case TD_o:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, Key_de_O, Key_de_OUml);*/
  /*case TD_O:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, LSHIFT(Key_de_O), LSHIFT(Key_de_OUml));*/
  /*case TD_u:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, Key_de_U, Key_de_UUml);*/
  /*case TD_U:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, LSHIFT(Key_de_U), LSHIFT(Key_de_UUml));*/
  /*case TD_E:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, Key_de_E, Key_de_Euro);*/
  /*case TD_S:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, Key_de_S, Key_de_SS);*/
  /*case TD_Q:*/
    /*return tapDanceActionKeys(tap_count, tap_dance_action, Key_de_Q, Key_de_At);*/
  } // end switch
}

void setup() {
  EEPROMKeymap.setup(10);

  QUKEYS(
    /*kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 3), ShiftToLayer(COL_11)),   // Switch to Column 10*/
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 3), ShiftToLayer(COMBO_LAYER_1)),      // a/layer_1-shift (on `num_pad`)
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 4), ShiftToLayer(COMBO_LAYER_2)),   // switch to column 11
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 1), ShiftToLayer(SYMBOL_LAYER)),      // A/layer-shift (on `num_pad`)
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 9), ShiftToLayer(SYMBOL_LAYER)),      // A/layer-shift (on `num_pad`)
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 0), Key_LeftShift),             // E/shift
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 11), Key_LeftShift),             // T/shift
    kaleidoscope::plugin::Qukey(AZERTY, KeyAddr(3, 5), Key_LeftGui),             // T/shift
    /*kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(1, 11), Key_LeftControl),          // N/ctrl*/
    kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(3, 6), ShiftToLayer(ALT_GR)),      // M/layer-shift (on `alt_gr`)
    /*kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(3, 7), ShiftToLayer(LEFT_LAYER)),  // Space/layer-shift (on `left_layer`)*/
    /*kaleidoscope::plugin::Qukey(BEPOCUSTO, KeyAddr(3, 4), ShiftToLayer(RIGHT_LAYER))  // Backspace/layer-shift (on `right_layer`)*/
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
