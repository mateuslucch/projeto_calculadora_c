#include <stdio.h>

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
        printf("Resultado: %d\n", resultado);
        break;
    case '-':
        resultado = num1 - num2;
        printf("Resultado: %d\n", resultado);
        break;
    case '*':
        resultado = num1 * num2;
        printf("Resultado: %d\n", resultado);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Erro: Divisão por zero não é permitida.\n");
            break;
        }

        resultado = num1 / num2;
        printf("Resultado: %d\n", resultado);

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