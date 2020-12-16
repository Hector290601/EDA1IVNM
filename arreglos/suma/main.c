#include <stdio.h>

void suma();

int main(){
	/*
		Este programa va a sumar n matrices de pxq las cuales serán ingresas y especificadas por el usuario, igualmente, avisará si es una matriz simétrica 
	*/
	int opc;
	do{
		printf("Seleccione una opción\n");
		printf("\t1)Sumar\n");
		printf("\t2)Salir\n");
		if(scanf("%d", &opc)){
			switch(opc){
				case 1:
					suma();
				break;
				case 2:
					printf("Adiós!\n");
				break;
				default:
					printf("Opción no válida\n");
				break;
			}
		}else{
			printf("No es un número\n");
		}
	}while(opc != 2);
	return 0;
}

void suma(){
	int p, q, n;
	printf("Cuántas matrices son?: ");
	if(scanf("%d", &n) == 1){
		printf("Ingrese el número de columnas: ");
		if(scanf("%d", &p) == 1){
			printf("Ingrese el número de filas: ");
			if(scanf("%d", &q) == 1){
				/////////////////////////////////////////////////////////////////////////////////////////////////////////DECLARAR LAS MATRICES
				int matrices[p][q][n], tmp, suma[p][q];
				/////////////////////////////////////////////////////////////////////////////////////////////////////////LLENAR LAS MATRICES
				for(int i = 0; i < n; i++){
					////////////////////////////////////////////////////////////////////////////////////////////////RECORRE LAS N MATRICES
					for(int j = 0; j < q; j++){
						///////////////////////////////////////////////////////////////////////////////////////RECORRE LOS REGNLONES DE CADA MATRIZ
						for(int k = 0; k < p; k++){
							//////////////////////////////////////////////////////////////////////////////RECORRE LAS COLUMNAS DE CADA MATRIZ
							printf("Ingrese el valor de la matriz %d en la posición [%d][%d]: ", i, k, j);
							if(scanf("%d", &tmp) == 1){
								matrices[k][j][i] = tmp;
								suma[k][j] = 0;
							}else{
								printf("Eso no es un número\n");
								k = k - 1;
							}
						}
					}
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////IMPRIME LAS N MATRICES
				for(int i = 0; i < n; i++){
					printf("Matriz %d [\n", i);
					for(int j = 0; j < q; j++){
							printf("\t[");
						for(int k = 0; k < p; k++){
								if(k + 1 < q){
									printf("%d, ", matrices[k][j][i]);
								}else{
									printf("%d]\n", matrices[k][j][i]);
								}
						}
					}
					printf("]\n");
				}
				/////////////////////////////////////////////////////////////////////////////////////////////////SUMA LAS N MATRICES EN UNA MATRIZ DE PxQ
				for(int i = 0; i < n; i++){
					for(int j = 0; j < q; j++){
						for(int k = 0; k < p; k++){
							suma[j][k] += matrices[k][j][i];
						}
					}
				}
				/////////////////////////////////////////////////////////////////////////////////////////////// IMPRIMIMOS LA MATRIZ SUMADA
				printf("La suma de matrices es: [\n");
				for(int i = 0; i < p; i++){
					printf("\t[");
					for(int j = 0; j < q; j++){
						if(j + 1 < q){
							printf("%d, ", suma[i][j]);
						}else{
							printf("%d", suma[i][j]);
						}
					}
					printf("]\n");
				}
				printf("]\n");
			}else{
				return;
			}
		}else{
			return;
		}
	}else{
		return;
	}
}

