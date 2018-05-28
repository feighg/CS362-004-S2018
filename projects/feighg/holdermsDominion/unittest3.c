/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testing gainCard() function
 * -----------------------------------------------------------------------
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
    int maxSupplyPos = 17;
    int p, r, supCount, supplyPos, toFlag;
    int deckCount, handCount, discardCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    
    
    printf ("TESTING gainCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
            for (supplyPos = 0; supplyPos < maxSupplyPos; supplyPos++)
            {
                for (toFlag = 0; toFlag < 3; toFlag++){
                    for (int i = 0; i < 8; i++){
                        memset(&G, 23, sizeof(struct gameState)); //clear game state
                        r = initializeGame(numPlayer, k, seed, &G); //initialize new game
                        G.supplyCount[supplyPos] = i;
                        if (supplyCount(supplyPos, &G) < 1){
                            printf("Testing pull from 0 supply pile.\n");
                            r = gainCard(supplyPos, &G, toFlag, p);
                            printf("Return value: %d, Expected: -1\n", r);
                            assert(r == -1);
                        }
                        else{
                            supCount = G.supplyCount[supplyPos];
                            
                            if (toFlag == 1){
                                printf("Testing add to deck. supplyPos is: %d, Flag is: %d, player is: %d\n", supplyPos, toFlag, p);
                                deckCount = G.deckCount[p];
                                r = gainCard(supplyPos, &G, toFlag, p);
#if (NOISY_TEST == 1)
                                printf("Deck Card: %d, Expected: %d\n", G.deck[p][deckCount], supplyPos);
                                printf("Deck Count: %d, Expected: %d\n", G.deckCount[p], deckCount+1);
#endif
                                assert(G.deck[p][deckCount] == supplyPos);
                                assert(G.deckCount[p] == deckCount + 1);
                                
                            }
                            else if (toFlag == 2){
                                printf("Testing add to hand. supplyPos is: %d, Flag is: %d, player is: %d\n", supplyPos, toFlag, p);
                                handCount = G.handCount[p];
                                r = gainCard(supplyPos, &G, toFlag, p);
#if (NOISY_TEST == 1)
                                printf("Hand Card: %d, Expected: %d\n", G.hand[p][handCount], supplyPos);
                                printf("Hand Count: %d, Expected: %d\n", G.handCount[p], handCount+1);
#endif
                                assert(G.hand[p][handCount] == supplyPos);
                                assert(G.handCount[p] == handCount + 1);
                                
                            }
                            else {
                                printf("Testing add to discard. supplyPos is: %d, Flag is: %d, player is: %d\n", supplyPos, toFlag, p);
                                discardCount = G.discardCount[p];
                                printf("Current discardCount: %d\n", discardCount);
                                r = gainCard(supplyPos, &G, toFlag, p);
#if (NOISY_TEST == 1)
                                printf("Discard Card: %d, Expected: %d\n", G.discard[p][discardCount], supplyPos);
                                printf("Discard Count: %d, Expected: %d\n", G.discardCount[p], discardCount+1);
#endif
                                assert(G.discard[p][discardCount] == supplyPos);
                                assert(G.discardCount[p] == discardCount + 1);
                                
                            }
#if (NOISY_TEST == 1)
                            printf("Supply Count: %d, Expected: %d\n", G.supplyCount[supplyPos], supCount-1);
#endif
                            assert(G.supplyCount[supplyPos] == supCount-1);
                        }
                }
            }
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}
