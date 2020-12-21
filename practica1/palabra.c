#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Mexicanos la a ABCDEFGHIJKLMNOPQRS Hola mundo el pan es rico, come bien.
//palabra[20] = {'M', 'e', 'x', 'i', 'c', 'a', 'n', 'o', 's', '\0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
//palabra[20] = {'l', 'a', '\0', 'i', 'c', 'a', 'n', 'o', 's', '\0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
//palabra[20] = {'a', '\0', 'x', 'i', 'c', 'a', 'n', 'o', 's', '\0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
//palabra[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'H', 'o', 'l', 'a', '\0', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'m', 'u', 'n', 'd', 'o', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'e', 'l', '\0', 'd', 'o', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'p', 'a', 'n', '\0', 'o', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'e', 's', '\0', '\0', 'o', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'r', 'i', 'c', 'o', '\0', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'\0', 'i', 'c', 'o', '\0', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'c', 'o', 'm', 'e', '\0', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'b', 'i', 'e', 'n', '\0', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//palabra[20] = {'\0', 'i', 'e', 'n', '\0', '\0', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', '\0'}
//frequencias[10][2] = [[], [], [], [], [], [], [], [], [], []], [[], [], [], [], [], [], [], [], [], []]

int main(){
	FILE* texto = NULL;
	char caracter;
	char frequencias[100][20];
	int frequenciasInt[100];
	char palabra[20];
	int i = 0;
	texto = fopen("archivo.txt", "r");
	for(int i = 0; i < 100; i++){
		strcpy(frequencias[i], "");
		frequenciasInt[i] = 0;
	}
	for(int i = 0; i < 100; i++){
		printf("%s->%d", frequencias[i], frequenciasInt[i]);
	}
	printf("\n");
	i = 0;
	while(texto != NULL){
		caracter = fgetc(texto);
		/*
		if(caracter == ' '){
			printf("\n");
		}else if(caracter == ','){
			printf(" ");
		}else if(caracter == '.'){
			printf("  ");
		}else if(caracter == ':'){
			printf(" ");
		}else{
			if(feof(texto)){
				break;
			}
			printf("%c", caracter);
		}*/
		if(isalpha(caracter)){
			palabra[i] = caracter;
			i += 1;
		}else if(caracter == ' '){
			palabra[i] = '\0';
			for(int j = 0; j < 100; j++){
				if(!strcmp(frequencias[j], palabra)){
					printf("no es una nueva palabra\n");
					frequenciasInt[j] += 1;
					break;
				}else if(strcmp(frequencias[j], "")){
					printf("es una nueva palabra\n");
					strcpy(frequencias[j], palabra);
					frequenciasInt[j] = 1;
				}
			}
			printf("%s\n", palabra);
			i = 0;
		}else if(caracter == '\n'){
			palabra[i] = '\0';
			for(int j = 0; j < 100; j++){
				if(!strcmp(frequencias[j], palabra)){
					printf("no es una nueva palabra\n");
					frequenciasInt[j] += 1;
					break;
				}else if(strcmp(frequencias[j], "")){
					printf("es una nueva palabra\n");
					strcpy(frequencias[j], palabra);
					frequenciasInt[j] = 1;
				}
			}
			printf("%s\n", palabra);
			i = 0;
		}
		if(feof(texto)){
			break;
		}
	}
	for(int i = 0; i < 100; i++){
		if(frequencias[i] != "  "){
			printf("%s->%d", frequencias[i], frequenciasInt[i]);
		}else{
			break;
		}
	}
	printf("\n");
	fclose(texto);
	return 0;
}
