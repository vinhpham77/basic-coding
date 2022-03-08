def isPalindrome(a):
    if a >= 0:
            b = a
            s = 0
            while b > 0:
                s = s*10+b%10
                b = b//10
            return s == a
    return False

def main():
    a = int(input("Input an integer: "))
    if isPalindrome(a):
        print("This is a Palindrome")
    else:
        print("This is not a Palindrome")

if __name__ == "__main__":
    main()