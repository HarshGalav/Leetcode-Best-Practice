class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>cache;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        auto it=cache[key];
        int val=it->second;
        dll.erase(it);
        dll.push_front({key,val});
        cache[key]=dll.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            dll.erase(cache[key]);
        }
        else if(dll.size() == cap) {
            auto lru = dll.back();
            cache.erase(lru.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        cache[key] = dll.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */