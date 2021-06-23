class Solution {
public:
	int sort_(vector<int> &arr, int l, int r){
		// 对l，r之间的数做快速排序,返回锚点元素的最终位置
		// 左闭右
		if (l>=r) return l;
		int first = l, last = r, t = arr[first];
		while(first<last && arr[last]>t) --last;
		arr[first] = arr[last];
		while(first<last && arr[first]<=t) ++first;
		arr[last] = arr[first];
		arr[first] = t;
		return first+1;
	}
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
		/*对arr做快速排序，每次可以定位一个元素的最终位置*/
		int t;
		int n = arr.size();
		while(1){
			t = sort_(arr, 0, n-1);
			if (t==k){
				// 返回前k个
				return vector<int>(arr.begin(), arr.begin()+k);
			}else if(t<k){
				
			}

		}
    }
};
