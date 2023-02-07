class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = fruits.size(),i,start=0,end=1,pos=0,maxi=0,dis;
        if(len<=2) return len;
        vector<pair<int,int>> v;
        v.push_back({fruits[i],0});
        v.push_back({-1,0});
        for(i=1; i<len; i++){
            if(v[0].first == fruits[i]){
                v[0].second = i;
            }else if(v[1].first == fruits[i]){
                v[1].second = i;
            }else if(v[1].first == -1){
                v[1].first = fruits[i];
                v[1].second = i;
            }else{
                dis = end - start;
                maxi = max(maxi,dis);
                if(fruits[i-1] == v[0].first) pos = 1;
                else pos = 0;
                start = v[pos].second+1;
                v[pos].first = fruits[i];
                v[pos].second = i;
            }
            end++;
        }
        dis = end - start;
        maxi = max(maxi,dis);
        return maxi;
    }
};