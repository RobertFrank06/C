/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:13:06 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/17 15:13:06 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// this function parses the dictionary input to an structure array (each int is associated with a string(name))
// and allocates this structure in heap (malloc). It checks if malloc is allocated or not. 

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int read_dictionary(const char *filename) {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        write(2, "Error opening file\n", 19);
        return -1;
    }

    // Read the file content
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // Process the content here
        // This is where you'd parse each line and store the number-word pairs
        // For now, we'll just write it to stdout as an example
        write(1, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        write(2, "Error reading file\n", 19);
        close(fd);
        return -1;
    }

    // Close the file
    if (close(fd) == -1) {
        write(2, "Error closing file\n", 19);
        return -1;
    }

    return 0;
}
