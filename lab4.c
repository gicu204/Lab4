#include<stdio.h>
#include<stdlib.h>
#include<string.h>





int main(){


char text[100];

    printf("enter the text you want to edit: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    int i,j,k,n,m,x,y,p,times,length,length2,length3,length4;
    char entertext[1000];
    char entertext2[1000];
    char space[1000];
    char space2[1000];
    int verify = 0;
    FILE *txt;

    while(verify == 0){

        printf("\n\n------------------------------ \n options: \n 1. Enter text\n 2. Search for word\n 3. Replace word\n");
        printf(" 4. Delete all text\n 5. Show the text\n 6. Save to a file\n 7. Load from a file\n 8. Exit");
        printf("\n choose the option with the number on the left of the option: ");
        scanf(" %d", &i);
        getchar();

        //
        switch(i){
            case 1:
                printf("enter the text you want to add: ");
                fgets(entertext, sizeof(entertext), stdin);
                entertext[strlen(entertext) - 1] = ' ';
                text[strlen(text)] = ' ';

                strcat(text, entertext);
                //printf("edited text: %s", text);
                break;
            case 2:
                printf("enter the word you want to see how many times it is founded: ");
                fgets(entertext, sizeof(entertext), stdin);
                entertext[strlen(entertext) - 1] = ' ';

                times = 0;
                p = 0;
                length = strlen(text);
                length2 = strlen(entertext);

                k = 0;
                for(j = 0; j < length2; j++){
                    if((entertext[k] != text[j]) && (text[j] != '\0')){
                        p = 0;
                        break;
                    }
                    if((text[j] == ' ') || (text[j] == '\0')){
                        p++;
                    }
                    k++;
                    p++;
                    if (p >= length2){
                        times++;
                        p = 0;
                        //printf("\n the word '%s' was found at 0", entertext);
                    }
                }

                for(j = 0; j < length; j++){
                if(text[j] == ' '){
                        n = j + 1;
                        p = 0;
                for(k = 0; k < length2; k++){
                    if(entertext[k] != text[n]){
                        if((p == length2) && ((text[n] == ' ') || (text[n] == '\0'))){
                            p++;
                        }else{
                            p = 0;
                            break;
                        }
                    }
                    n++;
                    p++;
                }
                    if (p >= length2){
                        times++;
                        // printf("\n the word '%s' was found at %d", entertext, j + 1);
                    }

                }
                }

                printf("the word %s was found %d times", entertext, times);
                break;
            case 3:
                printf("enter the word you want to replace: ");
                fgets(entertext, sizeof(entertext), stdin);
                entertext[strlen(entertext) - 1] = ' ';
                printf("enter the word you want to be place instead: ");
                fgets(entertext2, sizeof(entertext2), stdin);
                entertext2[strlen(entertext2) - 1] = ' ';

                length = strlen(text);
                length2 = strlen(entertext);
                length3 = strlen(entertext2);
                x = 0;
                y = 0;
                k = 0;
                p = 0;


                for(j = 0; j < length2; j++){
                    if((entertext[k] != text[j]) && (text[j] != '\0')){
                        p = 0;
                        break;
                    }
                    if((text[j] == ' ') || (text[j] == '\0')){
                        p++;
                    }
                    k++;
                    p++;
                    if (p >= length2){
                        p = 0;

                        for(n = 0; n < length3; n++){
                            space[x] = entertext2[n];
                            x++;
                        }
                        y = y + length2;
                    }
                }

                for(j = 0; j < length; j++){
                    space[x] = text[y];
                    x++;
                    y++;
                if(text[j] == ' '){
                        n = j + 1;
                        p = 0;
                for(k = 0; k < length2; k++){
                    if(entertext[k] != text[n]){
                        if((p == length2) && ((text[n] == ' ') || (text[n] == '\0'))){
                            p++;
                        }else{
                            p = 0;
                            break;
                        }
                    }
                    n++;
                    p++;
                }
                    if (p >= length2){
                            if(x > length3 + 1){x = x - length2;}
                            for(m = 0; m < length3; m++){
                                space[x] = entertext2[m];
                                x++;
                            }
                            if(y < length2){y = y + length2;}
                    }
                }
                }

                text[0] = '\0';
                strcpy(text, space);
                //printf("\n the edited text: %s", text);
                break;
            case 4:
                text[0] = '\0';
                printf("text deleted");
                break;
            case 5:
                printf("the text:%s", text);
                break;
            case 6:
                txt = fopen("in.txt", "a");
                fprintf(txt, "%s\n", text);
                fclose(txt);
                printf("text saved");
                break;
            case 7:
                txt = fopen("out.txt", "r");
                fgets(text,100, txt);
                text[strlen(text)] = '\0';
                fclose(txt);
                printf("text loaded");
                break;
            case 8:
                verify = 1;
                break;
        }
    }

return 0;
}
