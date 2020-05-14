#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct filme
{
    char nome[50];
    char genero[30];
    int ano;
};
struct filme* recebe_filmes(struct filme filmes[5]);
void imprime_filmes(struct filme filmes[5]);
void imprime_genero(struct filme filmes[5], char gen[20]);

int main(void)
{

    struct filme filmes[5];
    struct filme *pfilme;
    int opcao;
    char pgen[20];
    pfilme = recebe_filmes (filmes);
    while (0==0)
    {
        printf("\nDeseja visualizar os filmes produzidos entre 2001 e 2005 ou buscar por gênero?\n");
        printf("Digite 1 para visualizar os filmes produzidos entre 2001 e 2005 ou 2 para ver somente um gênero\n");
        scanf("%d", &opcao);
        system("clear");
        if (opcao == 1)
        {
            imprime_filmes(pfilme);
        }
        else
        {
            imprime_genero(pfilme, pgen);
        }
        printf("Deseja fazer algo mais? Digite 1 para sim ou 2 para nao.\n");
        scanf("%d", &opcao);
        system("clear");
        if (opcao == 2)
            break;
    }

}

struct filme* recebe_filmes (struct filme filmes[5])
{
    char j[10];
    for(int i = 0; i < 5; i++)
    {
        printf("\nDigite o nome do %d° filme: ", i+1);
        gets(filmes[i].nome);
        printf("Digite o gênero (letras minusculas, sem acento): ");
        gets(filmes[i].genero);
        printf("Digite o ano em que o filme foi lançado: ");
        scanf("%d", &filmes[i].ano);
        gets(j); //para captar o "enter" após o scanf
        system("clear"); //limpa a tela
    }
    return &filmes[0];
}

void imprime_filmes(struct filme filmes[5])
{
    printf("\nFilmes produzidos entre 2001 e 2005:\n\n");
     for(int i = 0; i < 5; i++)
    {
        if (filmes[i].ano >= 2001 && filmes[i].ano <= 2005)
        {
        printf("%d° filme: %s\n", i+1, filmes[i].nome);
        printf("Genero: %s\n", filmes[i].genero);
        printf("Ano em que o filme foi lançado: %d\n\n", filmes[i].ano);
        }
    }
}

void imprime_genero(struct filme filmes[5],char gen[20])
{
    char j[10];
    gets(j); //para captar o enter anterior
    printf("\nEscolha um gênero que tenha dado para um dos filmes\n(Ex: terror, aventura, comedia)\n");
    gets (gen);
    system("clear");
    printf("\nMostrando filmes do gênero %s:\n\n", gen);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(filmes[i].genero, gen) == 0)
        {
            printf("%d° filme: %s\n", i+1, filmes[i].nome);
            printf("gênero: %s\n", filmes[i].genero);
            printf("ano em que o filme foi lançado: %d\n\n", filmes[i].ano);
        }
    }
    if (strcmp(filmes[0].genero, gen) != 0 && strcmp(filmes[1].genero, gen) != 0 && strcmp(filmes[2].genero, gen) != 0 && strcmp(filmes[3].genero, gen) != 0 && strcmp(filmes[4].genero, gen) != 0)
        printf ("Você não incluiu o gênero %s na sua lista :(\n\n", gen);
}
