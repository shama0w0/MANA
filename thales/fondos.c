#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

struct trans
{
   int len;
   char datos[2000];
};

void proceso(char *aci, struct trans *tx_in, struct trans *tx_out, struct trans *tx_sa)
{


   int pid, qid;
   struct msgbuf
   {
      long mtype;
      struct
      {
         int pid;
         char datos[2000]; 
      }texto;
   }mensaje,respuesta;

   qid = msgget(589000,0666);
   pid = getpid();
   memset(&mensaje,0,sizeof mensaje);	
   memset(&respuesta,0,sizeof respuesta);
   sprintf(mensaje.texto.datos,"%6s","fondos");
   mensaje.mtype = 1;
   mensaje.texto.pid = pid;
   msgsnd(qid,&mensaje,strlen(mensaje.texto.datos)+4,0);
   msgrcv(qid,&respuesta,2000,pid,0);

   tx_out->len = sprintf(tx_out->datos,"%s",respuesta.texto.datos);
} 
