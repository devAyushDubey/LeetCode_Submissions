//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    {
        vector<pair<int,int>> vec;
        
        for(int i=0;i<N;i++)
            vec.push_back(make_pair(A[i],i));
            
        sort(vec.begin(),vec.end());
        
        
        vector<int> maxs;
        int mx = 0;
        for(int i=N-1;i>=0;i--){
            mx = max(mx,vec[i].second);
            maxs.push_back(mx);
        }
        reverse(maxs.begin(),maxs.end());
        
        int ans=0;
        for(int i=0;i<N;i++)
            ans = max(maxs[i]-vec[i].second,ans);
            
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends