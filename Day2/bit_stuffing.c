#include <stdio.h>
#include <string.h>
int main()
{
    char ch, arr[50] = "01111110", rec[50];
    int i, j, k, len = 8, cnt = 0;
    printf("\n Enter the data:\n");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '1')
            cnt++;
        else
            cnt = 0;
        arr[len++] = ch;
        if (cnt == 5)
        {
            arr[len++] = '0';
            cnt = 0;
        }
    }

    strcat(arr, "01111110");
    printf("\n Bit stuffed stream is:\n");
    for (i = 0; i < len + 8; i++)
        printf("%c", arr[i]);
    cnt = 0;
    printf("\n The destuffed stream is:\n");
    for (j = 8, k = 0; j < len; j++)
    {
        if (arr[j] == '1')
            cnt++;
        else
            cnt = 0;
        rec[k++] = arr[j];
        if (cnt == 5 && arr[j + 1] == '0')
        {
            j++;
            cnt = 0;
        }
    }
    for (j = 0; j < k; j++)
        printf("%c", rec[j]);
    return 0;
}