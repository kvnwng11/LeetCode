class Solution {

public:
    int compress(vector<char>& chars) {
        int toWrite = 0, ans = 0;

        for (int i=0; i<chars.size();) {
            int length = 1;
            while (i + length < chars.size() and chars[i+length] == chars[i])
                length++;

            chars[ans++] = chars[i];
            if (length > 1)
            {
                for (char c : to_string(length))
                    chars[ans++] = c;
            }

            i += length;
        }
        return ans;
    }
};