#pragma once

// Alt gr
#define ALTGR RALT

/* These are deviating from the us layout */
#define Fr_Circumflex Key_LeftBracket /* ^ and ¨ */
#define Fr_Trema LSHIFT(Fr_Circumflex) /* ¨ */

#define Fr_ExlamationMark Key_Slash
#define Fr_DoubleQuote Key_3
#define Fr_Paragraph LSHIFT(Fr_ExlamationMark)
#define Fr_Dollar Key_RightBracket
#define Fr_Pound LSHIFT(Key_RightBracket)
#define Fr_Percent LSHIFT(Key_Quote)
#define Fr_Ampersand Key_1
#define Fr_Slash LSHIFT(Key_Period)
#define Fr_LeftParen Key_5
#define Fr_RightParen Key_Minus
#define Fr_Equals Key_Equals
#define Fr_QuestionMark LSHIFT(Key_M)
#define Fr_LeftCurly ALTGR(Key_4)
#define Fr_RightCurly ALTGR(Key_Equals)
#define Fr_LeftBracket ALTGR(Key_5)
#define Fr_RightBracket ALTGR(Key_Minus)
#define Fr_Backslash ALTGR(Key_8)

#define Fr_Backtick ALTGR(Key_7)

#define Fr_At ALTGR(Key_0)
#define Fr_Euro ALTGR(Fr_E)

#define Fr_Plus LSHIFT(Key_Equals) /* Plus + Asterisk * and Tilde ~ */
#define Fr_Asterisk Key_Backslash /* * */
#define Fr_Tilde ALTGR(Key_2) /* ~ */

#define Fr_Hash ALTGR(Key_3) /* # */
#define Fr_Quote Key_4

#define Fr_LessThan Key_NonUsBackslashAndPipe /* < and > and | */
#define Fr_GreaterThan LSHIFT(Fr_LessThan)
#define Fr_Pipe ALTGR(Key_6)

#define Fr_Minus Key_6 /* - and _ */
#define Fr_Underscore Key_8

/* the default keys are just aliased to have them look the same */
#define Fr_NoEvent Key_NoEvent
#define Fr_ErrorRollover Key_ErrorRollover
#define Fr_PostFail Key_PostFail
#define Fr_ErrorUndefined Key_ErrorUndefined
#define Fr_A Key_Q
#define Fr_B Key_B
#define Fr_C Key_C
#define Fr_D Key_D
#define Fr_E Key_E
#define Fr_F Key_F
#define Fr_G Key_G
#define Fr_H Key_H
#define Fr_I Key_I
#define Fr_J Key_J
#define Fr_K Key_K
#define Fr_L Key_L
#define Fr_M Key_Semicolon
#define Fr_N Key_N
#define Fr_O Key_O
#define Fr_P Key_P
#define Fr_Q Key_A
#define Fr_R Key_R
#define Fr_S Key_S
#define Fr_T Key_T
#define Fr_U Key_U
#define Fr_V Key_V
#define Fr_W Key_Z
#define Fr_X Key_X
#define Fr_Y Key_Y
#define Fr_Z Key_W

#define Fr_1 LSHIFT(Key_1)
#define Fr_2 LSHIFT(Key_2)
#define Fr_3 LSHIFT(Key_3)
#define Fr_4 LSHIFT(Key_4)
#define Fr_5 LSHIFT(Key_5)
#define Fr_6 LSHIFT(Key_6)
#define Fr_7 LSHIFT(Key_7)
#define Fr_8 LSHIFT(Key_8)
#define Fr_9 LSHIFT(Key_9)
#define Fr_0 LSHIFT(Key_0)
#define Fr_Enter Key_Enter
#define Fr_Escape Key_Escape
#define Fr_Backspace Key_Backspace
#define Fr_Tab Key_Tab
#define Fr_Spacebar Key_Spacebar
#define Fr_Comma Key_M
#define Fr_Semicolon Key_Comma
#define Fr_Period LSHIFT(Fr_Semicolon)
#define Fr_Colon Key_Period

