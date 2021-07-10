class Solution {
public:
    string countOfAtoms(string formula) {
		map<string,int> mp;
		string atom = "";
		int count = 1;
		for (char &c:formula){
			if (c >= 'A' && c<='Z'){
				if (atom != ""){
					mp[atom]+=count;
					atom.clear();
					count=1;
				}
			}
		}

    }
};
