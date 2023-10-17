#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>



int main(){


size_t size = 100;
char *text = (char *)malloc(size * sizeof(char));

    printf("enter the text you want to edit: \n");


    if (text == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //fgets(text, sizeof(text), stdin);

    size_t tsize = 0;

    char ch;

    while (1) {
        ch = getchar();
        if (ch == '\n') {
            break;
        }

        text[tsize] = ch;
        tsize++;

        if (tsize == size - 1) {
            size = size * 2;
            char *new_buffer = (char *)realloc(text, size * sizeof(char));

            if (new_buffer == NULL) {
                printf("Memory reallocation failed.\n");
                free(text);
                return 1;
            }

            text = new_buffer;
        }

    }

    text[tsize] = '\0';


    //printf("text \n\n %s", text);
    //text[tsize - 1] = '\0';

    int i,j,k,n,m,x,y,p,o,times,length,length2,length3,length4;
    bool deleted = false;
    char entertext[1000];
    char entertext2[1000];
    //char *space = (char *)malloc(size * sizeof(char));
    char *space2 = (char *)malloc(size * sizeof(char));
    int verify = 0;
    FILE *txt;
    if(text[0] == '\0'){
        deleted = true;
    }

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
                //fgets(entertext, sizeof(entertext), stdin);
                //entertext[strlen(entertext) - 1] = ' ';

                text[tsize] = ' ';
                tsize++;

                while (1) {

                    ch = getchar();
                    if (ch == '\n') {
                        break;
                    }

                    text[tsize] = ch;
                    tsize++;

                    if (tsize == size - 1) {
                        size = size * 2;
                        char *new_buffer = (char *)realloc(text, size * sizeof(char));

                        if (new_buffer == NULL) {
                            printf("Memory reallocation failed.\n");
                            free(text);
                            return 1;
                        }

                        text = new_buffer;
                    }

                }

                text[tsize] = '\0';

                //if (deleted){ text[strlen(text)] = ' '; deleted = false; }
                //strcat(text, ' ');
                //strcat(text, space2);
                //space2[0] = '\0';
                //printf("edited text: %s", text);
                break;
            case 2:
                printf("enter the word you want to see how many times it is founded: ");
                fgets(entertext, sizeof(entertext), stdin);
                entertext[strlen(entertext) - 1] = '\0';

                times = 0;
                p = 0;
                length = strlen(text);
                length2 = strlen(entertext);

                k = 0;
                for(j = 0; j < length2 + 1; j++){
                    if((entertext[k] != text[j]) && ((text[j + 1] != '\0') || (text[j + 1] != '.') || (text[j + 1] != ','))){
                        p = 0;
                        break;
                    }
                    if((text[j] == ' ') || (text[j] == '\0') || (text[j] == '.') || (text[j] != ',')){
                        p++;
                    }
                    k++;
                    p++;
                    if (p > length2 + 2){
                        times++;
                        p = 0;
                        printf("\n the word '%s' was found at 0", entertext);
                    }
                }

                for(j = 0; j < length; j++){
                if((text[j] == ' ') || (text[j] == '.') || (text[j] == ',')){
                        n = j + 1;
                        p = 0;
                for(k = 0; k < length2 + 1; k++){
                       // printf("\n entertext[%d] = %c", k, entertext[k]);
                       // printf("\n text[%d] = %c", n, text[n]);
                    if(entertext[k] != text[n]){
                        if((p >= length2) && ((text[n] == ' ') || (text[n] == '\0') || (text[n] == '.') || (text[n] == ','))){
                            p++;
                        }else{
                            p = 0;
                            break;
                        }
                    }
                    n++;
                    p++;
                }
                    if (p >= length2 + 2){
                        times++;
                        printf("\n the word '%s' was found at %d", entertext, j + 1);
                    }

                }
                }

                printf("\nthe word %s was found %d times", entertext, times);
                break;
            case 3:
                printf("enter the word you want to replace: ");
                fgets(entertext, sizeof(entertext), stdin);
                entertext[strlen(entertext) - 1] = '\0';
                printf("enter the word you want to be place instead: ");
                fgets(entertext2, sizeof(entertext2), stdin);
                entertext2[strlen(entertext2) - 1] = '\0';

                length = strlen(text);
                length2 = strlen(entertext);
                length3 = strlen(entertext2);

                char *space = (char *)malloc(size * sizeof(char));
                //char space[length];
                x = 0;
                y = 0;
                k = 0;
                p = 0;
                o = 0;


                for(j = 0; j < length2 + 1; j++){
                    if((entertext[k] != text[j]) && ((text[j + 1] != '\0') || (text[j + 1] != '.') || (text[j + 1] != ','))){
                        p = 0;
                        break;
                    }
                    if((text[j] == ' ') || (text[j] == '\0') || (text[j] == '.') || (text[j] != ',')){
                        p++;
                    }
                    k++;
                    p++;
                    if (p > length2 + 2){
                        p = 0;

                        for(n = 0; n < length3; n++){
                            space[x] = entertext2[n];
                            x++;
                        }
                        o++;
                        y = y + length2;
                    }
                }

                for(j = 0; j < length; j++){
                    //if(y < length){
                        space[x] = text[y];
                        x++;
                        y++;

                    //printf("\n y = %d  and  length = %d", y, length);
                if((text[j] == ' ') || (text[j] == '.') || (text[j] == ',')){
                        n = j + 1;
                        p = 0;
                        //printf("\n j = %c", text[j]);
                for(k = 0; k < length2 + 1; k++){
                    if(entertext[k] != text[n]){
                        if((p >= length2) && ((text[n] == ' ') || (text[n] == '\0') || (text[n] == '.') || (text[n] == ','))){
                            p++;
                        }else{
                            p = 0;
                            break;
                        }
                    }
                        //printf("\n entertext[%d] = %c", k, entertext[k]);
                        //printf("\n text[%d] = %c", n, text[n]);
                    n++;
                    p++;
                }
                    if (p >= length2 + 2){

                            if(o > 0){x = x - length2;}
                            for(m = 0; m < length3; m++){
                                space[x] = entertext2[m];
                                //printf("\n %c", space[x]);
                                x++;
                                tsize++;
                            }

                            if(o == 0){y = y + length2;}
                            //y = y + length2;
                            //printf("\n %c", text[y]);
                    }
                }
                    //}
                }

                    //space[x + 1] = '\0';

                //free(text);

                //text[0] = '\0';
                //strcpy(text, space);

/*
                x = 0;

                while (1) {

                    ch = space[x];
                    if (ch == '\0') {
                        break;
                    }

                    text[x] = ch;
                    x++;

                    if (x == size - 1) {
                        size = size * 2;
                        char *new_buffer = (char *)realloc(text, size * sizeof(char));

                        if (new_buffer == NULL) {
                            printf("Memory reallocation failed.\n");
                            free(text);
                            return 1;
                        }

                        text = new_buffer;
                    }

                }

                text[x] = '\0';



                //free(space);
                space[0] = '\0';
*/
                text = space;


                printf("\n the edited text: %s", text);
                break;
            case 4:
                text[0] = '\0';
                deleted = true;
                printf("text deleted");
                break;
            case 5:
                printf("\n the text: \n%s", text);
                break;
            case 6:
                txt = fopen("in.txt", "a");
                fprintf(txt, "%s\n", text);
                fclose(txt);
                printf("text saved");
                break;
            case 7:
                txt = fopen("out.txt", "r");
                fgets(text, size, txt);
                text[strlen(text)] = '\0';
                fclose(txt);
                printf("text loaded");
                break;
            case 8:
                verify = 1;
                break;
        }
    }

    free(text);
return 0;
}
