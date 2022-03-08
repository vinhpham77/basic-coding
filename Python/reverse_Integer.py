def reverse_Integer(a):
    b = abs(a)
    s = 0
    while b > 0:
       s = s*10+b%10
       b = b//10
    if a < 0:
        return -s
    else:
        return s 

def main():
    a = int(input("Input an integer: "))
    print(reverse_Integer(a))

if __name__ == "__main__": 
    main()