#include <iostream>
#include "LamPhat.h"

using namespace std;

void nhap(double& gia_hai_nam_truoc, double& gia_nam_truoc, double& gia_hien_tai)
{
	cout << "Nhap gia cua mat hang hai nam truoc: ";
	cin >> gia_hai_nam_truoc;
	cout << "Nhap gia cua mat hang mot nam truoc: ";
	cin >> gia_nam_truoc;
	cout << "Nhap gia cua mat hang hien tai: ";
	cin >> gia_hien_tai;
}

double tinh_ty_le_lam_phat(double gia_nam_truoc, double gia_nam_do)
{
	return (gia_nam_do - gia_nam_truoc) / gia_nam_truoc;
}


bool la_lam_phat_tang(double ty_le_lam_phat_nam_truoc, double ty_le_lam_phat_nam_do)
{
	return ty_le_lam_phat_nam_do > ty_le_lam_phat_nam_truoc;
}

void xuat(double ty_le_lam_phat_nam_truoc, double ty_le_lam_phat_nam_nay)
{
	cout << "Ty le lam phat cua nam truoc: " << ty_le_lam_phat_nam_truoc << endl;
	cout << "Ty le lam phat cua nam nay: " << ty_le_lam_phat_nam_nay << endl;
	if (la_lam_phat_tang(ty_le_lam_phat_nam_truoc, ty_le_lam_phat_nam_nay))
	{
		cout << "Ty le lam phat nam nay tang so voi ty le lam phat nam truoc" << endl;
	}
	else
	{
		cout << "Ty le lam phat nam nay khong tang so voi ty le lam phat nam truoc" << endl;
	}
}
