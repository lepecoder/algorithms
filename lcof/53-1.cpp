class Solution {
public:
    int search(vector<int>& nums, int target) {
		int n = nums.size();
		int l=0, r=n;  // 左闭右开
		while(l<r){  // 等于target的最左元素
			int m = l+(r-l)/2;
			if (nums[m] >= target){
				r=m;
			}else{
				l=m+1;
			}
		}
		if (l==n || nums[l]!=target) return 0;
		int l_bound = l;
		l=0,r=n;
		while(l<r){
			int m = l+(r-l)/2;
			if (nums[m] <= target){
				l=m+1;
			}else{
				r=m;
			}
		}
		return l-l_bound;
    }
};
