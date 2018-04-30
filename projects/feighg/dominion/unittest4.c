//
//  isGameOverTest.c
//  Testing isGameOver() function
//
//  Created by Grace Feigh on 4/26/18.
//


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int maxProvince = 12;
    //int maxHandPos = 5;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    //int maxHandCount = 5;
    
    
    
    printf ("TESTING isGameOver():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (int i = 0; i <= maxProvince; i++){
            r = initializeGame(numPlayer, k, seed, &G);
            G.supplyCount[province] = i;
            if (i == 0){
#if (NOISY_TEST == 1)
                printf("Testing game with 0 province cards.\n");
#endif
                r = isGameOver(&G);
#if (NOISY_TEST == 1)
                printf("return value: %d, Expected: 1 \n", r);
#endif
                assert (r == 1);
            }
            else{
#if (NOISY_TEST == 1)
                printf("Testing game with %d province cards.\n", i);
#endif
                for (int j = 0; j < 5; j++){
                    G.supplyCount[j] = 0;
                    if (j >= 2){
                        printf("Testing game with >3 zero-count supply cards\n");
                        r = isGameOver(&G);
                        printf("return value: %d, Expected: 1\n", r);
                        assert(r==1);
                    }
                    else{
                        printf("Testing game with <3 zero-count supply cards\n");
                        r = isGameOver(&G);
                        printf("return value: %d, Expected: 0\n", r);
                        assert(r==0);
                    }
                }
            }
        }

    }
    
    printf("All tests passed!\n");
    
    return 0;
}
