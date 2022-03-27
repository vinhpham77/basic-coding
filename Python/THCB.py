import pandas as pd
import matplotlib.pyplot as plt

ngay = ['1/3', '2/3', '3/3', '4/3', '5/3', '6/3', '7/3']
giaBan = [46, 47, 46, 45, 46, 46, 45]
giaMua = [45, 46, 45.5, 44.5, 45, 45.5, 44.5]

location = 'giavang.csv'
duLieu = zip(ngay, giaBan, giaMua)
cot = ['Ngày', 'Giá vàng bán ra', 'Giá vàng mua vào']

df = pd.DataFrame(data = duLieu, columns = cot)

df.to_csv(location)

df = pd.read_csv(location)

plt.plot(df['Ngày'], df['Giá vàng mua vào'])
plt.xlabel('Ngày')
plt.ylabel('Giá vàng mua vào')

plt.show()
