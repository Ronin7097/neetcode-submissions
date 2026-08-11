from typing import List # this is used to add type hints for List type

def get_sum(nums: List[int]) -> int:
    total=0
    for i,e in enumerate(nums):
        total+=e
    return total

def get_min(nums: List[int]) -> int:
    minm=float('inf')
    for i,e in enumerate(nums):
        minm=min(e,minm)
    return minm

def get_max(nums: List[int]) -> int:
    maxm=float('-inf')
    for i,e in enumerate(nums):
        maxm=max(e,maxm)
    return maxm

# do not modify below this line
print(get_sum([1, 2, 3, 4, 5]))
print(get_sum([5, 4, 5, 6]))

print(get_min([7, 3, 4, 5]))
print(get_min([5, 4, 5, 6]))

print(get_max([7, 3, 4, 5]))
print(get_max([5, 4, 5, 6]))
