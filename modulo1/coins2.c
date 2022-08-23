#include <cs50.h>
#include <stdio.h>
#include <math.h>

/*Atividade Cash2: Faça um programa que dado o valor de troco informado pelo usuário, calcule e retorne
a quantidade de moedas necessárias entre os valores de 25c, 10c, 5c e 1c.
Este programa aceita valores fracionados positivos.*/

int main(void)
{
    float valor;
    do
    {
        //Solicita o input do user
        valor = get_float("Informe o troco: ");
    }

    //Verifica se o valor é válido e transforma em int
    while (valor <= 0);
    int centavos = round(valor * 100);
    int moedas = 0;

    //Loop calcula 25c
    while (centavos >= 25)
    {
        centavos -= 25;
        moedas++;
    }
    //Loop calcula 10c
    while (centavos >= 10)
    {
        centavos -= 10;
        moedas++;
    }
    //Loop calcula 5c
    while (centavos >= 5)
    {
        centavos -= 5;
        moedas++;
    }
    //Loop calcula 1c
    while (centavos >= 1)
    {
        centavos -= 1;
        moedas++;
    }

    //Retorna o output para o user
    printf("Você necessita de %i moedas para o troco informado!\n", moedas);
}
