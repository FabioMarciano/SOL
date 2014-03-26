/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.constant.h - SOL (Simple Object Library) constant header file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

#ifndef _SOL_CONSTANT_H
#define _SOL_CONSTANT_ 1

// @def	SOLSOF && SOLEOF
// Start Of File and End Of File definition. Set up to C function definitions even when using C++.
#ifdef __cplusplus
	#define __SOF__ extern "C" {
	#define __EOF__ }
#else
	#define __SOF__
	#define __EOF__
#endif

// @def	SOL_OS
// Operating System.
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
	#define SOL_OS 1
#elif defined(__APPLE__)
	#define SOL_OS 2
#elif defined(__linux__)
	#define SOL_OS 0
#else
	#define SOL_OS 3
#endif

// @def	SOL_CHAR_NULL
// Null character.
#define SOL_CHAR_NULL 0x00

// @def	SOL_CHAR_WHITE_SPACE
// No-break space character.
#define SOL_CHAR_WHITE_SPACE 0x20

// @def	SOL_CHAR_UNDERSCORE
// Underscore character.
#define SOL_CHAR_UNDERSCORE 0x5F

// @def	SOL_CHAR_AMPERSAND
// Ampersand character.
#define SOL_CHAR_AMPERSAND 0x26

// @def	SOL_CHAR_PLUS
// Plus sign/operator character.
#define SOL_CHAR_PLUS 0x2B

// @def	SOL_CHAR_PERCENT
// Percent/module sign/operator character.
#define SOL_CHAR_PERCENT 0x25

// @def	SOL_EMPTY
// Empty String.
#define SOL_EMPTY ""

// @def	SOL_CARRIAGE_RETURN
// Carriage return string.
#define SOL_CARRIAGE_RETURN "\r"

// @def	SOL_LINE_FEED
// Line feed string.
#define SOL_LINE_FEED "\n"

// @def	SOL_TAB
// Tab string.
#define SOL_TAB "\t"

// @def	SOL_EQUAL
// Equal string.
#define SOL_EQUAL "="

// @def	SOL_LT
// Less than string.
#define SOL_LT "<"

// @def	SOL_GT
// Greater than string.
#define SOL_GT ">"

// @def	SOL_DOT
// Dot string.
#define SOL_DOT "."

// @def	SOL_UNDERSCORE
// Dot string.
#define SOL_UNDERSCORE "_"

// @def	SOL_QUERYSTRING_DELIMITER
// Querystring delimiter string.
#define SOL_QUERYSTRING_DELIMITER "&"

// @def	SOL_QUERYSTRING_TOKEN_DELIMITER
// Querystring token delimiter string.
#define SOL_QUERYSTRING_TOKEN_DELIMITER SOL_EQUAL

// @def	SOL_DUMP_MODEL
// Dump model string.
#define SOL_DUMP_MODEL "%s " SOL_EQUAL SOL_GT " %s" SOL_LINE_FEED

// @def	SOL_CRLF
// Carriage Return and Line Feed Characters Pair by OS.
#if SOL_OS == 1
	#define SOL_CRLF SOL_CARRIAGE_RETURN SOL_LINE_FEED
#elif SOL_OS == 2
	#define SOL_CRLF SOL_CARRIAGE_RETURN SOL_CARRIAGE_RETURN
#else
	#define SOL_CRLF SOL_LINE_FEED SOL_LINE_FEED
#endif

// @def	SOL_LOWER_HEXSET
// Defines the lowercase hexadecimal set of characters.
#define SOL_LOWER_HEXSET "0123456789abcdef"

// @def	SOL_UPPER_HEXSET
// Defines the uppercase hexadecimal set of characters.
#define SOL_UPPER_HEXSET "0123456789ABCDEF"

// @def	SOL_HEXSET
// Defines the hexadecimal set of characters.
#define SOL_HEXSET SOL_LOWER_HEXSET

// @def	SOL_CRYPT_BYTE_FORMAT
// Defines the byte format for 2 characters hexadecimal.
#define SOL_CRYPT_BYTE_FORMAT "%02x"

