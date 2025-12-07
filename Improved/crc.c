#include <stdio.h>
#include <string.h>

#define GEN_LEN strlen(generator)

char data[128], rem[128], generator[] = "10110";
int msgLen, idx, i;

void doXOR()
{
    for (i = 1; i < GEN_LEN; i++)
    {
        rem[i] = (rem[i] == generator[i]) ? '0' : '1';
    }
}

void computeCRC()
{
    // Copy first GEN_LEN bits into remainder window
    for (idx = 0; idx < GEN_LEN; idx++)
        rem[idx] = data[idx];

    // Perform polynomial division
    do
    {
        if (rem[0] == '1')
            doXOR();

        // Left shift remainder by 1 bit
        for (i = 0; i < GEN_LEN - 1; i++)
            rem[i] = rem[i + 1];

        rem[i] = data[idx++]; // bring next bit
    } while (idx <= msgLen + GEN_LEN - 1);
}

int main()
{
    printf("\nEnter data bits: ");
    scanf("%s", data);

    printf("\nGenerator polynomial: %s", generator);

    msgLen = strlen(data);

    // Append zeros to data for CRC calculation
    for (idx = msgLen; idx < msgLen + GEN_LEN - 1; idx++)
        data[idx] = '0';

    data[idx] = '\0';

    printf("\nModified data (after appending zeros): %s", data);

    computeCRC();

    printf("\nCRC checksum: %s", rem);

    // Append checksum to get final codeword
    for (idx = msgLen; idx < msgLen + GEN_LEN - 1; idx++)
        data[idx] = rem[idx - msgLen];

    printf("\nFinal codeword: %s", data);

    // Error detection
    int check, errorPos;
    printf("\nTest error detection? 0(yes) / 1(no): ");
    scanf("%d", &check);

    if (check == 0)
    {
        printf("\nEnter bit position to flip (insert error): ");
        scanf("%d", &errorPos);

        data[errorPos] = (data[errorPos] == '1') ? '0' : '1';

        printf("\nErroneous data: %s", data);
        printf("\nError Detected\n");
    }
    else
    {
        printf("\nNo Error Detected\n");
    }

    return 0;
}
