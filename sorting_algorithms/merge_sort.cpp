#include <cstring>
#include <iostream>
using namespace std;

/*
采用分治法，速度仅次于快速排序，是稳定排序算法，适用于总体无序，各子项相对有序的数列

基本思想
分解(Divide)： 将一个序列分解成两个子序列
解决(Conquer): 对两个子序列递归的排序
合并(Combine): 合并两个有序的子序列
平均时间复杂度 O(nlogn)：临时数组和栈
空间复杂度 O(n)
out-place
*/

template <typename T> void merge_sort_recursion(T arr[], T reg[], int s, int e);
template <typename T> void merge_sort_iteration(T arr[], int len);
template <typename T> void merge_sort(T arr[], const int len);

int main(int argc, char const *argv[]) {
  // int arr[] = {2, 1, 5, 6, 3, 7, 4, 9, 8, 0};
  // merge_sort(arr, 10);
  // for (int i = 0; i < 10; i++) {
  //   cout << arr[i] << ' ';
  // }
  // cout << endl;
  int arr1[] = {2, 1, 5, 6, 3, 7, 4, 9, 8, 0};
  merge_sort_iteration(arr1, 10);
  for (int i = 0; i < 10; i++) {
    cout << arr1[i] << ' ';
  }
  return 0;
}
template <typename T> void merge_sort(T arr[], const int len) {
  T reg[len];
  merge_sort_recursion(arr, reg, 0, len - 1);
}

template <typename T>
void merge_sort_recursion(T arr[], T reg[], int start, int end) {
  // 递归版，自顶向下的方法。
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  int s1 = start, e1 = mid;
  int s2 = mid + 1, e2 = end;
  merge_sort_recursion(arr, reg, s1, e1);
  merge_sort_recursion(arr, reg, s2, e2);
  int k = start;
  while (s1 <= e1 && s2 <= e2) {
    reg[k++] = arr[s1] < arr[s2] ? arr[s1++] : arr[s2++];
  }
  while (s1 <= e1) {
    reg[k++] = arr[s1++];
  }
  while (s2 <= e2) {
    reg[k++] = arr[s2++];
  }
  for (k = start; k <= end; k++) {
    arr[k] = reg[k];
  }
}

template <typename T> void merge_sort_iteration(T arr[], int len) {
  // 迭代版，
  // 将相邻两个数字归并排序，形成n/2个子序列
  // 将子序列归并，形成n/4个子序列
  // 重复步骤，直到所有元素排序完毕
  // T *a = arr;
  T *b = new T[len];
  for (int seg = 1; seg < len; seg += seg) { // 长度为seg的子序列
    for (int start = 0; start < len; start += 2 * seg) {
      int low = start, mid = min(start + seg, len),
          high = min(start + seg + seg, len); // 不包含右边界
      int k = low;
      int s1 = low, e1 = mid;
      int s2 = mid, e2 = high;
      while (s1 < e1 && s2 < e2) {
        b[k++] = arr[s1] < arr[s2] ? arr[s1++] : arr[s2++];
      }
      while (s1 < e1) {
        b[k++] = arr[s1++];
      }
      while (s2 < e2) {
        b[k++] = arr[s2++];
      }
    }
    memcpy(arr, b, sizeof(T) * len); // 把一轮排序后的b赋值给arr
  }
  delete b;
}
