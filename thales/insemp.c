
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <math.h>
#include "save.h"

struct trans
{
   int len;
   char datos[5000];
};

void proceso(char *aci, struct trans *tx_in, struct trans *tx_out, struct trans *tx_sa)
{

   int pid,qid;
   char nomc[61], descrip[1001], res[3];
   
   memset(nomc,'\0',sizeof nomc);
   memset(descrip,'\0',sizeof descrip);
   memset(res,'\0',sizeof res);
   struct msgbuf
   { 
      long mtype;
      struct
      {
         int pid;
         char datos[5000];
      }texto; 
   }mensaje,respuesta;

      qid = msgget(589000,0666); 
      pid = getpid();
      save("insemp",&pid,"TXIN",tx_in->datos);
      memset(&mensaje,0,sizeof mensaje);
      memset(&respuesta,0,sizeof respuesta);
      sprintf(mensaje.texto.datos,"%6s","insemp");
      mensaje.mtype = 1; 
      mensaje.texto.pid = pid;
      msgsnd(qid,&mensaje,strlen(mensaje.texto.datos)+4,0);
      msgrcv(qid,&respuesta,5000,pid,0);
	  //tx_out->len = sprintf(tx_out->datos,"%s","hola");
	  	 tx_out->len = sprintf(tx_out->datos,"%s",respuesta.texto.datos);
}