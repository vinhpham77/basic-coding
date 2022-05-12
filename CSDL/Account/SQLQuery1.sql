CREATE DATABASE Account
GO
USE Account
GO

CREATE TABLE Account
(
	Username VARCHAR(20)  CONSTRAINT PK_Username PRIMARY KEY NOT NULL,
	Password VARCHAR(10) NOT NULL
)

INSERT Account VALUES
	('data1', '01234'),
	('data2', '01234'),
	('data3', '01234'),
	('data4', '01234'),
	('data5', '01234'),
	('macdinh', '0123')

