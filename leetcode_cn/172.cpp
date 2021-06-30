class Solution {
public:
    int trailingZeroes(int n) {
		int res = 0;
		cur_mul = 5;
		while (n>= cur_mul){
			res += n/cur_mul;
			cur_mul*=5;
		}
		return res;
    }
};
