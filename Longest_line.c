#include <stdio.h>
#include <string.h>

int main(){
    char buffer[250] = {0};
    char longest_line[250] = {0};
    int longest_length = 0;
    int c;

    FILE *fptr;

    int i = 0;
    int length = 0;

    char filename[100] = {0};
    printf("Enter the filename with extension ex. test.txt\n");
    printf("filename : ");
    scanf("%99s", filename);

    fptr = fopen(filename, "r");
    if(fptr == NULL){
        fprintf(stderr, "Error! File not found!\n");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));
    memset(longest_line, 0, sizeof(longest_length));
    length = 0;
    i = 0;

    while((c = fgetc(fptr)) != EOF){
        buffer[i] = c;
        length++;
        i++;
        if(c == '\n'){
            if(longest_length < length){
                memset(longest_line, 0, sizeof(longest_length));
                for(int j = 0; buffer[j] != '\0'; j++)
                    longest_line[j] = buffer[j];
                longest_length = length;
            }
            for(int j = 0; buffer[j] != '\0'; j++)
                buffer[j] = 0;
            length = 0;
            i = 0;
        }
    }
    longest_length--;
    longest_line[longest_length] = '\0';

    printf("Longest_line : %s\nLongest_length = %d\n\n", longest_line, longest_length);

    fclose(fptr);
    return 0;
}
