import string
import random

def random_password(n):
    digits = string.digits
    letters = string.ascii_letters
    password = list(digits + letters)
    random.shuffle(password)
    password = random.choices(password, k = int(n))
    password = ''.join(password)
    print("Your password is: ", password)

def main():
    n = input("How many characters do you want for your password: ")
    random_password(n)

if __name__ == "__main__":
    main()