#define Fr_CapsLock Key_CapsLock
#define Fr_F1 Key_F1
#define Fr_F2 Key_F2
#define Fr_F3 Key_F3
#define Fr_F4 Key_F4
#define Fr_F5 Key_F5
#define Fr_F6 Key_F6
#define Fr_F7 Key_F7
#define Fr_F8 Key_F8
#define Fr_F9 Key_F9
#define Fr_F10 Key_F10
#define Fr_F11 Key_F11
#define Fr_F12 Key_F12

#define Fr_PrintScreen Key_PrintScreen
#define Fr_ScrollLock Key_ScrollLock
#define Fr_Pause Key_Pause
#define Fr_Insert Key_Insert
#define Fr_Home Key_Home
#define Fr_PageUp Key_PageUp
#define Fr_Delete Key_Delete
#define Fr_End Key_End
#define Fr_PageDown Key_PageDown
#define Fr_RightArrow Key_RightArrow
#define Fr_LeftArrow Key_LeftArrow
#define Fr_DownArrow Key_DownArrow
#define Fr_UpArrow Key_UpArrow

#define Fr_KeypadNumLock Key_KeypadNumLock
#define Fr_KeypadDivide Key_KeypadDivide
#define Fr_KeypadMultiply Key_KeypadMultiply
#define Fr_KeypadSubtract Key_KeypadSubtract
#define Fr_KeypadAdd Key_KeypadAdd
#define Fr_KeypadEnter Key_KeypadEnter
#define Fr_Keypad1 Key_Keypad1
#define Fr_Keypad2 Key_Keypad2
#define Fr_Keypad3 Key_Keypad3
#define Fr_Keypad4 Key_Keypad4
#define Fr_Keypad5 Key_Keypad5
#define Fr_Keypad6 Key_Keypad6
#define Fr_Keypad7 Key_Keypad7
#define Fr_Keypad8 Key_Keypad8
#define Fr_Keypad9 Key_Keypad9
#define Fr_Keypad0 Key_Keypad0

#define Fr_PcApplication Key_PcApplication
#define Fr_Power Key_Power

#define Fr_KeypadEquals Key_KeypadEquals

#define Fr_F13 Key_F13
#define Fr_F14 Key_F14
#define Fr_F15 Key_F15
#define Fr_F16 Key_F16
#define Fr_F17 Key_F17
#define Fr_F18 Key_F18
#define Fr_F19 Key_F19
#define Fr_F20 Key_F20
#define Fr_F21 Key_F21
#define Fr_F22 Key_F22
#define Fr_F23 Key_F23
#define Fr_F24 Key_F24

#define Fr_Execute Key_Execute
#define Fr_Help Key_Help
#define Fr_Menu Key_Menu
#define Fr_Select Key_Select
#define Fr_Stop Key_Stop
#define Fr_Again Key_Again
#define Fr_Undo Key_Undo
#define Fr_Cut Key_Cut
#define Fr_Copy Key_Copy
#define Fr_Paste Key_Paste
#define Fr_Find Key_Find

#define Fr_Mute Key_Mute
#define Fr_VolumeUp Key_VolumeUp
#define Fr_VolumeDown Key_VolumeDown

#define Fr_LockingCapsLock Key_LockingCapsLock
#define Fr_LockingNumLock Key_LockingNumLock
#define Fr_LockingScrollLock Key_LockingScrollLock

#define Fr_KeypadDot Key_KeypadComma
#define Fr_KeypadEqualSign Key_KeypadEqualSign

#define Fr_International1 Key_International1
#define Fr_International2 Key_International2
#define Fr_International3 Key_International3
#define Fr_International4 Key_International4
#define Fr_International5 Key_International5
#define Fr_International6 Key_International6
#define Fr_International7 Key_International7
#define Fr_International8 Key_International8
#define Fr_International9 Key_International9
#define Fr_Lang1 Key_Lang1
#define Fr_Lang2 Key_Lang2
#define Fr_Lang3 Key_Lang3
#define Fr_Lang4 Key_Lang4
#define Fr_Lang5 Key_Lang5
#define Fr_Lang6 Key_Lang6
#define Fr_Lang7 Key_Lang7
#define Fr_Lang8 Key_Lang8
#define Fr_Lang9 Key_Lang9

