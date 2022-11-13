class MyHashMap {
public:
    
    vector<int> mp;
    
    MyHashMap() {
        vector<int> ref(1000001,-1);
        mp = ref;
    }
    
    void put(int key, int value) {
        mp[key] = value;
        //cout<<"PUT: "<<key<<" "<<value<<endl;
    }
    
    int get(int key) {
        //cout<<"GET: "<<key<<endl;
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
        //cout<<"REMOVE: "<<key<<endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */