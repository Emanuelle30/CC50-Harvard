#include <cs50.h>
#include <stdio.h>

/*Atividade Cash: Faça um programa que dado o valor de troco informado pelo usuário, calcule e retorne
a quantidade de moedas necessárias entre os valores de 25c, 10c, 5c e 1c.*/

int get_centavos(void);
int calcula_vinteCinco(int centavos);
int calcula_dez(int centavos);
int calcula_cinco(int centavos);
int calcula_um(int centavos);

int main(void)
{
    //Pergunta os centavos
    int centavos = get_centavos();

    //Calcula o número de moedas de vinteCinco centavos para dar ao cliente
    int vinteCinco = calcula_vinteCinco(centavos);
    centavos = centavos - vinteCinco * 25;

    //Calcula o número de moedas de dez centavos para dar ao cliente
    int dez = calcula_dez(centavos);
    centavos = centavos - dez * 10;

    //Calcula o número de moedas de cinco centavos para dar ao cliente
    int cinco = calcula_cinco(centavos);
    centavos = centavos - cinco * 5;

    //Calcula o número de moedas de um centavo para dar ao cliente
    int um = calcula_um(centavos);
    centavos = centavos - um * 1;

    // Soma moedas
    int coins = vinteCinco + dez + cinco + um;

    // Imprime o número total de moedas para dar ao cliente
    printf("%i\n", coins);
}
int get_centavos(void)
{
    int centavos;
    do
    {
        //Solicita o valor ao user
        centavos = get_int("Informe o valor: ");
    }

    // Verifica se o valor é positivo
    while (centavos < 0);
    return centavos;
}
//Loop calcula 25c
int calcula_vinteCinco(int centavos)
{
    int vinteCinco = 0;

    while (centavos >= 25)
    {
        centavos = centavos - 25;
        vinteCinco++;
    }
    return vinteCinco;
}
//Loop calcula 10c
int calcula_dez(int centavos)
{
    int dez = 0;
    while (centavos >= 10)
    {
        centavos = centavos - 10;
        dez++;
    }
    return dez;
}
//Loop calcula 5c
int calcula_cinco(int centavos)
{
    int cinco = 0;
    while (centavos >= 5)
    {
        centavos = centavos - 5;
        cinco++;
    }
    return cinco;
}
//Loop calcula 1c
int calcula_um(int centavos)
{
    int um = 0;
    while (centavos >= 1)
    {
        centavos = centavos - 1;
        um++;
    }
    return um;
}