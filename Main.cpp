#include <iostream>
#include "SinhVien.h"
#include "ChuongTrinh.h"
#include "Khoa.h"
#include "KhoaHoc.h"
#include "MonHoc.h"
#include "LopHoc.h"
#include "KetQua.h"
#include "GiangDay.h"
#include "ThongKe.h"
#include "mylib.h"
#include <stdlib.h>
#include <map>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define TXT_CLR 31
#pragma once

using namespace std;



void MenuDSSV(DSSV &dssv, DSLH &dslh)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU SINH VIEN ===========";
		cout << "\n1. Them 1 sinh vien";
		cout << "\n2. Xuat thong tin sinh vien";
		cout << "\n3. Tim sinh vien theo ma";
		cout << "\n4. Tim sinh vien theo ten";
		cout << "\n5. Xoa sinh vien theo ma";
		cout << "\n6. Cap nhat thong tin sinh vien";
		cout << "\n7. Sap xep theo ho ten sinh vien";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			//NhapNhieuSV(dssv);
			Nhap1SVVaoDS(dssv, dslh);
		}
		else if (luachon == 2)
		{
			cout << " __________________________________________________________________ " << endl;
			cout << "| " << setw(7) << left << "Ma SV" << setw(23) << left << "| Ho va Ten" << setw(13) << left << "| Ma Lop" << setw(8) << left << "| Nam Sinh" << setw(3) << left << "| Gioi Tinh"
				 << " |" << endl;
			cout << "|________|______________________|____________|_________|___________|" << endl;
			XuatNhieuSV(dssv);
			cout << "|__________________________________________________________________|" << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			fflush(stdin);

			char ms[10];
			cout << "\nNhap ma sinh vien can tim: ";
			gets(ms);
			NodeSV *pNew = TimSVTheoMa(dssv, ms);
			if (pNew == NULL)
			{
				cout << "Khong tim thay!!!" << endl;
			}
			else
				Xuat1SV(pNew->sinhvien);
			system("pause");
		}
		else if (luachon == 4)
		{
			fflush(stdin);
			char ten[10];
			cout << "\nNhap ten sinh vien can tim: ";
			gets(ten);

			NodeSV *pNew = TimSVTheoTen(dssv, ten);

			if (pNew == NULL)
			{
				cout << "Khong tim thay!!!" << endl;
			}
			else
				Xuat1SV(pNew->sinhvien);
			system("pause");
		}
		else if (luachon == 5)
		{
			fflush(stdin);
			char ma[10];
			cout << "\nNhap ma sinh vien can xoa: ";
			gets(ma);

			if (XoaX(dssv, ma) == 1)
			{
				cout << "Danh sach sinh vien sau khi xoa : " << endl;
				cout << " __________________________________________________________________ " << endl;
				cout << "| " << setw(7) << left << "Ma SV" << setw(23) << left << "| Ho va Ten" << setw(13) << left << "| Ma Lop" << setw(8) << left << "| Nam Sinh" << setw(3) << left << "| Gioi Tinh"
					 << " |" << endl;
				cout << "|________|______________________|____________|_________|___________|" << endl;
				XuatNhieuSV(dssv);
				cout << "|__________________________________________________________________|" << endl;
			}
			else
				cout << "Khong tim thay!!!!";
			system("pause");
		}
		else if (luachon == 6)
		{
			fflush(stdin);
			char ma[10];
			cout << "\nNhap ma sinh vien can cap nhat: ";
			gets(ma);

			CapNhatSV(dssv, ma,dslh);

			//			if(CapNhatSV(dssv,ma)==NULL)
			//			{
			cout << "Danh sach sinh vien sau khi cap nhat: " << endl;
			cout << " __________________________________________________________________ " << endl;
			cout << "| " << setw(7) << left << "Ma SV" << setw(23) << left << "| Ho va Ten" << setw(13) << left << "| Ma Lop" << setw(8) << left << "| Nam Sinh" << setw(3) << left << "| Gioi Tinh"
				 << " |" << endl;
			cout << "|________|______________________|____________|_________|___________|" << endl;
			XuatNhieuSV(dssv);
			cout << "|__________________________________________________________________|" << endl;
			//			}
			//			else
			//				cout<<"Khong tim thay!!!!";

			system("pause");
		}
		else if (luachon == 7)
		{
			fflush(stdin);
			cout << "Danh sach sinh vien sau khi sap xep:" << endl;
			Sort(dssv);
			cout << " __________________________________________________________________ " << endl;
			cout << "| " << setw(7) << left << "Ma SV" << setw(23) << left << "| Ho va Ten" << setw(13) << left << "| Ma Lop" << setw(8) << left << "| Nam Sinh" << setw(3) << left << "| Gioi Tinh"
				 << " |" << endl;
			cout << "|________|______________________|____________|_________|___________|" << endl;
			XuatNhieuSV(dssv);
			cout << "|__________________________________________________________________|" << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}
}

