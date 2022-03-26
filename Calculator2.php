<html>
<head>
	<meta charset="utf-8">
	<title>Máy tính</title>
	<?php 
		tinh() {
			$so1 = $_POST['txtSo1'];
			$so2 = $_POST['txtSo2'];
			$phepTinh = $_POST['phepTinh'];

			if (is_numeric($so1) && is_numeric($so2)) {
				switch (phepTinh) {
					case 'Cộng':
						$result = $so1 + $so2;
						break;
					case 'Trừ':
						$result = $so1 - $so2;
						break;
					default:
						// code...
						break;
				}
			}
		}		
	?>
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF']?>" method="POST" name="frmMayTinh">
		<table align="center" bgcolor="#CCCCCC">
			<tr>
				<td align="center" colspan=2 style="font-size:70px;color:blue">Máy tính</td>
			</tr>
			<tr>
				<td style="font-size:25px;color:blue">&nbsp;Số thứ nhất:&nbsp;&nbsp;</td>
				<td style="font-size:25px">
					<input type="text" name="txtSo1" id="txtSo1">
				</td>
			</tr>
			<tr>
				<td style="font-size:25px;color:blue">&nbsp;Số thứ hai:&nbsp;&nbsp;</td>
				<td style="font-size:25px">
					<input type="text" name="txtSo2" id="txtSo2">
				</td>
			</tr>
			<tr>
				<td align="center" colspan="2" style="font-size:15px;color: blue;">
					<input type="radio" name="phepTinh" id="rCong" value="Cộng"checked>Cộng
					<input type="radio" name="phepTinh" id="rTru" value="Trừ">Trừ
					<input type="radio" name="phepTinh" id="rNhan" value="Nhân" >Nhân
					<input type="radio" name="phepTinh" id="rChia" value="Chia">Chia
				</td>
			</tr>
			<tr>
				<td style="font-size:25px;color:blue">&nbsp;Kết quả:</td>
				<td style="font-size:25px">
					<input type="text" name="txtKQ" id="txtKQ" value="">
				</td>
			</tr>
			<tr><td align="right" colspan="2"><button type="submit" style="color: blue;" name="btnTinh">Tính</button></td></tr>
		</table>	
	</form>
</body>
</html>