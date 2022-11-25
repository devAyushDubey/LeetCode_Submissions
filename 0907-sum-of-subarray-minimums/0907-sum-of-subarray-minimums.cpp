class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        long long int ans = 0;
        //Left Smaller Element(at -1 if NOT exists) & Right Smaller Element(at n , if NOT exists)
        vector<int> lSe(n,-1),rSe(n,n);
        stack<int> s1,s2;

        for(int i=0;i<n;i++){
            //Put Equal either Here OR down
            while(!s1.empty() && arr[s1.top()] >= arr[i]){
                s1.pop();   
            }
            if(!s1.empty()){
                lSe[i] = s1.top();
            }
            s1.push(i);
        
        }

         for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()] > arr[i]){
                s2.pop();
            }
            if(!s2.empty()){
                rSe[i] = s2.top();
            }

            s2.push(i);
        }

        for(int i=0;i<n;i++){
            //Left Length arr[i] will be Max For
            int leftL = i - lSe[i];

            // Right Length arr[i] will be Max For
            int rightL = rSe[i] - i;

            ans = (ans + (((1LL*arr[i])*leftL)*(rightL))%mod)%mod;
        }

        return ans;

    }
};