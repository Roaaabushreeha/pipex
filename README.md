# pipex

**pipex** is a project from the **42 School Curriculum** that focuses on understanding UNIX processes, pipes, and file descriptors.  
The objective is to recreate the behavior of shell piping between commands, using system calls like `fork`, `execve`, `pipe`, and `dup2`.

---

## 📋 Project Description

The program mimics the shell behavior when piping commands together with input/output redirection.  

Example usage (equivalent to shell command):
```bash
< file1 cmd1 | cmd2 > file2
