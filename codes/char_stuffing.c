#include <stdio.h>
#define DLE 16
#define STX 2
#define ETX 3
int main()
{
    char ch,arr[50]={DLE,STX},rec[50];
    int len=2,i,j;
    printf("\n Enter the data stream:ctrl+p->DLE ctrl+b->STX ctrl+c->ETX \n");
        while ((ch=getchar())!='\n')            
        {
        if(ch==DLE)
        {
            arr[len++]=DLE;
            printf("DLE");
        }
        else if(ch==STX)
        {
            printf("STX");
        }
        else if(ch==ETX)
        {
            printf("ETX");
        }
        else {
            printf("%c",ch);
        }
        arr[len++]=ch;
    }
    arr[len++]=DLE;
    arr[len++]=ETX;
    printf("The stuffed stream is:\n");
    for(i=0;i<len;i++)
    {
        ch=arr[i];
        if(ch==DLE)
        {
            printf("DLE");
        }
        else if(ch==STX)
        {
            printf("STX");
        }
        else if(ch==ETX)
        {
            printf("ETX");
        }
        else{
            printf("%c",ch);
        }
    }
        printf("\n The destuffed data stream is:\n");
        for(j=2;j<len-2;j++) {
            ch=arr[j];
            if(ch==DLE)
        {printf("DLE");
            j++;
        }
        else if(ch==STX)
        {
            printf("STX");
        }
        else if(ch==ETX)
            {printf("ETX");
            }
            else{
                printf("%c",ch);
            }
        }
        return 0;
    }

/*
To run this code
open Powershell in admin mode
and then 
PS C:\Windows\system32> cd "c:\Users\Admin\Desktop\EC29\Day2\"
PS C:\Users\Admin\Desktop\EC29\Day2> gcc char_stuffing.c -o p.exe
PS C:\Users\Admin\Desktop\EC29\Day2> ./p.exe                                                                                                                                                                                                     Enter the data stream:ctrl+p->DLE ctrl+b->STX ctrl+c->ETX                                                              ^Phello^Bhi                                                                                                             PS C:\Users\Admin\Desktop\EC29\Day2> ./p.exe                                                                                                                                                                                                     Enter the data stream:ctrl+p->DLE ctrl+b->STX ctrl+c->ETX                                                              ^Bhello^Phi^C                                                                                                           STXhelloDLEhi^CThe stuffed stream is:DLESTXSTXhelloDLEDLEhi^CDLEETX
The destuffed data stream is:
 STXhelloDLEhi^C
*/