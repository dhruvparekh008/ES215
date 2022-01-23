

import random
import timeit


num = 512
p = [[0]*num]*num
for i in range(num):
    for j in range(num):
        p[i][j] = random.uniform(1,100)

q = [[0]*num]*num
for i in range(num):
    for j in range(num):
        q[i][j] = random.uniform(1,100)

r = [[0]*num]*num

starttime = timeit.default_timer()
for i in range(num):
    for j in range(num):
        for k in range(num):
            r[i][j] = p[i][k]*q[k][j]
stoptime = timeit.default_timer()

for i in range(num):
    print()
    for j in range(num):
        print(r[i][j] , end = " ")
print()
print('Total Time: ', stoptime - starttime)
