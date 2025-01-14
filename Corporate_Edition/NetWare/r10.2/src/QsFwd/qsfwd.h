// PROPRIETARY/CONFIDENTIAL. Use of this product is subject to license terms.
// Copyright (c) 2005 Symantec Corporation. All rights reserved.
SOCKET (*sym_socket)(int, int, int);
unsigned long (*sym_inet_addr) (const char FAR *);
struct hostent FAR * (*sym_gethostbyname) (const char FAR *);
int (*sym_connect)(SOCKET, const struct sockaddr FAR *, int);
int (*sym_shutdown)(SOCKET, int);
int (*sym_send) (SOCKET , const char FAR * ,int , int );
int (*sym_recv) (SOCKET , const char FAR * ,int , int );
int (*sym_closesocket) (SOCKET);
int (*sym_select)(int , fd_set FAR *,   fd_set FAR *, fd_set FAR *, const struct timeval FAR *);
int (*sym_startup)(WORD, LPWSADATA);
int (*sym_cleanup)(); 
BYTE majorServerVersion;
BYTE minorServerVersion;
