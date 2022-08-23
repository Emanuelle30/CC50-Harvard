#include <cs50.h>
#include <stdio.h>

/*Atividade 1: Recriar pirâmide em C, alinhada a direita, usando hashes ( # ) para tijolos.
Cada hash é um pouco mais alto do que largo, então a pirâmide em si também é mais alta do que larga.
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
    for (int i = 0; i < n; i++)
    {
        //colunas
        for (int j = 0; j < n; j++)
        {
            //lógica pirâmide
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}