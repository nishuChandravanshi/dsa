class LRUCache {
public:
    unordered_map<int, int> valueMap;
    unordered_map<int, list<int>::iterator> kv;
    list<int> l;
    int cap;
    int sz;
    LRUCache(int capacity) {
        sz = 0;
        cap = capacity;
    }
    
    int get(int key) {Valid(
        if(!kv.count(key))return -1;
        int val = valueMap[key];
        l.erase(kv[key]);
        l.push_front(key);
        kv[key] = l.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(!kv.count(key)){
            if(sz == cap){
                list<int>::iterator it = l.end();it--;
                valueMap.erase(*it);kv.erase(*it);
                l.pop_back();
            }
            else sz++;
        }
        else {
            list<int>::iterator it = kv[key];
            l.erase(it);
        }
        l.push_front(key);
        kv[key] = l.begin();
        valueMap[key] = value;
    }
};
