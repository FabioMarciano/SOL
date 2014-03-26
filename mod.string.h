/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.string.h - SOL (Simple Object Library) string module header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MOD_STRING_H
#define _SOL_MOD_STRING_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
 
__SOF__

// @name	__sol_module_string_substring_count__
// @param	char search string
// @param	char subject string
// @return	unsigned int number of substring ocorrences.
extern unsigned int __sol_module_string_substring_count__(const char *, const char *, ...);

// @name	__sol_module_string_replace__
// @param	char search string
// @param	char substitutive string
// @param	char subject string
// @return	char modified string.
extern char *__sol_module_string_replace__(const char *, const char *, const char *, ...);

// @name	__sol_module_string_split__
// @param	char subject
// @param	char delimiter
// @return	NODE of substrings.
extern NODE *__sol_module_string_split__(const char *, const char *, ...);

// @name	__sol_module_string_join__
// @param	NODE array of strings
// @param	char joint
// @return	char consolidated string.
extern char *__sol_module_string_join__(NODE *, const char *, ...);

// @name	__sol_module_string_trim__
// @param	char string
// @param	char character to trim
// @return	char trimmed string.
extern char *__sol_module_string_trim__(const char *, char);

// @name	__sol_module_string_left_trim__
// @param	char string
// @param	char character to trim
// @return	char left trimmed string.
extern char *__sol_module_string_left_trim__(const char *, char);

// @name	__sol_module_string_right_trim__
// @param	char string
// @param	char character to trim
// @return	char right trimmed string.
extern char *__sol_module_string_right_trim__(const char *, char);

// @name	__sol_module_string_to_lowercase__
// @param	char string
// @return	char lowercase string.
extern char *__sol_module_string_to_lowercase__(const char *);

// @name	__sol_module_string_to_uppercase__
// @param	char string
// @return	char uppercase string.
extern char *__sol_module_string_to_uppercase__(const char *);

// @name	__sol_module_string_compare__
// @param	char string #1
// @param	char string #2
// @return	BOOL true if the strings are equals.
extern BOOL __sol_module_string_compare__(const char *, const char *);

// @name	__sol_module_string_integer_to_string__
// @param	int number
// @return	char stringfied number
// String with stringfied number
extern char *__sol_module_string_integer_to_string__(int);

// @name	__sol_module_string_parse_querystring__
// @param	char subject
// @return	NODE structure with parsed querystring.
// extern NODE *__sol_module_string_parse_querystring__(char *);

__EOF__

#endif
