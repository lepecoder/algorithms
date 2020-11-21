# %%
import numpy as np

OldChrom = np.array([[0.1, 0.2, 0.3, 0.4, 0.5, 0.6], [0.3, 0.2, 0.5, 0.6, 0.1, 0.8]])
print(OldChrom[1][0])

# %%
np.random.seed(1)
print(np.random.rand(1))
print(np.random.rand(1))
