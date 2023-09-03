#include <stdio.h>

int main () {
    // Filebase
    FILE *fp;

    // read, write, append (process)
    // r -> read
    // fp = fopen("data.txt", "r");
    // fscanf(fp, "%[^\n]", txt);
    // printf("%s", txt);

    // w -> write (overwrite and create file)
    // fp = fopen("data.txt", "w");
    // fprintf(fp, "Hollo world!");
    
    // a -> append (add character)
    // fp = fopen("data.txt", "a");
    // fprintf(fp, "GM!");

    // r+ -> read, write (update per char)
    // fp = fopen("data.txt", "r+");
    // fprintf(fp, "Hello"); fix typo on write
    
    // w+ -> read, write (update all datas)
    // fp = fopen("data.txt", "w+");
    // fprintf(fp, "Test 123");
    // rewind(fp);
    // fscanf(fp, "%[^\n]", txt);
    // printf("%s", txt);

    
    // a+ -> append, read
    // fp = fopen("data.txt", "a+");
    // fprintf(fp, " world");

    // rewind(fp);
    // fscanf(fp, "%[^\n]", txt);
    // printf("%s", txt);

    // open, process, close
    char txt[200];

    // put process here
    // fp = fopen("data.txt", "a+");
    // fprintf(fp, " world");

    // rewind(fp);
    // fscanf(fp, "%[^\n]", txt);
    // printf("%s", txt);


    fclose(fp); // close the file after writing

    return 0;
}