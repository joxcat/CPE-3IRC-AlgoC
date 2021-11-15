#import <stdio.h>

int main() {
    printf("%lu", sizeof (int));
    printf("%lu", sizeof (int *));
    printf("%lu", sizeof (int **));
    printf("%lu", sizeof (char *));
    printf("%lu", sizeof (char **));
    printf("%lu", sizeof (char ***));
    printf("%lu", sizeof (float *));
    printf("%lu", sizeof (float **));
    printf("%lu", sizeof (float ***));

    return 0;
}
