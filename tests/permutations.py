from itertools import permutations
import random

num_permutations = 10000  # Number of random permutations to generate
num_integers = 100  # Number of integers in each iteration
first_num = 0  # Specify the first integer
last_num = 1000  # Specify the last integer

nums = list(range(first_num, last_num + 1))
permutation_size = min(len(nums), num_integers)

for _ in range(num_permutations):
    random_permutation = random.sample(nums, permutation_size)
    print(*random_permutation)
