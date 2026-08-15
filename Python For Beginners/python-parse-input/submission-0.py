from typing import List

def read_integers() -> List[int]:
    srr=input().split(',')
    arr :list(int)=[]
    for i in srr :
        arr.append(int(i))
    return arr

# do not modify the code below
print(read_integers())
print(read_integers())
print(read_integers())
