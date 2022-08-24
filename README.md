<div align="center">
   <h1>blck-shell</h1>

   <em>A glorified command-line interpreter.</em>

   <img src="https://img.shields.io/badge/C-C11-blue?style=flat-square&logo=c">
</div>

---

# About

**blck-shell** is a simple command-line interpreter. In likeliness with other command-line interpreters, all it does is it creates a child process that executes a command the a user enters and then it prompts the user for more input,when it has finished executing the command.

**blck-shell** is an interactive loop, that repeatedly prints a prompt, parses the input, executes the command specified on that line of input, and waits for the command to finish. The interactive loop is broken when an `exit` is executed.

# Usage

There are a couple of ways in which the **blck-shell** can be used.

The easiest way is to just execute the interactive loop:

```
./bsh
```

Another way, is to execute the interactive loop, with a batch file (file that consists a set of commands) as an argument:

```
./bsh <FILENAME>
```