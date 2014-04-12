/* Processed by ecpg (4.6.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "demonio.pgc"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Incluye el mecanismo de manejo de errores de SQL

#line 1 "/usr/pgsql-9.0/include/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.				*/

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 11 "demonio.pgc"



// Declaracion de variables a usar en SQL
/* exec sql begin declare section */

    
    
    
    

    
    
    
    
    
    
    
    
    
   
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    
    
   
    
    
   
   
    
    
    
    
    
    
    
    
    
    
    
    
   
    
   
    
    
    
    
   
    
   
    
    
   
    
   
   
#line 17 "demonio.pgc"
  struct varchar_SQL_dbname_1  { int len; char arr[ 9 ]; }  SQL_dbname ;
 
#line 18 "demonio.pgc"
  struct varchar_SQL_user_2  { int len; char arr[ 7 ]; }  SQL_user ;
 
#line 19 "demonio.pgc"
  struct varchar_SQL_password_3  { int len; char arr[ 20 ]; }  SQL_password ;
 
#line 20 "demonio.pgc"
  struct varchar_SQL_clave_4  { int len; char arr[ 11 ]; }  SQL_clave ;
 
#line 22 "demonio.pgc"
  struct varchar_SQL_nombre_5  { int len; char arr[ 31 ]; }  SQL_nombre ;
 
#line 23 "demonio.pgc"
  struct varchar_SQL_rut_6  { int len; char arr[ 11 ]; }  SQL_rut ;
 
#line 24 "demonio.pgc"
  struct varchar_SQL_fecha_n_7  { int len; char arr[ 31 ]; }  SQL_fecha_n ;
 
#line 25 "demonio.pgc"
  struct varchar_SQL_sueldo_8  { int len; char arr[ 16 ]; }  SQL_sueldo ;
 
#line 26 "demonio.pgc"
  struct varchar_SQL_cargo_9  { int len; char arr[ 31 ]; }  SQL_cargo ;
 
#line 27 "demonio.pgc"
  struct varchar_SQL_telefono_10  { int len; char arr[ 16 ]; }  SQL_telefono ;
 
#line 28 "demonio.pgc"
  struct varchar_SQL_direccion_11  { int len; char arr[ 61 ]; }  SQL_direccion ;
 
#line 29 "demonio.pgc"
  struct varchar_SQL_correo_12  { int len; char arr[ 61 ]; }  SQL_correo ;
 
#line 30 "demonio.pgc"
  struct varchar_SQL_estado_13  { int len; char arr[ 16 ]; }  SQL_estado ;
 
#line 32 "demonio.pgc"
  struct varchar_SQL_nivel_14  { int len; char arr[ 16 ]; }  SQL_nivel ;
 
#line 33 "demonio.pgc"
  struct varchar_SQL_centro_15  { int len; char arr[ 61 ]; }  SQL_centro ;
 
#line 34 "demonio.pgc"
  struct varchar_SQL_titulo_16  { int len; char arr[ 61 ]; }  SQL_titulo ;
 
#line 36 "demonio.pgc"
 int SQL_count ;
 
#line 37 "demonio.pgc"
  struct varchar_SQL_r1_17  { int len; char arr[ 11 ]; }  SQL_r1 ;
 
#line 38 "demonio.pgc"
  struct varchar_SQL_r2_18  { int len; char arr[ 11 ]; }  SQL_r2 ;
 
#line 39 "demonio.pgc"
  struct varchar_SQL_r3_19  { int len; char arr[ 11 ]; }  SQL_r3 ;
 
#line 40 "demonio.pgc"
  struct varchar_SQL_r4_20  { int len; char arr[ 11 ]; }  SQL_r4 ;
 
#line 41 "demonio.pgc"
  struct varchar_SQL_r5_21  { int len; char arr[ 11 ]; }  SQL_r5 ;
 
#line 42 "demonio.pgc"
  struct varchar_SQL_r6_22  { int len; char arr[ 11 ]; }  SQL_r6 ;
 
#line 43 "demonio.pgc"
  struct varchar_SQL_c1_23  { int len; char arr[ 31 ]; }  SQL_c1 ;
 
#line 44 "demonio.pgc"
  struct varchar_SQL_c2_24  { int len; char arr[ 31 ]; }  SQL_c2 ;
 
#line 45 "demonio.pgc"
  struct varchar_SQL_c3_25  { int len; char arr[ 31 ]; }  SQL_c3 ;
 
#line 46 "demonio.pgc"
  struct varchar_SQL_c4_26  { int len; char arr[ 31 ]; }  SQL_c4 ;
 
#line 47 "demonio.pgc"
  struct varchar_SQL_c5_27  { int len; char arr[ 31 ]; }  SQL_c5 ;
 
#line 48 "demonio.pgc"
  struct varchar_SQL_c6_28  { int len; char arr[ 31 ]; }  SQL_c6 ;
 
#line 49 "demonio.pgc"
  struct varchar_SQL_nombre1_29  { int len; char arr[ 31 ]; }  SQL_nombre1 ;
 
#line 50 "demonio.pgc"
  struct varchar_SQL_nombre2_30  { int len; char arr[ 31 ]; }  SQL_nombre2 ;
 
#line 51 "demonio.pgc"
  struct varchar_SQL_nombre3_31  { int len; char arr[ 31 ]; }  SQL_nombre3 ;
 
#line 52 "demonio.pgc"
  struct varchar_SQL_nombre4_32  { int len; char arr[ 31 ]; }  SQL_nombre4 ;
 
#line 53 "demonio.pgc"
  struct varchar_SQL_nombre5_33  { int len; char arr[ 31 ]; }  SQL_nombre5 ;
 
#line 54 "demonio.pgc"
  struct varchar_SQL_nombre6_34  { int len; char arr[ 31 ]; }  SQL_nombre6 ;
 
#line 55 "demonio.pgc"
 int SQL_codigo ;
 
#line 56 "demonio.pgc"
 int SQL_cod ;
 
#line 58 "demonio.pgc"
  struct varchar_SQL_nombrelog_35  { int len; char arr[ 16 ]; }  SQL_nombrelog ;
 
#line 59 "demonio.pgc"
  struct varchar_SQL_passlog_36  { int len; char arr[ 11 ]; }  SQL_passlog ;
 
#line 61 "demonio.pgc"
  struct varchar_SQL_nombrecargo_37  { int len; char arr[ 61 ]; }  SQL_nombrecargo ;
 
#line 62 "demonio.pgc"
  struct varchar_SQL_descripcion_38  { int len; char arr[ 1001 ]; }  SQL_descripcion ;
 
#line 65 "demonio.pgc"
  struct varchar_SQL_dc1_39  { int len; char arr[ 1001 ]; }  SQL_dc1 ;
 
#line 66 "demonio.pgc"
  struct varchar_SQL_dc2_40  { int len; char arr[ 1001 ]; }  SQL_dc2 ;
 
#line 67 "demonio.pgc"
  struct varchar_SQL_dc3_41  { int len; char arr[ 1001 ]; }  SQL_dc3 ;
 
#line 68 "demonio.pgc"
  struct varchar_SQL_dc4_42  { int len; char arr[ 1001 ]; }  SQL_dc4 ;
 
#line 69 "demonio.pgc"
  struct varchar_SQL_dc5_43  { int len; char arr[ 1001 ]; }  SQL_dc5 ;
 
#line 70 "demonio.pgc"
  struct varchar_SQL_dc6_44  { int len; char arr[ 1001 ]; }  SQL_dc6 ;
 
#line 71 "demonio.pgc"
  struct varchar_SQL_nombrec1_45  { int len; char arr[ 61 ]; }  SQL_nombrec1 ;
 
#line 72 "demonio.pgc"
  struct varchar_SQL_nombrec2_46  { int len; char arr[ 61 ]; }  SQL_nombrec2 ;
 
#line 73 "demonio.pgc"
  struct varchar_SQL_nombrec3_47  { int len; char arr[ 61 ]; }  SQL_nombrec3 ;
 
#line 74 "demonio.pgc"
  struct varchar_SQL_nombrec4_48  { int len; char arr[ 61 ]; }  SQL_nombrec4 ;
 
#line 75 "demonio.pgc"
  struct varchar_SQL_nombrec5_49  { int len; char arr[ 61 ]; }  SQL_nombrec5 ;
 
#line 76 "demonio.pgc"
  struct varchar_SQL_nombrec6_50  { int len; char arr[ 61 ]; }  SQL_nombrec6 ;
 
#line 78 "demonio.pgc"
  struct varchar_SQL_cargos_51  { int len; char arr[ 1001 ]; }  SQL_cargos ;
 
#line 80 "demonio.pgc"
  struct varchar_SQL_nombref_52  { int len; char arr[ 61 ]; }  SQL_nombref ;
 
#line 81 "demonio.pgc"
  struct varchar_SQL_rutf_53  { int len; char arr[ 11 ]; }  SQL_rutf ;
 
#line 82 "demonio.pgc"
  struct varchar_SQL_sueldof_54  { int len; char arr[ 16 ]; }  SQL_sueldof ;
 
#line 83 "demonio.pgc"
  struct varchar_SQL_estadof_55  { int len; char arr[ 3 ]; }  SQL_estadof ;
 
#line 85 "demonio.pgc"
  struct varchar_SQL_rutfondos_56  { int len; char arr[ 11 ]; }  SQL_rutfondos ;
 
