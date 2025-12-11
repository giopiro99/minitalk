# 📡 Minitalk - UNIX Signal Communication

**Minitalk** is a small data exchange program developed as part of the **42 School** curriculum. It explores the concept of **Inter-Process Communication (IPC)** by implementing a client-server architecture that communicates solely using UNIX signals.

The challenge is to transmit strings of data between two separate processes (a Client and a Server) using only two signals: `SIGUSR1` and `SIGUSR2`.

## ✨ Features

### Mandatory Part
* **Client-Server Architecture:** Two separate programs communicating via PID (Process ID).
* **Signal Handling:** Uses `sigaction` to intercept and process signals.
* **Bitwise Transmission:** Breaks down messages into bits and reconstructs them on the receiving end.
* **Compatibility:** Works with standard ASCII characters.

### 🌟 Bonus Part
* **Acknowledgement:** The server sends a signal back to the client confirming that the message has been fully received.
* **Unicode Support:** Capable of handling complex characters (e.g., emojis 😃, extended ASCII).
* **Robustness:** Handles rapid signal transmission without losing data.

---

## 🏗️ How It Works

Since we are limited to only two signals (`SIGUSR1` represents `0` and `SIGUSR2` represents `1`), the data must be transmitted **bit by bit**.

1.  **The Client:**
    * Takes a string and the Server PID as arguments.
    * Iterates through every character of the string.
    * Breaks each character down into 8 bits.
    * Sends `SIGUSR1` for a `0` bit and `SIGUSR2` for a `1` bit to the Server.
    * Waits for acknowledgement (in Bonus).

2.  **The Server:**
    * Starts and prints its PID.
    * Enters an infinite loop waiting for signals.
    * Upon receiving a signal, it sets the corresponding bit in a temporary character variable.
    * Once 8 bits are received, it prints the reconstructed character and resets the bit counter.

---

## 🚀 Installation & Usage

### 1. Compilation
Use the provided `Makefile` to compile the project.

```bash
# Clone the repository
git clone [https://github.com/giopiro99/minitalk.git](https://github.com/giopiro99/minitalk.git)
cd minitalk/minitalk

# Compile Mandatory (server & client)
make

# Compile Bonus (server_bonus & client_bonus)
make bonus

./server
# Output: Server PID: 12345

./client [SERVER_PID] "Hello World!"
# Example: ./client 12345 "Hello 42!"
```

```text
📂 Project Structure
minitalk/
├── Makefile
├── libft/                  # Custom Libft library
├── mandatory/
│   ├── client.c            # Client implementation
│   └── server.c            # Server implementation
└── bonus/
    ├── client_bonus.c      # Bonus Client with Ack
    └── server_bonus.c      # Bonus Server with Ack
```
🧠 What I Learned

UNIX Signals: Deep understanding of signal() vs sigaction(), signal masks, and handlers.

Bitwise Operators: manipulating data at the bit level (>>, <<, |, &) to serialize and deserialize data.

Concurrency: Handling asynchronous events where the timing of signal arrival is unpredictable.

Process Management: Understanding PIDs and basic IPC.
