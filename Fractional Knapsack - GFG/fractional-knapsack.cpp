//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool comp(Item& a, Item& b) {
        return ((b.value/(double)b.weight) > (a.value/(double)a.weight));
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<Item> vec;
        double prof = 0;
        
        for(int i=0;i<n;i++) vec.push_back(arr[i]);
        
        sort(vec.begin(),vec.end(),comp);
        
        while(W && vec.size()){
            
            if(W >= vec.back().weight){
                W -= vec.back().weight;
                prof+= vec.back().value;
                vec.pop_back();
            }
            else{
                prof += ((W/(double)vec.back().weight)*vec.back().value);
                W = 0;
            }
            
        }
        
        return prof;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends