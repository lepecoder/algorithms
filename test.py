import numpy as np


def sort4(li):
    for i in li:
        temp_l = []  # 储存li中小于i的值
        temp_g = []  # 储存li中大于等于i的值
        for j in li:
            if j < i:
                temp_l.append(j)
            else:
                temp_g.append(j)
        temp_l.extend(temp_g)  # 实现小于的左，大于的在右的一个列表拼接
        li = temp_l
    return li


for _ in range(10):
    li = np.random.randint(0, 80, 20)
    x = li.copy()
    ans = sort4(list(x))
    li.sort()
    print(ans)
    print(list(li))
    print("---")
