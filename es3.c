#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;

    if ((fp_read = fopen("../es3/Bronte.txt", "r")) == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("../es3/OutputOdd.txt", "w")) == NULL) {
        printf("Error opening output1 file\n");
        return 2;
    }
    if ((fp_write_even = fopen("../es3/OutputEven.txt", "w")) == NULL) {
        printf("Error opening output2 file\n");
        return 2;
    }

    printf("What's your name?");
    gets(name);
    while (!feof(fp_read)) {
        counter++;
        if (counter % 2 == 0) {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read)) {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        } else {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);

    return 0;
}