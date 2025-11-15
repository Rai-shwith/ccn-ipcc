#include <stdio.h>
#include <stdlib.h>   
#include <windows.h>  

#define w 1
int main()
{
    int i, f, frames[50];
    printf("\n Enter number of frames to transmit:");
    scanf("%d", &f);
    printf("\n Enter %d frames:", f);
    for (i = 1; i <= f; i++)
    {
        scanf("%d", &frames[i]);
        printf("\n With stop and wait protocol the frames will be sent in the following manner(assuming no corruption of frames)\n\n");
        printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n", w);
        printf("if error occur negative acknowledge is detected same frame is resend back\n");
        for (i = 1; i <= f; i++)
        {
            if ((rand() % 2) == 1)   
            {
                if ((i % w) == 0)
                {
                    printf("%d\n", frames[i]);
                    printf("Acknowledgement of above frames sent is received by sender\n\n");
                }
                else
                    printf("%d", frames[i]);
            }
            else
            {
                Sleep(3 * 1000);     // replaced sleep()
                printf("negative acknowledge resend %d frame\n", i);
                i = i - 1;
                Sleep(1 * 1000);     // replaced sleep()
            }
        }
        return 0;
    }
}

/*
OUTPUT:

 Enter number of frames to transmit:4

 Enter 4 frames:1,2,3,4

 With stop and wait protocol the frames will be sent in the following manner(assuming no corruption of frames)

After sending 1 frames at each stage sender waits for acknowledgement sent by the receiver

if error occur negative acknowledge is detected same frame is resend back
1
Acknowledgement of above frames sent is received by sender

-1556275042
Acknowledgement of above frames sent is received by sender

negative acknowledge resend 3 frame
negative acknowledge resend 3 frame
32766
Acknowledgement of above frames sent is received by sender

negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
1776185360
Acknowledgement of above frames sent is received by sender


*/


/*
OUTPUT:
 Enter number of frames to transmit:10

 Enter 10 frames:1,2,3,4,5,6,7,8,9,10

 With stop and wait protocol the frames will be sent in the following manner(assuming no corruption of frames)

After sending 1 frames at each stage sender waits for acknowledgement sent by the receiver

if error occur negative acknowledge is detected same frame is resend back
1
Acknowledgement of above frames sent is received by sender

-1556275042
Acknowledgement of above frames sent is received by sender

negative acknowledge resend 3 frame
negative acknowledge resend 3 frame
32766
Acknowledgement of above frames sent is received by sender

negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
negative acknowledge resend 4 frame
-1414041584
Acknowledgement of above frames sent is received by sender

32759
Acknowledgement of above frames sent is received by sender

-943719232
Acknowledgement of above frames sent is received by sender

126
Acknowledgement of above frames sent is received by sender

-943719232
Acknowledgement of above frames sent is received by sender

126
Acknowledgement of above frames sent is received by sender

-1519671168
Acknowledgement of above frames sent is received by sender

*/