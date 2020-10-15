#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>

unsigned sort(long long *, unsigned);
short args(int argc, char **argv, long long *FROM, long long *TO){
    if(argc <= 1) return -1;
    if(argc > 3) return -2;
    if((argc > 2 && strchr(argv[1], '=') == NULL) && strchr(argv[2], '=') == NULL) return -4;
    char *t1, *t2;
    unsigned X;
    if(strchr(argv[1], '=') != NULL) {
        X = strlen(argv[1]) - strlen(strchr(argv[1], '=')) + 1;
        if (X < strlen(argv[1])){
            t1 = malloc(sizeof(char) * X);
            strncpy(t1, argv[1], X);
            t1[X] = '\0';
            char *buf_string;
            long long buf_int = 0;
            buf_string = malloc(sizeof(char) * strlen(argv[1]) - X);
            buf_string = strchr(argv[1], '=') + 1;
            if ((buf_string[0] >= 49 && buf_string[0] <= 57) || buf_string[0] == '-')
                buf_int = strtoll(buf_string, &buf_string, 10);
            if (!strcmp(t1, "--from=")){
                if (strlen(buf_string) == 0) *FROM = buf_int; else *FROM = 0;
            }
            else if (!strcmp(t1, "--to=")) {
                if (strlen(buf_string) == 0) *TO = buf_int; else *TO = 0;
            }
        }
        else {
            if (strcmp(argv[1], "--from=") == 0) *FROM = 0;
            if (strcmp(argv[1], "--to=") == 0) *TO = 0;
        }
    }
    if(argc < 3 || strchr(argv[2], '=') == NULL) return 0;
    X = strlen(argv[2]) - strlen(strchr(argv[2], '=')) + 1;
    if(X < strlen(argv[2])) {
        t2 = malloc(sizeof(char) * X);
        strncpy(t2, argv[2], X);
        t2[X] = '\0';
        char *buf_string;
        long long buf_int;
        buf_string = malloc(sizeof(char) * (strlen(argv[2]) - X));
        buf_string = strchr(argv[2], '=') + 1;
        if((buf_string[0] >= 49 && buf_string[0] <= 57) || buf_string[0] == '-')  buf_int = strtoll(buf_string, &buf_string, 10);
        if(!strcmp(t2, "--from=")) {
            if(strlen(buf_string) == 0) *FROM = buf_int; else *FROM = 0;
            }
        else if(!strcmp(t2, "--to=")) {
            if(strlen(buf_string) == 0) *TO = buf_int; else *TO = 0;
            }
        }
    else {
        if(strcmp(argv[2], "--from =") == 0) *FROM = 0;
        if(strcmp(argv[2], "--to =") == 0) *TO = 0;
        }
        if(*FROM == LLONG_MIN && *TO == LLONG_MAX) return -4;
        if(!strcmp(t1, t2)) return -3;
        return 0;
    }

int main(int argc, char **argv) {

    long long s_From = LLONG_MIN, s_To = LLONG_MAX;
    int error_value = args(argc, argv, &s_From, &s_To);
    if(error_value) return error_value;
    long long *array = malloc(sizeof(long long) * 100);
    char divider = ' ';
    unsigned elems_count = 0;
    while(divider == ' ') {

        scanf("%lld%c", &array[elems_count], &divider);
        elems_count++;
    }
    unsigned counter = 0;
    for(unsigned i = 0; i < elems_count;i++) {

        if(array[i] > s_From && array[i] < s_To) counter++;
    }
    long long *a_reduced = malloc(sizeof(long long) * counter);
    counter = 0;
    for(unsigned i =0; i< elems_count;i++) {

        if(array[i] > s_From && array[i] < s_To) {

            a_reduced[counter] = array[i];
            counter++;
        } else {

            if(array[i] <= s_From) fprintf(stdout, "%lld ", array[i]);
            if(array[i] >= s_To) fprintf(stderr, "%lld ", array[i]);
        }
    }
    unsigned sw = 0;
    if(counter > 0) sw = sort(a_reduced, counter);
    free(array);
    free(a_reduced);
    return sw;
}

