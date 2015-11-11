#include "funciones.h"

int compruebaElementoVector(int * vector, int elem, int nelem){
int i=0;
	for(i=0; i<nelem; i++){
		if(vector[i]==elem){
			return 1;
		}
	}

	return 0;

}

int compruebaElementoMatriz(int ** matriz, int elem){
	//Con esta funcion comprobamos si el elemento esta en la matriz
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<9; j++){
			if(matriz[i][j] == elem){
				return 1;
			}
		}
	}
	
return 0;

}

int ** generaCarton(){
	int ** carton;
	int i,j,k=0;
	int aux;
	int quita;
	int quitados[4];
	int siguiente;
	//reservamos memoria
	
	carton = (int **)malloc(3*sizeof(int*));
	for(i=0; i<3; i++){
		carton[i] = (int*)malloc(9*sizeof(int));
	}

	//Rellenamos el carton con ceros
	for(i=0; i<3; i++){
		for(j=0; j<9; j++){
			carton[i][j]=0;
		}
	}
	
	//Hacemos las bolas aleatorias para el carton

	for(i=0; i<3; i++){
		for(j=0; j<9; j++){
			aux = (rand()%10) +j*10;
			if(j==8){
				aux = (rand()%11) +j*10;
			}
			if(aux==0){
				while(aux==0){
					aux=rand()%10;
				}
			}
			if(!compruebaElementoMatriz(carton, aux)){
				carton[i][j] = aux;
			}else{
				j--;
			}
		}
	}
	//Rellenamos el vector de quitados con 10
	for(i=0; i<4; i++){
		quitados[i] = 10;
	}

	//Ahora deberemos quitar 4 numeros por fila
	for(i=0; i<3;i++){
		siguiente=1;
		while(k!=4){
			quita = rand()%9;
			if(!compruebaElementoVector(quitados, quita, 4)){
				quitados[k] = quita;
				k++;
				carton[i][quita] = 0;
			}
		}
		for(j=0; j<4; j++){
		quitados[i] = 10;
		}
		k=0;
	}
	
	return carton;
}


void muestraCarton(int ** carton){
	int i,j;

	for(i=0; i<3; i++){
		for(j=0; j<9; j++){
			if(carton[i][j]==0){
				printf("X\t");
			}else{
			printf("%d\t", carton[i][j]);
			}
		}
		printf("\n");
	}

}


int registroUsuario(char usuario[50], char password[50]){
	FILE * fichero;
	char buffer[512];
	char * usu;
	char cadena[120];
	int valido=1;

	fichero = fopen("usuarios.txt", "r");

	valido = compruebaUsuario(usuario);

	//Ahora si valido sigue estando a 1, escribimos
	if(valido==0){
		//Escribimos en el fichero
		fclose(fichero);
		fichero = fopen("usuarios.txt", "a");
		strcpy(cadena, usuario);
		strcat(cadena, " ");
		strcat(cadena, password);
		fputs(cadena, fichero);
		fputs("\n", fichero);
		//Cerramos fichero
		fclose(fichero);
		return 1;

	}else{
		fclose(fichero);
		//Devolvemos 0
		return 0;
	}

}

int compruebaUsuario(char usuario[50]){
	FILE * fichero;
	char buffer[512];
	int vuelta=0;
	char * usu;

	fichero = fopen("usuarios.txt", "r");

	while((fgets(buffer,512,fichero))!=NULL){
		usu = strtok(buffer, " ");
		if(strcmp(usu, usuario)==0){
			vuelta=1;// El usuario ya existe en el fichero	
		}
	}

	return vuelta;
}

int compruebaUsuarioPassword(char usuario[50], char password[50]){
	FILE * fichero;
	char buffer[512];
	int vuelta=0;
	char * usu;
	char * pass;
	char aux[50];

	fichero = fopen("usuarios.txt", "r");

	while((fgets(buffer, 512, fichero))!=NULL){
		usu = strtok(buffer, " ");

		if(strcmp(usu, usuario)==0){
			//Comprobamos la contraseña
			strncpy(aux, buffer+strlen(usu)+1, 50);
			
			pass = strtok(aux, "\n");
			//Y ahora comparamos la pass dada con la de ese usuario
			if(strcmp(pass, password)==0){
				vuelta=1;
			}

		}

	}

	fclose(fichero);

	return vuelta;
}

//Devuelve la posicion en la que se encuentra el cliente segundo el descriptor dado
int devuelvePosicion(struct cliente arrayClientes[MAX_CLIENTES], int descriptor, int numClientes){

	//Recorremos el array, buscando 
	int i;

	for(i=0; i<numClientes; i++){
		if(arrayClientes[i].descriptor == descriptor){
			return i;
		}
	}

	return -1;
}