#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回指定的点所在的多边形序号。
     * @param points int整型vector<vector<>> 2维平面的候选点坐标。
     * @param polygens int整型vector<vector<>> 多边形顶点坐标索引。
     * @param positions int整型vector<vector<>> 需要计算的指定点坐标。
     * @return int整型vector
     */
    bool inOrOut(int nvert, int *x, int *y, int px, int py) {
        int i, j, cross = 0;
        for (i = 0, j = nvert - 1; i < nvert; j = i++) {
            if (((x[i] > px) != (x[j] > px)) && (px > (x[j] - x[i]) * (py - y[i]) / (y[j] - y[i]) + x[i])) cross++;
        }
        return cross % 2 != 0;
    }
    vector<int> PointInPolygen(vector<vector<int>> &points, vector<vector<int>> &polygens, vector<vector<int>> &positions) {
        // write code here
        int n = positions.size();
        vector<int> res(n, -1);
        for (int i = 0; i < polygens.size(); i++) {
            auto v = polygens[i];
            int nvert = v[2] - v[1];
            int x[nvert];
            int y[nvert];
            for (int j = v[1]; j < v[2]; j++) {
                x[j - v[1]] = points[j][0];
                y[j - v[1]] = points[j][1];
            }
            for (vector<int> &v2 : positions) {
                if (inOrOut(nvert, x, y, v2[0], v2[1])) {
                    res[i] = v[0];
                    break;
                }
            }
        }
        return res;
    }
};
int main() {
    //
    return 0;
}