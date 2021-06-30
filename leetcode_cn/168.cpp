class Solution {
public:
    string convertToTitle(int columnNumber) {
		string res = "";
		int k = columnNumber;
		do{
			--k;
			int mod = k%26;
			res += 'A'+mod;
			k/=26;
		}while(k)
		reverse(res.begin(),res.end());
		return res;
    }
};
