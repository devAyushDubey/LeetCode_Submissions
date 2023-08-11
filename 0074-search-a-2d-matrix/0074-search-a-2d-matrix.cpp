class Solution {
public:
    
    int bin_search(int left, int right, vector<int> vec, int target){
        if (left<=right){
            int mid = left + (right - left)/2;
            //cout<<vec[mid]<<endl;
            if(target > vec[mid])
                return bin_search(mid+1,right,vec,target);
            else if(target < vec[mid])
                return bin_search(left,mid-1,vec,target);
            else
                return mid;
        }
        return -1;
    }
    
    int binarySearch2D(int left, int right, vector<vector<int>>& vec, int target){
        
        int n = vec[0].size();
        
        if (left<=right){
            int mid = left + (right - left)/2;
            //cout<<vec[mid]<<endl;
            if(target > vec[mid][0] && target > vec[mid][n-1])
                return binarySearch2D(mid+1,right,vec,target);
            else if(target < vec[mid][0])
                return binarySearch2D(left,mid-1,vec,target);
            else
                return bin_search(0,n,vec[mid],target);
        }
        return -1;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        
        int ans = binarySearch2D(0,m-1,matrix,target);
        
        if(ans==-1)
            return false;
        return true;
    }
};