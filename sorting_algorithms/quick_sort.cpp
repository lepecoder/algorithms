/*
快速排序
通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，分别对这两部分记录继续进行排序，以达到整个序列有序。
非稳定排序，
最坏时间复杂度O(n^2)但很少，平均O(nlogn)

① 从数列中挑出一个元素，称为 “基准”（pivot），
②
重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的正确位置。这个称为分区（partition）操作。
③ 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
*/

#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector<int> &, int, int);

int main(int argc, char const *argv[]) {
  vector<int> v = {2, 1, 5, 6, 3, 7, 4, 9, 8, 0};
  quick_sort(v, 0, 9);
  for (int i = 0; i < 10; i++)
    cout << v[i] << ' ';
  cout << endl;
  return 0;
}

void quick_sort(vector<int> &nums, int l, int r) {
  if (l + 1 >= r)
    return;
  int first = l, last = r, key = nums[first];
  while (first < last) { // 利用双指针交替交换元素
    while (first < last && nums[last] >= key)
      --last;                 // 从后向前找到第一个小于key的元素
    nums[first] = nums[last]; // 此时nums[first]并不会丢失，因为被key记录
    while (first < last && nums[first] <= key)
      ++first;
    nums[last] = nums[first]; // 此时last也不会丢失，因为在上一步已经记录
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
  }
}
