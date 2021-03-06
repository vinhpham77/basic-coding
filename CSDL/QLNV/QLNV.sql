CREATE DATABASE QLNV
GO
USE QLNV
GO

CREATE TABLE PhongBan
(
	MaPB CHAR(10) CONSTRAINT PK_MaPB PRIMARY KEY NOT NULL,
	TenPB NVARCHAR(20)
)

CREATE TABLE NhanVien
(
	MaNV CHAR(5) CONSTRAINT PK_MaNV PRIMARY KEY NOT NULL,
	TenNV NVARCHAR(20),
	NgaySinh DATE,
	GioiTinh BIT,
	SoDT CHAR(10),
	MaPB CHAR(10) CONSTRAINT FK_MaPB FOREIGN KEY REFERENCES PhongBan(MaPB) ON UPDATE CASCADE ON DELETE CASCADE NOT NULL,
	Picture NVARCHAR(10)
)

INSERT PhongBan
VALUES('HC', N'Hành chính')
INSERT PhongBan
VALUES('KT', N'Kế toán')
INSERT PhongBan
VALUES('NS', N'Nhân sự')

INSERT NhanVien
VALUES('00001', N'Trần Cao Duyên', '02/12/2001', '0', '0398120202', 'KT' , NULL)
INSERT NhanVien
VALUES('00002', N'Phạm Ngọc Thái', '05/09/2003', '1', '0394312345', 'HC' , NULL)
INSERT NhanVien
VALUES('00003', N'Trần Thái Công', '06/30/2002', '1', '0292929292', 'NS' , NULL)
INSERT NhanVien
VALUES('00004', N'Nguyễn Yến Linh', '05/20/2002', '0', '0123823727', 'HC' , NULL);