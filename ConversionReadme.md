# 🌐 Network Byte Order Conversion in C

This is a simple C program that demonstrates how to convert numbers between **host byte order** and **network byte order** using the `htons()` and `htonl()` functions from the `<arpa/inet.h>` library.

## 🛠️ **Purpose**
The program:
1. 🔄 Converts a **16-bit port number** (`host_port`) from **host byte order** to **network byte order** using `htons()`.
2. 🔄 Converts a **32-bit IP address** (`host_address`) from **host byte order** to **network byte order** using `htonl()`.
3. 🖨️ Prints both the **host-ordered** and **network-ordered** values of the port and IP address.

---

## 📂 **Code Overview**

### Input:
- **`host_port`**: A port number (16-bit) in host byte order.
- **`host_address`**: An IP address (32-bit) in host byte order.

### Output:
The program prints:
- The **host-ordered port** and **network-ordered port**.
- The **host-ordered address** and **network-ordered address**.

---

## 🖥️ **How to Run**

1. **Compile** the program using GCC:

   gcc -o network_order network_order.c


Host Ordered port: 0x3039
Network Ordered port: 0x3930
Host Ordered address: 0x12345678
Network Ordered address: 0x78563412
