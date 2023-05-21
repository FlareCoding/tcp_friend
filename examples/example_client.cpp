#include <iostream>
#include "tcp_friend.hpp"
using namespace tcp_friend;

#define SERVER_PORT 10000

int main() {
	tcp_connection_socket connection = tcp_client_socket::connect("127.0.0.1", SERVER_PORT);
	if (!connection.is_alive()) {
		printf("Failed to connect to server on port %i\n", SERVER_PORT);
		return 1;
	}

	// Send a client message
	connection.send_string("hello client");

	// Receive the server response
	std::string msg;
	connection.recv_string(msg);
	printf("[*] Server said '%s'\n", msg.c_str());

	connection.close();
	return 0;
}
