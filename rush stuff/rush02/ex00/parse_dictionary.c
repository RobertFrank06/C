/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:13:06 by ipuig-pa          #+#    #+#             */
/*   Updated: 2024/08/17 21:55:48 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// this function parses the dictionary input to an structure array (each int is associated with a string(name))
// and allocates this structure in heap (malloc). It checks if malloc is allocated or not. 

// if there are 2 input arguments, we should take the first argument as the dict_filename. otherwise, we give the reference dictionary.

#define BUFFER_SIZE 1024

typedef struct{
	char	*number;
	char	*letters;
} Dict_entry;

typedef struct{
	Dict_entry	*entries;
	int			entry_num;
} Dictionary;


//function to open, read and close dictionary file. 
//fd (output of open) is file descriptor (it is a non-negative integer created on success, in contraposition to -1 when we get an error)
//bytes_read (output of read) is the number of bytes that read function read on success, 0 if it reaches the end of file and -1 if there is an error. 
//ssize_t is a variable type (a signed integer type used to represent sizes or counts of bytes. It's similar to size_t, but ssize_t can represent negative values.). Using ssize_t allows these functions to return a negative value to indicate an error, while still being able to represent large positive values for successful operations. needs unistd.h

/*while loop on read: How the loop works:

Each iteration of the loop reads up to BUFFER_SIZE bytes from the file.
The loop continues as long as read() returns a positive number (indicating bytes were read).
When read() returns 0, it means we've reached the end of the file, and the loop terminates.*/
int	open_read_close_dict(const char *filename)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	int	fd = open(filename, O_RDONLY)
	if (fd == -1)
		/*error;*/
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		while (i < 1024)
		{
			//ESTIC AQUI!!! cridar aqui l-altra funcio de parse, i donar d-input el pointer al buffer. Posar aquesta  part a l-altra funcio
			if (buffer[i] == ':')
			{
				//agafar la part anterior si son numeros. afafar la part posterior si son lletres. 
			}
		}
	}
	if (bytes_read == -1)
	{
		//error handling
		close(fd);
		return(-1);
	}
	if (close(fd) == -1)
	{
		//error
	}
	return(0)
}

Dictionary	*parseDictionary(const char *filename)
{
	
}

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
