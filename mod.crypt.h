/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.crypt.h - SOL (Simple Object Library) crypt module header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_MOD_CRYPT_H
#define _SOL_MOD_CRYPT_H 1

// @inc: SOL files.
#include "SOL/include.h"
#include "SOL/constant.h"
#include "SOL/macro.h"
#include "SOL/type.h"
 
__SOF__

// @name	__sol_module_crypt_md5__
// @param	const char string
// @return	char 32 bytes MD5 hash
// String encryptation basead on MD5 hash algorithm.
extern char *__sol_module_crypt_md5__(const char *, ...);

// @name	__sol_module_crypt_sha1__
// @param	const char string
// @return	char 40 bytes SHA-1 hash
// String encryptation basead on SHA-1 hash algorithm.
extern char *__sol_module_crypt_sha1__(const char *, ...);

// @name	__sol_module_crypt_encode_base64__
// @param	const char string
// @return	char Base 64 encoded string
// String encode basead on Base 64 algorithm.
extern char *__sol_module_crypt_encode_base64__(const char *, ...);

// @name	__sol_module_crypt_decode_base64__
// @param	const char base 64 encoded string
// @return	char base 64 decoded string
// String decode basead on Base 64 algorithm.
extern char *__sol_module_crypt_decode_base64__(const char *, ...);

// @name	__sol_module_crypt_encode_url__
// @param	char string to encode
// @return	char url encoded string.
extern char *__sol_module_crypt_encode_url__(const char *, ...);

// @name	__sol_module_crypt_decode_url__
// @param	char string to decode
// @return	char url decoded string.
extern char *__sol_module_crypt_decode_url__(const char *, ...);

// @name	__sol_module_crypt_decode_hex__
// @param	char string to decode
// @return	int number.
extern int __sol_module_crypt_decode_hex__(const char *, ...);

// @name	__sol_module_crypt_encode_hex__
// @param	int number to encode
// @return	char hexadecimal string.
extern char *__sol_module_crypt_encode_hex__(unsigned int, ...);

__EOF__

#endif