void MenuDSKQ(DSKQ &dskq, NODEMH &dsmh, DSSV &dssv)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU KET QUA ===========";
		cout << "\n1. Them 1 ket qua";
		cout << "\n2. Xuat thong tin ket qua";
		cout << "\n3. Tim ket qua theo ma";
		cout << "\n4. Tim ket qua theo ten";
		cout << "\n5. Xoa ket qua theo ma";
		cout << "\n6. Cap nhat thong tin ket qua";
		cout << "\n7. Sap xep theo ho ten ket qua";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuKQ(dskq, dsmh, dssv);
		}
		else if (luachon == 2)
		{

			XuatNhieuKQ(dskq);
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSLH(DSLH &dslh, NODEKHOA dsk, NODEKHOAHOC dskh, DSCTR dsctr)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU LOP HOC ===========";
		cout << "\n1. Them 1 lop hoc";
		cout << "\n2. Xuat thong tin lop hoc";
		cout << "\n3. Tim lop hoc theo ma";
		cout << "\n4. Tim lop hoc theo ten";
		cout << "\n5. Xoa lop hoc theo ma";
		cout << "\n6. Cap nhat thong tin lop hoc";
		cout << "\n7. Sap xep theo ho ten lop hoc";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuLH(dslh, dsk, dskh, dsctr);
		}
		else if (luachon == 2)
		{

			XuatNhieuLH(dslh);
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSMH(NODEMH &dsmh, NODEKHOA &dsk)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU MON HOC ===========";
		cout << "\n1. Them 1 mon hoc";
		cout << "\n2. Xuat thong tin mon hoc";
		cout << "\n3. Tim mon hoc theo ma";
		cout << "\n4. Tim mon hoc theo ten";
		cout << "\n5. Xoa mon hoc theo ma";
		cout << "\n6. Cap nhat thong tin mon hoc";
		cout << "\n7. Sap xep theo ho ten mon hoc";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuMH(dsmh, dsk);
		}
		else if (luachon == 2)
		{

			LNR(dsmh);
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSGD(DSGD &dsgd, DSCTR dsctr, NODEKHOA dsk, NODEMH dsmh)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU GIANG DAY ===========";
		cout << "\n1. Them 1 chuong trinh giang day";
		cout << "\n2. Xuat thong tin chuong trinh giang day";
		cout << "\n3. Tim chuong trinh giang day theo ma";
		cout << "\n4. Tim chuong trinh giang day theo ten";
		cout << "\n5. Xoa chuong trinh giang day theo ma";
		cout << "\n6. Cap nhat thong tin chuong trinh giang day";
		cout << "\n7. Sap xep theo ho ten chuong trinh giang day";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuGD(dsgd, dsctr, dsk, dsmh);
		}
		else if (luachon == 2)
		{

			XuatNhieuGD(dsgd);
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSCTR(DSCTR &dsctr)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU CHUONG TRINH ===========";
		cout << "\n1. Them 1 chuong trinh ";
		cout << "\n2. Xuat thong tin chuong trinh ";
		cout << "\n3. Tim chuong trinh theo ma";
		cout << "\n4. Tim chuong trinh theo ten";
		cout << "\n5. Xoa chuong trinh theo ma";
		cout << "\n6. Cap nhat thong tin chuong trinh ";
		cout << "\n7. Sap xep theo ho ten chuong trinh ";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuCTR(dsctr);
		}
		else if (luachon == 2)
		{

			XuatNhieuCTR(dsctr);
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSKH(NODEKHOAHOC &dskh)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU KHOA HOC ===========";
		cout << "\n1. Them 1 khoa hoc";
		cout << "\n2. Xuat thong tin khoa hoc";
		cout << "\n3. Tim khoa hoc theo ma";
		cout << "\n4. Tim khoa hoc theo ten";
		cout << "\n5. Xoa khoa hoc theo ma";
		cout << "\n6. Cap nhat thong tin khoa hoc";
		cout << "\n7. Sap xep theo ho ten khoa hoc";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			NhapNhieuKH(dskh);
		}
		else if (luachon == 2)
		{
			cout << " ____________________________________________ " << endl;
			cout << "| " << setw(13) << left << "Ma Khoa Hoc" << setw(15) << left << "| Nam Bat Dau" << setw(15) << left << "| Nam Ket Thuc |" << endl;
			cout << "|______________|______________|______________|" << endl;
			LNR(dskh);
			cout << "|____________________________________________|" << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
		}
		else if (luachon == 4)
		{
		}
		else if (luachon == 5)
		{
		}
		else if (luachon == 6)
		{
		}
		else if (luachon == 7)
		{
		}
		else
		{
			break;
		}
	}
}

