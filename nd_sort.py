# %%
import numpy as np
x = np.random.randint(1, 33, (4, 3))
print(x)


idx = np.lexsort(x.T)
print(idx)
print(x[idx])