#line 87 "demonio.pgc"
 int SQL_capital ;
 
#line 88 "demonio.pgc"
 int SQL_sueldocap ;
 
#line 90 "demonio.pgc"
 int SQL_num1 ;
/* exec sql end declare section */
#line 92 "demonio.pgc"

 
// Metodo para conectarse a la BdD
int SQLConectar() {

	strcpy(SQL_dbname.arr, "get");	
	SQL_dbname.len = strlen(SQL_dbname.arr);
	strcpy(SQL_user.arr, "sgonzalez");
	SQL_user.len = strlen(SQL_user.arr);	
	strcpy(SQL_password.arr, "dstdst");
	SQL_password.len = strlen(SQL_password.arr);

	{ ECPGconnect(__LINE__, 0, SQL_dbname.arr , SQL_user.arr , SQL_password.arr , NULL, 0); }
#line 104 "demonio.pgc"


  	if(sqlca.sqlcode != 0) {
    		printf("Error en la conexion con la base de datos\n\n");
    		return(0);
	} else {
    		printf("Conexion con base de datos realizada\n\n");
    		return(1);
	}
}// Fin SQLConectar()


int main() {

	printf("\n\n ++++++++++   Demonio en ejecucion   ++++++++++\n\n\n");
	printf("Conexion BdD:\n");
	
	SQLConectar();
	
	// Se definen variables y estructuras necesarias para la comunicacion entre el demonio y los .c

	int qid, pid , len;

	struct msgbuf
	{
		long mtype;
		struct
		{
			int pid;
			char datos[2000];
		} texto;
	} mensaje, respuesta;

	qid = msgget (589000, IPC_CREAT|0666);
	pid = getpid ();

	while(1){

		//limpiamos la estructura de mensaje
		memset(&mensaje, 0, sizeof mensaje);
			
		//Limpiamos la estructura de respuesta
		memset (&respuesta, 0, sizeof respuesta);
		
		if((len = msgrcv (qid, &mensaje, 2500, 1, 0)) > 0) {

		  	memset (&respuesta, 0, sizeof respuesta);
		  	printf("Recibido: (%d) <%d/%s>\n\n", mensaje.mtype, mensaje.texto.pid, mensaje.texto.datos);
		  	int pid_destino = mensaje.texto.pid;
 
			// Fomulario del que viene

			char formulario[7];
			memset (formulario, 0, sizeof formulario);
			sscanf(mensaje.texto.datos, "%6c", formulario);
			printf("El formulario es: [%s]\n\n", formulario);


		/*************************************************************************
			Formulario Ingreso
		*************************************************************************/

			if (strcmp(formulario, "regemp")==0){
	
				printf("   --------------------   \n   El proceso Es: Formulario Ingreso\n   --------------------\n\n");
 				char nombre1[31];
 				char rut1[11];
 				char fecha_n1[31];
 				char sueldo1[16];
 				char cargo1[31];
 				char telefono1[16];
 				char direccion1[61];
 				char correo1[61];
 				char estado1[16];
 
				//Limpiamos los Strings

				memset (nombre1, 0, sizeof nombre1);
				memset (rut1, 0, sizeof rut1);
				memset (fecha_n1, 0, sizeof fecha_n1);
				memset (sueldo1, 0, sizeof sueldo1);
				memset (cargo1, 0, sizeof cargo1);
				memset (telefono1, 0, sizeof telefono1);
				memset (direccion1, 0, sizeof direccion1);
				memset (correo1, 0, sizeof correo1);
				memset (estado1, 0, sizeof estado1);

				//Recibimos los datos desde el .c
	
				sscanf(mensaje.texto.datos, "%6c%30c%10c%30c%15c%30c%15c%60c%60c%15c", 
formulario, nombre1, rut1, fecha_n1, sueldo1, cargo1, telefono1, direccion1, correo1, estado1);

				//Guardamos la variable en la estructura arr de rut	

				sprintf(SQL_nombre.arr,"%s", nombre1);
				SQL_nombre.len=strlen(SQL_nombre.arr);


				sprintf(SQL_rut.arr,"%s", rut1);
				SQL_rut.len=strlen(SQL_rut.arr);


				sprintf(SQL_fecha_n.arr,"%s", fecha_n1);
				SQL_fecha_n.len=strlen(SQL_fecha_n.arr);


				sprintf(SQL_sueldo.arr,"%s", sueldo1);
				SQL_sueldo.len=strlen(SQL_sueldo.arr);

				sprintf(SQL_cargo.arr,"%s", cargo1);
				SQL_cargo.len=strlen(SQL_cargo.arr);

				sprintf(SQL_telefono.arr,"%s", telefono1);
				SQL_telefono.len=strlen(SQL_telefono.arr);


				sprintf(SQL_direccion.arr,"%s", direccion1);
				SQL_direccion.len=strlen(SQL_direccion.arr);


				sprintf(SQL_correo.arr,"%s", correo1);
				SQL_correo.len=strlen(SQL_correo.arr);


				sprintf(SQL_estado.arr,"%s", estado1);
				SQL_estado.len=strlen(SQL_estado.arr);

				if(strcmp(SQL_nombre.arr,"") == 0||strcmp(SQL_rut.arr,"") == 0 || strcmp(SQL_fecha_n.arr,"") ==0 || strcmp(SQL_sueldo.arr,"")==0 || strcmp(SQL_cargo.arr,"")==0 || strcmp(SQL_telefono.arr,"")==0 || strcmp(SQL_direccion.arr,"")==0 || strcmp(SQL_correo.arr,"")==0 || strcmp(SQL_estado.arr,"")==0){
                                       
                                        memset( &respuesta, 0, sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "04");
                                        respuesta.mtype = pid_destino;
                                        respuesta.texto.pid = pid;
                                        msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);
					printf("Faltan campos que rellenar\n");


				}
				else{


				printf("El nombre es: %s\n", SQL_nombre.arr);
				printf("El rut es: %s\n", SQL_rut.arr);
				printf("El fecha_nacimiento es: %s\n", SQL_fecha_n.arr);
				printf("El sueldo es: %s\n", SQL_sueldo.arr);
				printf("El cargo es: %s\n", SQL_cargo.arr);
				printf("El telefono es: %s\n", SQL_telefono.arr);
				printf("El direccion es: %s\n", SQL_direccion.arr);
				printf("El correo es: %s\n", SQL_correo.arr);
				printf("El estado es: %s\n", SQL_estado.arr);

				// Verificamos si el empleado ya esta registrado
				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from empleados where RUT = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 256 "demonio.pgc"


				if( SQL_count != 0) {
					
					printf("El empleado ya fue registrado\n");
					
					memset( &respuesta, 0, sizeof respuesta);
					sprintf(respuesta.texto.datos, "%s", "03");
					respuesta.mtype = pid_destino;
					respuesta.texto.pid = pid;
					msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);

				} else {


					// Insertamos el empleado en la BdD
					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into empleados ( nombre , rut , fecha_n , sueldo , cargo , telefono , direccion , correo , estado ) values ( $1  , $2  , $3  , $4  , $5  , $6  , $7  , $8  , $9  )", 
	ECPGt_varchar,&(SQL_nombre),(long)31,(long)1,sizeof(struct varchar_SQL_nombre_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_fecha_n),(long)31,(long)1,sizeof(struct varchar_SQL_fecha_n_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_sueldo),(long)16,(long)1,sizeof(struct varchar_SQL_sueldo_8), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_cargo),(long)31,(long)1,sizeof(struct varchar_SQL_cargo_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_telefono),(long)16,(long)1,sizeof(struct varchar_SQL_telefono_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_direccion),(long)61,(long)1,sizeof(struct varchar_SQL_direccion_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_correo),(long)61,(long)1,sizeof(struct varchar_SQL_correo_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_estado),(long)16,(long)1,sizeof(struct varchar_SQL_estado_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 272 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 273 "demonio.pgc"


					// Revisar en caso de error en la consulta
					if(sqlca.sqlcode != 0) {
						
						printf("\nERROR en la consulta SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					} else {			

						printf("\nEmpleado ingresado con exito\n\n");	
                            	
						memset(&respuesta,0,sizeof respuesta);
	                        		sprintf(respuesta.texto.datos, "%s", "01");
       	                        		respuesta.mtype=pid_destino;
                               	 		respuesta.texto.pid=pid;
                                		msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}

				} // Fin else
				}// Fin else condiciones

			}//Fin Formulario ingtra

			if(strcmp(formulario,"eliemp")==0)
			{
				
			printf("   --------------------   \n   El proceso es: Formulario de Eliminacion\n   -------------------\n\n");
			char rut1[11];

			memset(rut1, 0, sizeof rut1);

			sscanf(mensaje.texto.datos, "%6c%10c", formulario,rut1);

			sprintf(SQL_rut.arr, "%s", rut1);
			SQL_rut.len=strlen(SQL_rut.arr);

			if(strcmp(SQL_rut.arr,"          ")==0)
			{
				memset(&respuesta,0,sizeof respuesta);
				sprintf(respuesta.texto.datos, "%s", "02");
				respuesta.mtype=pid_destino;
				respuesta.texto.pid=pid;
				msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				printf("No se ingreso Rut\n");

			}else
			{
				printf("El rut es: %s\n", SQL_rut.arr);
				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from empleados where RUT = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 328 "demonio.pgc"

				if(SQL_count==0)
				{ 
					printf("El rut no existe en la base de datos\n");
					memset(&respuesta,0,sizeof respuesta);
					sprintf(respuesta.texto.datos, "%s", "03");
					respuesta.mtype=pid_destino;
					respuesta.texto.pid=pid;
					msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				}else
				{ 	

                                	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from empleados where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 340 "demonio.pgc"

                                	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 341 "demonio.pgc"

					
					if(sqlca.sqlcode !=0)
					{
						printf("ERROR en la consulta SQL\n");
						
						memset(&respuesta,0,sizeof respuesta);
						sprintf(respuesta.texto.datos, "%s", "03");
						respuesta.mtype=pid_destino;
						respuesta.texto.pid=pid;
						msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
					}else
					{
						printf("Empleado borrado con exito\n");

						memset(&respuesta,0,sizeof respuesta);
						sprintf(respuesta.texto.datos, "%s", "01");
						respuesta.mtype=pid_destino;
						respuesta.texto.pid=pid;
						msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
				}
			}
						
			}//fin eliminacion empleado

			 if(strcmp(formulario,"busemp")==0)
                        {

                        printf("   --------------------   \n   El proceso es: Formulario de Busqueda\n   -------------------\n\n");
                        char rut1[11];
			   char nombre1[31];

                        memset(rut1, 0, sizeof rut1);

                        sscanf(mensaje.texto.datos, "%6c%10c", formulario,rut1);

                        sprintf(SQL_rut.arr, "%s", rut1);
                        SQL_rut.len=strlen(SQL_rut.arr);

                        if(strcmp(SQL_rut.arr,"          ")==0)
                        {
                                memset(&respuesta,0,sizeof respuesta);
                                sprintf(respuesta.texto.datos, "%s", "02");
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                printf("No se ingreso Rut\n");

                        }else
                        {
                                printf("El rut es: %s\n", SQL_rut.arr);
                                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from empleados where RUT = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 394 "demonio.pgc"

                                if(SQL_count==0)
                                {
                                        printf("El rut no existe en la base de datos\n");
                                        memset(&respuesta,0,sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "03");
                                        respuesta.mtype=pid_destino;
                                        respuesta.texto.pid=pid;
                                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                }else
					{       

					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre , fecha_n , sueldo , cargo , telefono , direccion , correo , estado from empleados where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)31,(long)1,sizeof(struct varchar_SQL_nombre_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_fecha_n),(long)31,(long)1,sizeof(struct varchar_SQL_fecha_n_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_sueldo),(long)16,(long)1,sizeof(struct varchar_SQL_sueldo_8), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_cargo),(long)31,(long)1,sizeof(struct varchar_SQL_cargo_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_telefono),(long)16,(long)1,sizeof(struct varchar_SQL_telefono_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_direccion),(long)61,(long)1,sizeof(struct varchar_SQL_direccion_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_correo),(long)61,(long)1,sizeof(struct varchar_SQL_correo_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_estado),(long)16,(long)1,sizeof(struct varchar_SQL_estado_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 406 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 407 "demonio.pgc"

    
                                        if(sqlca.sqlcode !=0)
                                        {
                                                printf("ERROR en la consulta SQL\n");
						
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "03");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }else
                                        {
                                                printf("Empleado encontrado con exito\n");
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%2s %30s %30s %15s %30s %15s %60s %60s %15s","01",SQL_nombre.arr,SQL_fecha_n.arr,SQL_sueldo.arr,SQL_cargo.arr,SQL_telefono.arr,SQL_direccion.arr,SQL_correo.arr,SQL_estado.arr);
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }
                                }
                        }

                        }//fin busqueda empleado


			 if(strcmp(formulario,"modemp")==0)
                        {

                         printf("   --------------------   \n   El proceso es: Formulario de Modificacion\n   -------------------\n\n");
                         char nombre1[31];
                         char rut1[11];
                         char fecha_n1[31];
                         char sueldo1[16];
                         char cargo1[31];
                         char telefono1[16];
                         char direccion1[61];
                         char correo1[61];
                         char estado1[16];

                         //Limpiamos los Strings

                         memset (nombre1, 0, sizeof nombre1);
                         memset (rut1, 0, sizeof rut1);
                         memset (fecha_n1, 0, sizeof fecha_n1);
                         memset (sueldo1, 0, sizeof sueldo1);
                         memset (cargo1, 0, sizeof cargo1);
                         memset (telefono1, 0, sizeof telefono1);
                         memset (direccion1, 0, sizeof direccion1);
                         memset (correo1, 0, sizeof correo1);
                         memset (estado1, 0, sizeof estado1);

                         //Recibimos los datos desde el .c

                         sscanf(mensaje.texto.datos, "%6c%10c%30c%30c%15c%30c%15c%60c%60c%15c",formulario, rut1, nombre1, fecha_n1, sueldo1, cargo1, telefono1, direccion1, correo1, estado1);


                         sprintf(SQL_nombre.arr,"%s", nombre1);
                         SQL_nombre.len=strlen(SQL_nombre.arr);


                         sprintf(SQL_rut.arr,"%s", rut1);
                         SQL_rut.len=strlen(SQL_rut.arr);


                         sprintf(SQL_fecha_n.arr,"%s", fecha_n1);
                         SQL_fecha_n.len=strlen(SQL_fecha_n.arr);


                         sprintf(SQL_sueldo.arr,"%s", sueldo1);
                         SQL_sueldo.len=strlen(SQL_sueldo.arr);

                         sprintf(SQL_cargo.arr,"%s", cargo1);
                         SQL_cargo.len=strlen(SQL_cargo.arr);

                         sprintf(SQL_telefono.arr,"%s", telefono1);
                         SQL_telefono.len=strlen(SQL_telefono.arr);


                         sprintf(SQL_direccion.arr,"%s", direccion1);
                         SQL_direccion.len=strlen(SQL_direccion.arr);


                         sprintf(SQL_correo.arr,"%s", correo1);
                         SQL_correo.len=strlen(SQL_correo.arr);


                         sprintf(SQL_estado.arr,"%s", estado1);
                         SQL_estado.len=strlen(SQL_estado.arr);

                        if(strcmp(SQL_rut.arr,"          ")==0)
                        {
                                memset(&respuesta,0,sizeof respuesta);
                                sprintf(respuesta.texto.datos, "%s", "02");
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                printf("No se ingreso Rut\n");

                        }else
                        {
                                printf("El rut es: %s\n", SQL_rut.arr);
                                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from empleados where RUT = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 509 "demonio.pgc"

                                if(SQL_count==0)
                                {
                                        printf("El rut no existe en la base de datos\n");
                                        memset(&respuesta,0,sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "03");
                                        respuesta.mtype=pid_destino;
                                        respuesta.texto.pid=pid;
                                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                }else 
                                {       
					if(strcmp(SQL_nombre.arr,"") == 0||strcmp(SQL_rut.arr,"") == 0 || strcmp(SQL_fecha_n.arr,"") ==0 || strcmp(SQL_sueldo.arr,"")==0 || strcmp(SQL_cargo.arr,"")==0 || strcmp(SQL_telefono.arr,"")==0 || strcmp(SQL_direccion.arr,"")==0 || strcmp(SQL_correo.arr,"")==0 || strcmp(SQL_estado.arr,"")==0)
					{

					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre , fecha_n , sueldo , cargo , telefono , direccion , correo , estado from empleados where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)31,(long)1,sizeof(struct varchar_SQL_nombre_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_fecha_n),(long)31,(long)1,sizeof(struct varchar_SQL_fecha_n_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_sueldo),(long)16,(long)1,sizeof(struct varchar_SQL_sueldo_8), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_cargo),(long)31,(long)1,sizeof(struct varchar_SQL_cargo_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_telefono),(long)16,(long)1,sizeof(struct varchar_SQL_telefono_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_direccion),(long)61,(long)1,sizeof(struct varchar_SQL_direccion_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_correo),(long)61,(long)1,sizeof(struct varchar_SQL_correo_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_estado),(long)16,(long)1,sizeof(struct varchar_SQL_estado_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 523 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 524 "demonio.pgc"

    
                                        if(sqlca.sqlcode !=0)
                                        {
                                                printf("ERROR en la consulta SQL\n");
						
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }else
                                        {
                                                printf("Empleado encontrado con exito\n");
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos,"%2s%10s%30s%30s%15s%30s%15s%60s%60s%15s","04",SQL_rut.arr,SQL_nombre.arr,SQL_fecha_n.arr,SQL_sueldo.arr,SQL_cargo.arr,SQL_telefono.arr,SQL_direccion.arr,SQL_correo.arr,SQL_estado.arr);
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }

					}else
					{
						
                                        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update empleados set nombre = $1  , fecha_n = $2  , sueldo = $3  , cargo = $4  , telefono = $5  , direccion = $6  , correo = $7  , estado = $8  where rut = $9 ", 
	ECPGt_varchar,&(SQL_nombre),(long)31,(long)1,sizeof(struct varchar_SQL_nombre_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_fecha_n),(long)31,(long)1,sizeof(struct varchar_SQL_fecha_n_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_sueldo),(long)16,(long)1,sizeof(struct varchar_SQL_sueldo_8), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_cargo),(long)31,(long)1,sizeof(struct varchar_SQL_cargo_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_telefono),(long)16,(long)1,sizeof(struct varchar_SQL_telefono_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_direccion),(long)61,(long)1,sizeof(struct varchar_SQL_direccion_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_correo),(long)61,(long)1,sizeof(struct varchar_SQL_correo_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_estado),(long)16,(long)1,sizeof(struct varchar_SQL_estado_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 548 "demonio.pgc"

                                        { ECPGtrans(__LINE__, NULL, "commit");}
#line 549 "demonio.pgc"


                                        // Revisar en caso de error en la consulta
                                        if(sqlca.sqlcode != 0) {
 
                                                printf("\nERROR en la consulta SQL\n\n");

                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                                        } else {

                                                printf("\nEmpleado modificado con exito\n\n");

                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "01");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                                        }


					}


 
                                }
                        }
			}//fin formulario modificacion

			if(strcmp(formulario,"mosemp")==0)
			{
			printf("Recibi: %s\n\n",mensaje.texto.datos);
			int ccont;
			int x;
			sscanf(mensaje.texto.datos,"%6s%10d",formulario,&ccont);
			/* declare curs1 cursor for select rut , nombre , cargo from empleados order by rut */
#line 589 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs1 cursor for select rut , nombre , cargo from empleados order by rut", ECPGt_EOIT, ECPGt_EORT);}
#line 590 "demonio.pgc"

			for(x=0;x<=ccont;x++){
			memset(SQL_nombre1.arr,0,sizeof SQL_nombre1.arr);
                        memset(SQL_nombre2.arr,0,sizeof SQL_nombre2.arr);
                        memset(SQL_nombre3.arr,0,sizeof SQL_nombre3.arr);
                        memset(SQL_nombre4.arr,0,sizeof SQL_nombre4.arr);
                        memset(SQL_nombre5.arr,0,sizeof SQL_nombre5.arr);
                        memset(SQL_nombre6.arr,0,sizeof SQL_nombre6.arr);
			memset(SQL_c1.arr,0,sizeof SQL_c1.arr);
                        memset(SQL_c2.arr,0,sizeof SQL_c2.arr);
                        memset(SQL_c3.arr,0,sizeof SQL_c3.arr);
                        memset(SQL_c4.arr,0,sizeof SQL_c4.arr);
                        memset(SQL_c5.arr,0,sizeof SQL_c5.arr);
                        memset(SQL_c6.arr,0,sizeof SQL_c6.arr);
			memset(SQL_r1.arr,0,sizeof SQL_r1.arr);
                        memset(SQL_r2.arr,0,sizeof SQL_r2.arr);
                        memset(SQL_r3.arr,0,sizeof SQL_r3.arr);
                        memset(SQL_r4.arr,0,sizeof SQL_r4.arr);
                        memset(SQL_r5.arr,0,sizeof SQL_r5.arr);
                        memset(SQL_r6.arr,0,sizeof SQL_r6.arr);


			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r1),(long)11,(long)1,sizeof(struct varchar_SQL_r1_17), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre1),(long)31,(long)1,sizeof(struct varchar_SQL_nombre1_29), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c1),(long)31,(long)1,sizeof(struct varchar_SQL_c1_23), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 612 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r2),(long)11,(long)1,sizeof(struct varchar_SQL_r2_18), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre2),(long)31,(long)1,sizeof(struct varchar_SQL_nombre2_30), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c2),(long)31,(long)1,sizeof(struct varchar_SQL_c2_24), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 613 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r3),(long)11,(long)1,sizeof(struct varchar_SQL_r3_19), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre3),(long)31,(long)1,sizeof(struct varchar_SQL_nombre3_31), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c3),(long)31,(long)1,sizeof(struct varchar_SQL_c3_25), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 614 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r4),(long)11,(long)1,sizeof(struct varchar_SQL_r4_20), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre4),(long)31,(long)1,sizeof(struct varchar_SQL_nombre4_32), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c4),(long)31,(long)1,sizeof(struct varchar_SQL_c4_26), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 615 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r5),(long)11,(long)1,sizeof(struct varchar_SQL_r5_21), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre5),(long)31,(long)1,sizeof(struct varchar_SQL_nombre5_33), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c5),(long)31,(long)1,sizeof(struct varchar_SQL_c5_27), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 616 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs1", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_r6),(long)11,(long)1,sizeof(struct varchar_SQL_r6_22), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre6),(long)31,(long)1,sizeof(struct varchar_SQL_nombre6_34), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_c6),(long)31,(long)1,sizeof(struct varchar_SQL_c6_28), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 617 "demonio.pgc"

			}
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close curs1", ECPGt_EOIT, ECPGt_EORT);}
#line 619 "demonio.pgc"

                        memset(&respuesta,0,sizeof respuesta);
			ccont=ccont++;
			if (sqlca.sqlcode != 0)
			{
				sprintf(respuesta.texto.datos,"%s","02");
			}
			else
			{	

 
                        if(strcmp(SQL_r6.arr,"")==0)
                        {
				memset(&respuesta,0,sizeof respuesta);
				sprintf(respuesta.texto.datos,"%2s%10d%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s","03",ccont,SQL_nombre1.arr,SQL_r1.arr,SQL_c1.arr,SQL_nombre2.arr,SQL_r2.arr,SQL_c2.arr,SQL_nombre3.arr,SQL_r3.arr,SQL_c3.arr,SQL_nombre4.arr,SQL_r4.arr,SQL_c4.arr,SQL_nombre5.arr,SQL_r5.arr,SQL_c5.arr,SQL_nombre6.arr,SQL_r6.arr,SQL_c6.arr);
			 	printf("mande: %s\n",respuesta.texto.datos);
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				memset(SQL_nombre1.arr,'\0',sizeof SQL_nombre1.arr); 
				memset(SQL_nombre2.arr,'\0',sizeof SQL_nombre2.arr);
				memset(SQL_nombre3.arr,'\0',sizeof SQL_nombre3.arr);
				memset(SQL_nombre4.arr,'\0',sizeof SQL_nombre4.arr);
				memset(SQL_nombre5.arr,'\0',sizeof SQL_nombre5.arr);
				memset(SQL_nombre6.arr,'\0',sizeof SQL_nombre6.arr);
				memset(SQL_c1.arr,'\0',sizeof SQL_c1.arr);
                                memset(SQL_c2.arr,'\0',sizeof SQL_c2.arr);
                                memset(SQL_c3.arr,'\0',sizeof SQL_c3.arr);
                                memset(SQL_c4.arr,'\0',sizeof SQL_c4.arr);
                                memset(SQL_c5.arr,'\0',sizeof SQL_c5.arr);
                                memset(SQL_c6.arr,'\0',sizeof SQL_c6.arr);
				memset(SQL_r1.arr,'\0',sizeof SQL_r1.arr);
                                memset(SQL_r2.arr,'\0',sizeof SQL_r2.arr);
                                memset(SQL_r3.arr,'\0',sizeof SQL_r3.arr);
                                memset(SQL_r4.arr,'\0',sizeof SQL_r4.arr);
                                memset(SQL_r5.arr,'\0',sizeof SQL_r5.arr);
                                memset(SQL_r6.arr,'\0',sizeof SQL_r6.arr);

                                printf("No quedan mas empleados que mostrar\n");

                        }
				else{

				memset(&respuesta,0,sizeof respuesta);
				sprintf(respuesta.texto.datos,"%2s%10d%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s%30s%10s%30s","01",ccont,SQL_nombre1.arr,SQL_r1.arr,SQL_c1.arr,SQL_nombre2.arr,SQL_r2.arr,SQL_c2.arr,SQL_nombre3.arr,SQL_r3.arr,SQL_c3.arr,SQL_nombre4.arr,SQL_r4.arr,SQL_c4.arr,SQL_nombre5.arr,SQL_r5.arr,SQL_c5.arr,SQL_nombre6.arr,SQL_r6.arr,SQL_c6.arr);
			 	printf("mande: %s\n",respuesta.texto.datos);
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				memset(SQL_nombre1.arr,'\0',sizeof SQL_nombre1.arr); 
				memset(SQL_nombre2.arr,'\0',sizeof SQL_nombre2.arr);
				memset(SQL_nombre3.arr,'\0',sizeof SQL_nombre3.arr);
				memset(SQL_nombre4.arr,'\0',sizeof SQL_nombre4.arr);
				memset(SQL_nombre5.arr,'\0',sizeof SQL_nombre5.arr);
				memset(SQL_nombre6.arr,'\0',sizeof SQL_nombre6.arr);
				memset(SQL_c1.arr,'\0',sizeof SQL_c1.arr);
                                memset(SQL_c2.arr,'\0',sizeof SQL_c2.arr);
                                memset(SQL_c3.arr,'\0',sizeof SQL_c3.arr);
                                memset(SQL_c4.arr,'\0',sizeof SQL_c4.arr);
                                memset(SQL_c5.arr,'\0',sizeof SQL_c5.arr);
                                memset(SQL_c6.arr,'\0',sizeof SQL_c6.arr);
				memset(SQL_r1.arr,'\0',sizeof SQL_r1.arr);
                                memset(SQL_r2.arr,'\0',sizeof SQL_r2.arr);
                                memset(SQL_r3.arr,'\0',sizeof SQL_r3.arr);
                                memset(SQL_r4.arr,'\0',sizeof SQL_r4.arr);
                                memset(SQL_r5.arr,'\0',sizeof SQL_r5.arr);
                                memset(SQL_r6.arr,'\0',sizeof SQL_r6.arr);

				}

			}
		}
		
		if (strcmp(formulario, "regedu")==0){
	
				printf("   --------------------   \n   El proceso Es: Formulario Ingreso Educacion\n   --------------------\n\n");

				char rut2[11];
				char nivel1[16];
				char centro1[61];
				char titulo1[61];
 
				//Limpiamos los Strings

				memset (nivel1, 0, sizeof nivel1);
				memset (rut2, 0, sizeof rut2);
				memset (centro1, 0, sizeof centro1);
				memset (titulo1, 0, sizeof titulo1);

				//Recibimos los datos desde el .c
	
	
				sscanf(mensaje.texto.datos,"%6c%10c%15c%60c%60c", formulario,rut2,nivel1,centro1,titulo1);


				//Guardamos la variable en la estructura arr de rut	


				sprintf(SQL_rut.arr,"%s", rut2);
				SQL_rut.len=strlen(SQL_rut.arr);
				
				sprintf(SQL_nivel.arr,"%s", nivel1);
				SQL_nivel.len=strlen(SQL_nivel.arr);
				
				sprintf(SQL_centro.arr,"%s", centro1);
				SQL_centro.len=strlen(SQL_centro.arr);
				
				sprintf(SQL_titulo.arr,"%s", titulo1);
				SQL_titulo.len=strlen(SQL_titulo.arr);



				if(strcmp(SQL_rut.arr,"") == 0 || strcmp(SQL_nivel.arr,"") ==0 || strcmp(SQL_centro.arr,"")==0 || strcmp(SQL_titulo.arr,"")==0 ){
                                       
                                        memset( &respuesta, 0, sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "04");
                                        respuesta.mtype = pid_destino;
                                        respuesta.texto.pid = pid;
                                        msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);
					printf("Faltan campos que rellenar\n");


				}
				else{


				printf("El rut es: %s\n", SQL_rut.arr);
				printf("El nivel es: %s\n", SQL_nivel.arr);
				printf("El centro es: %s\n", SQL_centro.arr);
				printf("El titulo es: %s\n", SQL_titulo.arr);

				// Verificamos si el empleado ya esta registrado
				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 751 "demonio.pgc"


				if( SQL_count != 0) {
					
					printf("El empleado ya tiene educacion registrada\n");
					
					memset( &respuesta, 0, sizeof respuesta);
					sprintf(respuesta.texto.datos, "%s", "03");
					respuesta.mtype = pid_destino;
					respuesta.texto.pid = pid;
					msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);

				} else {


					// Insertamos el empleado en la BdD
					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into educacion ( rut_empleado , nivel_escolaridad , centro_educativo , nombre_titulo ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nivel),(long)16,(long)1,sizeof(struct varchar_SQL_nivel_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_centro),(long)61,(long)1,sizeof(struct varchar_SQL_centro_15), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_titulo),(long)61,(long)1,sizeof(struct varchar_SQL_titulo_16), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 767 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 768 "demonio.pgc"
 

					// Revisar en caso de error en la consulta
					if(sqlca.sqlcode != 0) {
						
						printf("\nERROR en la consulta SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					} else {			

						printf("\nEducacion del empleado ingresada con exito\n\n");	
                            	
						memset(&respuesta,0,sizeof respuesta);
	                        		sprintf(respuesta.texto.datos, "%s", "01");
       	                        		respuesta.mtype=pid_destino;
                               	 		respuesta.texto.pid=pid;
                                		msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}

				} // Fin else
				}// Fin else condiciones

			}//Fin Formulario regedu
		
		
		if(strcmp(formulario,"eliedu")==0)
			{
				
			printf("   --------------------   \n   El proceso es: Formulario de Eliminacion Educacion\n   -------------------\n\n");
			char rut2[11];

			memset(rut2, 0, sizeof rut2);

			sscanf(mensaje.texto.datos, "%6c%10c", formulario,rut2);

			sprintf(SQL_rut.arr, "%s", rut2);
			SQL_rut.len=strlen(SQL_rut.arr);

			if(strcmp(SQL_rut.arr,"          ")==0)
			{
				memset(&respuesta,0,sizeof respuesta);
				sprintf(respuesta.texto.datos, "%s", "02");
				respuesta.mtype=pid_destino;
				respuesta.texto.pid=pid;
				msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				printf("No se ingreso Rut\n");

			}else
			{
				printf("El rut es: %s\n", SQL_rut.arr);
				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 824 "demonio.pgc"

				if(SQL_count==0)
				{ 
					printf("El rut no existe en la base de datos\n");
					memset(&respuesta,0,sizeof respuesta);
					sprintf(respuesta.texto.datos, "%s", "03");
					respuesta.mtype=pid_destino;
					respuesta.texto.pid=pid;
					msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				}else
				{ 	

                                	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 836 "demonio.pgc"

                                	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 837 "demonio.pgc"

					
					if(sqlca.sqlcode !=0)
					{
						printf("ERROR en la consulta SQL\n");
						
						memset(&respuesta,0,sizeof respuesta);
						sprintf(respuesta.texto.datos, "%s", "03");
						respuesta.mtype=pid_destino;
						respuesta.texto.pid=pid;
						msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
					}else
					{
						printf("Empleado borrado con exito\n");

						memset(&respuesta,0,sizeof respuesta);
						sprintf(respuesta.texto.datos, "%s", "01");
						respuesta.mtype=pid_destino;
						respuesta.texto.pid=pid;
						msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
				}
			}
						
			}//fin eliminacion educacion empleado	



	    if(strcmp(formulario,"busedu")==0)
                        {

                        printf("   --------------------   \n   El proceso es: Formulario de Busqueda\n   -------------------\n\n");
                        char rut2[11];

                        memset(rut2, 0, sizeof rut2);

                        sscanf(mensaje.texto.datos, "%6c%10c", formulario,rut2);

                        sprintf(SQL_rut.arr, "%s", rut2);
                        SQL_rut.len=strlen(SQL_rut.arr);

                        if(strcmp(SQL_rut.arr,"          ")==0)
                        {
                                memset(&respuesta,0,sizeof respuesta);
                                sprintf(respuesta.texto.datos, "%s", "02");
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                printf("No se ingreso Rut\n");

                        }else
                        {
                                printf("El rut es: %s\n", SQL_rut.arr);


                                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 893 "demonio.pgc"

                                if(SQL_count==0)
                                {
                                        printf("El rut no existe en la base de datos\n");
                                        memset(&respuesta,0,sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "03");
                                        respuesta.mtype=pid_destino;
                                        respuesta.texto.pid=pid;
                                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                }else
					{       

					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nivel_escolaridad , centro_educativo , nombre_titulo from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nivel),(long)16,(long)1,sizeof(struct varchar_SQL_nivel_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_centro),(long)61,(long)1,sizeof(struct varchar_SQL_centro_15), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_titulo),(long)61,(long)1,sizeof(struct varchar_SQL_titulo_16), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 905 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 906 "demonio.pgc"

    
                                        if(sqlca.sqlcode !=0)
                                        {
                                                printf("ERROR en la consulta SQL\n");
						
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "03");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }else
                                        {
                                                printf("Empleado encontrado con exito\n");
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%2s%16s%61s%61s","01",SQL_nivel.arr,SQL_centro.arr,SQL_titulo.arr);
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }
                                }
                        }

                        }//fin busqueda educacion empleado

		
		if(strcmp(formulario,"modedu")==0)
                        {

                         printf("   --------------------   \n   El proceso es: Formulario de Modificacion Educacion\n   -------------------\n\n");

				char rut2[11];
				char nivel1[16];
				char centro1[61];
				char titulo1[61];
 
				//Limpiamos los Strings

				memset (nivel1, 0, sizeof nivel1);
				memset (rut2, 0, sizeof rut2);
				memset (centro1, 0, sizeof centro1);
				memset (titulo1, 0, sizeof titulo1);

				//Recibimos los datos desde el .c
	
	
				sscanf(mensaje.texto.datos,"%6c%10c%15c%60c%60c", formulario,rut2,nivel1,centro1,titulo1);


				//Guardamos la variable en la estructura arr de rut	


				sprintf(SQL_rut.arr,"%s", rut2);
				SQL_rut.len=strlen(SQL_rut.arr);
				
				sprintf(SQL_nivel.arr,"%s", nivel1);
				SQL_nivel.len=strlen(SQL_nivel.arr);
				
				sprintf(SQL_centro.arr,"%s", centro1);
				SQL_centro.len=strlen(SQL_centro.arr);
				
				sprintf(SQL_titulo.arr,"%s", titulo1);
				SQL_titulo.len=strlen(SQL_titulo.arr);


                        if(strcmp(SQL_rut.arr,"          ")==0)
                        {
                                memset(&respuesta,0,sizeof respuesta);
                                sprintf(respuesta.texto.datos, "%s", "02");
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                printf("No se ingreso Rut\n");

                        }else
                        {
                                printf("El rut es: %s\n", SQL_rut.arr);
                                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 983 "demonio.pgc"

                                if(SQL_count==0)
                                {
                                        printf("El rut no existe en la base de datos\n");
                                        memset(&respuesta,0,sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%s", "03");
                                        respuesta.mtype=pid_destino;
                                        respuesta.texto.pid=pid;
                                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                }else 
                                {       
					if(strcmp(SQL_rut.arr,"") == 0 || strcmp(SQL_nivel.arr,"") ==0 || strcmp(SQL_centro.arr,"")==0 || strcmp(SQL_titulo.arr,"")==0)
					{

					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nivel_escolaridad , centro_educativo , nombre_titulo from educacion where rut_empleado = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nivel),(long)16,(long)1,sizeof(struct varchar_SQL_nivel_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_centro),(long)61,(long)1,sizeof(struct varchar_SQL_centro_15), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_titulo),(long)61,(long)1,sizeof(struct varchar_SQL_titulo_16), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 997 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 998 "demonio.pgc"

    
                                        if(sqlca.sqlcode !=0)
                                        {
                                                printf("ERROR en la consulta SQL\n");
						
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }else
                                        {
                                                printf("Educacion del empleado encontrada con exito\n");
                                                memset(&respuesta,0,sizeof respuesta);
						      sprintf(respuesta.texto.datos, "%2s%10s%16s%61s%61s","04",SQL_rut.arr,SQL_nivel.arr,SQL_centro.arr,SQL_titulo.arr);
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
                                        }

					}else
					{
						
                                        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update educacion set nivel_escolaridad = $1  , centro_educativo = $2  , nombre_titulo = $3  where rut_empleado = $4 ", 
	ECPGt_varchar,&(SQL_nivel),(long)16,(long)1,sizeof(struct varchar_SQL_nivel_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_centro),(long)61,(long)1,sizeof(struct varchar_SQL_centro_15), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_titulo),(long)61,(long)1,sizeof(struct varchar_SQL_titulo_16), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1022 "demonio.pgc"

                                        { ECPGtrans(__LINE__, NULL, "commit");}
#line 1023 "demonio.pgc"


                                        // Revisar en caso de error en la consulta
                                        if(sqlca.sqlcode != 0) {
 
                                                printf("\nERROR en la consulta SQL\n\n");

                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                                        } else {

                                                printf("\nEmpleado modificado con exito\n\n");

                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "01");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                                        }


					}


 
                                }
                        }
			}//fin formulario modificacion educacion

