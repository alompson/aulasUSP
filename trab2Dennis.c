#include <stdio.h>
#include <stdlib.h>
int** aloca_e_soma (int**A, int**B, int m, int n);
int** free_matriz (int** mat, int m);

int main()
{
    int**Ma;
    int**Mb;
    int**soma;
    int m, n;
    printf ("quais sao as dimensoes das matrizes A e B a serem somadas?\nLinhas: ");
    scanf("%d", &m);
    printf("\nColunas: ");
    scanf("%d", &n);
    soma = aloca_e_soma (Ma, Mb, m, n);
    printf ("matriz soma de A+B: \n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", soma[i][j]);
        }
    printf("\n");
    }


    if (free_matriz(soma, m) != NULL) //desaloca soma
    {
        printf("erro ao desalocar matriz soma");
        exit(1);
    }
    return 0;
}



int** aloca_e_soma (int**A, int**B, int m, int n)
{
    int **soma;
    int i, j;
    A = (int**)calloc(m, sizeof(int*));  //alocando memoria A
    if (A == NULL)
    {
        printf("\n  memoria insuficiente  \n");
        exit(1);
    }

    for ( i = 0; i < m; i++)
    {
        A[i]= (int*)calloc(n, sizeof(int));
        if (A[i] == NULL)
        {
            printf("\n  memoria insuficiente  \n");
            exit(1);
        }
    }

    for ( i = 0; i < m; i++) //definindo valores matriz A
    {
        for ( j = 0; j < n; j++)
        {
            printf("\nValor de A[%d][%d]: ", i+1, j+1);
            scanf ("%d", &A[i][j]);
        }
    }


        B = (int**)calloc(m, sizeof(int*));  //alocando memoria B
    if (B == NULL)
    {
        printf("\n  memoria insuficiente  \n");
        exit(1);
    }

    for ( i = 0; i < m; i++)
    {
        B[i]= (int*)calloc(n, sizeof(int));
        if (B[i] == NULL)
        {
            printf("\n  memoria insuficiente  \n");
            exit(1);
        }
    }


    for (i = 0; i < m; i++) //definindo valores matriz B
    {
        for (j = 0; j < n; j++)
        {
            printf("\nValor de B[%d][%d]: ", i+1, j+1);
            scanf ("%d", &B[i][j]);
        }
    }

     soma = (int**)calloc(m, sizeof(int*));  //alocando memoria matriz soma
    if (soma == NULL)
    {
        printf("\n  memoria insuficiente  \n");
        exit(1);
    }

    for (i = 0; i < m; i++)
    {
        soma[i]= (int*)calloc(n, sizeof(int));
        if (soma[i] == NULL)
        {
            printf("\n  memoria insuficiente  \n");
            exit(1);
        }
    }

    for (i = 0; i < m; i++) //soma A+B
    {
        for (j = 0; j < n; j++)
        {
            soma[i][j] = A[i][j] + B[i][j];
        }
    }

    if (free_matriz(A, m) != NULL)//desaloca A
    {
        printf("erro ao desalocar matriz A");
        exit(1);
    }
    if (free_matriz(B, m) != NULL)//desaloca B
    {
        printf("erro ao desalocar matriz B");
        exit(1);
    }
return soma;
}


int** free_matriz (int** mat, int m)
{
    for (int i = 0; i < m; i++)
    {
        free (mat[i]);
    }
    free(mat);
    return NULL;
}
