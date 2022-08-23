#include <cs50.h>
#include <stdio.h>

/*Atividade 2: Recriar pirâmides em C, alinhadas em paralelo, usando hashes ( # ) para tijolos.
A torre 1 deverá está alinhada a esquerda, enquanto a torre 2 à direita e deverá existir um espaço entre as duas.
O programa deve permitir que o usuário decida qual deve ser a altura da pirâmide, primeiro solicitando
um número inteiro positivo entre 1 e 8. Se o usuário não inserir, de fato, um número inteiro positivo entre 1 e 8,
quando solicitado, o programa deve solicitar novamente ao usuário até que ele coopere.*/

int main(void)
{
    int n;
    do
    {
        //input - Pega o valor do usuário
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //linhas
    for (int i = n; i > 0; i--)
    {
        //colunas
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        //torre esquerda
        for (int j = 0; j < (n - i + 1); j++)
        {
            printf("#");
        }
        //espaço no meio
        printf("  ");

        //torre direita
        for (int j = 0; j < (n - i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}