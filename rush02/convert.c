/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:25:15 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/29 15:32:18 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "convert.h"
#include "utils.h"

static t_dict *find_entry(t_dict *dict, int key) {
    while (dict) {
        if (dict->key == key) {
            return dict;
        }
        dict = dict->next;
    }
    return NULL;
}

static char *append_str(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = malloc(len1 + len2 + 2); // +2 for space and null-terminator
    if (!result) return NULL;
    strcpy(result, str1);
    result[len1] = ' ';
    strcpy(result + len1 + 1, str2);
    return result;
}

char *convert_number(t_dict *dict, const char *number) {
    char *result = NULL;
    int num = atoi(number);

    // Handle zero case
    if (num == 0) {
        t_dict *entry = find_entry(dict, 0);
        if (entry) {
            result = strdup(entry->value);
        }
        return result;
    }

    // Conversion logic for numbers
    while (num > 0) {
        int divisor;
        if (num >= 1000000) {
            divisor = 1000000;
        } else if (num >= 1000) {
            divisor = 1000;
        } else if (num >= 100) {
            divisor = 100;
        } else {
            divisor = 1;
        }

        int key = (num / divisor) * divisor;
        t_dict *entry = find_entry(dict, key);
        if (!entry) {
            free(result);
            return NULL;
        }

        if (result) {
            char *new_result = append_str(result, entry->value);
            free(result);
            result = new_result;
        } else {
            result = strdup(entry->value);
        }

        num %= divisor;
    }

    return result;
}
