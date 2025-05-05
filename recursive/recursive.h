//
// Created by 임준식 on 25. 5. 5.
//

#ifndef DATA_STRUCTURE_RECURSIVE_H
#define DATA_STRUCTURE_RECURSIVE_H

int factorial(int n){
    if(n <= 1) return 1;
    else return (n * factorial(n-1));
}

#endif //DATA_STRUCTURE_RECURSIVE_H
