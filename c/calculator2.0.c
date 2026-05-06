#include <stdio.h>
#include<windows.h>
int escolha;
char R;
float x,y;

void exibirMenu(){
    printf("Escolha uma das operacoes abaixo; \n");
    printf("|--------------------------------\n");
    printf("|--- 1 --- :Soma          |\n");
    printf("|--- 2 --- :Subtracao     |\n");
    printf("|--- 3 --- :Multiplicacao |\n");
    printf("|--- 4 --- :Divisao       |\n");
    printf("|--------------------------------\n");
    printf(">");
}

void escolhaxy(){
    printf("Escolha o valor de x: ");
    scanf("%f",&x);
    printf("Escolha o valor de y: ");
    scanf("%f",&y);
}

void continuar(){
    printf("Quer continuar ?[S/N]: ");
    scanf(" %c", &R);
}

int main(){

    exibirMenu();

    scanf("%i", &escolha);
    switch (escolha)
    {
    case 1:
        R ='S';
        printf("Abrindo soma...\n");
        while (R == 'S' || R =='s')
        {
            escolhaxy();
            printf("Execultando soma...\n");
            Sleep(500);
            printf("Resultado: %.2f\n",x + y);
            continuar();
        }
        break;
        
        case 2:
        R = 's';
        printf("Abrindo subtracao...\n");
        while (R == 'S' || R =='s'){
            escolhaxy();
            printf("Execultanco subtracao...\n");
            Sleep(500);
            printf("Resultado: %.2f\n",x - y);
            continuar();
        }
        break;

        case 3:
        R = 's';
        printf("Abrindo multiplicacao...\n");
        while (R == 'S' || R =='s'){
            escolhaxy();
            printf("Execultando multiplicacao...\n");
            Sleep(500);
            printf("Resultado: %.2f", x * y);
            continuar();
        }
        break;

        case 4:
        R = 'S';
        printf("Abrindo divisão...\n");
        while (R == 'S' || R =='s'){
            escolhaxy();
            printf("Execultando divisao...\n");
            Sleep(500);
            printf("Resultado: %.2f", x/y);
            continuar();
        }
        break;
    
    default:
        break;
    }    
}

