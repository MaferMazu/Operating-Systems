#include <stdio.h>
#include <stdlib.h>
using System;

/*Estructura de datos*/
#include "hash.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int lenPelicula = 1024;
	int lenCancion = 1024;
	int lenPrintCancion = 16;
	int eficiencia = 16;

	while(true){

		Console.WriteLine("Introduzca el nombre de la pelicula:");
		String texto;
		texto=Console.ReadLine();

		if(texto.compare("---")==0){
			while(true){
				int num;
				printf("%s\n","Configuracion de busqueda:\n\n
				1. Longitud máxima del nombre de la película (por defecto, 1024 caracteres)\n
				2. Longitud máxima del nombre de la canción (por defecto, 1024 caracteres)\n
				3. Número máximo de canciones a imprimir (por defecto 16 canciones)\n
				4. Eficiencia (por defecto 16 buckets)\n
				5. Cancelar cambio de configuración\n
				6. Salir del programa\n");

				num=Console.ReadInt();
				if(0<num<7){
					int num1;
					if(num==1){
						Console.WriteLine("Introduzca la longitud maxima del nombre de la pelicula");
						num1=Console.ReadInt();
						lenPelicula = num1;
					}
					if(num==2){
						Console.WriteLine("Introduzca la longitud maxima del nombre de la cancion");
						num1=Console.ReadInt();
						lenCancion = num1;
					}
					if(num==3){
						Console.WriteLine("Introduzca la longitud maxima canciones a escribir");
						num1=Console.ReadInt();
						lenPrintCancion = num1;
					}
					if(num==4){
						Console.WriteLine("Introduzca la eficiencia");
						num1=Console.ReadInt();
						eficiencia = num1;
					}
					if(num==5){
						int lenPelicula = 1024;
						int lenCancion = 1024;
						int lenPrintCancion = 16;
						int eficiencia = 16;
						Console.WriteLine("Se ha cancelado el cambio de configuracion y todos los valores estan por defecto");
					}
					if(num==6){
						exit(0);
					}
				}
			}
			
		}

	    HashTable_t *ht = ht_create(eficiencia);

	    
	    
	    /* Probadno la tabla de hash */
	    
	    //insert 

	    ht_insert(ht, "pelicula 1", "cancion x");
	    ht_insert(ht, "pelicula 2", "cancion y");
	    ht_insert(ht, "pelicula 3", "cancion z");

		// printf table
		
	    printf("%s\n", ht_index(ht, "pelicula 1"));
	    printf("%s\n", ht_index(ht, "pelicula 2"));
	    printf("%s\n", ht_index(ht, "pelicula 3"));
	    
	    //Limpiamos la tabla
	    
	    ht_free(ht);
	    
	    /* Probando la lista */
	    
	    //Creamos lista
	    List * list = emptylist();
	    
	    //Add
		add("cancion 1", list);
		add("cancion 2", list);
		add("cancion 3", list);
		
		//show
		display(list);
		
		//delete
		delete("cancion 1", list);
		
		//show
		display(list);
		
		//reversed
		reverse(list);
		printf("Reversed: ");
		display(list);
		
		//limpiamos lista
		destroy(list);
		return 0;
	}
}
