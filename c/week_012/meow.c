#include <stdio.h>
#include <windows.h>

int main(){
    int n;

    while (1)
    {
        printf("Quantos meow? ");
        scanf ("%i", &n);

        if (n < 0){
            printf("um numero positivo idiota, minhas lombrigas não querem meow \n");

            continue;
        }

        else{
            break;
        }
    }

    for ( int i = 0; i < n; i++){
        printf("meow \n");
        Sleep(1000);
    }
    
   

}