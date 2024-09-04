/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:32:51 by hnisirat          #+#    #+#             */
/*   Updated: 2024/06/29 15:32:55 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"
#include "convert.h"
#include "utils.h"

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        write(2, "Usage: ./rush-02 [dictionary] number\n", 37);
        return 1;
    }

    char *dict_file = (argc == 3) ? argv[1] : "numbers.dict";
    char *number = (argc == 3) ? argv[2] : argv[1];

    if (!is_positive_number(number)) {
        write(1, "Error\n", 6);
        return 1;
    }

    t_dict *dict = parse_dict(dict_file);
    if (!dict) {
        write(1, "Dict Error\n", 11);
        return 1;
    }

    char *result = convert_number(dict, number);
    if (result) {
        write(1, result, strlen(result));
        write(1, "\n", 1);
        free(result);
    } else {
        write(1, "Dict Error\n", 11);
    }

    free_dict(dict);
    return 0;
}
