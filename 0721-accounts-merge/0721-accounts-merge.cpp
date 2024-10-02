class UnionFind {
private:
    vector<int> father;
    
public:

    UnionFind(vector<vector<string>>& accounts) {
        father = vector<int>(accounts.size());
        for (int i=0; i<accounts.size(); ++i)
            father[i] = i;
    }

    int find(int x) {
        if (x == father[x]) return x;
        int tmp = find(father[x]);
        father[x] = tmp;
        return tmp;
    }

    void join(int x, int y) {
        int father1 = find(x);
        int father2 = find(y);
        father[father1] = father2;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind u{accounts};

        unordered_map<string, int> emailToGroup;
        for (int i=0; i<accounts.size(); ++i) {
            string name = accounts[i][0];

            for (int j=1; j<accounts[i].size(); ++j) {
                string email = accounts[i][j];

                if (!emailToGroup.count(email))
                    emailToGroup[email] = i;
                else
                    u.join(i, emailToGroup[email]);
            }
        }

        unordered_map<int, vector<string>> accountToEmailList;
        for (auto &[email, group] : emailToGroup) {
            accountToEmailList[u.find(group)].push_back(email);
        }

        vector<vector<string>> ans;

        for (auto& [group, emails] : accountToEmailList) {
            vector<string> account{accounts[group][0]};
            account.insert(account.end(), emails.begin(), emails.end());
            sort(account.begin() + 1, account.end());
            ans.push_back(account);
        }

        return ans;
    }
};