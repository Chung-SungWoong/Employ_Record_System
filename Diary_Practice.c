#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

void welcome_message();
int insert();
int append();
int view();

int main()
{
    FILE *fp;
    char press;
    int num;
    First:

    while (1) {
        char pass[30];
        printf("Enter your password: ");
        scanf("%s", pass);

        if(strcmp(pass,"pass") == 0){
            break;
        } else {
            printf("Try Again!: ");
        }
    }

    printf("\n\n---- Press ----- operation ------\n\n");
    printf("     '+' ------ add new note     \n");
    printf("     'a' ------ append new note     \n");
    printf("     'v' ------ View Previous     \n");
    printf("     'e' ------ Exit Program     \n\n");
    printf("-------------------------------\n\n");

    while(1)
    {
        scanf("%c",&press);

        if (press == '+'){

            insert();
            printf("Press '1' for continue\n'0' for Exit\n");

            scanf("%d", &num);
            if (num == 1){
                goto First;
            }
            else{
                break;
            }
        }
        else if (press == 'a'){
            append();
            printf("Press '1' for continue\n'0' for Exit\n");
            scanf("%d", &num);
            if (num == 1){
                goto First;
            }
            else{
                break;
            }
        }
        else if (press == 'v'){
            view();
            printf("Press '1' for continue\n'0' for Exit\n");
            scanf("%d", &num);
            if (num == 1){
                goto First;
            }
            else{
                break;
            }
        }
        else if (press == 'e'){
            return 0;
        }
        else{
            printf("Please press correct key.\n");
        }
    }
    return 0;
}

void welcome_message() {
    printf("---***---***----***----***----***---\n\n");
    printf("|<--     Welcome to our Diary    -->|\n\n");
    printf("---***---***----***----***---***---\n\n");
}

int insert(){
    FILE *fp;
    char note[2000], date[20] ;
    welcome_message();
    time_t t = time(NULL);
    printf("%s", ctime(&t));
//    printf("Enter date of your note : ");
//    scanf("%s", date);
    //printf("%s",date);
    printf("\n");
    printf("Just write your note from here....\n---->>");
    scanf(" %[^\n]s",note);
    fp = fopen("diary.txt", "w");
    fprintf(fp, ctime(&t));
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nSuccessfully Copied.....:)\n");
    fclose(fp);
    return 0;
}

int append() {
    FILE *fp;
    char note[2000], date[20] ;
    welcome_message();
    printf("Enter date of your note : ");
    scanf("%s", date);
    //printf("%s",date);
    printf("\n");
    printf("Just write your note from here....\n---->>");
    scanf(" %[^\n]s", note);
    fp = fopen("diary.txt", "a");
    fprintf(fp, date);
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nSuccessfully Copied.....:)\n");
    fclose(fp);
    return 0;
}

int view() {
    FILE *fp;
    char ch;
    fp = fopen("diary.txt", "r");
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nYour previous note : \n\n");
    printf("===============================================================================\n");

    while( ( ch = fgetc(fp) ) != EOF ){
        printf("%c", ch);
    }
    printf("\n");
    printf("===============================================================================\n");
    fclose(fp);
    return 0;