# minitalk
Minitalk is a simple client-server program that enables inter-process communication by sending messages as signals between processes in a Unix environment.
------------------
Minitalk is a simple communication program between processes using UNIX signals. It consists of a server and a client: the client sends messages to the server one bit at a time, using signals to represent bits, and the server reconstructs and displays the message.

## Features

- Inter-process communication using `SIGUSR1` and `SIGUSR2`
- Sending and receiving messages bit by bit
- Handling multiple messages in sequence
- Basic error handling and acknowledgment

## How it works

- The server waits for signals and reconstructs the message from received bits.
- The client converts the message to bits and sends signals corresponding to 0s and 1s.
- After receiving a message, the server can send an acknowledgment to the client.

## Usage

Compile with `make` or `make bonus`, then run the server and client in separate terminals:

```bash
./server
./client <server_pid> "Your message here"

