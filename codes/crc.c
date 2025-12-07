#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N strlen(g)
char t[128], cs[128], g[] = "10110";
int a, e, c;
void xor()
{
    for (c = 1; c < N; c++)
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}
void crc()
{
    for (e = 0; e < N; e++)
        cs[e] = t[e];
    do
    {
        if (cs[0] == '1')
            xor();
        for (c = 0; c < N - 1; c++)
            cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}
void main()
{
    // rscr();
    printf("\n Enter poly:");
    scanf("%s", t);
    printf("\n Generating Polynomial is:%s", g);
    a = strlen(t);
    for (e = a; e < a + N - 1; e++)
        t[e] = '0';
    printf("\n Modified t[u] is:%s", t);
    crc();
    printf("\n Checksum is:%s", cs);
    // RC
    for (e = a; e < a + N - 1; e++)
        t[e] = cs[e - a];
    printf("\n Final codeword is:%s", t);
    int check, gg;
    printf("\n Test error detection 0(yes) 1(no)?");
    scanf("%d", &check);
    if (check == 0)
    {
        printf("\n Enter position where you want to insert error");
        scanf("%d", &gg);
        t[gg] = (t[gg] == '1' ? '0' : '1');
        printf("\nErrorneous data: %s", t);
        printf("\nError Detected");
    }
    else
    {
        printf("\nno Error Detected");
    }
}