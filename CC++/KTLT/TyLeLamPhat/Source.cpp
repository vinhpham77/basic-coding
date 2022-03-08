#include <iostream>
#include "LamPhat.h"

using namespace std;

int main()
{
	double gia_hai_nam_truoc;
	double gia_nam_truoc;
	double gia_hien_tai;
	double ty_le_lam_phat_nam_truoc;
	double ty_le_lam_phat_nam_nay;

	nhap(gia_hai_nam_truoc, gia_nam_truoc, gia_hien_tai);
	ty_le_lam_phat_nam_truoc = tinh_ty_le_lam_phat(gia_hai_nam_truoc, gia_nam_truoc);
	ty_le_lam_phat_nam_nay = tinh_ty_le_lam_phat(gia_nam_truoc, gia_hien_tai);
	xuat(ty_le_lam_phat_nam_truoc, ty_le_lam_phat_nam_nay);

	system("pause");
	return 0;
}