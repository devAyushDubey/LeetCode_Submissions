
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
		unordered_map<long, long> map[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				long diff = (long)nums[i] - (long)nums[j];
				if (diff <= INT_MIN || diff >= INT_MAX) continue;
				long till_j = map[j][diff];
				res += till_j;
				map[i][diff] += (till_j + 1);
			}
		}
		return res;
    }
};