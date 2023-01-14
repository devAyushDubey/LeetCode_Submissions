class Solution {
public:
  int find(int x , vector<int> & parents)
  {
     return parents[x] == x ? x : find(parents[x],parents);
  }
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<int> parents(26);

        for(int i = 0 ; i < 26 ; i++)
        parents[i] = i ;

        for(int i = 0 ; i < s1.length() ; i++)
        {
            int x = find(s1[i] -'a',parents);
            int y = find(s2[i] -'a',parents);

            if(x != y)
            parents[max(x,y)] = min(x,y);
        }

        for(int i = 0 ; i < baseStr.length();i++)
        baseStr[i] = find(baseStr[i] -'a' , parents) + 'a';
        
        return baseStr ;
    }
};