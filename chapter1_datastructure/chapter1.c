#include "chapter1.h"

int get_max_score(int n){
    int scores[MAX_ELEMENTS];

    int i, largest;
    largest = scores[0];
    for(i = 1; i < n; i++){
        if(scores[i] > largest){
            largest = scores[i];
        }
    }
    return largest;
}