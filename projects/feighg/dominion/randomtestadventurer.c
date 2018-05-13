//
//  randadventurer.c
//  
//
//  Created by Grace Feigh on 5/11/18.
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
    int i, p, r, handCount, cardDrawn;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    
    printf ("TESTING adventurerfun():\n");
    for (int y = 0; y < 100; y++)
    {
        seed = rand() % 1000;
        p = rand() % numPlayer;
        //deckCountNum = rand() % 11;
        //test with 0 deckCount - be sure shuffle works
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        printf("Testing with player %d and %d deckCount.\n", p, G.deckCount[p]);
        //add deck to discard pile
        /*
        for (i = 0; i < G.deckCount[p];i++){
            G.discard[p][i] = G.deck[p][i];
            G.deck[p][i] = -1;
        }
         */
        //G.deckCount[p] = deckCountNum;
        handCount = G.handCount[p];
        adventurerfun(p, &G);
        printf("Testing that treasure cards were drawn. \n");
        for (i = 0; i<2; i++){
            cardDrawn = G.hand[p][handCount + i];
            printf("Card at position: %d\n", handCount + i);
            printf("Card drawn: %d\n", cardDrawn);
            if (cardDrawn == copper || cardDrawn== silver || cardDrawn == gold){
                printf("Test passed.\n");
            }
            else{
                printf("Test failed.\n");
                failedTests += 1;
            }
        }
        printf("Testing that 2 cards were drawn. \n");
        printf("HandCount: %d, Expected: %d\n", G.handCount[p], handCount+2);
        failedTests += assertNums(G.handCount[p], handCount+2);
    }
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}

