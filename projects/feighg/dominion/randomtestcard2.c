//
//  randomtestcard2.c
//  
//
//  Created by Grace Feigh on 5/13/18.
//

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertNums.c"
#include <time.h>
#include <stdlib.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    srand(time(NULL));
    int seed;
    int numPlayer = 2;
    int i, p, r, handCount, coins, handPos;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    int choice1, choice2, choice3;
    
    
    
    printf ("TESTING stewardfun():\n");
    for (i = 0; i < 100; i++)
    {
        p = rand() % numPlayer;
        handPos = rand() % 5;
        seed = rand() % 1000;
        
        choice1 = rand() % 5;
        do{
            choice2 = rand() % 5;
        }while(choice1 == choice2);
        do{
            choice3 = rand() % 5;
        }while(choice3 == choice1 || choice3 == choice2);
                
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
                
                handCount = G.handCount[p];
                coins = G.coins;
                printf("Testing with choice1 = %d, choice2 = %d, choice3 = %d, handPos = %d\n", choice1, choice2, choice3, handPos);
                stewardfun(choice1, choice2, choice3, handPos, p, &G);
                if (choice1 == 1){
                    printf("Handcount: %d, Expected: %d\n", G.handCount[p], handCount+1);
                    failedTests += assertNums(G.handCount[p], handCount + 1);
                }
                else if (choice1 == 2){
                    printf("Coins: %d, Expected: %d\n", G.coins, coins + 2);
                    failedTests += assertNums(G.coins, coins + 2);
                    printf("Handcount: %d, Expected: %d\n", G.handCount[p], handCount -1);
                    failedTests += assertNums(G.handCount[p], handCount - 1);
                }
                else{
                    printf("Handcount: %d, Expected: %d\n", G.handCount[p], handCount - 3);
                    failedTests += assertNums(G.handCount[p], handCount - 3);
                }
        
    }
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}
