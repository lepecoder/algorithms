class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		queue<string> q;  // bfs的队列
		unordered_set<string> st;  // 记录已经走过的节点
        string start = "0000";
		// st.emplace(start);
		for(string &s:deadends){
			st.emplace(s);
		}
        if (st.count(start)==0){
		    q.emplace(start);
        }
		int res = 0;
        // cout << q.size();
		while(!q.empty()){
			int n = q.size();
			while(n--){
				string t_str = q.front();
                // cout << t_str << ' ';
				q.pop();
				if (t_str == target) return res;
				// add adjcent nodes into queue
				for(int i=0;i<4;i++){
					string s1 = t_str;
					if (s1[i] == '9'){ // plus
						s1[i] = '0';
					}else{
						++s1[i];
					}
					if (st.count(s1)==0){
						st.emplace(s1);
						q.emplace(s1);
					}
					string s2 = t_str;
					if (s2[i] == '0'){
						s2[i] = '9';
					}else{
						--s2[i];
					}
					if (st.count(s2)==0){
						st.emplace(s2);
						q.emplace(s2);
					}
				}
			}
			++res;
		}
		return -1;
    }
};
