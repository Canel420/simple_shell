![“The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

# Simple Shell

This is an implementation of a simple bash shell for linux operating systems
interaction. It has limited power giving that it can only run
simple commands for file management and system navigation.

## Compilation

To start the shell you need to compile the files given in the repository and
run the executable. You will see a **$** prompt when shell is waiting for a
command from the user

''''
 gcc -Wall -Werror -Wextra -pedantic *.c

''''


## Commands

Some of the commands that can be execute on the terminal are the following:

* ls - List current directory contents.
* man - Print manual for a command.
* pwd - Print working directory.
* cd - Change directory.
* mkdir - Create a directory.
* echo - Prints text to the terminal window.
* touch - Creates a file.
* mv - Move or rename a file.
* less - View the contents of a text file.
* cat - Read a file, create a file, and concatenates files.

## Built-in Functions

These are the functions that comes with the shell program and are not part of
the kernel services.

* exit - exits the shell.

* env - Prints the current environment.

## Exit commands and the Shell

To exit the shell, built-in function **exit** can be used. End of files commands
like **ctrl-c** and **ctrl-d** are also allowed.

## Files

* sim_shell.c - Main program which supports the prompt and general executions.
* shell.h - Header file of the shell. Contains functions prototypes, definitions and requiered libraries.
* split.c - Function to tokenize the standar input lines.
* paths.c - Function that searchs for commands in PATH enviromental variable.
* execution.c - Function to create new processes for execution.

## Comments

**Use under your own risk!**