//transacciones de interfaz

	if(strcmp(formulario,"logusu") == 0)
		{ printf("\nEn logusu\n\n");
			char cla[11];
			char nom[16];
			memset(cla,'\0',sizeof cla);
			memset(nom,'\0',sizeof nom);
			sscanf(mensaje.texto.datos,"%6c%15s%10s",formulario,nom,cla);
			
			 
			sprintf(SQL_nombrelog.arr,"%s", nom);
			SQL_nombrelog.len=strlen(SQL_nombrelog.arr);
			
			sprintf(SQL_passlog.arr,"%s", cla);
			SQL_passlog.len=strlen(SQL_passlog.arr);
			   
			   
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from users where nombre = $1  and pass = $2 ", 
	ECPGt_varchar,&(SQL_nombrelog),(long)16,(long)1,sizeof(struct varchar_SQL_nombrelog_35), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_passlog),(long)11,(long)1,sizeof(struct varchar_SQL_passlog_36), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1075 "demonio.pgc"

			memset(&respuesta,0,sizeof respuesta);
			if (SQL_count == 0)
			{printf("\nNo existe user\n\n");
				sprintf(respuesta.texto.datos,"%2s","02");
				 	 
			}
			else
			{printf("\nExiste user\n\n");
					sprintf(respuesta.texto.datos,"%2s","01");
 
			}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin logusu
		
		if(strcmp(formulario,"inscar") == 0)
		{ printf("\nEn inscar\n\n");
			char descrip[1001];
			char nomc[61];
			memset(descrip,'\0',sizeof descrip);
			memset(nomc,'\0',sizeof nomc);
			sscanf(mensaje.texto.datos,"%6c%60c%1000[^\n]",formulario,nomc,descrip);
			

			
			
			printf("El nomc es: %s", nomc);
			printf("El descripcion es: %s\n", descrip);

			 
			sprintf(SQL_nombrecargo.arr,"%s", nomc);
			SQL_nombrecargo.len=strlen(SQL_nombrecargo.arr);
			
			sprintf(SQL_descripcion.arr,"%s", descrip);
			SQL_descripcion.len=strlen(SQL_descripcion.arr);
			   
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from cargos where nombre_cargo = $1 ", 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1116 "demonio.pgc"

			memset(&respuesta,0,sizeof respuesta);
			if (SQL_count == 0)
			{printf("\nNo existe cargo\n\n");
			
							{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into cargos ( nombre_cargo , descripcion ) values ( $1  , $2  )", 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_descripcion),(long)1001,(long)1,sizeof(struct varchar_SQL_descripcion_38), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1121 "demonio.pgc"

                                { ECPGtrans(__LINE__, NULL, "commit");}
#line 1122 "demonio.pgc"

                                if (sqlca.sqlcode != 0)
                                {
                                        printf("Error al ingresar el cargo");
                                        sprintf(respuesta.texto.datos,"%s","03");
                                }
                                else
                                {
                                        printf("Cargo Ingresado correctamente\n\n");
                                }
			
				sprintf(respuesta.texto.datos,"%2s","01");
				 	 
			}
			else
			{printf("\nExiste cargo\n\n");
					sprintf(respuesta.texto.datos,"%2s","02");
 
			}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin inscar
		
		
		if(strcmp(formulario,"modcar") == 0)
		{ printf("\nEn modcar\n\n");
			char descrip[1001];
			char nomc[61];
			memset(descrip,'\0',sizeof descrip);
			memset(nomc,'\0',sizeof nomc);
			sscanf(mensaje.texto.datos,"%6c%60c%1000[^\n]",formulario,nomc,descrip);
			

			
			
			printf("El nomc es: %s", nomc);
			printf("El descripcion es: %s\n", descrip);

			 
			sprintf(SQL_nombrecargo.arr,"%s", nomc);
			SQL_nombrecargo.len=strlen(SQL_nombrecargo.arr);
			
			sprintf(SQL_descripcion.arr,"%s", descrip);
			SQL_descripcion.len=strlen(SQL_descripcion.arr);
			   
			//EXEC SQL SELECT COUNT (*) INTO :SQL_count FROM cargos WHERE nombre_cargo = :SQL_nombrecargo;
			memset(&respuesta,0,sizeof respuesta);
			//if (SQL_count == 0)
			//{printf("\nNo existe cargo\n\n");
			
							{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update cargos set descripcion = $1  where nombre_cargo = $2 ", 
	ECPGt_varchar,&(SQL_descripcion),(long)1001,(long)1,sizeof(struct varchar_SQL_descripcion_38), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1176 "demonio.pgc"

                                { ECPGtrans(__LINE__, NULL, "commit");}
#line 1177 "demonio.pgc"

                                if (sqlca.sqlcode != 0)
                                {
                                        printf("Error al ingresar el cargo");
                                        sprintf(respuesta.texto.datos,"%s","03");
                                }
                                else
                                {
                                        printf("Cargo Ingresado correctamente\n\n");
                                }
			
				sprintf(respuesta.texto.datos,"%2s","01");
				 	 
			//}
			//else
			//{printf("\nExiste cargo\n\n");
			//		sprintf(respuesta.texto.datos,"%2s","02");
 
	//		}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin modcar
		
		
		if(strcmp(formulario,"buscar") == 0)
		{ printf("\nEn buscar\n\n");
			char descrip[1001];
			char nomc[61];
			memset(descrip,'\0',sizeof descrip);
			memset(nomc,'\0',sizeof nomc);
			sscanf(mensaje.texto.datos,"%6c%60c",formulario,nomc);
			
	       
			
			
			printf("El nomc es: %s", nomc);

			 
			sprintf(SQL_nombrecargo.arr,"%s", nomc);
			SQL_nombrecargo.len=strlen(SQL_nombrecargo.arr);
			
			sprintf(SQL_descripcion.arr,"%s", descrip);
			SQL_descripcion.len=strlen(SQL_descripcion.arr);
			   
			//EXEC SQL SELECT COUNT (*) INTO :SQL_count FROM cargos WHERE nombre_cargo = :SQL_nombrecargo;
			memset(&respuesta,0,sizeof respuesta);
			//if (SQL_count != 0)
			//{
			
							{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre_cargo , descripcion from cargos where nombre_cargo = $1 ", 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_descripcion),(long)1001,(long)1,sizeof(struct varchar_SQL_descripcion_38), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1230 "demonio.pgc"

                                { ECPGtrans(__LINE__, NULL, "commit");}
#line 1231 "demonio.pgc"

                                if (sqlca.sqlcode != 0)
                                {
                                        printf("Error al buscar el cargo");
                                        sprintf(respuesta.texto.datos,"%s","03");
                                }
                                else
                                {
                                        printf("Cargo encontrado correctamente\n\n");
                                }
			
				sprintf(respuesta.texto.datos,"/%2s/%6s/%1000s","01",SQL_nombrecargo.arr,SQL_descripcion.arr);
				 	 
			//}
			//else
			//{printf("\nNo existe cargo\n\n");
			//		sprintf(respuesta.texto.datos,"%2s","02");
 
			//}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin buscar
		
		if(strcmp(formulario,"elicar") == 0)
		{ printf("\nEn elicar\n\n");
			char descrip[1001];
			char nomc[61];
			memset(descrip,'\0',sizeof descrip);
			memset(nomc,'\0',sizeof nomc);
			sscanf(mensaje.texto.datos,"%6c%60c",formulario,nomc);
			
	       
			
			
			printf("El nomc es: %s", nomc);

			 
			sprintf(SQL_nombrecargo.arr,"%s", nomc);
			SQL_nombrecargo.len=strlen(SQL_nombrecargo.arr);
			
			sprintf(SQL_descripcion.arr,"%s", descrip);
			SQL_descripcion.len=strlen(SQL_descripcion.arr);
			   
			//EXEC SQL SELECT COUNT (*) INTO :SQL_count FROM cargos WHERE nombre_cargo = :SQL_nombrecargo;
			memset(&respuesta,0,sizeof respuesta);
			//if (SQL_count != 0)
			//{
			
							{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from cargos where nombre_cargo = $1 ", 
	ECPGt_varchar,&(SQL_nombrecargo),(long)61,(long)1,sizeof(struct varchar_SQL_nombrecargo_37), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1283 "demonio.pgc"

                                { ECPGtrans(__LINE__, NULL, "commit");}
#line 1284 "demonio.pgc"

                                if (sqlca.sqlcode != 0)
                                {
                                        printf("Error al buscar el cargo");
                                        sprintf(respuesta.texto.datos,"%s","03");
                                }
                                else
                                {
                                        printf("Cargo encontrado correctamente\n\n");
                                }
			
				sprintf(respuesta.texto.datos,"/%2s/%6s/%1000s","01",SQL_nombrecargo.arr,SQL_descripcion.arr);
				 	 
			//}
			//else
			//{printf("\nNo existe cargo\n\n");
			//		sprintf(respuesta.texto.datos,"%2s","02");
 
			//}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin elicar
		
		if(strcmp(formulario,"insemp") == 0)
		{ printf("\nEn insemp\n\n");
			char descrip[1001];
			char nomc[61];
			memset(descrip,'\0',sizeof descrip);
			memset(nomc,'\0',sizeof nomc);
			sscanf(mensaje.texto.datos,"%6c",formulario);
			
	       
			
			
			//printf("El nomc es: %s", nomc);

			 
			sprintf(SQL_nombrecargo.arr,"%s", nomc);
			SQL_nombrecargo.len=strlen(SQL_nombrecargo.arr);
			
			sprintf(SQL_descripcion.arr,"%s", descrip);
			SQL_descripcion.len=strlen(SQL_descripcion.arr);
			   
			//EXEC SQL SELECT COUNT (*) INTO :SQL_count FROM cargos WHERE nombre_cargo = :SQL_nombrecargo;
			memset(&respuesta,0,sizeof respuesta);
			//if (SQL_count != 0)
			//{
			
							{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre_cargo from cargos", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_descripcion),(long)1001,(long)1,sizeof(struct varchar_SQL_descripcion_38), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1336 "demonio.pgc"

                                { ECPGtrans(__LINE__, NULL, "commit");}
#line 1337 "demonio.pgc"

                                if (sqlca.sqlcode != 0)
                                {
                                        printf("Error al buscar el cargo");
                                        sprintf(respuesta.texto.datos,"%s","03");
                                }
                                else
                                {
                                        printf("Cargo encontrado correctamente\n\n");
					printf("datos: %s" ,SQL_descripcion.arr);
                                }
				sprintf(respuesta.texto.datos,"/%2s/%1000s","01",SQL_descripcion.arr);
				 	 
			//}
			//else
			//{printf("\nNo existe cargo\n\n");
			//		sprintf(respuesta.texto.datos,"%2s","02");
 
			//}
			
			
			respuesta.mtype = pid_destino;
      		respuesta.texto.pid = pid;
      		msgsnd (qid, &respuesta, strlen(respuesta.texto.datos)+4, 0);
		}
		//fin insemp
		
		if(strcmp(formulario,"moscar") == 0)
		{ 			printf("Recibi: %s\n\n",mensaje.texto.datos);
			int ccont2;
			int x;
			sscanf(mensaje.texto.datos,"%6s%10d",formulario,&ccont2);
			/* declare curs2 cursor for select nombre_cargo , descripcion from cargos */
#line 1369 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs2 cursor for select nombre_cargo , descripcion from cargos", ECPGt_EOIT, ECPGt_EORT);}
#line 1370 "demonio.pgc"

			
			//for(x=0;x<=ccont2;x++){
			memset(SQL_nombrec1.arr,0,sizeof SQL_nombrec1.arr);
                

			//	memset(SQL_nombrec2.arr,0,sizeof SQL_nombrec2.arr);
                   //       memset(SQL_nombrec3.arr,0,sizeof SQL_nombrec3.arr);
                     //     memset(SQL_nombrec4.arr,0,sizeof SQL_nombrec4.arr);
                       //   memset(SQL_nombrec5.arr,0,sizeof SQL_nombrec5.arr);
                        //  memset(SQL_nombrec6.arr,0,sizeof SQL_nombrec6.arr);
			memset(SQL_dc1.arr,0,sizeof SQL_dc1.arr);
                       //memset(SQL_dc2.arr,0,sizeof SQL_dc2.arr);
                  //      memset(SQL_dc3.arr,0,sizeof SQL_dc3.arr);
                  //      memset(SQL_dc4.arr,0,sizeof SQL_dc4.arr);
                  //      memset(SQL_dc5.arr,0,sizeof SQL_dc5.arr);
                  //      memset(SQL_dc6.arr,0,sizeof SQL_dc6.arr);


			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs2", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombrec1),(long)61,(long)1,sizeof(struct varchar_SQL_nombrec1_45), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_dc1),(long)1001,(long)1,sizeof(struct varchar_SQL_dc1_39), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1389 "demonio.pgc"

			//EXEC SQL FETCH curs2 INTO :SQL_nombrec2,:SQL_dc2;
			//EXEC SQL FETCH curs2 INTO :SQL_nombrec3,:SQL_dc3;
			//EXEC SQL FETCH curs2 INTO :SQL_nombrec4,:SQL_dc4;
			//EXEC SQL FETCH curs2 INTO :SQL_nombrec5,:SQL_dc5;
			//EXEC SQL FETCH curs2 INTO :SQL_nombrec6,:SQL_dc6;
			//}
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close curs2", ECPGt_EOIT, ECPGt_EORT);}
#line 1396 "demonio.pgc"

                        memset(&respuesta,0,sizeof respuesta);
						
			//ccont2=ccont2++;
			//if (sqlca.sqlcode != 0)
			//{   
			//			sprintf(respuesta.texto.datos,"%s","02");
			//}
			//else
			//{	

 
                //        if(strcmp(SQL_nombrec6.arr,"")==0)
                  //      {
				//memset(&respuesta,0,sizeof respuesta);
				//sprintf(respuesta.texto.datos,"%2s%10d%60s%1000s%60s%1000s%60s%1000s%60s%1000s%60s%1000s%60s%1000s","03",ccont2,SQL_nombrec1.arr,SQL_dc1.arr,SQL_nombrec2.arr,SQL_dc2.arr,SQL_nombrec3.arr,SQL_dc3.arr,SQL_nombrec4.arr,SQL_dc4.arr,SQL_nombrec5.arr,SQL_dc5.arr,SQL_nombrec6.arr,SQL_dc6.arr);
			 	//sprintf(respuesta.texto.datos,"%2s%10d%60s%1000s","03",ccont2,SQL_nombrec1.arr,SQL_dc1.arr);
				//printf("mande: %s\n",respuesta.texto.datos);
                 //               respuesta.mtype=pid_destino;
                 //               respuesta.texto.pid=pid;
                 //               msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				//memset(SQL_nombrec1.arr,'\0',sizeof SQL_nombrec1.arr); 
				//memset(SQL_nombrec2.arr,'\0',sizeof SQL_nombrec2.arr);
				//memset(SQL_nombrec3.arr,'\0',sizeof SQL_nombrec3.arr);
				//memset(SQL_nombrec4.arr,'\0',sizeof SQL_nombrec4.arr);
				//memset(SQL_nombrec5.arr,'\0',sizeof SQL_nombrec5.arr);
				//memset(SQL_nombrec6.arr,'\0',sizeof SQL_nombrec6.arr);
				//memset(SQL_dc1.arr,'\0',sizeof SQL_dc1.arr);
                              //  memset(SQL_dc2.arr,'\0',sizeof SQL_dc2.arr);
                               // memset(SQL_dc3.arr,'\0',sizeof SQL_dc3.arr);
                               // memset(SQL_dc4.arr,'\0',sizeof SQL_dc4.arr);
                              //  memset(SQL_dc5.arr,'\0',sizeof SQL_dc5.arr);
                              //  memset(SQL_dc6.arr,'\0',sizeof SQL_dc6.arr);

                       //         printf("No quedan mas cargos que mostrar-b\n");

                    //    }
				//else{

				memset(&respuesta,0,sizeof respuesta);
				//sprintf(respuesta.texto.datos,"%2s%10d%60s%1000s%60s%1000s%60s%1000s%60s%1000s%60s%1000s%60s%1000s","01",ccont2,SQL_nombrec1.arr,SQL_dc1.arr,SQL_nombrec2.arr,SQL_dc2.arr,SQL_nombrec3.arr,SQL_dc3.arr,SQL_nombrec4.arr,SQL_dc4.arr,SQL_nombrec5.arr,SQL_dc5.arr,SQL_nombrec6.arr,SQL_dc6.arr);
			 	sprintf(respuesta.texto.datos,"/%2s/%60s/%1000s","01",SQL_nombrec1.arr,SQL_dc1.arr);  
				printf("mande: %s\n",respuesta.texto.datos);
                                respuesta.mtype=pid_destino;
                                respuesta.texto.pid=pid;
                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);
				memset(SQL_nombrec1.arr,'\0',sizeof SQL_nombrec1.arr); 
				//memset(SQL_nombrec2.arr,'\0',sizeof SQL_nombrec2.arr);
				//memset(SQL_nombrec3.arr,'\0',sizeof SQL_nombrec3.arr);
				//memset(SQL_nombrec4.arr,'\0',sizeof SQL_nombrec4.arr);
				//memset(SQL_nombrec5.arr,'\0',sizeof SQL_nombrec5.arr);
				//memset(SQL_nombrec6.arr,'\0',sizeof SQL_nombrec6.arr);
				memset(SQL_dc1.arr,'\0',sizeof SQL_dc1.arr);
                               //memset(SQL_dc2.arr,'\0',sizeof SQL_dc2.arr);
                            //   memset(SQL_dc3.arr,'\0',sizeof SQL_dc3.arr);
                           //    memset(SQL_dc4.arr,'\0',sizeof SQL_dc4.arr);
                           //     memset(SQL_dc5.arr,'\0',sizeof SQL_dc5.arr);
                            //    memset(SQL_dc6.arr,'\0',sizeof SQL_dc6.arr);


				//}

			//}
		}
		//fin moscar
	

		if(strcmp(formulario,"caremp") == 0)
		{ 			printf("Recibi: %s\n\n",mensaje.texto.datos);
			int ccont2;
			int x;
			sscanf(mensaje.texto.datos,"%6s%10d",formulario,&ccont2);
			
		}
		//fin caremp	
		
		
		if(strcmp(formulario,"fondos") == 0)
				{ 			
						printf("En fondos");

						sscanf(mensaje.texto.datos,"%6s",formulario);
						{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select capital from fondos", ECPGt_EOIT, 
	ECPGt_int,&(SQL_capital),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1478 "demonio.pgc"

						{ ECPGtrans(__LINE__, NULL, "commit");}
#line 1479 "demonio.pgc"

			
										
					if(sqlca.sqlcode != 0) {
						
						printf("\nERROR en la consulta SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					} else {			 
												printf("\nConsulta fondos bien SQL\n\n");
												printf("fondos:%d\n", SQL_capital);
                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "/%2s/%10d","01",SQL_capital);
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
			 
				}
		//fin fondos	
		
		 
		if(strcmp(formulario,"modfon") == 0)
				{ 			
						printf("En modfon");

						int dinero3;
						
						char fodos_new[11];

                         //Limpiamos los Strings

                         memset (fodos_new, 0, sizeof fodos_new);

                         //Recibimos los datos desde el .c

                        sscanf(mensaje.texto.datos,"%6c%10d",formulario,&dinero3);
									
						SQL_num1=dinero3;
 
						printf("Se reciben los siguientes datos:\nDinero: %d\n\n",SQL_num1);
						
			             { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fondos set capital = $1 ", 
	ECPGt_int,&(SQL_num1),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1527 "demonio.pgc"

                         { ECPGtrans(__LINE__, NULL, "commit");}
#line 1528 "demonio.pgc"

			
					if(sqlca.sqlcode != 0) 
						{
						
						printf("\nERROR en la actualizacion SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                        sprintf(respuesta.texto.datos, "%s", "02");
                        respuesta.mtype=pid_destino;
                        respuesta.texto.pid=pid;
                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

						} else {			 
								printf("\nactualizacion fondos bien SQL\n\n");
								memset(&respuesta,0,sizeof respuesta);
								sprintf(respuesta.texto.datos, "%s", "01");
								respuesta.mtype=pid_destino;
								respuesta.texto.pid=pid;
								msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
			 
				}
		//fin modfon
		
		
		if(strcmp(formulario,"fonmos") == 0)
				{ 			
						printf("En fonmos");

						sscanf(mensaje.texto.datos,"%6s",formulario);
						//EXEC SQL SELECT nombre,rut,sueldo,estado_p INTO :SQL_nombref,:SQL_rutf,:SQL_sueldof,:SQL_estadof FROM empleados;
						//EXEC SQL COMMIT;

						
						
								/* declare curs3 cursor for select nombre , rut , sueldo , estado_p from empleados */
#line 1565 "demonio.pgc"

			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare curs3 cursor for select nombre , rut , sueldo , estado_p from empleados", ECPGt_EOIT, ECPGt_EORT);}
#line 1566 "demonio.pgc"

			
			memset(SQL_nombref.arr,0,sizeof SQL_nombref.arr);
			memset(SQL_rutf.arr,0,sizeof SQL_rutf.arr);
			memset(SQL_sueldof.arr,0,sizeof SQL_sueldof.arr);
			memset(SQL_estadof.arr,0,sizeof SQL_estadof.arr);


			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch curs3", ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombref),(long)61,(long)1,sizeof(struct varchar_SQL_nombref_52), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_rutf),(long)11,(long)1,sizeof(struct varchar_SQL_rutf_53), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_sueldof),(long)16,(long)1,sizeof(struct varchar_SQL_sueldof_54), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_estadof),(long)3,(long)1,sizeof(struct varchar_SQL_estadof_55), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1574 "demonio.pgc"

						
						
						
										
					if(sqlca.sqlcode != 0) {
						
						printf("\nERROR en la consulta SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					} else {			 
												printf("\nConsulta fonmos bien SQL2\n\n");
												//printf("fonmos5:%s\n", SQL_nombref);
                                                memset(&respuesta,0,sizeof respuesta);
												
                                                sprintf(respuesta.texto.datos, "/%2s/%60s/%10s/%15s/%2s","01",SQL_nombref.arr,SQL_rutf.arr,SQL_sueldof.arr,SQL_estadof.arr);
												
												
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
			 
				}
		//fin fonmos	
	

if(strcmp(formulario,"fonpag") == 0)
				{ 			
						printf("En fonpag2");
						char remp[11];
						int dinero3;
						
						char fodos_new[11];

                         //Limpiamos los Strings
						memset(remp,'\0',sizeof remp);
                         memset (fodos_new, 0, sizeof fodos_new);

                         //Recibimos los datos desde el .c

                        sscanf(mensaje.texto.datos,"%6c%10s",formulario,remp);
									
						//sprintf(SQL_rutfondos.arr,"%s", remp);
						//SQL_rutfondos.len=strlen(SQL_rutfondos.arr);

				sprintf(SQL_rut.arr,"%10s", remp);
				SQL_rut.len=strlen(SQL_rut.arr);
printf("El rut es: %s", SQL_rut.arr); 

						
						//printf("Se reciben los siguientes datos:\nrutemp: %s\n\n",SQL_rutfondos);
						
						{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select sueldo from empleados where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)11,(long)1,sizeof(struct varchar_SQL_rut_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_sueldocap),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1633 "demonio.pgc"

						{ ECPGtrans(__LINE__, NULL, "commit");}
#line 1634 "demonio.pgc"

						if(sqlca.sqlcode != 0) 
						{printf("\nERROR select sueldo SQL\n\n");}
						
						{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select capital from fondos", ECPGt_EOIT, 
	ECPGt_int,&(SQL_capital),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 1638 "demonio.pgc"

						{ ECPGtrans(__LINE__, NULL, "commit");}
#line 1639 "demonio.pgc"

						if(sqlca.sqlcode != 0) 
						{printf("\nERROR select capital SQL\n\n");}
 printf("sueldo:%d\n", SQL_sueldocap);

printf("capital:%d\n", SQL_capital);

printf("resto:%d\n", SQL_num1);

						SQL_num1=SQL_capital-SQL_sueldocap;
						if(SQL_num1<0){SQL_num1=0;}
						
			             { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update fondos set capital = $1 ", 
	ECPGt_int,&(SQL_num1),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 1651 "demonio.pgc"

                         { ECPGtrans(__LINE__, NULL, "commit");}
#line 1652 "demonio.pgc"

						 if(sqlca.sqlcode != 0) 
						{printf("\nERROR update fondos SQL\n\n");}
						 
						 { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update empleados set estado_p = '2'", ECPGt_EOIT, ECPGt_EORT);}
#line 1656 "demonio.pgc"
 
                         { ECPGtrans(__LINE__, NULL, "commit");}
#line 1657 "demonio.pgc"

						 if(sqlca.sqlcode != 0) 
						{printf("\nERROR update empleados SQL\n\n");}
			
					if(sqlca.sqlcode != 0) 
						{
						
						printf("\nERROR en la actualizacion SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                        sprintf(respuesta.texto.datos, "%s", "02");
                        respuesta.mtype=pid_destino;
                        respuesta.texto.pid=pid;
                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

						} else {			 
								printf("\nactualizacion fondos bien SQL\n\n");
								memset(&respuesta,0,sizeof respuesta);
								sprintf(respuesta.texto.datos, "%s", "01");
								respuesta.mtype=pid_destino;
								respuesta.texto.pid=pid;
								msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}
			 
				}
		//fin fonpag	
		
		
}
}
}


