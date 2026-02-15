*This project has been created as part of the 42 curriculum by yafshar, shhidrob.*

# minishell

## Description
**minishell** is a simplified UNIX shell written in C.
It provides an interactive prompt, reads user input using `readline`, parses commands, performs environment variable expansion, handles pipes and redirections, and executes built-in commands or external programs using UNIX system calls.

The goal of this project is to understand:
- command parsing and tokenization
- process creation and execution (`fork`, `execve`, `waitpid`)
- pipes and file descriptor redirection (`pipe`, `dup2`, `open`, `close`)
- environment variable handling and exit status management
- signal handling in interactive programs
- memory management and error handling

---

## Instructions

### Build
```bash
make
```

Optional:
```bash
make clean
make fclean
make re
```

### Run
```bash
./minishell
```

### Example usage
```bash
minishell$ echo hello
minishell$ echo $HOME
minishell$ ls | wc -l
minishell$ cat < infile | grep hello > out.txt
minishell$ echo text >> out.txt
minishell$ export A=42
minishell$ unset A
minishell$ env
minishell$ exit 0
```

---

## Resources

### References
The following references were used to understand expected shell behavior and system calls:
- GNU Bash manual
- POSIX shell documentation
- man pages


### AI usage disclosure
AI tools were used as a learning and debugging support tool, specifically for:
- understanding UNIX system calls and their error cases
- discussing parsing and execution architecture ideas
- identifying edge cases involving pipes, redirections, heredoc, and expansions
- suggesting debugging strategies for memory leaks, file descriptor handling, and signal behavior

---

## Authors
- yafshar
- shhidrob