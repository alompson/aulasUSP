#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (){
    srand(time(NULL));
    int i, p, gabarito[i], resposta[i];
    for (i = 1; i >= 0; i++){
        printf("Nivel %d:\n", i);
        printf ("Memorize: ");
        for (p = 0; p < i; p++){
        //p siginifica posicao a ser analisada do vetor gabarito com i elementos
            gabarito[p] = (rand()%10);
            printf ("%d ", gabarito[p]);
        }
        printf("\n");
        sleep(5);
        system("clear");
        printf("Nivel %d:\n", i);
        printf("Digite a sequencia de numeros que apareceu, com espaços entre os numeros: \n");
        for (p = 0; p < i; p++){
            scanf("%d", &resposta[p]);
            if (resposta[p] != gabarito[p]){
            printf ("\n woops, voce errou! \nSeu total de pontos foi %d\n", i-1);
            sleep(2);
            return(0);
        }
        }
        printf("acertou!\n");
        sleep(1);
        system("clear");



}
}
