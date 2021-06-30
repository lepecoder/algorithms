# %%
class C:
    def run(self):
        self.a = 1


# %%
c = C()
c.run()
c.a = 2
c.run()
print(c.a)

# %%
import numpy as np
p = np.array([3, 2, 0 * float('inf')])
try:
    action = np.random.choice(3, size=1, p=p / sum(p))
except:
    print(p)
    action = 4
print(action)
