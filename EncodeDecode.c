#include<stdio.h>

    void EncodeMsg(char mes[]);
    void DecodeMsg(char mes[]);

int main()
{
    int option,run=1;
    char mes[150];

 while (run==1)
 {
    printf("--MENU--\n");
    printf("1.Encode message\n");
    printf("2.Decode message\n");
    printf("0.Exit\n");
    printf("Choose any option: ");
    scanf("%d",&option);

    if (option == 0)
    {
        printf("Program End.\n");
        run=0;
        return 0;
    }
    else if(option == 1)
    {
        printf("\nEnter message to encode: ");
        scanf(" %[^\n]", mes);
        EncodeMsg(mes);
        printf("\nEncoded: %s\n", mes);

    }    
    else if (option == 2)
    {
        printf("\nEnter message to decode: ");
        scanf(" %[^\n]", mes);
        DecodeMsg(mes);
        printf("\nDecoded: %s\n", mes);

    }
    else 
    printf("\nInvalid option!");
    }
 }

void EncodeMsg(char mes[])
{

    int count=0;

    while(mes[count] !='\0')
    {
        count++;
    }

    int len=count;

    for (int i= 0; i < len/2; i++)
    {
        char temp=mes[i];
        mes[i] = mes[len - i-1];
        mes[len - i-1]=temp;
    }

    for(int i= 0; i < len; i++)
    {
        mes[i]=mes[i] ^ 0b00010010; 
    }
}

void DecodeMsg(char mes[])
{
    int count=0;

    while(mes[count] !='\0')
    {
        count++;
    }

    int len=count;
    for(int i= 0; i < len; i++)
    {
        mes[i]=mes[i] ^ 0b00010010; 
    }

    for (int i=0; i < len/2; i++)
    {
        char temp=mes[i];
        mes[i] = mes[len - i-1];
        mes[len - i-1]=temp;
    }
}
