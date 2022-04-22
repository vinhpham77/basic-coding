﻿CREATE DATABASE QLNV
USE QLNV
GO

CREATE TABLE NhanVien
(
	MaNV CHAR(5) CONSTRAINT PK_MaNV PRIMARY KEY NOT NULL,
	TenNV NVARCHAR(30),
	NgaySinh DATE,
	GioiTinh BIT,
	SoDT CHAR(10),
	MaPB CHAR(5) CONSTRAINT FK_MaPB FOREIGN KEY REFERENCES PhongBan(MaPB) ON DELETE CASCADE ON UPDATE CASCADE NOT NULL,
	Picture VARCHAR(100)
)

CREATE TABLE PhongBan
(
	MaPB CHAR(5) CONSTRAINT PK_MaPB PRIMARY KEY NOT NULL,
	TenPB NVARCHAR(40)
)

INSERT NhanVien VALUES
	('NV001', N'Đỗ Giang', '12/12/2002', '1', '0398120321', 'HC', NULL),
	('NV002', N'Đỗ Xuyên', '02/22/2002', '1', '0398120221', 'NS', NULL),
	('NV003', N'Lỗ Tấn', '06/23/2002', '1', '0398120321', 'KT', NULL)

INSERT PhongBan VALUES
	('HC', N'Hành chính'),
	('NS', N'Nhân sự'),
	('KT', N'Kế toán')