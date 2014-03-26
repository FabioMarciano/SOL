/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.string.c - SOL (Simple Object Library) string module source file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

// @inc: SOL module header.
#include "SOL/module.h"

unsigned int __sol_module_string_substring_count__(const char *search, const char *subject, ...) {
	register unsigned int output = 0;
	register unsigned int length = strlen(search);

	if(length != 0) {
		for(subject = strstr(subject, search); subject; subject = strstr(subject + length, search)) {
			++output;
		}
	}

	return output;
}

char *__sol_module_string_substring__(const char *subject, int start, int length) {
	char *output = NULL;
	return output;
}

char *__sol_module_string_replace__(const char *old, const char *new, const char *subject, ...) {
	char *buffer, *output = NULL;
	char *temp, *spos;
	unsigned int count = __sol_module_string_substring_count__(old, subject);

	size_t slen = strlen(subject);
	size_t olen = strlen(old);
	size_t nlen = strlen(new);
	size_t diff = 0;

	ptrdiff_t offset;

	if(olen > 0 && slen > 0) {

		diff = (nlen != olen) ? (slen + (count * (nlen - olen))) : diff;
		output = (char *)malloc((sizeof(char) * diff) + 1);
		for(buffer = output, temp = (char *)subject; (spos = strstr(temp, old)) != NULL; temp = spos + olen) {
			offset = spos - temp;
			memcpy(buffer, temp, offset);
			buffer += offset;
			memcpy(buffer, new, nlen);
			buffer += nlen;
		}
		strcpy(buffer, temp);

	} else {
		output = (char *)malloc(sizeof(char) * slen);
		strcpy(output, subject);
	}

	return output;
}

NODE *__sol_module_string_split__(const char *subject, const char *delimiter, ...) {
	NODE *output = NULL;
	char *token, *stemp, *dtemp;

	stemp = strdup((char *)subject);
	dtemp = strdup((char *)delimiter);
	token = strtok(stemp, dtemp);

	while(token != NULL) {
		if(output != NULL) {
			output->next = __sol_module_node_new__(NULL, NULL);
			output->next->previous = output;
			output = output->next;
		} else {
			output = __sol_module_node_new__(NULL, NULL);
		}

		output->value = strdup(token);
		token = strtok(NULL, dtemp);
	}

	free(stemp);
	free(dtemp);

	while(output->previous != NULL) {
		output = output->previous;
	}

	return output;
}

char *__sol_module_string_join__(NODE *array, const char *joint, ...) {
	char *output = NULL;
	register unsigned int length = 0;
	register unsigned int offset = strlen(joint);

	__sol_module_node_rewind__(&array);

	while(array != NULL) {
		length += strlen((char *)array->value) + offset;
		if(array->next == NULL) {
			break;
		}
		array = array->next;
	}

	output = (char *)malloc((sizeof(char *) * length) + 1);

	__sol_module_node_rewind__(&array);

	while(array != NULL) {
		strcat(output, (char *)array->value);
		if(array->next == NULL) {
			break;
		} else {
			strcat(output, joint);
		}
		array = array->next;
	}

	return output;
}

char *__sol_module_string_left_trim__(const char *subject, char character) {
	char *output = NULL;

	character = character ? character : SOL_CHAR_WHITE_SPACE;

	if(strlen(subject) > 0) {
		output = strdup(subject);
		while(*output == character) {
			output++;
		}
	}

	return output;
}

char *__sol_module_string_right_trim__(const char *subject, char character) {
	char *output = NULL;
	char *tmpptr;

	character = character ? character : SOL_CHAR_WHITE_SPACE;

	if(strlen(subject) > 0) {
		output = strdup(subject);
		tmpptr = output + (strlen(output) - 1);

		while((*tmpptr) == character) {
			tmpptr--;
			*(tmpptr + 1) = SOL_CHAR_NULL;
		}
	}

	return output;
}

char *__sol_module_string_trim__(const char *subject, char character) {
	char *output = NULL;
	char *lstrim = NULL;

	character = character ? character : SOL_CHAR_WHITE_SPACE;

	if(strlen(subject) > 0) {
		lstrim = strdup(__sol_module_string_left_trim__(subject, character));
		output = strdup((strlen(lstrim) > 0 ? __sol_module_string_right_trim__(lstrim, character) : SOL_EMPTY));
		free(lstrim);
	}

	return output;
}

char *__sol_module_string_to_lowercase__(const char *subject) {
	char *output;
	register int length = strlen(subject);
	register int tmplen = 0;
	wchar_t *tmpstr, *auxptr;

	tmpstr = (wchar_t *)malloc(sizeof(wchar_t) * length);
	auxptr = tmpstr;

	swprintf(tmpstr, length, L"%hs", subject);
	tmplen = wcslen(tmpstr);

	while(tmplen--) {
		*auxptr = towlower(*auxptr);
		auxptr++;
	}

	output = (char *)malloc((sizeof(char) * wcslen(tmpstr)) + 1);
	sprintf(output, "%S", tmpstr);

	free(tmpstr);

	return output;
}

