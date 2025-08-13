# Minishell

A Unix-like shell implementation written in C, created as a learning project to understand low-level system programming, process management, and shell design.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

## Project Overview

**Minishell** is a minimal shell project that emulates the behavior of standard Unix shells. It allows users to interact with their operating system through a command-line interface, running commands, handling pipes, redirections, and supporting built-in shell functionalities.

The project is developed primarily in C, focusing on replicating fundamental shell features as a way to deepen understanding of process control, file descriptors, signal handling, and job control in Unix-like operating systems with the help of my colleague [Luis Ribeiro](https://github.com/LuirR91).

## Features

- Command parsing and execution
- Built-in commands (`cd`, `echo`, `pwd`, `exit`, etc.)
- Input and output redirection (`>`, `<`, `>>`)
- Pipes (`|`) for chaining commands
- Environment variable management
- Signal handling (e.g., `Ctrl+C` interruptions)
- Error handling and informative messages

## Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/dde-carv/Minishell.git
   cd Minishell
   ```

2. **Build the project:**
   ```sh
   make
   ```
   This will generate the `minishell` executable in the project directory.

## Usage

Run the shell:

```sh
./minishell
```

Once inside Minishell, you can enter commands as you would in a typical Unix shell. For example:

```sh
echo Hello, world!
ls -l | grep minishell
cat file.txt > output.txt
```

Use `exit` to leave the shell.

---
