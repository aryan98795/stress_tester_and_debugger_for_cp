import random

t = 1
print(t)

n = 10
m = 10
print(n, m)

# Generate n integers in range [1, 10] for a small test
arr = [random.randint(1, 15) for _ in range(n)]
print(' '.join(map(str, arr)))
