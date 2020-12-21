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
	int tam = 20;
	FILE* texto = NULL;
	char caracter;
	int frequencias[tam];
	char palabra[tam];
	int i = 0, max = 0, min = 100;
	texto = fopen("archivo.txt", "r");
	for(int i = 0; i < tam; i++){
		frequencias[i] = 0;
	}
	for(int i = 0; i < tam; i++){
		printf("%d->%d\n", i, frequencias[i]);
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
			frequencias[i] += 1;
			printf("%s\n", palabra);
			i = 0;
		}else if(caracter == '\n'){
			palabra[i] = '\0';
			frequencias[i] += 1;
			printf("%s\n", palabra);
			i = 0;
		}
		if(feof(texto)){
			break;
		}
	}
	for(int i = 1; i < tam; i++){
		if(frequencias[i] > max){
			max = frequencias[i];
		}else if(frequencias[i] < min && frequencias[i] > 0){
			min = frequencias[i];
		}
		printf("%d->%d\n", i, frequencias[i]);
	}
	printf("\n");
	printf("Mayor frecuencia: %d, menos frcuencia: %d\n", max, min);
	fclose(texto);
	return 0;
}
