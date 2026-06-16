#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Aceitar um unico argumento de linha de comando
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Abra o cartão de memoria

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Usage: ./recover: Not found");
        return 1;
    }

    // Ctriar um buffer para os blocos
    uint8_t buffer[512];
    FILE *img = NULL;
    int jpeg_count = 0;
    char filename[8];

    // Enquanto ainda faltam daados para ler o cartão de memoria
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // se encontrou assinatura
            if (img != NULL)
            {
                // fechar jpeg antigo
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "w");
            jpeg_count++;
        }
        // Criar JPEGs a partir dos dados
        if (img != NULL)
        {
            // escrever bloco
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
}