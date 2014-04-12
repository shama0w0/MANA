#include <stdio.h>
#include <time.h>
#include <errno.h>

void save(char *proceso,int *pid,char *tipo,char *datos)
{
   char linea[500],fecha[128];
   time_t tiempo = time(0);
   struct tm *tlocal = localtime(&tiempo);
   strftime(fecha,128,"%d/%m/%y %H:%M:%S",tlocal);
   sprintf(linea,"Proceso: %s | Pid: %d | %s Datos: %s | Fecha: %s\n",proceso,*pid,tipo,datos,fecha);
   FILE *fp;
   fp = fopen("/home/17271897/bitacora.log","a");
   if(fp==NULL)
   {
      *pid=errno;
   }
   fputs(linea,fp);
   fclose(fp);
   return;
}
