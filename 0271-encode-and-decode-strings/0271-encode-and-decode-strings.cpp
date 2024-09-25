class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";

        for (string &str : strs) {
            ans += to_string(str.size());
            ans += '#';
            ans += str;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        // 3#abc5#abcde
        //      ^
        while (i < s.size()) {
            size_t delimIdx = s.find('#', i);

            int length = stoi(s.substr(i, delimIdx - i));
            ans.push_back(s.substr(delimIdx+1, length));
            i = delimIdx + length + 1;
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));