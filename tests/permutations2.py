from itertools import permutations
import random

num_permutations = 100  # Number of random permutations to generate
first_num = -5000  # Specify the first integer
last_num = 5000  # Specify the last integer

nums = list(range(first_num, last_num + 1))

all_permutations = list(permutations(nums, len(nums)))
random.shuffle(all_permutations)

for i in range(num_permutations):
    print(*all_permutations[i])