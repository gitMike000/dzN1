#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <ip4> <port>" << std::endl;
        return EXIT_FAILURE;
    }

    sockaddr_in serv_addr;
    if (inet_pton(AF_INET, argv[1], &(serv_addr.sin_addr))<1)
    {
        std::cout << "Ip address not valid" << std::endl;
        return EXIT_FAILURE;
    };
    const int port { std::stoi(argv[2]) };
    serv_addr.sin_port=htons(port);
    serv_addr.sin_family=PF_INET;

    char ip4[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(serv_addr.sin_addr), ip4, INET_ADDRSTRLEN);
    std::cout << "Starting client for "
              <<  ip4
              << " on the port " << port << "...\n";

    socket_wrapper::SocketWrapper sock_wrap;
    socket_wrapper::Socket sock = {AF_INET, SOCK_DGRAM, IPPROTO_UDP};
    if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }


    if (connect(sock, reinterpret_cast<const sockaddr*>(&serv_addr), sizeof(serv_addr)) != 0)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        // Socket will be closed in the Socket destructor.
        return EXIT_FAILURE;
    }


    char buffer[256];
    char buffer_rec[256];

    struct sockaddr_in client_address = {0};
    socklen_t client_address_len = sizeof(sockaddr_in);
    ssize_t recv_len = 0;

    bool run = true;
    std::cout<<"Enter message ('exit' to quit)"<<std::endl;

    while (run)
    {
        std::cin>>buffer;
        sendto(sock, buffer, sizeof (buffer), 0, reinterpret_cast<const sockaddr *>(&serv_addr),
               sizeof(serv_addr));
        recv_len = recvfrom(sock, buffer_rec, sizeof(buffer_rec) - 1, 0,
                            reinterpret_cast<sockaddr *>(&client_address),
                            &client_address_len);
        if (recv_len > 0)
        {
            std::cout<<buffer_rec<<std::endl;
        };

        //Exit
        if  ( std::string(buffer).find("exit") == 0 )
        {
            std::cout << "Breaking" << std::endl;
            run=false;
        };

        std::cout << std::endl;
    }

    close(sock);

    return EXIT_SUCCESS;
}

