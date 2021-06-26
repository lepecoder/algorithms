class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		int n = candiesCount.size();
		long long int dp[n+1];
		dp[0]=0;
		for (int i=0;i<n;i++){
			dp[i+1] = dp[i]+candiesCount[i];
		}
		vector<bool> res;
		res.reserve(queries.size());
		for (vector<int> & query:queries){
			int low_bound = query[1];
			long long high_bound = (query[1]+1ll)*query[2];
            if (dp[query[0]+1] > low_bound && dp[query[0]] < high_bound){
				res.emplace_back(true);
			}else{
				res.emplace_back(false);
            }
		}
		return res;
    }
};
