#include <stdio.h>
#include <omp.h>
#include "./n-body.c"

void start(){
    int j = 0;
    int i = 0;
    for (j = 0; j < 1; ++j){
        for (i = 0; i < 10000; ++i){
            updatePhysics(i * 100);
        }
    }
}

int main(){
    start();
    return 0;
}