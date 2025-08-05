size = int(input())
arr = list(map(int, input().split()))


pos_count = 0
neg_count = 0
zero_count = 0


for num in arr:
    if num > 0:
        pos_count += 1
    elif num == 0:
        zero_count += 1
    elif num < 0:
        neg_count += 1


p_ratio = pos_count / size
n_ratio = neg_count / size
z_ratio = zero_count / size


print(f"{p_ratio:.6f}")
print(f"{n_ratio:.6f}")
print(f"{z_ratio:.6f}")