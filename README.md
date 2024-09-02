# Pipex

<img width="659" alt="Pipex" src="https://github.com/user-attachments/assets/a38a040b-adda-4da9-b2f4-6f688f88417a">

## Description

**Pipex** is a project designed to help you understand and implement the concept of pipes in UNIX-based systems. The goal is to create a program that mimics the behavior of shell pipes by redirecting the output of one command to the input of another. This project will deepen your understanding of process creation, inter-process communication, and file handling in C.

## Project Objectives

- **UNIX Mechanisms**: Gain in-depth knowledge of pipes and how they work in UNIX systems.
- **C Programming**: Improve your skills in C, focusing on system calls and error handling.
- **Process Management**: Learn how to manage multiple processes and handle inter-process communication.

## Requirements

- Implement a program named `pipex` that takes four arguments: `file1`, `cmd1`, `cmd2`, and `file2`.
- The program should replicate the behavior of the following shell command:
  
  ```bash
  < file1 cmd1 | cmd2 > file2
  ```
- Your project must be written in C and adhere to the coding standards of the school.
- Ensure thorough error handling, avoiding unexpected quits due to segmentation faults, bus errors, double free, etc.
- The program must not have memory leaks.

## Compilation

To compile the project, use the provided Makefile with the following rules:

- **`make`** or **`make all`**: Compile the pipex program.
- **`make clean`**: Remove object files.
- **`make fclean`**: Remove object files and the executable.
- **`make re`**: Recompile the project.

  ```bash
  $ make
  ```

## Usage

To run the **`pipex`** program, use the following command structure:

```bash
$ ./pipex file1 cmd1 cmd2 file2
```

This will execute **`cmd1`** with **`file1`** as input, then pipe the output to **`cmd2`**, and finally save the result in **`file2`**.

### Example

```bash
$ ./pipex infile "ls -l" "wc -l" outfile
```

This should behave like:

```bash
$ < infile ls -l | wc -l > outfile
```

## Bonus

You can earn extra points by implementing the following features:

- **Multiple Pipes**: Allow the program to handle more than two commands, chaining them together as in:

```bash
$ ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

This should behave like:

```bash
$ < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
- **Here Document** Support: Implement support for **`here_doc`** where the first parameter is "here_doc":

```bahs
$ ./pipex here_doc LIMITER cmd cmd1 file
```

This should behave like:

```bash
$ cmd << LIMITER | cmd1 >> file
```
