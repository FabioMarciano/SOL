/*
 * SOL - Simple Object Library
 * -----------------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in MEL root for details.
 *
 * SOL.mod.node.c - SOL (Simple Object Library) node module source file
 *
 * Copyright (c) 2014 Fábio Marciano <fabioamarciano@gmail.com>
 *
 */

// @inc: SOL module header.
#include "SOL/module.h"

NODE *__sol_module_node_new__(const char *name, const char *value) {
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->name = name != NULL ? strdup(name) : NULL;
	node->value = value != NULL ? strdup(value) : NULL;
	node->attributes = NULL;
	node->events = NULL;
	node->childNodes = NULL;
	node->parentNode = NULL;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

unsigned int __sol_module_node_length__(NODE *node) {
	register unsigned int count = 0;
	NODE *cursor = NULL;

	if(node != NULL) {
		cursor = node;
		count++;

		while(cursor->previous != NULL) {
			cursor = cursor->previous;
		}

		while(cursor->next != NULL) {
			cursor = cursor->next;
			count++;
		}
	}

	cursor = NULL;

	return count;
}

unsigned int __sol_module_node_rewind__(NODE **node) {
	register unsigned int count = 0;

	if(*node != NULL) {
		while((*node)->previous != NULL) {
			*node = (*node)->previous;
			count++;
		}
	}

	return count;
}

unsigned int __sol_module_node_forward__(NODE **node) {
	register unsigned int count = 0;

	if(*node != NULL) {
		while((*node)->next != NULL) {
			*node = (*node)->next;
			count++;
		}
	}

	return count;
}

unsigned int __sol_module_node_index__(NODE **node) {
	register int index = 0;
	NODE **cursor = node;

	if(*cursor != NULL) {
		while((*cursor)->previous != NULL) {
			index++;
			*cursor = (*cursor)->previous;
		}
	}

	return index;
}

unsigned int __sol_module_node_jump__(NODE **node, int position) {
	register int count = 0;
	register int index = position;
	register int length = *node != NULL ? __sol_module_node_length__(*node) : 0;

	if(*node != NULL) {

		__sol_module_node_rewind__(&(*node));

		if(position != 0) {
			index = (index >= length ? index % length : (index < 0 ? (length - ((index * -1) % length)) : index));
			while(index--) {
				*node = (*node)->next;
			}
		}
	}

	return count;
}

unsigned int __sol_module_node_walk__(NODE **node, int steps) {
	register int index = __sol_module_node_index__(&(*node));
	register int length = 0;
	register int cursor = index;
	register int target = 0;

	if(*node != NULL) {
		if(steps != 0) {
			length = __sol_module_node_length__(*node);
			target = steps >= 0 ? steps % length : length - ((steps * -1) % length);
			target = cursor + target >= length ? target - length : target;

			if(target > 0) {
				while(target--) {
					*node = (*node)->next;
				}
			} else {
				target *= -1;
				while(target--) {
					*node = (*node)->previous;
				}
			}
		}
	}

	return index;
}

void __sol_module_node_dump__(NODE *node) {
	NODE *cursor = node;
	unsigned int tab = 0;
	int i = 0;

	if(cursor != NULL) {
		while(cursor->previous != NULL) {
			cursor = cursor->previous;
		}

		while(cursor) {
			for(i = 0; i < tab; i++) {
				printf(SOL_TAB);
			}
			printf(SOL_DUMP_MODEL, (cursor->name != NULL ? cursor->name : ""), (cursor->value != NULL ? cursor->value : ""));
			if(cursor->childNodes != NULL) {
				cursor = cursor->childNodes;
				tab++;
			} else {
				if(cursor->next != NULL) {
					cursor = cursor->next;
				} else {
					if(cursor->parentNode != NULL) {
						if(cursor->parentNode->next != NULL) {
							cursor = cursor->parentNode->next;
							tab--;
						} else {
							break;
						}
					} else {
						break;
					}
				}
			}
		}
	}
}

void __sol_module_node_push__(NODE **node, const char *name, const char *value) {
	NODE *new = __sol_module_node_new__(name != NULL ? name : SOL_EMPTY, value != NULL ? value : SOL_EMPTY);

	if(*node != NULL) {

		while((*node)->next != NULL) {
			*node = (*node)->next;
		}
		__sol_module_node_append__(&(*node), new);
	} else {
		*node = new;
	}

	__sol_module_node_rewind__(&(*node));
}

void __sol_module_node_unshift__(NODE **node, const char *name, const char *value) {}

NODE *__sol_module_node_pop__(NODE **node) {
	NODE *output = NULL;
	return output;
}

NODE *__sol_module_node_shift__(NODE **node) {
	NODE *output = NULL;
	return output;
}

void __sol_module_node_append__(NODE **node, NODE *child) {

	if(*node != NULL) {

		while(child->previous != NULL) {
			child = child->previous;
		}

		while((*node)->next != NULL) {
			*node = (*node)->next;
		}

		(*node)->next = child;
		child->previous = *node;
		child->parentNode = (*node)->parentNode;
	} else {
		*node = child;
	}

	__sol_module_node_rewind__(&(*node));

}

void __sol_module_node_prepend__(NODE **node, NODE *child) {

	if(*node != NULL) {

		while(child->next != NULL) {
			child = child->next;
		}

		while((*node)->previous != NULL) {
			*node = child->previous;
		}

		(*node)->previous = child;
		child->next = *node;
		child->parentNode = (*node)->parentNode;

	} else {
		*node = child;
	}

	__sol_module_node_rewind__(&(*node));

}

void __sol_module_node_detach__(NODE **node) {

	if(*node != NULL) {
		if((*node)->next != NULL) {
			(*node)->next->previous = (*node)->previous != NULL ? (*node)->previous : NULL;
		}

		if((*node)->previous != NULL) {
			(*node)->previous->next = (*node)->next != NULL ? (*node)->next : NULL;
		}

		(*node)->next = NULL;
		(*node)->previous = NULL;
		(*node)->parentNode = NULL;
	}

}

void __sol_module_node_clear__(NODE **node) {
	NODE **cursor = node;

	printf("LIMPANDO:\n\tName: %s\n\tValue: %s\n\n", (*cursor)->name, (*cursor)->value);

	// CHECK CHILD NODES
	// CHECK NEXT
	// CHECK PREVIOUS
	// CLEAR VALUE
	// CLEAR NAME
	// CLEAR ATTRIBUTES
	// CLEAR EVENTS

	free((*cursor)->name);
	free((*cursor)->value);
	(*cursor)->name = NULL;
	(*cursor)->value = NULL;

	(*cursor) = NULL;
}

void __sol_module_node_drop__(NODE **node) {
	__sol_module_node_detach__(&(*node));
	__sol_module_node_clear__(&(*node));
}

void __sol_module_node_set_attribute__(NODE **node, const char *name, const char *value) {}

void __sol_module_node_set_event__(NODE **node, const char *name, const char *value) {}

void __sol_module_node_set_value__(NODE **node, const char *value) {
	if(*node != NULL) {
		if((*node)->value != NULL) {
			free((*node)->value);
			(*node)->value = NULL;
		}

		if(value != NULL) {
			(*node)->value = strdup(value);
		} else {
			(*node)->value = NULL;
		}
	}
}

void __sol_module_node_add_event__(NODE **node, const char *name, const char *value) {}

char *__sol_module_node_get_event__(NODE **node, const char *name) {
	char *output = NULL;
	return output;
}

char *__sol_module_node_get_attribute__(NODE **node, const char *name) {
	char *output = NULL;
	return output;
}

char *__sol_module_node_get_value__(NODE **node, const char *name) {
	char *output = NULL;
	NODE *cursor = *node;

	while(cursor->previous != NULL) {
		cursor = cursor->previous;
	}

	while(cursor != NULL) {
		if((__sol_module_string_compare__(cursor->name, name))) {
			output = cursor->value;
			break;
		}
		cursor = cursor->next;
	}

	return output;
}
