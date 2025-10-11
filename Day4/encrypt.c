#include <stdio.h>
#include <string.h>
#include <conio.h>
void encrypt (char *message, int key){
    for (int i = 0; message[i] != '\0';i ++){
        char ch = message[i];
        if (ch >='a' && ch <='z'){
            ch = (ch - 'a' + key ) % 26 + 'a';
        }else if (ch >='A' && ch <='Z'){
            ch = (ch - 'A' + key ) % 26 + 'A';
        }
        message[i]=ch;
    }
}

void decrypt (char *message, int key){
    for (int i = 0; message[i] != '\0';i ++){
        char ch = message[i];
        if (ch >='a' && ch <='z'){
            ch = (ch - 'a' - key ) % 26 + 'a';
        }else if (ch >='A' && ch <='Z'){
            ch = (ch - 'A' - key ) % 26 + 'A';
        }
        message[i]=ch;
    }
}
int main(){
    char message[100];
    int key;
    printf("Enter a message ");
    gets(message);
    printf("Enter key (1-25): ");
    scanf("%d",&key);
    encrypt(message,key);
    printf("Encrypted message: %s\n",message);
    decrypt(message,key);
    printf("Decrypted message: %s\n",message);
    return 0;
}