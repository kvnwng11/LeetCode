class Solution {
private:
    map<string, int> parser(string &s, int &i) {
        map<string, int> ans;

        string atom = "", count = "";

        while (i < s.size() and s[i] != ')') {
            map<string, int> counts = parseUnits(s, i);
            merge(ans, counts, 1);
        }

        return ans;
    }

    map<string, int> parseUnits(string &s, int &i) {
        map<string, int> ans;
        if (s[i] == '(') {
            map<string, int> counts = parser(s, ++i);
            int digits = getDigits(s, ++i);
            merge(ans, counts, digits);
        }
        else {
            int i0 = i++;
            while (i < s.size() and islower(s[i])) i++;
            string atom = s.substr(i0, i-i0);
            int digits = getDigits(s, i);
            ans[atom] += digits;
        }

        return ans;
    }

    int getDigits(string &s, int &i) {
        int i1 = i;
        while (i < s.size() and isdigit(s[i])) i++;
        int digits = i == i1? 1 : stoi(s.substr(i1, i - i1));
        return digits;
    }

    void merge(map<string, int>& counts, map<string, int>& cnts, int times) {
        for (pair<string, int> p : cnts)
            counts[p.first] += p.second * times;
    }

public:
    string countOfAtoms(string formula) {
        int i = 0;
        map<string, int> counts = parser(formula, i);
        string ans = "";
        for (auto [atom, count] : counts) {
            ans += atom;
            if (count > 1) ans += to_string(count);
        }
        return ans;
    }
};