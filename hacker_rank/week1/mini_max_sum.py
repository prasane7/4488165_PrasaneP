nums = list(map(int, input().split()))

total_sum = sum(nums)

excluded_sums = []

for number in nums:
    excluded_sums.append(total_sum - number)

lowest_sum = min(excluded_sums)

highest_sum = max(excluded_sums)

print(lowest_sum, highest_sum)