// @def	SOL_CRYPT_DATA_MAX_LENGTH
// Defines the maximum length of block to process in crypt algoritms.
#define SOL_CRYPT_DATA_MAX_LENGTH 512

// @def	SOL_CRYPT_SALT
// Defines the salt to crypt methods.
#define SOL_CRYPT_SALT "FabioMarciano"

// @def	SOL_MIME_TEXT_PLAIN
// Defines the mime type text/plain.
#define SOL_MIME_TEXT_PLAIN "text/plain"

// @def	SOL_MIME_TEXT_HTML
// Defines the mime type text/html.
#define SOL_MIME_TEXT_HTML "text/html"

// @def	SOL_MIME_IMAGE_JPEG
// Defines the mime type image/jpeg.
#define SOL_MIME_IMAGE_JPEG "image/jpeg"

// @def	SOL_MIME_IMAGE_PNG
// Defines the mime type image/png.
#define SOL_MIME_IMAGE_PNG "image/png"

// @def	SOL_MIME_IMAGE_BMP
// Defines the mime type image/bmp.
#define SOL_MIME_IMAGE_BMP "image/bmp"

// @def	SOL_MIME_IMAGE_GIF
// Defines the mime type image/gif.
#define SOL_MIME_IMAGE_GIF "image/gif"

// @def	SOL_CHARSET
// Defines the default charset.
#define SOL_CHARSET "UTF-8"

// @def	SOL_LANGUAGE
// Defines the lang.
#define SOL_LANG "pt"

// @def	SOL_COUNTRY_ISO
// Defines the country abbreviation (ISO).
#define SOL_COUNTRY_ISO "BR"

// @def	SOL_COUNTRY_LABEL
// Defines the country label.
#define SOL_COUNTRY_LABEL "Brasil"

// @def	SOL_LANGUAGE
// Defines the language.
#define SOL_LANGUAGE SOL_LANG SOL_UNDERSCORE SOL_COUNTRY_ISO

// @def	SOL_LOCALE
// Localization.
#define SOL_LOCALE SOL_LANGUAGE SOL_DOT SOL_CHARSET

// @def	SOL_HTTP_CHARSET
// Defines default HTTP charset.
#define SOL_HTTP_CHARSET "charset" SOL_EQUAL SOL_CHARSET

// @def	SOL_HTTP_CONTENT_TYPE
// Defines default HTTP content type.
#define SOL_HTTP_CONTENT_TYPE "Content-type:" SOL_MIME_TEXT_HTML

// @def	SOL_HTTP_HEADER
// Defines default HTTP response header.
#define SOL_HTTP_HEADER SOL_HTTP_CONTENT_TYPE ";" SOL_HTTP_CHARSET SOL_LINE_FEED SOL_LINE_FEED

// @def	SOL_HTTP_ENCTYPE_URL_ENCODED
// Defines HTTP ENCTYPE url encoded.
#define SOL_HTTP_ENCTYPE_URL_ENCODED "application/x-www-form-urlencoded"

// @def	SOL_HTTP_ENCTYPE_MULTIPART
// Defines HTTP ENCTYPE multipart.
#define SOL_HTTP_ENCTYPE_MULTIPART "multipart/form-data"

// @def	SOL_HTTP_ENCTYPE
// Defines default HTTP ENCTYPE mode.
#define SOL_HTTP_ENCTYPE SOL_HTTP_ENCTYPE_URL_ENCODED

// @def	SOL_DB_HOST
// Defines default database host.
#define SOL_DB_HOST "localhost"

// @def	SOL_DB_USER
// Defines default database user.
#define SOL_DB_USER "root"

// @def	SOL_DB_PASSWORD
// Defines default database password.
#define SOL_DB_PASSWORD "admin"

// @def	SOL_DB_NAME
// Defines default database name.
#define SOL_DB_NAME ""

// @def	SOL_DB_PORT
// Defines mysql database port.
#define SOL_DB_MYSQL_PORT 3306

// @def	SOL_DB_POSTGRES_USER
// Defines postgres database user.
#define SOL_DB_POSTGRES_USER "postgres"

// @def	SOL_DB_POSTGRES_PORT
// Defines postgres database port.
#define SOL_DB_POSTGRES_PORT 5432

#endif
