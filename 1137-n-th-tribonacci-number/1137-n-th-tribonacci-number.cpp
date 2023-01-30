class Solution {
public:
    int tribonacci(int n) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(1);
        
        for(int i=3;i<=n;i++)
            vec.push_back(vec[i-1] + vec[i-2] + vec[i-3]);
        
        return vec[n];
    }
};