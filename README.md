# get_next_line

The objective of this project is to implement a function named `get_next_line` that reads text from a file descriptor, one line at a time, until the end of the file or an error occurs. The function should return the line that was read or NULL if there is nothing else to read or if an error occurred.

## Key Features

- Read text from a file descriptor one line at a time
- Return the line that was read
- Include the terminating `\n` character in the returned line (except at the end of the file)
- Manage buffer size dynamically using the `-D BUFFER_SIZE=n` compiler flag
- Bonus: Implement `get_next_line` using only one static variable
- Bonus: Manage multiple file descriptors simultaneously

## Knowledge Gained

- Understanding of static variables in C programming
- Implementation of file I/O operations in C
- Dynamic memory management and buffer handling
