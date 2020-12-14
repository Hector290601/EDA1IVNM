#include <stdio.h>

/*
#define COLUMNS 3
#define ROWS 3
tipoDeValorDeRetorno nombreDeLaFunción(Parámetros){
	cuerpo
	return si es necesario
}

int main(void){
	return 1;
}

float main(vois){
	return 1.1;
}

void main(void){
	
}

char main(void){
	return 'c';
}

matriz = [1, 6, 9]
matriz = [[1], [6], [9]]
matriz= [1,
	 6,
	 9]
*/

int main(void){
	int COLUMNS, ROWS;
	printf("Ingrese el número de columnas: ");
	scanf("%d", &COLUMNS);
	printf("Ingrese el número de filas: ");
	scanf("%d", &ROWS);
	int matriz[COLUMNS][ROWS], tmp, matrizTranspuesta[COLUMNS][ROWS];
	for(int i = 0; i < COLUMNS; i++){
		for(int j = 0; j < ROWS; j++){
			printf("Ingrese el valor de la matriz[%d][%d]\n", i, j);
			scanf("%d", &tmp);
			matriz[i][j] = tmp;
		}
	}
	printf("matriz = [\n\t[");
	for(int i = 0; i < COLUMNS; i++){
		for(int j = 0; j < ROWS; j++){
			if(j < ROWS - 1){
				printf("%d,", matriz[i][j]);
			}else{
				printf("%d", matriz[i][j]);
			}
		}
		if(i < COLUMNS - 1){
			printf("]\n\t[");
		}else{
			printf("]\n");
		}
	}
	printf("]\n");
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++){
			matrizTranspuesta[i][j] = matriz[j][i];
		}
	}
	printf("matriz Transpuesta = [\n\t[");
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLUMNS; j++){
			if(j < COLUMNS - 1){
				printf("%d,", matrizTranspuesta[i][j]);
			}else{
				printf("%d", matrizTranspuesta[i][j]);
			}
		}
		if(i < ROWS -1){
			printf("]\n\t[");
		}else{
			printf("]\n");
		}
	}
	printf("]\n");
	return 1;
}

