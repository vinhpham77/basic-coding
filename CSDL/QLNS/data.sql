USE QLNS
GO

INSERT DMPHONG VALUES
	('KT', N'Kế toán'),
	('HC', N'Hành chính'),
	('NS', N'Nhân sự')
	
INSERT CHUCVU VALUES
	('NVHD', N'Nhân viên hợp đồng', '200000'),
	('NVDH', N'Nhân viên dài hạn', '300000'),
	('TP', N'Trưởng phòng', '1000000')

INSERT DSNV VALUES
	('KT001', N'Nguyễn Văn A', 'KT', '1.4', 'NVHD'),
	('KT002', N'Nguyễn Thị Loan', 'KT', '1.6', 'NVDH'),
	('KT003', N'Nguyễn Hoàng', 'KT', '2.5', 'TP'),
	('HC001', N'Nguyễn Hoa', 'HC', '1.5', 'NVDH'),
	('HC002', N'Phạm Toàn', 'HC', '2.5', 'TP'),
	('NS001', N'Ngô Tất Tố', 'NS', '2.9', 'NVDH'),
	('NS002', N'Đào Mận', 'NS', '1.8', 'TP')
