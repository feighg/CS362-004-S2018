//
//  councilRoomTest.c
//  Testing councilRoom card
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
    int i, p, r, handCount, otherPlayerCount, handPos, nBuys, otherPlayerCountNew;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    //int councilRoom = k[1];
    struct gameState G;
    int failedTests = 0;
    //int bonus = 1;
    
    
    
    printf ("TESTING councilRoom card in cardEffect():\n");
    for (handPos = 0; handPos < 5; handPos ++){
        
            p=0;
            memset(&G, 23, sizeof(struct gameState)); //clear game state
            r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        printf("Game initialized\n");
            handCount = G.handCount[p];
            for (i = 0; i < numPlayer; i++){
                if (i != p) otherPlayerCount = G.handCount[i];
            }
            nBuys = G.numBuys;
        printf("buys received. \n");
        printf("Testing council_roomEffect\n");
        
            //cardEffect(councilRoom, 1, 2, 3, &G, handPos, &bonus);
            council_roomEffect (&G, p, handPos);
            printf("Testing with handPos %d\n", handPos);
            printf("HandCount for current player: %d, Expected: %d\n", G.handCount[p], handCount + 3);
            failedTests += assertNums(G.handCount[p], handCount + 3);
            printf("Buys: %d, Expected: %d\n", G.numBuys, nBuys+1);
            failedTests += assertNums(G.numBuys, nBuys+1);
            
            for (i = 0; i < numPlayer; i++){
                if (i != p) otherPlayerCountNew = G.handCount[i];
            }
            
            printf("HandCount for other player: %d, Expected: %d\n", otherPlayerCountNew, otherPlayerCount+1);
            failedTests += assertNums(otherPlayerCountNew, otherPlayerCount+1);
        }
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}

