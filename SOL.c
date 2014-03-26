/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.c - SOL (Simple Object Library) source file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

// @inc: SOL header file.
#include "SOL/SOL.h"

// @name	__sol_load_environment__
// @type	static
// @param	none
// @return	void
static void __sol_load_environment__() {
	extern char **environ;
	extern NODE *ENV;

	char *val;
	char **aux = environ;
	int length;

	while(*aux) {
		val = strstr(*aux, SOL_QUERYSTRING_TOKEN_DELIMITER);
		length = strlen(*aux) - strlen(val);
		if(ENV != NULL) {
			ENV->next = __sol_module_node_new__(NULL, NULL);
			ENV->next->previous = ENV;
			ENV = ENV->next;
		} else {
			ENV = __sol_module_node_new__(NULL, NULL);
		}
		ENV->value = strdup(val + 1);
		ENV->name = (char *)malloc((sizeof(char) * length) + 1);
		memcpy(ENV->name, *aux, length);
		aux++;
	}
	__sol_module_node_rewind__(&ENV);
}

// @name	__sol_init__
// @type	constructor
// @param	none
// @return	void
__attribute__((constructor)) static void __sol_init__() {

	setlocale(LC_ALL, SOL_LOCALE);

	// NODE MODULE
	SOL.Node.Length = __sol_module_node_length__;
	SOL.Node.Rewind = __sol_module_node_rewind__;
	SOL.Node.Forward = __sol_module_node_forward__;
	SOL.Node.Jump = __sol_module_node_jump__;
	SOL.Node.Walk = __sol_module_node_walk__;
	SOL.Node.Index = __sol_module_node_index__;
	SOL.Node.New = __sol_module_node_new__;
	SOL.Node.Drop = __sol_module_node_drop__;
	SOL.Node.Dump = __sol_module_node_dump__;
	SOL.Node.Push = __sol_module_node_push__;
	SOL.Node.Append = __sol_module_node_append__;
	SOL.Node.Prepend = __sol_module_node_prepend__;
	SOL.Node.Set.Value = __sol_module_node_set_value__;
	SOL.Node.Set.Attribute = __sol_module_node_set_attribute__;

	// STRING MODULE
	SOL.String.SubstringCount = __sol_module_string_substring_count__;
	SOL.String.Replace = __sol_module_string_replace__;
	SOL.String.Split = __sol_module_string_split__;
	SOL.String.Join = __sol_module_string_join__;
	SOL.String.LeftTrim = __sol_module_string_left_trim__;
	SOL.String.RightTrim = __sol_module_string_right_trim__;
	SOL.String.Trim = __sol_module_string_trim__;
	SOL.String.ToLowerCase = __sol_module_string_to_lowercase__;
	SOL.String.ToUpperCase = __sol_module_string_to_uppercase__;
	SOL.String.Compare = __sol_module_string_compare__;
	SOL.String.IntegerToString = __sol_module_string_integer_to_string__;

	// CRYPT MODULE
	SOL.Crypt.MD5 = __sol_module_crypt_md5__;
	SOL.Crypt.SHA1 = __sol_module_crypt_sha1__;
	SOL.Crypt.Encode.Base64 = __sol_module_crypt_encode_base64__;
	SOL.Crypt.Encode.Url = __sol_module_crypt_encode_url__;
	SOL.Crypt.Decode.Base64 = __sol_module_crypt_decode_base64__;
	SOL.Crypt.Decode.Url = __sol_module_crypt_decode_url__;
	SOL.Crypt.Decode.Hex = __sol_module_crypt_decode_hex__;
	SOL.Crypt.Encode.Hex = __sol_module_crypt_encode_hex__;

	// DB MODULE
	SOL.DB.New = __sol_module_db_new__;
	SOL.DB.Status = __sol_module_db_status__;
	SOL.DB.Connect = __sol_module_db_connect__;
	SOL.DB.Set.Attribute = __sol_module_db_set_attribute__;
	SOL.DB.Set.Type = __sol_module_db_set_type__;
	SOL.DB.Set.Host = __sol_module_db_set_host__;
	SOL.DB.Set.User = __sol_module_db_set_user__;
	SOL.DB.Set.Password = __sol_module_db_set_password__;
	SOL.DB.Set.Name = __sol_module_db_set_name__;
	SOL.DB.Set.Port = __sol_module_db_set_port__;

	/*SOL.DB.Status = __sol_module_db_status__;
	SOL.DB.Shutdown = __sol_module_db_shutdown__;
	SOL.DB.Set.Data = __sol_module_db_set_data__;
	SOL.DB.Set.Host = __sol_module_db_set_host__;
	SOL.DB.Set.User = __sol_module_db_set_user__;
	SOL.DB.Set.Password = __sol_module_db_set_password__;
	SOL.DB.Set.Name = __sol_module_db_set_name__;
	SOL.DB.Get.Host = __sol_module_db_get_host__;
	SOL.DB.Get.User = __sol_module_db_get_user__;
	SOL.DB.Get.Password = __sol_module_db_get_password__;
	SOL.DB.Get.Name = __sol_module_db_get_name__;
	SOL.DB.Use = __sol_module_db_use__;*/

	// HTTP MODULE
	// SOL.HTTP.Querystring.Parse = __sol_module_http_querystring_parse__;

	__sol_load_environment__();

}

// @name	__sol_quit__
// @type	constructor
// @param	none
// @return	void
__attribute__((destructor)) static void __sol_quit__() {
	if(ENV != NULL) {
		__sol_module_node_rewind__(&ENV);
		free(ENV);
	}
	__sol_engine__ &= FALSE;
}

// @fnc	Library's init function.
void SOL_Init() {
	__sol_engine__ |= TRUE;
}

// @fnc	Library's quit function.
void SOL_Quit() {}
