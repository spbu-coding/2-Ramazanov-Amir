#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_SORT 100

void sort(int *array, int size);

int main(int argc, char **argv) {

    if (argc<2) {
        return -1;
    }
    else if (argc >3 ){
        return -2;
    }
    int from,to;
    int from_count=0,to_count =0;

    for(int i=1; i<argc;i++){
        if(strncmp(argv[i],"--from=",7)==0 ){
            from_count++;
            from = atoi(argv[i]+7);
        }
        else if (strncmp (argv[i],"--to=",5)==0){
            to_count++;
            to= atoi(argv[i]+5);
        }
    }
    if((from_count==2) || (to_count==2)) {
        return -3;
    }
    if ((from_count==0) && (to_count==0)) {
        return -4;
    }
    int array[MAX_INPUT_SORT],array_cop[MAX_INPUT_SORT], size = 0, num;
    char delim ;

    do {
        scanf("%d%c",&num, &delim);
        if (num<=from){
            fprintf(stdout,"%d ",num);
        }
        if(num>=to){
            fprintf(stderr,"%d ",num);
        }
        if ((num> from)&&(num<to)) {
            array[size]=num;
            array_cop[size]=num;
            size++;
        }
    }while(delim==' ');


    sort(array,size);

    int count=0;
    for (int i=0;i<size;i++){
        if(array_cop[i] != array[i]){
            count++;
        }
    }

    return count;
}