BOOL __sol_module_string_compare__(const char *a, const char *b) {
	BOOL output = FALSE;
	const char *p = a;
	const char *q = b;
	register unsigned int x, y;

	if(p != NULL && q != NULL) {
		x = strlen(p);
		y = strlen(q);
		output |= x == y ? TRUE : FALSE;

		while(x) {
			x--;
			output &= *p++ == *q++ ? TRUE : FALSE;

			if(!output) {
				break;
			}
		}
	} else if(p == NULL && q == NULL) {
		output |= TRUE;
	}

	return output;
}

char *__sol_module_string_to_uppercase__(const char *subject) {
	char *output;
	register int length = strlen(subject);
	register int tmplen = 0;
	wchar_t *tmpstr, *auxptr;

	tmpstr = (wchar_t *)malloc(sizeof(wchar_t) * length);
	auxptr = tmpstr;

	swprintf(tmpstr, length, L"%hs", subject);
	tmplen = wcslen(tmpstr);

	while(tmplen--) {
		*auxptr = towupper(*auxptr);
		auxptr++;
	}

	output = (char *)malloc((sizeof(char) * wcslen(tmpstr)) + 1);
	sprintf(output, "%S", tmpstr);

	free(tmpstr);

	return output;
}

char *__sol_module_string_integer_to_string__(int number) {
	int i = 0, j, count = 0, sign, copy;
	char c, *buffer = NULL;

	if((sign = number) < 0) {
		number *= -1;
	}

	copy = number;

	do {
		count++;
	} while((copy /= 10) > 0);

	buffer = (char *)malloc(sizeof(char) * count + 1);

	do {
		buffer[i++] = number % 10 + '0';
	} while ((number /= 10) > 0);

	if (sign < 0) {
		buffer[i++] = '-';
	}

	buffer[i] = '\0';

	for(i = 0, j = strlen(buffer) - 1; i < j; i++, j--) {
		c = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = c;
	}

	return buffer;
}



/*
NODE *__sol_module_string_parse_querystring__(char *subject) {
	NODE *output = NULL;
	char *tmp = NULL;
	char *aux = NULL;
	char *key = NULL;
	char *val = NULL;

	int subLen, auxLen, tmpLen, keyLen, valLen;

	if(subject) {

		subLen = subject != NULL ? strlen(subject) : 0;

		while(*subject == SOL_CHAR_AMPERSAND || *subject == SOL_CHAR_WHITE_SPACE) {
			subject++;
		}

		subject = __sol_module_string_right_trim__(subject, SOL_CHAR_AMPERSAND);

		subLen = subject != NULL ? strlen(subject) : 0;

		if(subLen > 0) {

			aux = subject;

			for(subject; subLen > 0; aux++) {
				aux = strstr(aux, SOL_QUERYSTRING_DELIMITER);
				auxLen = aux ? strlen(aux) : 0;

				if((subLen - auxLen) > 1) {
					tmpLen = (subLen - auxLen);

					tmp = (char *)malloc(sizeof(char) * tmpLen + 1);
					memcpy(tmp, subject, tmpLen);

					while(*tmp == SOL_CHAR_AMPERSAND || *tmp == SOL_CHAR_WHITE_SPACE || *tmp == SOL_CHAR_PLUS) {
						tmp++;
						*(tmp - 1) = SOL_CHAR_NULL;
						tmpLen--;
					}

					val = strstr(tmp, SOL_QUERYSTRING_TOKEN_DELIMITER);

					if(val != NULL) {
						*val = SOL_CHAR_NULL;
						val++;
					}

					valLen = val != NULL ? strlen(val) : 0;
					key = tmp;
					keyLen = strlen(key);

					if(keyLen > 0) {
						while(*key) {
							*key = *key == SOL_CHAR_WHITE_SPACE || *key == SOL_CHAR_PLUS ? SOL_CHAR_UNDERSCORE : *key;
							key++;
						}
						key = tmp;
					} else {
						key = NULL;
					}

					key = keyLen > 0 ? key : NULL;
					val = valLen > 0 ? val : NULL;

					if(key != NULL) {
						if(output == NULL) {
							output = __sol_module_node_new__(NULL, NULL);
						} else {
							output->next = __sol_module_node_new__(NULL, NULL);
							output->next->previous = output;
							output = output->next;
						}

						output->name = strdup(__sol_module_crypt_url_decode__(key));

						if(val != NULL) {
							output->value = strdup(__sol_module_crypt_url_decode__(val));
						}
					}
				}
				subject += subLen - (aux ? strlen(aux) : 0);
				subLen = strlen(subject);
			}
		}
	}

	__sol_module_node_rewind__(&output);

	return output;
}
*/