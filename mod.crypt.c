/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.crypt.c - SOL (Simple Object Library) crypt module source file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

// @inc: SOL module header.
#include "SOL/module.h"

char *__sol_module_crypt_md5__(const char *subject, ...) {
	MD5_CTX context;
	int i, length = strlen(subject);
	unsigned char digest[MD5_DIGEST_LENGTH];
	char *output = (char*)malloc((MD5_DIGEST_LENGTH * 2) + 1);

	MD5_Init(&context);

	while(length > 0) {
		MD5_Update(&context, subject, (length > SOL_CRYPT_DATA_MAX_LENGTH ? SOL_CRYPT_DATA_MAX_LENGTH : length));
		length -= SOL_CRYPT_DATA_MAX_LENGTH;
		subject += SOL_CRYPT_DATA_MAX_LENGTH;
	}

	MD5_Final(digest, &context);

	for(i = 0; i < MD5_DIGEST_LENGTH; ++i) {
		snprintf(&(output[i * 2]), MD5_DIGEST_LENGTH * 2, SOL_CRYPT_BYTE_FORMAT, (unsigned int)digest[i]);
	}

	return output;
}

char *__sol_module_crypt_sha1__(const char *subject, ...) {
	SHA_CTX context;
	int i, length = strlen(subject);
	unsigned char digest[SHA_DIGEST_LENGTH];
	char *output = (char*)malloc((SHA_DIGEST_LENGTH * 2) + 1);

	SHA1_Init(&context);

	while(length > 0) {
		SHA1_Update(&context, subject, (length > SOL_CRYPT_DATA_MAX_LENGTH ? SOL_CRYPT_DATA_MAX_LENGTH : length));
		length -= SOL_CRYPT_DATA_MAX_LENGTH;
		subject += SOL_CRYPT_DATA_MAX_LENGTH;
	}

	SHA1_Final(digest, &context);

	for(i = 0; i < SHA_DIGEST_LENGTH; ++i) {
		snprintf(&(output[i * 2]), SHA_DIGEST_LENGTH * 2, SOL_CRYPT_BYTE_FORMAT, (unsigned int)digest[i]);
	}

	return output;
}

char *__sol_module_crypt_encode_base64__(const char *subject, ...) {
	char *output = NULL;
	BIO *bio, *b64;
	FILE* stream;
	int elen = 4 * ceil((double)strlen(subject) / 3);
	output = (char *)malloc(elen + 1);

	stream = fmemopen(output, elen + 1, "w");
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_fp(stream, BIO_NOCLOSE);
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
	BIO_write(bio, subject, strlen(subject));
	(void) BIO_flush(bio);
	BIO_free_all(bio);

	fclose(stream);

	return output;
}

char *__sol_module_crypt_decode_base64__(const char *subject, ...) {
	char *output = NULL;
	BIO *bio, *b64;

	int dlen;
	int slen = strlen(subject);
	int padd = 0;
 
	if(subject[slen-1] == '=' && subject[slen-2] == '=') //last two chars are =
	padd = 2;
	else if (subject[slen-1] == '=') //last char is =
	padd = 1;
	 
	dlen = (int) slen * 0.75 - padd;

	output = (char *)malloc(dlen + 1);
	FILE* stream = fmemopen((char *)subject, strlen(subject), "r");

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_fp(stream, BIO_NOCLOSE);
	bio = BIO_push(b64, bio);
	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush output
	slen = BIO_read(bio, output, slen);
	//Can test here if slen == dlen - if not, then return an error
	output[slen] = '\0';

	BIO_free_all(bio);
	fclose(stream);

	return output;
}

char *__sol_module_crypt_encode_url__(const char *subject, ...) {
	unsigned int length = strlen(subject);
	char *output, *cursor;

	if(length) {
		cursor = output = (char *)malloc((sizeof(char) * (length * 3)) + 1);
		if(output) {
			while(*subject) {
				if((*subject >= '0' && *subject <= '9') || (*subject >= 'a' && *subject <= 'z') || (*subject >= 'A' && *subject <= 'Z') || *subject == '-' || *subject == '_' || *subject == '.' || *subject == '~') {
					*cursor++ = *subject;
				} else if(*subject == ' ') {
					*cursor++ = SOL_CHAR_PLUS;
				} else {
					*cursor++ = SOL_CHAR_PERCENT;
					*cursor++ = SOL_HEXSET[*subject >> 4 & 15];
					*cursor++ = SOL_HEXSET[*subject & 15];
				}
				subject++;
			}
			*cursor = SOL_CHAR_NULL;
		}
	}

	return output;
}

char *__sol_module_crypt_decode_url__(const char *subject, ...) {
	char *output, *cursor;
	int length = strlen(subject);
	BOOL isHex;
	char hex[3] = {0};

	if(length) {
		cursor = output = (char *)malloc(sizeof(char) * length + 1);
		if(output) {
			while(*subject) {
				if(*subject == SOL_CHAR_PERCENT) {
					isHex = TRUE;
					isHex &= ((*(subject + 1) >= '0' && *(subject + 1) <= '9') || (*(subject + 1) >= 'a' && *(subject + 1) <= 'f') || (*(subject + 1) >= 'A' && *(subject + 1) <= 'F')) ? TRUE : FALSE;
					isHex &= ((*(subject + 2) >= '0' && *(subject + 2) <= '9') || (*(subject + 2) >= 'a' && *(subject + 2) <= 'f') || (*(subject + 2) >= 'A' && *(subject + 2) <= 'F')) ? TRUE : FALSE;
					if(isHex) {
						hex[0] = *(++subject);
						hex[1] = *(++subject);
						hex[2] = SOL_CHAR_NULL;
						*cursor++ = __sol_module_crypt_decode_hex__(hex);
					} else {
						*cursor++ = *subject;
					}
				} else if(*subject == SOL_CHAR_PLUS) {
					*cursor++ = SOL_CHAR_WHITE_SPACE;
				}  else {
					*cursor++ = *subject;
				}
				subject++;
			}
			*cursor = '\0';
		}
	}

	return output;
}

int __sol_module_crypt_decode_hex__(const char *subject, ...) {
	register int output = 0;
	register int chrpow = 1;
	register int len = strlen(subject);
	char *strhex = (char *)subject + len;

	while(len > 0) {
		len--;
		--strhex;
		if(!((*strhex >= 'A' && *strhex <= 'F') || (*strhex >= 'a' && *strhex <= 'f') || (*strhex >= '0' && *strhex <= '9'))) {output = 0; break;}
		output += (((*strhex >= 'A' && *strhex <= 'F') || (*strhex >= 'a' && *strhex <= 'f') ? (*strhex & 0xDF) - 'A' + 10 : (*strhex >= '0' && *strhex <= '9' ? *strhex - '0' : 0)) * chrpow);
		chrpow *= 16;
	}

	return output;
}

char *__sol_module_crypt_encode_hex__(unsigned int value, ...) {
	char *output = NULL;
	char buffer[64] = {0};
	sprintf(buffer, "%x", value);

	output = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
	strcpy(output, buffer);

	return output;
}

