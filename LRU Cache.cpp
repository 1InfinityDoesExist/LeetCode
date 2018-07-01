class LRUCache {
    private:
        vector<int> v;
        int capacity;
        map<int, int> mp;
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key) {
        vector<int>::iterator iter = find(v.begin(), v.end(), key);
        if(iter != v.end()){
            int sk = *iter;
            v.erase(iter);
            v.push_back(sk);
            return mp[key];
        }
        else{
            return -1;
        }

    }

    void put(int key, int value) {
        vector<int>::iterator iter = find(v.begin(), v.end(), key);
        if(iter == v.end()){
            if(v.size() == capacity){
                vector<int>::iterator jter = v.begin();
                v.erase(jter);
            }
            v.push_back(key);
            mp[key] = value;
        }else{
            if(value != mp[key]){
                mp[key] = value;
            }
            int sk = *iter;
            v.erase(iter);
            v.push_back(sk);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
