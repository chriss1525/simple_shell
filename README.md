# Simple Shell

This is a simple implementation of a Unix shell in C. It can be used to execute basic shell commands and handle I/O redirection.

## Getting Started

To get started with the Simple Shell, you'll need to have a C compiler installed on your machine. You can download the GNU Compiler Collection (GCC) from the official website: https://gcc.gnu.org/

Once you have GCC installed, you can clone this repository to your local machine:

```bash
git clone https://github.com/chriss1525/simple_shell.git
```

## Usage

To use the Simple Shell, navigate to the cloned repository and run the following command:

```go
gcc *.c
```

This will compile the shell program. You can then run the shell by entering the following command:

```bash
./hsh
```

You should see a command prompt (>) indicating that the shell is ready to accept commands. You can enter any basic shell command, such as ls or cd, and the shell will execute it.

The Simple Shell also supports I/O redirection using the > and < symbols. For example, you can redirect the output of a command to a file like this:

```bash
ls > files.txt
```

This will create a file called files.txt and write the output of the ls command to it.

To exit the Simple Shell, simply press ctrl + C.

### Contributing


If you'd like to contribute to this project, feel free to fork the repository and submit a pull request.
