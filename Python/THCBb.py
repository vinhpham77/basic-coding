import pandas as pd

MaNV = ['3', '5', '1', '6', '9']
Ho = ['Võ Phương Linh', 'Nguyễn Đặng Khánh', 'Nguyễn Thị Na', 'Lê Thị Thanh', 'Nguyễn Như']
Ten = ['Phươn', 'Mai', 'Nu', 'Quý', 'Quỳnh']
Ngaysinh = ['1/7/2000', '3/8/2000', '5/2/2001', '6/3/2003', '5/6/2000']
Doanhso = ['1200', '1000', '2500', '1800', '700']

location = 'DSNV.csv'
duLieu = zip(MaNV, Ho, Ten, Ngaysinh, Doanhso)
cot = ['MaNV', 'Ho', 'Ten', 'Ngaysinh', 'Doanhso']

df = pd.DataFrame(data = duLieu, columns = cot)

df.to_csv(location)

df = pd.read_csv(location)

# avg = 0
# for i in df['Doanhso']:
#     avg += 

# plt.show()