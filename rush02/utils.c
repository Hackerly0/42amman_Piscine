/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:25:35 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/29 15:25:41 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int is_positive_number(const char *str) {
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit((unsigned char)*str)) return 0;
        str++;
    }
    return 1;
}

char *trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == '\0') return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

size_t strlen(const char *str) {
    const char *s = str;
    while (*s) s++;
    return s - str;
}
