//
//  assertNums.c
//  
//
//  Created by Grace Feigh on 4/26/18.
//

#include <stdio.h>

int assertNums(int i, int j){
    if (i == j){
        printf("test passed\n");
        return 0;
    }
    else{
        printf("test FAILED\n");
        return 1;
    }
}
