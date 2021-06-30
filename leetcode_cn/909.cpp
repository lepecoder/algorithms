class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
		int n = board.size();
		int vis[n*n+1];
		memset(vis,0,sizeof(vis));
		queue<pair<int,int>> q;  // 位置，移动次数
		q.emplace(1,0);
		while(!q.empty()){
			auto p = q.front();
			q.pop();
			for(int i=1;i<=6;i++){
				int nxt =  p.first+i;
				if (nxt >n*n){
					break;
				}
				auto  rc = 
			}
		}
    }
};
