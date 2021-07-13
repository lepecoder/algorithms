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
a = np.array([1, 2, 3])
print(a)
a = np.r_[a, a[-1]]
print(a)
