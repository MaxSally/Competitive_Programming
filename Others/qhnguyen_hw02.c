#include<stdio.h>

const int N = 1000;


int main(){
    int lst[N], mark[N];
    memset(mark, mark + N, 0);
    int cnt = 0;
    for(int i = 1; 1LL * i * i * i < 1000; ++i){
        lst[i] = i * i * i;
        mark[i * i * i] = 1;
        cnt++;
    }
    int found = 0;
    for(int i = 1; i < cnt; ++i){
        for(int j = 1; j < cnt; ++j){
            if(mark[lst[i] + lst[j]] == 1){
                printf("found a triplets %d %d %d", lst[i], lst[j], lst[i] + lst[j]);
                found = 1;
            }
        }
    }
    if(found == 0){
        printf("No positive perfect cubes less than 1000 that are the sum of the cubes of two positive integers.\n");
    }

    return 0;
}
