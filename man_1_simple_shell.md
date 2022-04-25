% HSH(1) hsh 4.2.0
% Manu, Teo y Karol
% April 2022

# NAME
hsh - Handicapped Shell - standard command language interpreter

#SYNOPSIS

hsh [command] [option] [file]

# DESCRIPTION
The hsh utility is a command language interpreter that shall execute commands
read from a command line string, the standard input, or a specified file.
The application shall ensure that the commands to be executed are expressed in
the language of the sh - shell command language.

Does not have input/output redirection. Neither arrow keyboard keys can be use
for hsh displacement.

# OPERANDS
## command_file - The pathname of a file containing commands. If the
                  pathname contains one or more <slash> characters, the
                  implementation attempts to read that file; the file
                  need not be executable.
		  * The implementation shall attempt to read that file
                    from the current working directory.
		  * If the file is not in the current working
                    directory, the implementation may perform a search
                    for an executable file using the value of PATH.

## command_name - A string assigned to special parameter 0 when executing
                  the commands in command_string.  If command_name is not
                  specified, special parameter 0 shall be set to the
                  value of the first argument passed to hsh from its
                  parent, which is normally a pathname used to execute the
		  sh utility.
# EXTENDED OPTIONS

## end-of-file - Interpreted as the end of input in sh.

 <control>‐D Ends hsh program.

# BUILT-IN FUNCTIONS

env - Write in standar output the environment of the user's session.

exit - Ends the hsh program with exit status 0.


#EXIT STATUS
Is NOT handled.

# EXAMPLES
1. Execute a shell command from a string:

   ./hsh echo my dinosaur

2. Read a te from a fixt file from current directory:

   ./hsh less TihsIsaFile.txt

# BUGS

It has a segmentation fault from an invalid read of size possibly in a malloc
mrmory allocation size.

Have some memory leaks.

Report more aerrors to <4521@holbertonschool.com>

# COMMENTS

Use under your own risk!