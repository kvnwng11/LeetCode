class Solution {
    unordered_set<char> vowels{
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    };

    bool isVowel(char c) {
        return vowels.count(c);
    }

public:
    string reverseVowels(string s) {
        vector<int> vowelIdx;

        for (int i=0; i<s.size(); ++i) {
            if (isVowel(s[i])) {
                vowelIdx.push_back(i);
            }
        }

        for (int i=0; i<vowelIdx.size()/2; ++i) {
            int left = i;
            int right = vowelIdx.size()-1-i;
            swap(s[vowelIdx[left]], s[vowelIdx[right]]);
        }
        
        return s;
    }
};