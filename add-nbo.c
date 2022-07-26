#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    FILE *fh;
    FILE *th;
    uint32_t data1;
    uint32_t data2;
    uint32_t result;
    

    fh = fopen(argv[1], "rb");
    th = fopen(argv[2], "rb");

    fread(&data1, sizeof(uint32_t), 4, fh);
    fread(&data2, sizeof(uint32_t), 4, th);

    data1 = ntohl(data1);
    data2 = ntohl(data2);

    result = data1 + data2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", data1, data1, data2, data2, result, result);

    fclose(fh);
    fclose(th);
    return 0;
}
