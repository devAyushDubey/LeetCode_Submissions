class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        if(n==0)
            return;
        for(int i=0;i<m;i++){
            if(nums2[0] < nums1[i]){
                int temp = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = temp;
                sort(nums2.begin(),nums2.end());
            }   
        }
        for(int i=m;i<nums1.size();i++)
            nums1[i] = nums2[i-m];
    }
};