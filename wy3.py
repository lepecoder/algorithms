maxn = 64
res = 100


def dfs(k, idx, sum_, step, path):
    if k <= 0:
        return
    if idx > maxn:
        return
    if sum_ == k:
        global res
        if res > step:
            res = min(res, step)
            # print(path)
    if sum_ > k:
        return
    t = 2**idx
    dfs(k, idx + 1, sum_ + t, step + 1, path + [t])
    dfs(k, idx + 1, sum_, step, path)


if __name__ == '__main__':
    s = int(input())
    dfs(s, 0, 0, 0, [])
    ans = res
    for x in range(10):
        t = 2**x
        dfs(t - s, 0, 0, 0, [])
    ans = min(ans, res + 1)
    if ans > maxn:
        print(-1)
    else:
        print(ans)
