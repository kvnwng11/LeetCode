class FileSystem {
private:
    struct Node {
        string name = "";
        string content = "";
        bool isFile = 0;
        
        map<string, Node> children;
    };    
    
    Node root;
    
    vector<string> parse(string &s) {
        vector<string> ans;
        if (s == "/") return ans;
        
        string path = s + "@";
    
        string curr = "";
        for (int i=1; i<path.size(); ++i) {
            char c = path[i];
            
            if (c == '/' or c == '@') {
                ans.push_back(curr);
                curr = "";
            }
            else {
                curr += c;
            }
        }
        
        return ans;
    }
    
    
public:
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        vector<string> parsed = parse(path);
        
        Node *curr = &root;

        /*
        cout << "Path: " << path << endl;
        for (string s : parsed)
            cout << s << endl;
        cout << endl;
        */
        
        for (int i=0; i<parsed.size(); ++i) {
            string token = parsed[i];
            curr = &curr->children[token];
        }
                
        if (curr->isFile) {
            //cout << "Name: " << curr->name << endl;
            vector<string> ans;
            ans.push_back(curr->name);
            return ans;
        }
        else {
            vector<string> ans;
            for (auto &p : curr->children) {
                //cout << p.first << endl;
                ans.push_back(p.first);
            }
            return ans;
        }
    }
    
    void mkdir(string path) {
        vector<string> parsed = parse(path);
        
        Node *curr = &root;
        
        for (int i=0; i<parsed.size(); ++i) {
            string token = parsed[i];
            
            // Need to create
            if (i == parsed.size()-1 or curr->children.count(token) == 0) {
                Node newDir;
                newDir.name = token;
                newDir.isFile = 0;
                curr->children[token] = newDir;
                                
                curr = &curr->children[token];
            }
            
            // Exists
            else {
                curr = &curr->children[token];
            }
        }        
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> parsed = parse(filePath);
        
        // Find the file
        Node *curr = &root;
        for (int i=0; i<parsed.size()-1; ++i) {
            string token = parsed[i];
            
            // Need to create
            if (curr->children.count(token) == 0) {
                Node newDir;
                newDir.name = token;
                newDir.isFile = 0;
                curr->children[token] = newDir;
                
                curr = &curr->children[token];
            }
            
            // Exists
            else {
                curr = &curr->children[token];
            }
        }
        
        string fileName = parsed.back();
        
        // Need to create file
        if (curr->children.count(fileName) == 0) {
            Node newDir;
            newDir.name = fileName;
            newDir.isFile = 1;
            curr->children[fileName] = newDir;
        }
        
        // Add to file
        curr->children[fileName].content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> parsed = parse(filePath);

        Node *curr = &root;
        for (int i=0; i<parsed.size(); ++i) {
            string token = parsed[i];
            

            curr = &curr->children[token];
        }
        
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */