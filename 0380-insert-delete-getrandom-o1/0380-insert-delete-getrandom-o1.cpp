class RandomizedSet {
public:    
    unordered_set<int>s;

    
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(s.count(val)) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it=rand();
        return *next(s.begin(),it%s.size());
       
        
    }
};