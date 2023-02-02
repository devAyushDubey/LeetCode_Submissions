class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o) {
        map<char,int>m;
       
        for(int i=0;i<o.size();i++) m[o[i]]=i;
         for(int i=0;i<w.size()-1;i++)
        { string a=w[i];
          string b=w[i+1];
          if(b.size()<a.size())
          {  int x=0;
            for(int j=0;j<b.size();j++)
            {
                if(m[a[j]]>m[b[j]]){return false; cout<<"#"; }
                else if(m[a[j]]==m[b[j]])x++;
                else break;

               if(x==b.size()) return false;
            }
           }
          else 
            for(int j=0;j<a.size();j++)
            {
               if(m[a[j]]>m[b[j]])return false; 
               else if(m[a[j]]==m[b[j]]) continue;
               else break;
            }
        }
        return true;
    }
};