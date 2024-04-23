/*
 * AndreNascimentoInfo2_12_03.c
 *
 *  Created on: 12 de mar. de 2024
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void determinante(int m[2][2]) {
	int a = m[0][0] * m[1][1];
	int b = m[1][0] * m[0][1];
	int d = a - b;

	printf("O determinante da matriz é: %d", d);
}

void atv1() {
	printf("Atividade 1\n");
	int m1[2][2];
	int i, j, k, l;
	printf("Entre com os elementos da matriz:\n");

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("Entre com o elemento [%d][%d]: ", i, j);
			scanf("%d", &m1[i][j]);
		}
	}

	printf("\nA matriz é: \n");

	for (k = 0; k < 2; k++) {
		for (l = 0; l < 2; l++) {
			printf("[%d]\t", m1[k][l]);
		}
		printf("\n");
	}

	determinante(m1);
}

void atv2() {
	printf("\n\nAtividade 2\n");

	int a = 0;
	int b = 0;
	char nome[15];

	printf("Digite o nome do arquivo de texto que deseja abrir: ");
	scanf("%s", nome);

	strcat(nome,".txt");

	printf("\nDigite o tamanho de linhas e colunas que seu arquivo possui: ");
	scanf("%d %d", &a, &b);

	char mm[a][b];
	char * token;
	int x = 0;
	int z = 0;
	int r = 0;
	int h = 0;
	int f = 0;
	int c = 0;
	int d = 0;
	char str[50];
	char caractere[50] = "";

	FILE *file = fopen(nome, "r");

	if (file == NULL) {
		printf("Não foi possível ler o arquivo\n");
	}

	while(fgets(str, sizeof(str), file) != NULL){
		token = strtok(str," ,\n");
		while(token != NULL){
			strcat(caractere, token);

			token = strtok(NULL," ,\n");
		}
	}


	for (r = 0; r < (strlen(caractere)); r++){
		mm[x][z++] = caractere[r];
	}

	printf("\nMatriz lida: \n");

	for (h = 0; h < a; h++) {
		for (f = 0; f < b; f++) {
			printf("[%c]\t", mm[h][f]);
		}
		printf("\n");
	}

	for(c = 0; c < a; c++){
		for (d = 0; d < b; d++){
			switch(mm[c][d]){
			case '0':
				mm[c][d] = 'a';
				break;
			case '1':
				mm[c][d] = 'e';
				break;
			case '2':
				mm[c][d] = 'i';
				break;
			case '3':
				mm[c][d] = 'o';
				break;
			case '4':
				mm[c][d] = 'u';
				break;
			}
		}
	}

	printf("\nMatriz modificada: \n");

	for (h = 0; h < a; h++) {
		for (f = 0; f < b; f++) {
			printf("[%c]\t", mm[h][f]);
		}
		printf("\n");
	}

	fclose(file);
}

void maiormenor(int vet[], int tam, int *numMaior, int *numMenor){
	int contador1;

	*numMenor = vet[0];

	for(contador1 = 0; contador1 < tam; contador1++){
		if(vet[contador1] > *numMaior){
			*numMaior = vet[contador1];
		}
		if(vet[contador1] < *numMenor){
			*numMenor = vet[contador1];
		}
	}
}

void inverte(int vetor[], int tamanho){
	int cont;
	int cont2;
	int cont3 = 0;
	int vetorintermediario[tamanho];

	for(cont = 0; cont < tamanho; cont++){
		vetorintermediario[cont] = vetor[cont];
	}

	for(cont2 = 4; cont2 >= 0; cont2--){
		vetor[cont3] = vetorintermediario[cont2];
		cont3++;
	}
}

void atv3(){
	printf("\n\nAtividade 3\n");

	int array[5];
	int contador;
	int maior = 0;
	int menor = 0;

	printf("Forneça os valores do array de 5 espaços: ");

	for(int i = 0; i < 5; i++){
		scanf("%d", &array[i]);
	}

	printf("Vetor normal: ");

	for(contador = 0; contador < 5; contador++){
				printf("%d", array[contador]);
	}

	maiormenor(array, 5, &maior, &menor);
	inverte(array, 5);

	printf("\nVetor invertido: ");

	for(contador = 0; contador < 5; contador++){
				printf("%d", array[contador]);
	}

	printf("\nO maior e o menor número deste vetor são, respectivamente: %d, %d", maior, menor);
}

int main() {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");

	atv1();
	atv2();
	atv3();

	return 0;
}
