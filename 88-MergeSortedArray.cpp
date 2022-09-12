class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> st;
        for (int i = 0;i<m;i++)
            st.insert(nums1[i]);
        for (auto i : nums2)
            st.insert(i);
        nums1 = {};
        for (auto i : st)
            nums1.push_back(i);
    }
};