class Solution {
public:
    string addStrings(string num1, string num2) {
		int i = num1.length()-1;
		int j = num2.length()-1;
		int add = 0;
		string res = "";
		while(i>=0 || j>=0 || add){
			int x = i>=0?num1[i]-'0':0;
			int y = j>=0?num2[j]-'0':0;
			int result = x+y+add;
			res.emplace_back('0'+result%10);
			add = result/10;
			--i;
			--j;
		}
		reverse(res.begin(),res.end());
		return res;
    }
};