void MenuDSK(NODEKHOA &dsk)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU KHOA ===========";
		cout << "\n1. Them 1 khoa";
		cout << "\n2. Xuat thong tin khoa";
		cout << "\n3. Tim khoa theo ma";
		cout << "\n4. Xoa khoa theo ma";
		cout << "\n5. Cap nhat thong tin khoa";
		cout << "\n6. Sap xep theo ma khoa";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ======================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			fflush(stdin);
			NhapNhieuKhoa(dsk);
		}
		else if (luachon == 2)
		{
			cout << " ______________________________________________ " << endl;
			cout << "| " << setw(8) << left << "Ma Khoa" << setw(21) << left << "| Ten Khoa" << setw(14) << left << "| Nam Thanh Lap |" << endl;
			cout << "|_________|____________________|_______________|" << endl;
			fflush(stdin);
			NLR(dsk);
			cout << "|______________________________________________|" << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			fflush(stdin);
			char ms[10];
			cout << "\nNhap ma khoa can tim: ";
			gets(ms);
			NODEKHOA t = TimKhoaTheoMa(dsk, ms);
			if (t == NULL)
			{
				cout << "Khong tim thay!!!" << endl;
			}
			else
				Xuat1Khoa(t->info);
			system("pause");
		}
		else if (luachon == 4)
		{
			KHOA k;
			fflush(stdin);
			char ma[10];
			cout << "\nNhap ma khoa can xoa: ";
			gets(k.maKhoa);

			if (TimKhoaTheoMa(dsk, k.maKhoa) == NULL)
			{
				cout << "Khong tim thay!!!!" << endl;
				system("pause");
			}
			else
			{
				XoaNode(dsk, k);
				cout << "Danh sach khoa sau khi xoa:" << endl;
				cout << " ______________________________________________ " << endl;
				cout << "| " << setw(8) << left << "Ma Khoa" << setw(21) << left << "| Ten Khoa" << setw(14) << left << "| Nam Thanh Lap |" << endl;
				cout << "|_________|____________________|_______________|" << endl;
				NLR(dsk);
				cout << "|______________________________________________|" << endl;
				system("pause");
			}
		}
		else if (luachon == 5)
		{
			fflush(stdin);
			char ma[10];
			cout << "\nNhap ma khoa can cap nhat: ";
			gets(ma);
			if (CapNhatKhoa(dsk, ma) == 1)
			{
				cout << "Danh sach khoa sau khi cap nhat: " << endl;
				cout << " ______________________________________________ " << endl;
				cout << "| " << setw(8) << left << "Ma Khoa" << setw(21) << left << "| Ten Khoa" << setw(14) << left << "| Nam Thanh Lap |" << endl;
				cout << "|_________|____________________|_______________|" << endl;
				NLR(dsk);
				cout << "|______________________________________________|" << endl;
				system("pause");
			}
		}
		else if (luachon == 6)
		{
			cout << "Danh sach khoa sap xep theo ma: " << endl;

			cout << " ______________________________________________ " << endl;
			cout << "| " << setw(8) << left << "Ma Khoa" << setw(21) << left << "| Ten Khoa" << setw(14) << left << "| Nam Thanh Lap |" << endl;
			cout << "|_________|____________________|_______________|" << endl;
			LNR(dsk);
			cout << "|______________________________________________|" << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}
}
void MenuThongKe(DSSV &dssv, DSCTR &dsctr, NODEKHOA &dsk, NODEKHOAHOC &dskh, NODEMH &dsmh, DSLH &dslh, DSKQ &dskq, DSGD &dsgd)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU THONG KE ===========";
		cout << "\n1. Thong ke sinh vien theo lop ";
		cout << "\n2. Thong ke sinh vien theo khoa ";
		cout << "\n3. Thong ke sinh vien theo hoc ki ";
		cout << "\n4. Thong ke sinh vien theo nam hoc ";
		cout << "\n5. Thong ke mon hoc co nhieu sinh vien hoc nhat trong tung nam ";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ===================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le!!!" << endl;
			system("pause");
		}
		else if (luachon == 1)
		{
			char malop[10];
			//			cout<<"nhap ma lop: ";
			//			cin>>malop;
			//XuatSVCua1Lop(dssv,dslh,malop);
			cout << " ____________________ " << endl;
			cout << "| " << setw(8) << left << "Ma Lop" << setw(10) << left << "| So Luong"
				 << " |" << endl;
			cout << "|_________|__________|" << endl;
			Xuat(dssv);
			cout << "|____________________|" << endl;
			system("pause");
		}
		else if (luachon == 2)
		{

			cout << " __________________________________________ " << endl;
			cout << "| " << setw(8) << left << "Ma Khoa" << setw(22) << left << "| Ten Khoa" << setw(10) << left << "| So Luong"
				 << " |" << endl;
			cout << "|_________|_____________________|__________|" << endl;
			Xuat2(dssv, dslh, dsk);
			cout << "|__________________________________________|" << endl;
			system("pause");
		}
		else if (luachon == 3)
		{
			cout << " ___________________ " << endl;
			cout << "| " << setw(7) << left << "Hoc Ky" << setw(10) << left << "| So Luong"
				 << " |" << endl;
			cout << "|________|__________|" << endl;
			Xuat3(dsgd, dskq, dssv);
			cout << "|___________________|" << endl;
			system("pause");
		}
		else if (luachon == 4)
		{

			cout << " __________________________________ " << endl;
			cout << "| " << setw(12) << left << "Ma Khoa Hoc" << setw(10) << left << "| Nam Hoc" << setw(10) << left << "| So Luong"
				 << " |" << endl;
			cout << "|_____________|_________|__________|" << endl;
			Xuat4(dssv, dslh, dskh);
			cout << "|__________________________________|" << endl;
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << " ____________________________________________________ " << endl;
			cout << "| " << setw(30) << left << "Ten Mon Hoc" << setw(10) << left << "| Nam Hoc" << setw(10) << left << "| So Luong"
				 << " |" << endl;
			cout << "|_______________________________|_________|__________|" << endl;
			Xuat5(dskq, dsgd, dsmh);
			cout << "|____________________________________________________|" << endl;

			system("pause");
		}
		else
		{
			break;
		}
	}
}

