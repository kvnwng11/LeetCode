class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        unordered_map<int, int> cardCount;
        for (int card : hand)
            cardCount[card]++;

        for (int i=0; i<hand.size(); ++i) {
            int startCard = hand[i];

            while (cardCount[startCard-1]) {
                startCard--;
            }

            while (startCard <= hand[i]) {
                while (cardCount[startCard]) {
                    for (int nextCard = startCard; nextCard < startCard + groupSize; ++nextCard) {
                        if (!cardCount[nextCard]) return false;
                        cardCount[nextCard]--;
                    }
                }
                startCard++;
            }
        }

        return true;
    }
};