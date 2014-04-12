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


   int pid, qid,cod_ent;
   char  opcion[2], aux_cod[11],aux[3];
   struct msgbuf
   {
      long mtype;
      struct
      {
         int pid;
         char datos[2000]; 
      }texto;
   }mensaje,respuesta;
   memset(opcion,'\0',sizeof opcion);
   memset(aux,'\0',sizeof aux);
   sscanf(tx_in->datos,"%1c",opcion);

   if (strcmp(opcion,"n") == 0)
   {
      tx_sa->len = 0;
      memset(tx_sa->datos,'\0',sizeof tx_sa->datos);
   }
   if (tx_sa->len == 0)
   {
      memset(tx_sa->datos,'\0',sizeof tx_sa->datos);
      cod_ent =0;
   }
   else
   {
      memset(aux_cod,'\0',sizeof aux_cod);
      sscanf(tx_sa->datos,"%10d",&cod_ent);
      
   }
   qid = msgget(589000,0666);
   pid = getpid();
   memset(&mensaje,0,sizeof mensaje);	
   memset(&respuesta,0,sizeof respuesta);
   sprintf(mensaje.texto.datos,"%6s%10d","mosemp",cod_ent);
   mensaje.mtype = 1;
   mensaje.texto.pid = pid;
   msgsnd(qid,&mensaje,strlen(mensaje.texto.datos)+4,0);
   msgrcv(qid,&respuesta,2000,pid,0);
   sscanf(respuesta.texto.datos,"%2s%10d",aux,&cod_ent);
   tx_sa->len = sprintf(tx_sa->datos,"%10d",cod_ent);
   tx_out->len = sprintf(tx_out->datos,"%432s",respuesta.texto.datos);
} 
