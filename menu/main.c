#include <stdio.h>

int main(){
	/*
		Este programa es un menú sencillo
		Selecciona una opción:
			1) Hola
			2) Adiós
		Declarar un for:
		for(variableEnteraAContar; condición del tipo [variable <=Numero]; aumento [variable += 1])
		while(variable <= condición)
		do{
			cuerpo
		}while(condición);
	*/
	int opcion;
	do{
		//printf("Selecciona una opción:\n\t1)Saludo\n\t2)Adiós\n");
		printf("Selecciona una opción:\n");
		printf("\t1)Saludo\n");
		printf("\t2)Vámonos\n");
		if(scanf("%d", &opcion) == 1){
			switch(opcion){
				case 1:
					printf("Hola!, mucho gusto\n");
				break;
				case 2:
					printf("Adiós banda! \n");
				break;
				default:
					printf("Opción no válida\n");
				break;
			}
		}else{
			printf("Eso no es un número\n");
			setbuf(stdin, NULL);
		}
	}while(opcion != 2);
	return 0;
}
