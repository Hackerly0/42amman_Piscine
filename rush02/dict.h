/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:22:59 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/29 15:23:04 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
#define DICT_H

typedef struct s_dict {
    int key;
    char *value;
    struct s_dict *next;
} t_dict;

t_dict *parse_dict(const char *filename);
void free_dict(t_dict *dict);

#endif
