#include <stdio.h>
#include <math.h>


int main(){
    
    float a, b, c, ax, bx, ax2, bx2, delta, x1, x2, raizdelta, denominador, somax; // Declaracao das variaveis de tipo float que serão usadas
    int escolha; // Variavel que recebe o input do usuario
    while(1) // Cria um loop que se mantem ativo durante todo o programa
    {
        printf("\n||| MENU PRINCIPAL |||\n\n");
        printf("Voce pode acessar diferentes funcoes digitando os numeros 1, 2, 3 e 0, sendo eles:\n"); 
        printf("\n1- Resolver equacao de primeiro grau\n2- Resolver equacao do segundo grau\n3- Sobre o programa\n0- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        if (escolha == 1) // Verificando o input do usuario
        {
            printf("A equacao de primeiro grau possui o seguinte formato:\n ax + b = 0\n");
            printf("Digite o valor de a (Numero que possui variavel x): ");        
            scanf("%f", &a);
            if (a == 0) // Equacoes de 1 grau nao podem ser concluidas com A == 0, pois elimina a variavel (nesse caso vai resultar em erro na hora da divisao, fazendo b ser dividido por 0).
            {
                printf("\n\nPara concluir a equacao de primeiro grau, o valor de A precisa ser diferente de 0.\n\n");
                continue;
            }
            printf("Digite o valor de b (Numero que nao possui variavel): ");
            scanf("%f", &b);

            
            
            printf("\nEtapas:\n");
            printf("1) A equacao enviada e (%.2f)x + (%.2f) = 0\n", a, b);
            b = -b; // Inverter o sinal faz com que seja possivel igualar a operação
            printf("2) Isolar o valor de x invertendo o sinal de b: (%.2f) = 0 + %.2f\n", a, b);
            printf("3) Divir ambos os lados por a: (%.2f)x / (%.2f) = (%.2f) / (%.2f) \n", a, a, b, a);
            float resolucao1 = b / a; // valor de b (nesse caso, valor sem variavel isolado) é dividido pelo valor a frente da variavel (a)
            printf("4) Resultado: %.2f\n\n", resolucao1);
            printf("O valor de X e igual a: %.2f\n\n", resolucao1);
            
        }
        else if (escolha == 2)
        {
                printf("A equacao de segundo grau possui o seguinte formato: \n ax^2 + bx + c = 0\n");
                printf("Digite o valor de ax^2 (Valor com variavel elevado ao quadrado): ");
                scanf("%f", &ax);
                if (ax == 0) // Equacoes de 2 grau com (a = 0) se tornam equacoes de 1 grau
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
                printf("Substituindo os valores: (%.2f^2)-(4.%.2f.%.2f)\n", bx, ax, c);
                bx2 = pow(bx, 2); // ax2 e bx2 guardam os valores das etapas mais avançadas do calculo, facilitando para resolver a equacao
                ax2 = 4*ax*c;
                printf("(%.2f)-(%.2f)\n", bx2, ax2);
                delta = bx2-ax2; // formula de delta aplicada aos valores
                printf("O valor de delta e: %.2f.\n", delta);
                /*
                Em equacoes de segundo grau o delta define como as raizes vao se comportar:
                Delta > 0 = Raizes duplas distintas
                Delta < 0 = Nenhuma raiz real
                Delta == 0 = Raiz unica ou raiz real dupla repetida
                */ 
                if (delta > 0) 
                // Com raizes duplas distintas, o valor de -b ira somar e subtrair a raiz quadrada de delta e ser divido por 2*ax, resultando no valor das duas raizes (x1, x2)
                {
                    printf("\nCom o valor de delta sendo positivo, sera utilizado a formula:\n(-b) +- sqrt(delta)/(2*a)\n");
                    printf("Dado o delta positivo, as raizes seram duplas.\n\n");
                    raizdelta = sqrt(delta);
                    printf("| sqrt(Delta) = sqrt(%.2f) = %.2f\n", delta, raizdelta); 
                    denominador = 2*ax;
                    printf("| Denominador = 2*a = %.2f\n\n", denominador);

                    printf("Calculo de X1:\n");

                    printf("| x1 = (-b + sqrt(delta)) / (2a)\n");
                    printf("| x1 = (-(%.2f) + %.2f) / %.2f\n", bx, raizdelta, denominador);
                    somax = -bx + raizdelta;
                    printf("| x1 = %.2f / %.2f\n", somax, denominador);
                    x1 = (-bx + sqrt(delta)) / (2*ax); // -b + raiz de delta / 2*, sendo o X1
                    printf("| x1 = %.2f\n\n", x1);

                    printf("Calculo de X2:\n");

                    printf("| x2 = (-b - sqrt(delta)) / (2a)\n");
                    printf("| x2 = (-(%.2f) - %.2f) / %.2f\n", bx, raizdelta, denominador);
                    somax = -bx - raizdelta;
                    printf("| x2 = %.2f / %.2f\n", somax, denominador);
                    x2 = (-bx - sqrt(delta)) / (2*ax); // -b - raiz de delta / 2*a, sendo o valor de X2
                    printf("| x2 = %.2f\n\n", x2);
                    printf("Os valores das raizes sao: x1 = %.2f, x2 = %.2f\n\n", x1, x2);

                    
                   
                }
                else if (delta == 0) // com Delta = 0 so havera uma raiz 
                {
                    
                    printf("\nCom o delta igual a zero, havera apenas uma unica raiz.\n\n");
                    raizdelta = sqrt(delta);
                    printf("| sqrt(Delta) = sqrt(%.2f) = %.2f\n", delta, raizdelta);
                    denominador = 2*ax;
                    printf("| Denominador = 2*a = 2*%.2f = %.2f\n", ax, denominador);
                    printf("| X = -(%.2f) + %.2f / (%.2f)\n", bx, raizdelta, denominador);
                    bx = -bx + raizdelta; 
                    printf("| X = %.2f / %.2f\n", bx, denominador);
                    x1 = bx / denominador;
                    printf("| X = %.2f\n", x1);
                    printf("| Por conta do delta ser igual a 0, somar ou subtrair raiz de delta resultara no mesmo resultado, gerando uma unica raiz");
                    printf("\n\n O valor da raiz e: %.2f\n\n", x1);
                }
                else
                {
                    printf("\nCom o delta sendo negativo, a operacao nao vai possuir raizes reais, pois");
                    printf("\nnumeros negativos nao possuem raizes pertencentes aos numeros reais.\n");
                }

        }
        else if (escolha == 3)
        {
            printf("\nPrograma desenvolvido por: Bernardo Menna\nTrabalho para a disciplina de Algoritmos 1.\n\n");
        }
        else if (escolha == 0)
        {
            break; // Sai do loop inicial, fechando o programa e mostrando a mensagem abaixo.
        }
        else   
        {
            printf("\nDigite um numero valido que esteja nas opcoes do menu.\n");
            continue;
        }
            
        
    }
    printf("Obrigado por utilizar nosso programa!"); // Mensagem ao sair do programa
}    
