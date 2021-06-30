class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> st;
		for(int i=0;i<=k;i++){
			if (st.count(nums[i])){
				return true;
			}else{
				st.emplace(nums[i]);
			}
		}
		++k;
		int n = nums.size();
		for(int i=0; i+k<n; i++){
			st.erase(nums[i]);
			if (st.count(nums[i+k])){
				return true;
			}else{
				st.emplace(nums[i+k]);
			}
		}
		return  false;
    }
};
