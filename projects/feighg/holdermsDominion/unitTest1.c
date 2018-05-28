//
//  scoreTest.c
//  Testing scoreFor() function
//
//  Created by Grace Feigh on 4/26/18.
//

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
    int maxCardCount = 5;
    int i, p, r, gameScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    
    
    
    printf ("TESTING scoreFor():\n");
    for (p = 0; p < numPlayer; p++)
    {
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        for (i = 0; i < maxCardCount; i++)
        {
            int score = 0;
            //add cards to hand
            G.hand[p][6*i] = curse;
            G.hand[p][1+(6*i)] = estate;
            G.hand[p][2+(6*i)] = duchy;
            G.hand[p][3+(6*i)] = province;
            G.hand[p][4+(6*i)] = great_hall;
            G.hand[p][5+(6*i)] = gardens;
            
            //calculate score
            score = score - (i);
            score = score + i;
            score = score + (i*3);
            score = score + (i*6);
            score = score + i;
            score = score + ( fullDeckCount(p, 0, &G) / 10 );
            
            //set counts
            G.handCount[p] = i*6;
            G.discardCount[p] = 0;
            G.deckCount[p] = 0;
            printf("Testing with handcount: %d, discardcount: %d, deckCount: %d, and %d of each card\n", G.handCount[p], G.discardCount[p], G.deckCount[p], i);
            gameScore = scoreFor(p, &G);
            printf("Score: %d, Expected: %d\n", gameScore, score);
            failedTests += assertNums(gameScore, score);
    
            G.discard[p][6*i] = curse;
            G.discard[p][1+(6*i)] = estate;
            G.discard[p][2+(6*i)] = duchy;
            G.discard[p][3+(6*i)] = province;
            G.discard[p][4+(6*i)] = great_hall;
            G.discard[p][5+(6*i)] = gardens;
            
            //calculate score
            score = score - (i);
            score = score + i;
            score = score + (i*3);
            score = score + (i*6);
            score = score + i;
            score = score + ( fullDeckCount(p, 0, &G) / 10 );
            
            //set counts
            G.handCount[p] = i*6;
            G.discardCount[p] = i*6;
            G.deckCount[p] = 0;
            printf("Testing with handcount: %d, discardcount: %d, deckCount: %d, and %d of each card\n", G.handCount[p], G.discardCount[p], G.deckCount[p], i);
            gameScore = scoreFor(p, &G);
            printf("Score: %d, Expected: %d\n", gameScore, score);
            failedTests += assertNums(gameScore, score);
            
            
            G.deck[p][6*i] = curse;
            G.deck[p][1+(6*i)] = estate;
            G.deck[p][2+(6*i)] = duchy;
            G.deck[p][3+(6*i)] = province;
            G.deck[p][4+(6*i)] = great_hall;
            G.deck[p][5+(6*i)] = gardens;
            
            //calculate score
            score = score - (i);
            score = score + i;
            score = score + (i*3);
            score = score + (i*6);
            score = score + i;
            score = score + ( fullDeckCount(p, 0, &G) / 10 );
            
            //set counts
            G.handCount[p] = i*6;
            G.discardCount[p] = i*6;
            G.deckCount[p] = i*6;
            printf("Testing with handcount: %d, discardcount: %d, deckCount: %d, and %d of each card\n", G.handCount[p], G.discardCount[p], G.deckCount[p], i);
            gameScore = scoreFor(p, &G);
            printf("Score: %d, Expected: %d\n", gameScore, score);
            failedTests += assertNums(gameScore, score);
      
}
}
    if (failedTests == 0) printf("All tests passed!\n");
    else printf("Tests failed.\n");
    return 0;
}

