class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> indices;
        int numR = 0, numD = 0;

        for (int i=0; i<senate.size(); ++i) {
            indices.push(i);
            if (senate[i] == 'R') numR++;
            else numD++;
        }

        int banR = 0, banD = 0;
        while (numR > 0 and numD > 0) {
            
            int curr = indices.front(); indices.pop();

            if (senate[curr] == 'R') {
                if (banR) {
                    numR--;
                    banR--;
                }
                else {
                    banD++;
                    indices.push(curr);
                }
            }
            else {
                
                if (banD) {
                    numD--;
                    banD--;
                }
                else {
                    banR++;
                    indices.push(curr);
                }
            }

        }

        return numD > 0? "Dire": "Radiant";
    }
};