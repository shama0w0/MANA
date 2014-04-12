#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct trans
{
int len;
char datos[2000];
};

void proceso (char *aci , struct trans *tx_in, struct trans *tx_out, struct trans *tx_sa)
{

 char nombre[31];
 char rut[11];
 char fecha_n[31];
 char sueldo[16];
 char cargo[31];
 char telefono[16];
 char direccion[61];
 char correo[61];
 char estado[16];

memset (nombre, 0, sizeof nombre);
memset (rut, 0, sizeof rut);
memset (fecha_n, 0, sizeof fecha_n);
memset (sueldo, 0, sizeof sueldo);
memset (cargo, 0, sizeof cargo);
memset (telefono, 0, sizeof telefono);
memset (direccion, 0, sizeof direccion);
memset (correo, 0, sizeof correo);
memset (estado, 0, sizeof estado);

printf("\n-------- RECIBIDO --------\n\n");

// tx_in tiene la tx de entrada
sscanf
(tx_in->datos,"%10c %30c %30c %15c %30c %15c %60c %60c %15c",rut,nombre,fecha_n,sueldo,cargo,telefono,direccion,correo,estado);
printf( "Llego desde el formulario: %s \n", tx_in->datos);

printf("Nombre: %s \n", nombre);
printf("Rut: %s \n", rut);
printf("Fecha: %s \n", fecha_n);
printf("Sueldo: %s \n", sueldo);
printf("Cargo: %s \n", cargo);
printf("Telefono: %s \n", telefono);
printf("Direccion: %s \n", direccion);
printf("Correo: %s \n", correo);
printf("Estado: %s \n", estado);

printf("variables listas \n");

// Comunicacion con el demonio


int qid,pid;

        struct msgbuf {
                long mtype;
                struct {
                        int pid;
                        char dat[2000];
                } texto;
        } mensaje, respuesta;

        qid = msgget(589000, 0666);
        pid = getpid();

        // Limpiamos la estructura del mensaje
        memset(&mensaje, 0, sizeof mensaje);

        // guardamos en la estructura mensaje lo que se quiere enviar al demonio

        sprintf(mensaje.texto.dat, "%6s%s%s%s%s%s%s%s%s%s", "modemp", rut, nombre, fecha_n,
sueldo, cargo, telefono, direccion, correo, estado);

        mensaje.mtype = 1;
        mensaje.texto.pid = pid;
	msgsnd(qid, &mensaje, strlen(mensaje.texto.dat)+4,0);

        // Limpiamos la estructura de respuesta
        memset(&respuesta, 0, sizeof respuesta);

        msgrcv(qid, &respuesta, 2000, pid, 0);

        printf("\n\n -------- RESPUESTA --------\n\n");

        printf("respuesta demonio: %s\n\n", respuesta.texto.dat);

        // en tx out se debe dejar la tx se salida
        tx_out->len= sprintf (tx_out->datos,"%s", respuesta.texto.dat);


}











