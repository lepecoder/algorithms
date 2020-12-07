class Solution:
    def countPrimes(self, n: int) -> int:
        """
        筛素数法
        众所周知,素数的倍数一定不是素数,我们可以用一个布尔数组保存信息,
        一开始假设所有数都是素数,从第一个素数2开始,将它的倍数标记为false,
        然后找到下一个素数3,将它的倍数也标记为false,之后继续找素数并筛去它的倍数
        """
        if n < 2:
            return 0
        res = [1]*n
        for i in range(2, int(n**0.5)+1):
            if res[i]:
                # res[i*i:n:i] = [0]*((n-1-i*i)//i+1)
                for j in range(i*i, n, i):
                    res[j] = 0
        return sum(res) - 2
