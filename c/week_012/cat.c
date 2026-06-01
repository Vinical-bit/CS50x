#include <stdio.h>
#include <windows.h>

void meow(void);

int n;
int main(){
     
    printf("Quantas meow? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        meow();
    }
}















































































void meow(void){
    printf("meow\n");
}