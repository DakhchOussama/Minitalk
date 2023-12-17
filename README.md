# Minitalk Project

Welcome to the Minitalk project! 🚀 This project involves creating a communication program in the form of a client and a server using UNIX signals.

## Project Overview

- **Executable Files:** `client` and `server` 📁
- **Makefile:** Provide a Makefile to compile your source files. It must not relink. 🛠️
- **Libft:** You can use your libft. 📚
- **Error Handling:** Thoroughly handle errors to prevent unexpected exits (e.g., segmentation fault, bus error, double free). Your program mustn't have memory leaks. 🚫
- **Global Variables:** You can have one global variable per program (one for the client and one for the server), but justify their use. 🌐
- **Allowed Functions:**
  - `write`
  - `ft_printf` and any equivalent you coded
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`

## Mandatory Part 🛠️

- The server must be started first and print its PID after launch.
- The client takes two parameters: The server PID and the string to send.
- The client must send the string to the server.
- Once received, the server must print the string quickly.

**Note:** "Quickly" means that if you think it takes too long, then it probably is. 1 second for displaying 100 characters is considered too much.

- The server should be able to receive strings from several clients in a row without needing to restart.
- Communication between the client and server must be done only using UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Bonus List

- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support!

## How to Use 🚀

1. Clone the repository to your local machine.
2. Navigate to the project folder.
3. Build the project using the provided Makefile.
   ```
   $ make
   ```
Start the server:
  ```
  $ ./server
  ```
Launch the client with the server PID and the string to send:
```
  $ ./client [server_pid] [your_string]
```
