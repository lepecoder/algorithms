class Solution {
public:
    int add(int a, int b) {
		if (b==0) return a;
		int n = a^b;
		int c = (unsigned int)(a&b)<<1;
		return add(n,c);
    }
};
