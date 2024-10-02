class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counts;
        for (char c : ransomNote)
            counts[c] += 1;
        
        int required = counts.size();
        for (char c : magazine) {
            counts[c] -= 1;
            if (counts[c] == 0) required--;
        }
        return required == 0;
    }
};