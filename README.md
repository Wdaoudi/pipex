# Pipex
<div align="center">
  <img src="https://img.shields.io/badge/norminette-passing-success"/>
  <img src="https://img.shields.io/badge/42-project-000000"/>
</div>

## 💡 About
> A program that simulates shell pipe behavior, handling command execution and file redirection.

This project implements the functionality of the shell pipe operator (|) in C, allowing commands to be chained together with their input/output being redirected between files and processes. It provides a deep understanding of Unix processes, file descriptors, and pipe mechanisms.

## 🛠️ Usage
### Requirements
- GCC compiler
- Make
- Unix-based operating system
- Basic shell commands knowledge

### Instructions
**1. Compiling**
```shell
$ git clone https://github.com/wdaoudi-/pipex
$ cd pipex
$ make
```

**2. Running the program**
```shell
$ ./pipex file1 cmd1 cmd2 file2
```
This will behave like: `< file1 cmd1 | cmd2 > file2`

Example:
```shell
$ ./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to: `< infile ls -l | wc -l > outfile`

## 📋 Features
### Core Features
| Feature | Description |
|---------|-------------|
| Pipe Simulation | Replicates the behavior of shell pipes |
| File Redirection | Handles input/output file redirection |
| Command Execution | Executes shell commands with arguments |
| Error Handling | Robust error management for various scenarios |

### Bonus Features
- Multiple pipe handling (`cmd1 | cmd2 | cmd3 ... | cmdn`)
- Here_doc support (`<<` and `>>` operators)

## ⚙️ Implementation Details
### Architecture
- Uses fork() to create child processes for command execution
- Implements pipe() for inter-process communication
- Manages file descriptors for input/output redirection
- Handles PATH resolution for command execution
- Memory management with proper cleanup

### Technical Choices
- Written in C
- Follows 42 School's Norm
- Uses allowed functions only:
  - open, close, read, write
  - malloc, free
  - perror, strerror
  - access, dup, dup2
  - execve, exit, fork
  - pipe, unlink
  - wait, waitpid

## 🚨 Error Management
- Non-existent input file handling
- Invalid command handling
- Memory allocation failure handling
- File permission errors
- Pipe creation errors
- Fork failures
- Command execution errors

## 🧪 Testing
```shell
# Basic test
$ ./pipex infile "grep hello" "wc -w" outfile

# Here_doc test (bonus)
$ ./pipex here_doc LIMITER cmd cmd1 file
```

## 📚 Resources
- Unix Processes Documentation
- File Descriptor Documentation
- Pipe System Call Manual
- Fork System Call Documentation

## 🗣️ About
### Contributing
Feel free to submit issues and enhancement requests!

### License
This project is part of 42 School's curriculum.

---
Made with ❤️ by wdaoudi-