void MenuChinh(DSSV &dssv, DSCTR &dsctr, NODEKHOA &dsk, NODEKHOAHOC &dskh, NODEMH &dsmh, DSLH &dslh, DSKQ &dskq, DSGD &dsgd)
{
	
	while (true)
	{
		system("cls");
		cout<<"Ten sv: Cao Nguyen Son Lam "<<endl;
		cout<<"        Nguyen Manh Hung   "<<endl;
		cout<<"        Trieu Dang Khoa    "<<endl;
	
		cout << "\n\n\t\t =========== MENU CHINH ===========";
		cout << "\n1. Quan ly DSKhoa ";
		cout << "\n2. Quan ly DSKhoaHoc ";
		cout << "\n3. Quan ly DSSinhVien ";
		cout << "\n4. Quan ly DSChuongTrinh ";
		cout << "\n5. Quan ly DSMonHoc ";
		cout << "\n6. Quan ly DSKetQua ";
		cout << "\n7. Quan ly DSLopHoc ";
		cout << "\n8. Quan ly DSGiangDay ";
		cout << "\n9. Thong Ke ";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ===================================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 10)
		{
			cout << "\nLua chon khong hop le!!!" << endl;
			system("pause");
		}
		else if (luachon == 1)
		{
			MenuDSK(dsk);
		}
		else if (luachon == 2)
		{
			MenuDSKH(dskh);
		}
		else if (luachon == 3)
		{
			MenuDSSV(dssv, dslh);
		}
		else if (luachon == 4)
		{
			MenuDSCTR(dsctr);
		}
		else if (luachon == 5)
		{
			MenuDSMH(dsmh, dsk);
		}
		else if (luachon == 6)
		{
			MenuDSKQ(dskq, dsmh, dssv);
		}
		else if (luachon == 7)
		{
			MenuDSLH(dslh, dsk, dskh, dsctr);
		}
		else if (luachon == 8)
		{
			MenuDSGD(dsgd, dsctr, dsk, dsmh);
		}
		else if (luachon == 9)
		{
			MenuThongKe(dssv, dsctr, dsk, dskh, dsmh, dslh, dskq, dsgd);
		}
		//		MenuThongKe(dssv,dsctr,dsk,dskh,dsmh,dslh,dskq,dsgd);
		else
		{
			break;
		}
	}
}
int main()
{
	//	SetBGColor(41);
	DSSV dssv;
	DSCTR dsctr;
	DSLH dslh;
	DSKQ dskq;
	DSGD dsgd;

	NODEKHOA dsk;
	NODEKHOAHOC dskh;
	NODEMH dsmh;

	InitGD(dsgd);
	InitKQ(dskq);
	InitSV(dssv);
	InitLH(dslh);

	KhoiTaoCay(dsk);
	KhoiTaoCay(dskh);
	KhoiTaoCay(dsmh);
	
	DocFileSinhVienNhiPhan(dssv);
//	DocFileSinhVien(dssv);

//	DocFileChuongTrinh(dsctr);
	DocFileChuongTrinhNhiPhan(dsctr);

//	DocFileKhoa(dsk);
	DocFileKhoa_NhiPhan(dsk);

//	DocFileKH(dskh);
	DocFileKhoaHoc_NhiPhan(dskh);

//	DocFileMH(dsmh);
	DocFileMonHoc_NhiPhan(dsmh);
	
//	DocFileLH(dslh);
	DocFileLopHocNhiPhan(dslh);
	
//	DocFileKQ(dskq);
	DocFileKetQuaNhiPhan(dskq);
	
//	DocFileGD(dsgd);
	DocFileGiangDayNhiPhan(dsgd);
	//	Menu(dssv,dsctr,dsk,dskh,dsmh,dslh);
	//MenuSV()
	MenuChinh(dssv, dsctr, dsk, dskh, dsmh, dslh, dskq, dsgd);
	
	GhiFileGiangDayNhiPhan(dsgd);
//	GhiFileGD(dsgd);
	
//	GhiFileKQ(dskq);
	GhiFileKetQuaNhiPhan(dskq);
	
//	GhiFileSinhVien(dssv);
	GhiFileSinhVienNhiPhan(dssv);
	
//	GhiFileChuongTrinh(dsctr);
	GhiFileChuongTrinhNhiPhan(dsctr);
	
//	GhiFileLH(dslh);
	GhiFileLopHocNhiPhan(dslh);
	
//	Ghi_NLR_KHOA(dsk);
	Ghi_NLR_KHOA_NHIPHAN(dsk);
	
//	Ghi_NLR_KH(dskh);
	Ghi_NLR_KHOAHOC_NHIPHAN(dskh);
	
//	Ghi_NLR_MH(dsmh);
	Ghi_NLR_MONHOC_NHIPHAN(dsmh);
	
}
