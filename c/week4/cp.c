#include <stdio.h>

typedef unsigned char BYTE;

int main( int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // o b significa que o arquivo será aberto para leitura em modo binário
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) !=0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
    
}