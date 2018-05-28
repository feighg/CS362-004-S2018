//
//  adventurerTest.c
//  Testing adventurerfun() function
//
//  Created by Grace Feigh on 4/27/18.
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
    int i, p, r, handCount, cardDrawn;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int failedTests = 0;
    
    
    
    printf ("TESTING adventurerfun():\n");
    for (p = 0; p < numPlayer; p++)
    {
        //test with 0 deckCount - be sure shuffle works
        printf("Testing with 0 deckCount.\n");
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        //add deck to discard pile
        for (i = 0; i < G.deckCount[p];i++){
            G.discard[p][i] = G.deck[p][i];
            G.deck[p][i] = -1;
        }
        G.deckCount[p] = 0;
        handCount = G.handCount[p];
        adventurerEffect(&G, p);
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
        
        //testing with 1 deckCount
        printf("Testing with 5 deckCount.\n");
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        G.deckCount[p] = 5;
        handCount = G.handCount[p];
        adventurerEffect(&G, p);
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
        
        //testing with full deckCount
        printf("Testing with 10 deckcount.\n");
        memset(&G, 23, sizeof(struct gameState)); //clear game state
        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
        G.deckCount[p] = 10;
        handCount = G.handCount[p];
        adventurerEffect(&G, p);
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
