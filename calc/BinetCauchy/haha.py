import numpy as np 
B = np.array([[1, -1, 1, 0, 0, 1],
              [0, 0, -1, -1, 0, -1],
              [-1, 1, 0, 0, 1, 0]])

bt = np.transpose(B)
a = np.matmul(B, bt)
haha = np.linalg.det(a)
print(haha)