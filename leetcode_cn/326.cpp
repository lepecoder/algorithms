class Solution {
public:
    bool isPowerOfThree(int n) {
		int x = 19;
		int res = 1;
		for (int i=0;i<=x;i++){
			if (n == res) return true;
			res *= 3;
		}
		return false;
    }
};
