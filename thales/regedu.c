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

 char rut[11];
 char nivel[16];
 char centro[61];
 char titulo[61];

memset (nivel, 0, sizeof nivel);
memset (rut, 0, sizeof rut);
memset (centro, 0, sizeof centro);
memset (titulo, 0, sizeof titulo);

printf("\n-------- RECIBIDO --------\n\n");

// tx_in tiene la tx de entrada
sscanf(tx_in->datos,"%10c %15c %60c %60c",rut,nivel,centro,titulo);
printf( "Llego desde el formulario: %s \n", tx_in->datos);

printf("Rut: %s \n", rut);
printf("nivel: %s \n", nivel);
printf("centro: %s \n", centro);
printf("titulo: %s \n", titulo);


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

	sprintf(mensaje.texto.dat, "%6s%s%s%s%s", "regedu", rut, nivel, centro, titulo);

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


