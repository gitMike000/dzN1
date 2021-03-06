#pragma once

extern "C"
{
#ifdef _WIN32
#    include <ws2tcpip.h>
#    include <winsock2.h>

	/* See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 */
#    ifndef _WIN32_WINNT
#        define _WIN32_WINNT 0x0501  /* Windows XP. */
#    endif
typedef SOCKET SocketDescriptorType;
typedef int ssize_t;
#	if !defined(in_addr_t)
#include <cinttypes>
typedef uint32_t in_addr_t;
#	endif
#else
/* Assume that any non-Windows platform uses POSIX-style sockets instead. */
#    include <sys/socket.h>
#    include <arpa/inet.h>
#    include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#    include <unistd.h> /* Needed for close() */
typedef int SocketDescriptorType;
#endif

// Defined for Windows Sockets.
#if not defined(INVALID_SOCKET)
#    define INVALID_SOCKET (-1)
#endif

// Defined for Windows Sockets.
#if not defined(SOCKET_ERROR)
#    define SOCKER_ERROR (-1)
#endif

}
