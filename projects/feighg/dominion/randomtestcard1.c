//
//  randomtestcard1.c
//  
//
//  Created by Grace Feigh on 5/13/18.
//


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
    int seed = 1000;
    int numPlayer = 2;
    int maxCardCount = 5;
    int p, r, handPos, handCount, deckCount, playedCardCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    
    
    
    printf ("TESTING smithyfun():\n");
    for (int i = 0; i < 100; i++)
    {
        p = rand() % numPlayer;
        seed = rand() % 1000;
        handPos = rand() % maxCardCount;
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        handCount = G.handCount[p];
        deckCount = G.deckCount[p];
        playedCardCount = G.playedCardCount;
            handCount = handCount + 2;
            deckCount = deckCount - 3;
            playedCardCount = playedCardCount + 1;
            smithyfun(p, &G, handPos);
            printf("Playing with player %d, handPos %d\n", p, handPos);
            printf("HandCount: %d, Expected: %d\n", G.handCount[p], handCount);
            failedTests += assertNums(G.handCount[p], handCount);
            printf("DeckCount: %d, Expected: %d\n", G.deckCount[p], deckCount);
            failedTests += assertNums(G.deckCount[p], deckCount);
            printf("PlayedCardCount: %d, Expected: %d\n", G.playedCardCount, playedCardCount);
            failedTests += assertNums(G.playedCardCount, playedCardCount);
    }
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}

