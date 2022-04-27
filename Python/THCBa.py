a = int(input("Nhap vao so tien can gui ngan hang: "))
b = float(input("Nhap vao lai suat hang thang cua ngan hang: "))
m = int(input("Nhap vao so thang gui tiet kiem: "))

tien = a
for i in range(m):
    tien += tien*b

print("So tien nhan duoc sau", m, "la:", tien)