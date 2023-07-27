#include<stdio.h>
#include<limits.h>
int checkHit(int incomingpage, int queue[], int occupied) 
    {
    for(int i=0; i<occupied; i++) {
        if(incomingpage == queue[i])
        return 1;
    }
    return 0;

    }
    void printFrame(int queue[], int occupied)
    {
        for(int i=0; i<occupied; i++) {

    }

