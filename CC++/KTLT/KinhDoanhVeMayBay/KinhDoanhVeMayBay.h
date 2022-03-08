#pragma once
#include "ThongSo.h"
#include <fstream>

//void moTep(ofstream&);
void banVe(char[][SO_GHE]);
void chon(wchar_t& luaChon);
void chonLoaiVe(wchar_t&, bool&);
void hienThiMenu();
void hienThiSoDo(char[][SO_GHE]);
void huyVe(char[][SO_GHE]);
void khoiTaoChoNgoi(char[][SO_GHE]);
bool laChoNgoiTrong(char);
bool laThoat(wchar_t&);
void chonChoNgoi(wchar_t, wchar_t&, wchar_t&, bool&);
void thongBaoChonSai();
short thongKeLoaiVe(char[][SO_GHE], short, short);
void thongKeTatCa(char[][SO_GHE]);