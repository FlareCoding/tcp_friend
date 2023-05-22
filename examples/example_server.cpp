#include <iostream>
#include "tcp_friend.hpp"
using namespace tcp_friend;

#define SERVER_PORT 10000

int main() {
	// Bind the server socket
	tcp_server_socket server_socket;
	if (!server_socket.bind("0.0.0.0", SERVER_PORT)) {
		printf("Failed to bind server socket to port %i\n", SERVER_PORT);
		server_socket.close();
		return 1;
	}

	printf("[*] Listening for connections...\n");

	// Start listening for 1 incoming client connection
	if (!server_socket.listen(1)) {
		printf("Failed to listen on port %i\n", SERVER_PORT);
		server_socket.close();
		return 1;
	}

	// Accept the incoming connection
	auto connection = server_socket.accept();
	if (!connection->is_alive()) {
		printf("Failed to accept a connection on port %i\n", SERVER_PORT);
		server_socket.close();
		return 1;
	}

	printf("'%s' connected on port %i\n", connection->get_address().c_str(), connection->get_port());

	// Receive a message from the client
	std::string msg;
	connection->recv_string(msg);
	printf("[*] Client said '%s'\n", msg.c_str());

	// Send a server response back
	connection->send_string("hello from server");

	connection->close();
	server_socket.close();
	return 0;
}
