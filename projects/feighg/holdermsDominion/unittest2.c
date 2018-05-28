/*
 * Testing discardCard function
 */

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
    int maxHandPos = 5;
    int p, r, handCount, handPos, trashFlag, cardAtPos;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    
    
    printf ("TESTING discardCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (handPos = 0; handPos < maxHandPos; handPos++)
            {
                for (trashFlag = 0; trashFlag <= 1; trashFlag++){
#if (NOISY_TEST == 1)
                printf("Test player %d with %d card(s) and %d hand position.\n", p, handCount, handPos);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
                G.playedCardCount = 0;
                cardAtPos= G.hand[p][handPos];
                discardCard(handPos, p, &G, trashFlag);
                    
                if (trashFlag == 0){
#if (NOISY_TEST == 1)
                        printf("playedCard = %d, expected = %d\n", G.playedCards[0], cardAtPos);
#endif
                        assert(G.playedCards[0] == cardAtPos);
#if (NOISY_TEST == 1)
                        printf("playedCardCount = %d, expected = %d\n", G.playedCardCount, 1);
#endif
                        assert(G.playedCardCount == 1);
                }
                    
                if (handCount > 0){
#if (NOISY_TEST == 1)
                printf("handcount = %d, expected = %d\n", G.handCount[p], handCount - 1);
#endif
                assert(G.handCount[p] == handCount-1); // check if the number of cards is correct
                }
                else if (handCount < 1){
#if (NOISY_TEST == 1)
                    printf("handcount = %d, expected = %d\n", G.handCount[p], handCount);
#endif
                    assert(G.handCount[p] == handCount);
                }
                
                }
            }
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}
