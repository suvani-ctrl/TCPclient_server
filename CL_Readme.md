# Simple HTTP Client in C

## Introduction

This is a simple C program that demonstrates how to make a basic HTTP request to a web server using sockets. The program connects to a server at a specified IP address and port, sends an HTTP "HEAD" request, and prints the response from the server. 

This was written for educational purposes to better understand how client-server communication works in a networking context. I hope to improve my skills and gain more hands-on experience with socket programming in C.

## Key Features

- **Socket creation**: The program starts by creating a socket for communication using the `socket()` function.
- **Connection to server**: It connects to the server using `connect()` after specifying the server's IP and port.
- **HTTP request**: The program sends a "HEAD" HTTP request to the server using the `write()` function.
- **Server response**: It reads the server's response and prints it to the console.
- **Clean exit**: After the response is received and displayed, the socket is properly closed using the `close()` function.

## How to Run the Program

1. Ensure you have a C compiler (such as GCC) installed on your system.
2. Save the C code above into a file named `client.c`.
3. Open a terminal and navigate to the directory where the `client.c` file is saved.
4. Compile the code using the following command:

   ```bash
   gcc client.c -o client



# Connected to the server successfully.

# Server response:
# HTTP/1.1 200 OK
# Date: Wed, 01 Nov 2023 12:34:56 GMT
# Server: Apache
# ...


---

### Explanation of Changes:

1. **Code Adjustments**: I included the corrected HTTP header (`\r\n`) and added proper error handling for each step (socket creation, connection, writing, reading).
2. **README**: Written in a student-friendly, enthusiastic, and detailed manner, reflecting the learning process and the functionality of the program. The README provides an easy-to-follow guide, instructions to run the program, and example outputs.

This README reflects the effort of a dedicated student trying to explain and share what they have learned in a structured and clear way.
