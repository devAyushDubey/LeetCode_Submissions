//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    vector<string> ans;
	
	    void printPermutations(string str, string asf){
    
            int n = str.length();
            
            if(n == 0){
                ans.push_back(asf);
                return;
            }
            
            unordered_map<char,bool> exists;
            
            for(int i=0;i<n;i++){
                if(!exists[str[i]]){
                    printPermutations(str.substr(0,i) + str.substr(i<n-1?i+1:i,n-i-1),asf+str[i]);
                    exists[str[i]] = true;
                }
            }
    
        }
	
		vector<string> find_permutation(string S){
		    printPermutations(S,"");
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends