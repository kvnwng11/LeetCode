class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> indicesR;
        queue<int> indicesD;

        for (int i=0; i<senate.size(); ++i) {
            if (senate[i] == 'R') indicesR.push(i);
            else indicesD.push(i);
        }

        while (indicesR.size() > 0 and indicesD.size() > 0) {
            
            int rTurn = indicesR.front(); indicesR.pop();
            int dTurn = indicesD.front(); indicesD.pop();

            if (rTurn < dTurn) indicesR.push(dTurn + n);
            else indicesD.push(rTurn + n);
        }

        return indicesR.empty()? "Dire": "Radiant";
    }
};