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
   char datos[2000];
};

void proceso(char *aci, struct trans *tx_in, struct trans *tx_out, struct trans *tx_sa)
{

   int pid,qid;
   char nomc[61], descrip[1001], res[3];
   
   memset(nomc,'\0',sizeof nomc);
   memset(descrip,'\0',sizeof descrip);
   memset(res,'\0',sizeof res);
   
   sscanf(tx_in->datos,"%60c",nomc);
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
      save("buscar",&pid,"TXIN",tx_in->datos);
      memset(&mensaje,0,sizeof mensaje);
      memset(&respuesta,0,sizeof respuesta);
      sprintf(mensaje.texto.datos,"%6s%60s","buscar",nomc);
      mensaje.mtype = 1;
      mensaje.texto.pid = pid;
      msgsnd(qid,&mensaje,strlen(mensaje.texto.datos)+4,0);
      memset(&respuesta, 0, sizeof respuesta);
      msgrcv(qid,&respuesta,2000,pid,0);
      //sscanf(respuesta.texto.datos,"%2c",res);

   tx_out->len = sprintf(tx_out->datos,"%s",respuesta.texto.datos);
}