# get_next_line

An implementation of a function that reads and returns one line at a time from a file descriptor.

The project was developed as part of the 42 curriculum and focuses on file descriptors, static variables, memory management, and buffered input.

## About

The main function is:

```c
char *get_next_line(int fd);
```

Each call returns the next available line from the given file descriptor.

The repository also contains a bonus implementation designed to support multiple file descriptors.

The buffer size can be changed at compile time using the `BUFFER_SIZE` macro.

## Getting Started

### Requirements

- GCC or Clang
- A Unix-like environment

Clone the repository:

```bash
git clone git@github.com:Daviddm03/get_next_line-42.git
cd get_next_line-42
```

Create a simple `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror \
    get_next_line.c \
    get_next_line_utils.c \
    main.c \
    -o gnl
```

Run:

```bash
./gnl
```

A custom buffer size can be defined during compilation:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 \
    get_next_line.c \
    get_next_line_utils.c \
    main.c \
    -o gnl
```

## What I Learned

This project helped me understand how buffered reading works and how data can persist between function calls using static variables.

It also required careful memory management because the function needs to preserve unread data while returning each completed line independently.

## Tech

C · File Descriptors · Static Variables · Memory Management
