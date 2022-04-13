USE QLNS
GO

INSERT DMPHONG VALUES
	('KD', N'Kinh doanh'),
	('KT', N'Kế toán'),
	('HC', N'Hành chính'),
	('NS', N'Nhân sự')
	
INSERT CHUCVU VALUES
	('NVKT', N'Nhân viên kế toán', '400000'),
	('NVKD', N'Nhân viên kinh doanh', '445000'),
	('NVHC', N'Nhân viên hành chính', '415000'),
	('TPHC', N'Trưởng phòng hành chính', '1000000'),
	('TPNS', N'Trưởng phòng nhân sự', '1150000'),
	('TPKD', N'Trưởng phòng kinh doanh', '1550000'),
	('TPKT', N'Trưởng phòng kế toán', '1250000')

INSERT DSNV VALUES
	('KD001', N'Nguyễn Văn A', 'KD', '1.4', 'NVKD'),
	('KD002', N'Nguyễn Thị Loan', 'KD', '1.6', 'NVKD'),
	('KD003', N'Nguyễn Hoàng', 'KD', '2.5', 'TPKD'),
	('TC001', N'Nguyễn Hoa', 'HC', '1.5', 'NVHC'),
	('TC002', N'Phạm Toàn', 'HC', '2.5', 'TPHC'),
	('NS001', N'Ngô Tất Tố', 'NS', '2.9', 'TPNS'),
	('KT001', N'Đào Mận', 'KT', '1.8', 'NVKT')