#define Fr_AlternateErase Key_AlternateErase
#define Fr_Sysreq Key_Sysreq
#define Fr_Cancel Key_Cancel
#define Fr_Clear Key_Clear
#define Fr_Prior Key_Prior
#define Fr_Return Key_Return
#define Fr_Separator Key_Separator
#define Fr_Out Key_Out
#define Fr_Oper Key_Oper
#define Fr_ClearSlashAgain Key_ClearSlashAgain
#define Fr_CrselSlashProps Key_CrselSlashProps
#define Fr_Exsel Key_Exsel

// Reserved	0xA5-AF
#define Fr_Keypad00 Key_Keypad00
#define Fr_Keypad000 Key_Keypad000
#define Fr_ThousandsSeparator Key_ThousandsSeparator
#define Fr_DecimalSeparator Key_DecimalSeparator
#define Fr_CurrencyUnit Key_CurrencyUnit
#define Fr_CurrencySubunit Key_CurrencySubunit
#define Fr_KeypadLeftParen Key_KeypadLeftParen
#define Fr_KeypadRightParen Key_KeypadRightParen
#define Fr_KeypadLeftCurlyBrace Key_KeypadLeftCurlyBrace
#define Fr_KeypadRightCurlyBrace Key_KeypadRightCurlyBrace
#define Fr_KeypadTab Key_KeypadTab
#define Fr_KeypadBackspace Key_KeypadBackspace
#define Fr_KeypadA Key_KeypadA
#define Fr_KeypadB Key_KeypadB
#define Fr_KeypadC Key_KeypadC
#define Fr_KeypadD Key_KeypadD
#define Fr_KeypadE Key_KeypadE
#define Fr_KeypadF Key_KeypadF
#define Fr_KeypadXor Key_KeypadXor
#define Fr_KeypadCarat Key_KeypadCarat
#define Fr_KeypadPercent Key_KeypadPercent
#define Fr_KeypadLessThan Key_KeypadLessThan
#define Fr_KeypadGreaterThan Key_KeypadGreaterThan
#define Fr_KeypadAmpersand Key_KeypadAmpersand
#define Fr_KeypadDoubleampersand Key_KeypadDoubleampersand
#define Fr_KeypadPipe Key_KeypadPipe
#define Fr_KeypadDoublepipe Key_KeypadDoublepipe
#define Fr_KeypadColon Key_KeypadColon
#define Fr_KeypadPoundSign Key_KeypadPoundSign
#define Fr_KeypadSpace Key_KeypadSpace
#define Fr_KeypadAtSign Key_KeypadAtSign
#define Fr_KeypadExclamationPoint Key_KeypadExclamationPoint
#define Fr_KeypadMemoryStore Key_KeypadMemoryStore
#define Fr_KeypadMemoryRecall Key_KeypadMemoryRecall
#define Fr_KeypadMemoryClear Key_KeypadMemoryClear
#define Fr_KeypadMemoryAdd Key_KeypadMemoryAdd
#define Fr_KeypadMemorySubtract Key_KeypadMemorySubtract
#define Fr_KeypadMemoryMultiply Key_KeypadMemoryMultiply
#define Fr_KeypadMemoryDivide Key_KeypadMemoryDivide
#define Fr_KeypadPlusSlashMinus Key_KeypadPlusSlashMinus
#define Fr_KeypadClear Key_KeypadClear
#define Fr_KeypadClearEntry Key_KeypadClearEntry
#define Fr_KeypadBinary Key_KeypadBinary
#define Fr_KeypadOctal Key_KeypadOctal
#define Fr_KeypadDecimal Key_KeypadDecimal
#define Fr_KeypadHexadecimal Key_KeypadHexadecimal

#define Fr_LeftControl Key_LeftControl
#define Fr_LeftShift Key_LeftShift
#define Fr_LeftAlt Key_LeftAlt
#define Fr_LeftGui Key_LeftGui
#define Fr_RightControl Key_RightControl
#define Fr_RightShift Key_RightShift
#define Fr_RightAlt Key_RightAlt
#define Fr_RightGui Key_RightGui