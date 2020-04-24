#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE * pFile;
    char name[10000];
    char mystring[1000];

    pFile = fopen ("test.txt" , "r");
    if (pFile == NULL)
        perror ("Error opening file");
    else
    {
        int u=0;
        while ( fgets (mystring , 1000 , pFile) != NULL )
        {
//            printf("%s\n",mystring);
//            printf("%d\n",strlen(mystring));
            int l=0;
            for(l=0;l<strlen(mystring);l++)
            {
                if((mystring[l]>64 && mystring[l]<93) || (mystring[l]>96 && mystring[l]<125))
                {
                    name[u]=mystring[l];
                    u++;
                }
            }
        }
    }
    printf(name);

    char key[10]="KEYS";
//    char name[20] = "ATTACKATDAWN";

    int keylen=strlen(key);
    int textlen=strlen(name);

    char ls[textlen+1][keylen+1];

    int i=0,k=0;
    for (i = 0; i < keylen; i++)
    {
        ls[k][i]=key[i];
    }
    ls[k][i]='\0';
    k++;
    for(i=0;i<strlen(name);i++)
    {
        int j=0;
        while(j<keylen)
        {
            if(i<strlen(name))
            {
                ls[k][j]=name[i];
            }
            else
            {
                ls[k][j]='X';
            }
            j++;
            i++;
        }
        ls[k][j]='\0';
        i--;
        k++;
    }

    i=0;
    printf("Plain key:  %s\n",ls[i]);
    printf("Plain text \n");
    for(i=1;i<k;i++)
    {
        printf("%s",ls[i]);
    }

    printf("\n\nText in form of list\n");
    for(i=0;i<k;i++)
    {
        printf("%s\n",ls[i]);
    }

    for (i = 0; i < keylen-1; i++) {
        int min_idx = i;
        int j;
        for (j = i + 1; j < keylen; j++)
            if (ls[0][j] < ls[0][min_idx])
                min_idx = j;

        for(j=0;j<k;j++)
        {
            char temp = ls[j][min_idx];
            ls[j][min_idx] = ls[j][i];
            ls[j][i] = temp;
        }
    }

    printf("\n\nSipher Text in form of list \n");
    for(i=0;i<k;i++)
    {
        printf("%s\n",ls[i]);
    }

    i=0;
    printf("\nSipher key:  %s\n",ls[i]);
    printf("Siphertext text \n");
    for(i=1;i<k;i++)
    {
        printf("%s",ls[i]);
    }
    printf("\n\n");

    return 0;
}
