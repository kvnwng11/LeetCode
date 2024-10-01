class TimeMap {
private:
    struct data {
        string value;
        int timestamp;
    };
    unordered_map<string, vector<data>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!m.count(key)) m[key] = vector<data>();
        m[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";

        int left = 0, right = m[key].size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (m[key][mid].timestamp <= timestamp) left = mid+1;
            else right = mid-1;
        }

        if (right == -1) return "";

        return m[key][left-1].value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */