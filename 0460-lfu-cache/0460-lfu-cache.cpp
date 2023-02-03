class LFUCache {
public:
    unordered_map <int, list <int>> freqs;
    unordered_map <int, tuple <list <int> :: iterator, int, int>> m;
    int n, init_cap;
    int low = -1;
    LFUCache(int capacity) {
        n = init_cap = capacity;
    }
    int inc(int key, int value = -1) { 
        auto [it, f, v] = m[key];
        if (value != -1) v = value;
        freqs[f].erase(it); // remove from previous freq
        freqs[f + 1].emplace_front(key); // up it to next level
        m[key] = {freqs[f + 1].begin(), f + 1, v}; // update map
        if (f == low && freqs[f].size() == 0)
            low++; // lowest moved up
        return v;
    }
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        return inc(key);
    }
    void add(int key, int value) {
        if (--n < 0) { // delete lowest freq
            m.erase(freqs[low].back());
            freqs[low].pop_back();
        } 
        freqs[1].emplace_front(key); 
        m[key] = {freqs[1].begin(), 1, value};
        low = 1; // new lowest 
    }
    void put(int key, int value) {
        if (init_cap == 0) return ;
        if (m.find(key) == m.end()) 
            add(key, value);
        else // update
            inc(key, value);
    }
};