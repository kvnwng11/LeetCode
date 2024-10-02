class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        unordered_map<string, vector<string>> adjList;

        for (string &word : wordList) {
            for (int i=0; i<L; ++i) {
                string newWord = word.substr(0, i) + '*' + word.substr(i+1, L);
                adjList[newWord].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> seen;       
        seen.insert(beginWord);

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == endWord) return dist;
            
            for (int i=0; i<L; ++i) {
                string newWord = curr.substr(0, i) + '*' + curr.substr(i+1, L);

                for (string &neighbor : adjList[newWord]) {
                    if (neighbor == endWord) return dist + 1;

                    if (!seen.count(neighbor)) {
                        seen.insert(neighbor);
                        q.push({neighbor, dist+1});
                    }
                }
            }
        }

        return 0;
    }
};