Socket Programming in C 🖥️🔌
Description 📜
This is a simple server program written in C for socket programming. It demonstrates the creation of a server socket, binding it to an IP and port, listening for incoming client connections, and sending a message to the client. This is a basic example of how to handle communication between a server and a client over a network.

Features ✨
Server creates a socket 🛠️
Binds to IP and port (8080) 🌐
Listens for incoming client connections 👂
Sends a message to the client 📩
Closes the socket after communication is complete 🔒
Prerequisites 🛑
Basic knowledge of C programming 📝
A Linux-based environment or C compiler for compilation and execution 🖥️
How to Run 🔥
Clone the repository to your local machine:
 
git clone https://github.com/your-username/socket-programming-in-c.git
Navigate into the project directory:
 
cd socket-programming-in-c
Compile the program:
 
gcc server.c -o server
Run the server:
 
./server
The server will start listening on port 8080. You can connect to it using a client program, and it will send a message back once the connection is established.
