#include <stdio.h>
#include <stdlib.h>

long long decimalParaBinario(int decimalNum)
{
    long long binaryNum = 0;
    int remainder, i = 1;

    while (decimalNum > 0)
    {
        remainder = decimalNum % 2;
        decimalNum = decimalNum / 2;
        binaryNum += remainder * i;
        i *= 10;
    }

    return binaryNum;
}

void decimalParaHexadecimal(int decimalNum, char hexadecimalNum[])
{
    int remainder;
    int i = 0;

    while (decimalNum > 0)
    {
        remainder = decimalNum % 16;
        if (remainder < 10)
            hexadecimalNum[i] = remainder + '0';
        else
            hexadecimalNum[i] = remainder - 10 + 'A';
        decimalNum = decimalNum / 16;
        i++;
    }

    int j, k;
    char temp;
    for (j = 0, k = i - 1; j < k; j++, k--)
    {
        temp = hexadecimalNum[j];
        hexadecimalNum[j] = hexadecimalNum[k];
        hexadecimalNum[k] = temp;
    }

    hexadecimalNum[i] = '\0';
}

void imprimirResultados(int resultado, char operador, int num1, int num2)
{
    char hexadecimalNum[50];
    decimalParaHexadecimal(resultado, hexadecimalNum);

    printf("\n");
    printf("Resultados de %d %c %d em:\n", num1, operador, num2);
    printf("Decimal: %d \n", resultado);
    printf("Binário: %lld \n", decimalParaBinario(resultado));
    printf("Hexadecimal: %s \n", hexadecimalNum);
    printf("\n");
}

void Decimal()
{
    int num1, num2, resultado;
    char operador;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador);

    switch (operador)
    {
    case '+':
        resultado = num1 + num2;
        imprimirResultados(resultado, operador, num1, num2);
        break;
    case '-':
        resultado = num1 - num2;
        imprimirResultados(resultado, operador, num1, num2);
        break;
    case '*':
        resultado = num1 * num2;
        imprimirResultados(resultado, operador, num1, num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Erro: Divisão por zero não é permitida.\n");
            break;
        }

        resultado = num1 / num2;
        imprimirResultados(resultado, operador, num1, num2);        

        break;
    default:
        printf("Erro: Operador inválido.\n");
        break;
    }
}

int main()
{
    Decimal();
    return 0;
}