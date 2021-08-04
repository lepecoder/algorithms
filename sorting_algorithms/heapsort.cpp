/** 堆排序
 * 大顶堆：节点的值大于等于其子节点的值，升序排序
 * 小顶堆：节点的值小于等于其子节点的值，降序排序
 * 算法步骤：
 * 1. 创建一个堆
 * 2. 把堆首和堆尾互换
 * 3. 断开堆尾连接，堆的尺寸-1
 * 4. 重复上述步骤，直到堆的尺寸=1
 */

#include <bits/stdc++.h>
using namespace std;
/** 代码实现
 * 由于是完全二叉树，所以不需要真的建立树结构，我们可以直接
 * 计算父节点的左右子节点下标。
 * 由完全二叉树的性质，叶子节点数等于floor(n/2)，由此
 * 在调整二叉树时我们可以找到最后一个不是叶子节点的节点开始
 * 调整。
 */
void adjust(vector<int> &nums, int len, int idx) {
    /** 调整第idx个节点，使它的左右子节点都比他小
     * 由于可能导致节点互换，因此这是一个递归的调整
     */
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int maxid = idx;
    if (l < len && nums[l] > nums[maxid]) maxid = l;
    if (r < len && nums[r] > nums[maxid]) maxid = r;
    if (maxid != idx) {
        swap(nums[idx], nums[maxid]);
        adjust(nums, len, maxid);
    }
}

void heap_sort(vector<int> &nums) {
    int n = nums.size();
    /** 只要我们找到下标的对应关系，就可以
     * 假定一个数组是一棵完全二叉树
     *        x
     *      /  \
     *  2*x+1  2*x+2
     */
    for (int i = n / 2 - 1; i >= 0; i--) {
        // 从最后一个非叶子节点向上调整
        adjust(nums, n, i);
    }
    // 取出堆中最大的节点，和最后一个节点互换，之后继续
    // 调整堆，使保持大顶堆的性质
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        adjust(nums, i, 0);
    }
}

int main() {
    vector<int> v{8, 1, 14, 3, 21, 5, 7, 10};
    heap_sort(v);
    for (int &x : v) { cout << x << ' '; }
    cout << endl;
    return 0;
}