/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:27 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/29 15:24:30 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "utils.h"

static t_dict *create_entry(int key, const char *value) {
    t_dict *entry = malloc(sizeof(t_dict));
    if (!entry) return NULL;
    entry->key = key;
    entry->value = strdup(value);
    entry->next = NULL;
    return entry;
}

static void add_entry(t_dict **dict, t_dict *entry) {
    entry->next = *dict;
    *dict = entry;
}

static char *read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) return NULL;

    char buffer[4096];
    char *content = NULL;
    int bytes_read, total_length = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        char *new_content = malloc(total_length + bytes_read + 1);
        if (!new_content) {
            free(content);
            close(fd);
            return NULL;
        }
        if (content) {
            memcpy(new_content, content, total_length);
            free(content);
        }
        memcpy(new_content + total_length, buffer, bytes_read);
        total_length += bytes_read;
        new_content[total_length] = '\0';
        content = new_content;
    }
    close(fd);
    return content;
}

t_dict *parse_dict(const char *filename) {
    char *content = read_file(filename);
    if (!content) return NULL;

    t_dict *dict = NULL;
    char *line = content;
    char *line_end;

    while ((line_end = strchr(line, '\n')) != NULL) {
        *line_end = '\0';
        char *sep = strchr(line, ':');
        if (sep) {
            *sep = '\0';
            int key = atoi(line);
            char *value = trim(sep + 1);
            if (*value != '\0') {
                t_dict *entry = create_entry(key, value);
                if (!entry) {
                    free_dict(dict);
                    free(content);
                    return NULL;
                }
                add_entry(&dict, entry);
            }
        }
        line = line_end + 1;
    }
    free(content);
    return dict;
}

void free_dict(t_dict *dict) {
    while (dict) {
        t_dict *next = dict->next;
        free(dict->value);
        free(dict);
        dict = next;
    }
}
