#include <stdio.h>
#include <math.h>


int main(){
    
    float a, b, i, c, ax, bx, delta, x1, x2; // Declaracao das variaveis de tipo float que seram usadas
    int escolha; // Variavel que recebe o input do usuario
    while(1) // Cria um loop que se mantem ativo durante todo o programa
    {
        printf("||| MENU PRINCIPAL |||\n");
        printf("Voce pode acessar diferentes funcoes digitando os numeros 1, 2, 3 e 0, sendo eles:"); 
        printf("\n1- Resolver equacao de primeiro grau\n2- Resolver equacao do segundo grau\n3- Sobre o programa\n0- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        if (escolha == 1) // Verificando o input do usuario
        {
            printf("A equacao de primeiro grau possui o seguinte formato:\n ax + b = 0\n");
            printf("Digite o valor de a (Numero que possui variavel x): ");        
            scanf("%f", &a);
            if (a == 0) // Equacoes de 1 grau nao podem ser concluidas com A == 0, a variavel x deixa de ter funcao (nesse caso vai resultar em erro na hora da divisao).
            {
                printf("\n\nPara concluir a equacao de primeiro grau, o valor de A precisa ser diferente de 0.\n\n");
                continue;
            }
            printf("Digite o valor de b (Numero que nao possui variavel): ");
            scanf("%f", &b);

            printf("Digite o valor apos o sinal de '=': ");
            scanf("%f", i);
            
            printf("\nEtapas:\n");
            printf("1) A equacao enviada e (%.2f)x + (%.2f) = %f\n", a, b, i);
            b = -b; // Equivalente a subtrair b em ambos os lados
            printf("2) Isolar o valor de x: (%.2f)x = %.2f\n", a, b);
            printf("3) Divir ambos os lados por a: (%.2f)x / (%.2f) = (%.2f) / (%.2f) \n", a, a, b, a);
            float resolucao1 = b / a; // valor de B é dividido pelo valor a frente da variavel (A)
            printf("4) Resultado: %.2f\n\n", resolucao1);
            printf("O valor de X e igual a: %.2f\n\n", resolucao1);
            
        }
        else if (escolha == 2)
        {
                printf("A equacao de segundo grau possui o seguinte formato: \n ax^2 + bx + c = 0\n");
                printf("Digite o valor de ax^2 (Valor com variavel elevado ao quadrado): ");
                scanf("%f", &ax);
                if (ax == 0) // Equacoes de 2 grau com A = 0 podem ser resolvidas tratando ela como uma equacao de 1 grau.
                {
                    printf("\n\nEquacoes de 2 grau com A = 0 se tornam equacoes de 1 grau.\nVoce pode resolver ela usando a opcao 'Resolver Equacao de primeiro grau'.\n\n");
                    continue; // Retorna ao inicio do loop
                }
                printf("Digite o valor de bx (Valor com variavel): ");
                scanf("%f", &bx);
                printf("Digite o valor de c (Valor sem variavel): ");
                scanf("%f", &c);

                printf("\nEtapas:\n");
                printf("Descobrir o valor de Delta, seguindo a formula: (b^2)-4*a*c\n");
                printf("Substituindo os valores: (%.2f^2)-4.%.2f.%.2f\n", bx, ax, c);
                delta = pow(bx, 2)-(4*ax*c); // formula de delta aplicada aos valores
                printf("O valor de delta e: %.2f.\n", delta);
                /*
                Em equacoes de segundo grau o delta define como as raizes vao se comportar:
                Delta > 0 = Raizes duplas distintas
                Delta < 0 = Nenhuma raiz real
                Delta == 0 = Raiz unica ou raiz real dupla repetida
                */ 
                if (delta > 0) 
                // Com raizes duplas, o valor de -b ira somar e subtrair a raiz quadrada de delta e ser divido por 2*ax, resultando no valor das duas raizes (x1, x2)
                {
                    printf("\nCom o valor de delta sendo positivo, sera utilizado a formula:\n(-b) +- sqrt(delta)/(2*a)\n");
                    printf("Dado o delta positivo, as raizes seram duplas, sendo X1 = -(%.2f)+sqrt(%.2f) / (2.%.2f)\n", bx, delta, ax); 
                    x1 = (-bx + sqrt(delta)) / (2*ax); // -b + raiz de delta / 2*, sendo o X1
                    printf("X1 = %.2f\n", x1);
                    printf("Para calcular X2 = (%.2f)-sqrt(%.2f)/2.%.2f\n", bx, delta, ax);
                    x2 = (-bx - sqrt(delta)) / (2*ax); // -b - raiz de delta / 2*a, sendo o valor de X2
                    printf("X2 = %.2f\n\n", x2);
                    printf("Os valores das raizes sao: x1 = %.2f, x2 = %.2f\n\n", x1, x2);

                    
                   
                }
                else if (delta == 0) // Raiz = 0 so havera um valor de X.
                {
                    
                    printf("Com o delta igual a zero, havera apenas uma unica raiz, sendo ela  X = (%.2f)+sqrt(%.2f)/2.%.2f\n", bx, delta, ax); 
                    x1 = (-bx + sqrt(delta)) / (2*ax); // -b + raiz de delta / 2*, sendo o X1
                    
                    printf("Por conta do delta ser igual a 0, somar ou subtrair delta resultara no mesmo resultado, gerando uma unica raiz");
                    printf("\n\n O valor da raiz e: %.2f\n\n", x1);
                }
                else
                {
                    printf("\nCom o delta sendo negativo, sabe-se que a operacao nao resultara em uma raiz real\n");
                    printf("\nNumeros negativos nao possuem raizes pertencentes aos numeros reais.\n");
                }

        }
        else if (escolha == 3)
        {
            printf("\nPrograma desenvolvido por: Bernardo Menna.\nTrabalho para a disciplina de Algoritmos 1.\n\n");
        }
        else if (escolha == 0)
        {
            break; // Sai do loop inicial, fechando o programa e mostrando a mensagem abaixo.
        }
            
        
    }
    printf("Obrigado por utilizar nosso programa!"); // Mensagem ao sair do programa
}    
