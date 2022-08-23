#include <cs50.h>
#include <stdio.h>

/*Atividade Credit: Faça um programa que ao receber o input do usuário, verifica de acordo com o algoritmo de Luhn"s,
se o número de cartão de crédito informado é (sintaticamente) válido. Se válido o programa deverá verificar a qual bandeira
a numeração pertence e imprimir na tela, caso contrário deverá imprimir "INVALID"*/

int main()
{
    long credit;
    long credit_copy;
    int total_soma = 0, position = 0, total_length = 0;
    do
    {
        // Solicita o input do user
        credit = get_long("Informe o número do cartão: ");
        credit_copy = credit;

        // Verifica de acordo com o algoritmo de Luhn"s se o número de cartão de crédito informado é (sintaticamente) válido

        while (credit != 0)
        {

            if (position % 2 != 0)
            {
                // temp -> refere-se ao valor dos resultados sem a redução de digitos
                int temp = 2 * (credit % 10);
                if (temp > 9)
                {
                    total_soma += temp % 10 + temp / 10; // redução dos digitos 12 => 1 + 2
                }
                else
                {
                    total_soma += temp;
                }
            }
            else
            {
                total_soma += credit % 10;
            }
            credit = credit / 10;
            position++;
            total_length++;
        }
    }
    while (credit != 0);

    if (total_soma % 10 == 0)
    {
        // American Express: será válido se possuir 15 digitos e iniciar com 34 ou 37
        long amex_start = credit_copy / 10000000000000;
        if ((amex_start == 34 || amex_start == 37) && total_length == 15)
        {
            printf("AMEX\n");
            return 0;
        }

        // Mastercards: será válido se possuir 16 digitos e iniciar com números de 51 a 55
        long master_card_start = credit_copy / 100000000000000;
        if ((total_length == 16) && (master_card_start >= 51 && master_card_start <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // VISA: será válido se possuir entre 13 e 16 digitos e iniciar com o número 4
        long visa_start = credit_copy / 1000000000000;
        if ((total_length == 16 || total_length == 13) && (visa_start == 4 || master_card_start / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }

        // Caso a numeração não atenda as regras será impresso "INVALID"
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
