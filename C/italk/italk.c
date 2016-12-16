#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
   struct sockaddr_in sv_addr, cl_addr;
   socklen_t sv_len, cl_len;
   
   sv_len = sizeof sv_addr;
   cl_len = sizeof cl_addr;
   
   if(getsockname(0, (struct sockaddr *)&sv_addr, &sv_len) < 0){
      perror("getsockname");
      return 1;
   }
   
   fprintf(stderr, "getsockname: addr = %s, port = %d\n",
      inet_ntoa(sv_addr.sin_addr), ntohs(sv_addr.sin_port));
   
   if(getpeername(0, (struct sockaddr *)&cl_addr, &cl_len) < 0){
      perror("getpeername");
      return 2;
   }
   
   fprintf(stderr, "getpeername: addr = %s, port = %d\n",
      inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));
   
   write(1, "Responce OK.\n", 13);
   return 0;
}