//
//  stewardTest.c
//  
//
//  Created by Grace Feigh on 4/28/18.
//

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertNums.c"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int i, p, r, handCount, coins, handPos;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    int choice1, choice2, choice3;
    
    
    
    printf ("TESTING stewardfun():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handPos = 0; handPos < 5; handPos++){
            for (i = 0; i < 3; i++){
                choice1 = i;
                choice2 = i+1;
                choice3 = i+1;
                
                memset(&G, 23, sizeof(struct gameState)); //clear game state
                r = initializeGame(numPlayer, k, seed, &G); //initialize new game
                
                handCount = G.handCount[p];
                coins = G.coins;
                printf("Testing with choice1 = %d, choice2 = %d, choice3 = %d, handPos = %d\n", choice1, choice2, choice3, handPos);
                cardEffect(steward, choice1, choice2, choice3, &G, handPos, 0);
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
        }
        
    }
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}
