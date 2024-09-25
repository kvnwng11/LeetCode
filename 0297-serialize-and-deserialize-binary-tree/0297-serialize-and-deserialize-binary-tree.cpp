/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    const int NULL_VAL = 1002;

    void serializeHelper(TreeNode* root, string &str) {
        if (!root) {
            str += '#';
            str += to_string(NULL_VAL);
            return;
        }

        str += '#';
        str += to_string(root->val);
        serializeHelper(root->left, str);
        serializeHelper(root->right, str);
    }

    TreeNode* deserializeHelper(queue<int> &vals) {
        if (vals.empty()) return nullptr;
        int curr = vals.front();
        vals.pop();

        if (curr == NULL_VAL) return nullptr;

        TreeNode* newNode = new TreeNode(curr);
        newNode->left = deserializeHelper(vals);
        newNode->right = deserializeHelper(vals);
        return newNode;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        serializeHelper(root, ans);
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> vals;
        int i = 0;
        while (0 <= i && i < data.size() && data[i] == '#') {
            int curr = data.find('#', i);
            i = data.find('#', curr+1);
            if (i == string::npos)
                vals.push(stoi(data.substr(curr+1)));
            else
                vals.push(stoi(data.substr(curr+1, i - curr + 1)));
        }

        return deserializeHelper(vals);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));