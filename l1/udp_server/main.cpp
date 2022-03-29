#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include <socket_wrapper/socket_class.h>
#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>

#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{

  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
    return EXIT_FAILURE;
  }

  socket_wrapper::SocketWrapper sock_wrap;
  const int port { std::stoi(argv[1]) };

  socket_wrapper::Socket sock = { AF_INET, SOCK_DGRAM, IPPROTO_UDP };

  std::cout << "Starting echo server on the port " << port << "...\n";

  if (!sock)
  {
    std::cerr << sock_wrap.get_last_error_string() << std::endl;
    return EXIT_FAILURE;
  }

  sockaddr_in addr = {
      .sin_family = PF_INET,
      .sin_port = htons(port),
  };

  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock, reinterpret_cast<const sockaddr *>(&addr), sizeof(addr)) != 0)
  {
    std::cerr << sock_wrap.get_last_error_string() << std::endl;
    // Socket will be closed in the Socket destructor.
    return EXIT_FAILURE;
  }

  char buffer[256];

  // socket address used to store client address
  struct sockaddr_in client_address = {0};
  socklen_t client_address_len = sizeof(sockaddr_in);
  ssize_t recv_len = 0;

  std::cout << "Running echo server...\n" << std::endl;
  char client_address_buf[INET_ADDRSTRLEN];

  bool run = true;

  while (run)
  {
    // Read content into buffer from an incoming client.
    recv_len = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                        reinterpret_cast<sockaddr *>(&client_address),
                        &client_address_len);

    if (recv_len > 0)
    {
      buffer[recv_len] = '\0';
      char hbuf[NI_MAXHOST] = "\0";
      getnameinfo(reinterpret_cast<sockaddr *>(&client_address),
                  client_address_len, hbuf, sizeof(hbuf), nullptr, 0,
                  NI_NAMEREQD);
      std::cout << "Client with address "
                << inet_ntop(AF_INET, &client_address.sin_addr,
                             client_address_buf,
                             sizeof(client_address_buf) /
                                 sizeof(client_address_buf[0]))
                << "(name=" << hbuf << ")"
                << ":" << ntohs(client_address.sin_port) << " sent datagram "
                << "[length = " << recv_len << "]:\n'''\n"
                << buffer << "\n'''" << std::endl;

      sendto(sock, buffer, recv_len, 0,
             reinterpret_cast<const sockaddr *>(&client_address),
             client_address_len);

      // Exit
      if ( std::string(buffer).find("exit") == 0 ) {
        std::cout << "Breaking" << std::endl;
        run = false;
      };
    }

    std::cout << std::endl;
  }

  close(sock);

  return EXIT_SUCCESS;
}
