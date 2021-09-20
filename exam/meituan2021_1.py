def mt(n, x, y, arr):
    if (2 * x) > n or (2 * y) < n:
        return -1
    arr.sort()
    # 要求最低分数线，也就是淘汰的最少，晋级的最多，
    # 我们可以让晋级是上线，即有y人晋级
    # 那么淘汰的就是n-y,那么分数线就是第n-y个选手的分数
    idx = max(n - y - 1, x - 1)
    return arr[idx]


n, x, y = map(int, input().split(' '))
arr = list(map(int, input().split(' ')))
ans = mt(n, x, y, arr)
print(ans)
