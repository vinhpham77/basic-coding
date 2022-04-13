CREATE DATABASE QLNS
USE QLNS
GO

CREATE TABLE DSNV
(
	MaNV		CHAR(5)			CONSTRAINT PK_maNV	PRIMARY KEY		NOT NULL,
	HoTen		NVARCHAR(30)										NOT NULL,
	MaPhong		CHAR(5)			CONSTRAINT FK_MaPhong FOREIGN KEY	
								REFERENCES DMPhong(MaPhong) ON
								DELETE CASCADE ON UPDATE CASCADE	NULL,
	HeSoLuong	FLOAT												NULL,
	MaChucVu	CHAR(5)			CONSTRAINT FK_MaChucVu FOREIGN KEY
								REFERENCES CHUCVU(MaChucVu) ON
								DELETE CASCADE ON UPDATE CASCADE	NULL
)

CREATE TABLE CHUCVU
(
	MaChucVu	CHAR(5)			CONSTRAINT PK_MaChucVu PRIMARY KEY	NOT NULL,
	TenChucVu	NVARCHAR(30)										NOT NULL,
	PhuCapCV	FLOAT												NULL
)

CREATE TABLE DMPHONG
(
	MaPhong		CHAR(5)			CONSTRAINT PK_MaPhong PRIMARY KEY	NOT NULL,
	TenPhong	NVARCHAR(30)										NOT NULL
)