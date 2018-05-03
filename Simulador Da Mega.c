#include "Cayo.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
*/
// Cayo Da Silva Lima RA: 2215114748


unsigned int B[9] = {0,0,0,0,0,0,0,0,0,0}; // Matriz das apostas.
unsigned int A[6]; // Vetor do bilhete sorteado.
int I,J; //Contador
unsigned int N; //Variável dos números aleatorios
int GA=0,GI=0,GS=0; //Número de ganhadores de Sena,Quina e Quadra
int C; //vencedores
int X; //Variável de recebimento das apostas
int Y; //Variável dos números sorteados
char R; // repetição do programa
char Q;
int H = 6; // aumento de aposta

void mega(void){ // função de geração do bilhete da mega
	   srand(time(NULL));
    puts("\n\t\t\t\t**MEGA SENA**\n");
    puts("Voce tem direito a 6 numeros\nDeseja aumentar?\nDigite 'S' pra sim ou qualquer outra coisa para continuar");
    scanf("%s", &Q);
    if(Q == 's' || Q == 'S'){
    	puts("Quer aumentar sua sorte para quanto?\nPode escolher entre 7 ~ 10, qualquer outro numero sera invalido");
    	scanf("%i", &H);
		while(H < 6 || H > 10){
		puts("Parece que voce nao entendeu...\nE entre 7 ~ 10, Tente Novamente...");
    		scanf("%i", &H);
    	
	}
	system("cls");
	}
    puts("\t\t\tBILHETES GERADOS\n");
    printf("\t\t\t");
    for(I = 0 ; I < H ; I++) {
            N = (rand()%60) + 1;
            B[H] = N;
            printf("%02u ",B[H]);
    }
    printf("\n\n");
}


int main() {
	do{
	
    srand(time(NULL));
    mega(); // chamando a função mega
    
    puts("\t\t\tNUMEROS SORTEADOS\n");
 for(J = 0 ; J< H ; J++) {
            A[J] = (rand()%60) + 1;
        }
    printf("\t\t\t");
    for(I = 0 ; I< 6 ; I++) 
	printf("%u ",A[I]);
    printf("\n");
    for(I = 0 ; I< 6 ; I++) {
        C = 0;
        for(J = 0 ; J< H ; J++) {
            X = B[H];
            if(X == A[0] || X == A[1] || X == A[2] || X == A[3] || X == A[4] || X == A[5]) {
                C++;
            }
            if(C == 4) GA++;
            if(C == 5) GI++;
            if(C == 6) GS++;
        }
    }
    printf("\n");
    puts("\t\t\tResultado Final\n");
    if(GA == 1)
    puts("Parabens voce ganhou a QUADRA!!!!\n");
      if(GI == 1)
    puts("Parabens voce ganhou a QUINA!!!!\n");
      if(GS == 1)
    puts("Parabens voce ganhou a SENA e esta milionario!!!!\n");
    if(GA == 0 && GI == 0 && GS == 0)
	puts("Nao foi Desta Vez, Mais sorte na proxima.\n");
	
    puts("Deseja Tenta Novamente?\nDigite 'S' caso queira, ou qualquer outra coisa para encerrar...");
    scanf("%s", &R);
    system("cls");
}while(R == 's' || R == 'S');
    puts("\n\t\t\t FIM \n");
    getch();
    return 0;
}
