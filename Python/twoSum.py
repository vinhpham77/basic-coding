def twoSum(nums, target):
    n = len(nums)
    for i in range(n-1):
            for j in range(i+1, n):
                if nums[i] + nums[j] == target:
                   return [i, j]
    return None

def insertLs():
    n = int(input("How many elements do you want: "))
    nums = []
    for i in range(n):
        a = int(input(f"Insert element #{i}: "))
        nums.append(a)
    return nums

def main():
    nums = insertLs()
    target = int(input("Insert a number: "))
    print(twoSum(nums, target))

if __name__ == "__main__":
    main()