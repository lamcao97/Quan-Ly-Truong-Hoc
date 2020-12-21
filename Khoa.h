#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#pragma once
using namespace std;
//KhaiBao
struct Khoa
{
	char maKhoa[10];
	char tenKhoa[30];
	char namThanhLap[5];
};
typedef struct Khoa KHOA;
struct NodeKHOA
{
	KHOA info;
	NodeKHOA *left;
	NodeKHOA *right;
};
typedef struct NodeKHOA *NODEKHOA;


void KhoiTaoCay(NODEKHOA &t)
{
	t = NULL;
}
void Free(NODEKHOA t)
{
	if (t == NULL)
		return;
	Free(t->left);
	Free(t->right);
	Free(t);
}
int SoSanhMa(KHOA khoa1, KHOA khoa2)
{
	return strcmp(khoa1.maKhoa, khoa2.maKhoa);
}
void InsertKhoa(NODEKHOA &t, KHOA khoa)
{

	if (t == NULL)
	{
		NodeKHOA *q = new NodeKHOA;
		q->info = khoa;
		q->left = NULL;
		q->right = NULL;
		t = q;
	}
	else
	{
		if (SoSanhMa(t->info, khoa) > 0)
		{
			return InsertKhoa(t->left, khoa);
		}

		else if (SoSanhMa(t->info, khoa) < 0)
		{
			return InsertKhoa(t->right, khoa);
		}
	}
}
void XuatKhoa(Khoa KHOA)
{
	cout << "| " << setw(10) << left << KHOA.maKhoa << setw(21) << left << KHOA.tenKhoa << setw(14) << left << KHOA.namThanhLap << "|" << endl;
}
void Xuat1Khoa(Khoa KHOA)
{
	cout << "- Ma Khoa: " << KHOA.maKhoa << endl;
	cout << "- Ten Khoa : " << KHOA.tenKhoa << endl;
	cout << "- Nam Thanh Lap : " << KHOA.namThanhLap << endl;
}
void NLR(NODEKHOA t)
{
	if (t != NULL)
	{
		XuatKhoa(t->info);
		NLR(t->left);
		NLR(t->right);
	}
}
NODEKHOA TimKhoaTheoMa(NODEKHOA &t, char *maKhoa)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(t->info.maKhoa, maKhoa) > 0)
		TimKhoaTheoMa(t->left, maKhoa);
	else if (strcmp(t->info.maKhoa, maKhoa) < 0)
		TimKhoaTheoMa(t->right, maKhoa);
	else
		return t;
}

bool TimKhoaTheoMa2(NODEKHOA &t, char *maKhoa)
{
	if (t == NULL)
		return false;
	else if (strcmp(t->info.maKhoa, maKhoa) > 0)
		TimKhoaTheoMa(t->left, maKhoa);
	else if (strcmp(t->info.maKhoa, maKhoa) < 0)
		TimKhoaTheoMa(t->right, maKhoa);
	else
		return true;
}

NODEKHOA TimKhoaTheoTen(NODEKHOA t, char *tenKhoa)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(t->info.tenKhoa, tenKhoa) > 0)
		TimKhoaTheoTen(t->left, tenKhoa);
	else if (strcmp(t->info.tenKhoa, tenKhoa) < 0)
		TimKhoaTheoTen(t->right, tenKhoa);
	else
		return t;
}

void TimKiemTheoTen2(NODEKHOA t, char *ten)
{
	if (t != NULL)
	{
		if (strcmp(t->info.tenKhoa, ten) == 0)
		{

			Xuat1Khoa(t->info);
		}
		else
		{
			TimKiemTheoTen2(t->left, ten);
			TimKiemTheoTen2(t->right, ten);
		}
	}
}

KHOA Nhap1Khoa(NODEKHOA t)
{
	KHOA khoa;
	fflush(stdin);

	do
	{
		cout << "- Nhap Ma Khoa(toi da 10 ki tu): ";
		gets(khoa.maKhoa);

		if (TimKhoaTheoMa(t, khoa.maKhoa) != NULL)
		{
			cout << "Ma Khoa Da Ton Tai!!!" << endl;
		}
		else if (strlen(khoa.maKhoa) > 10)
		{
			cout << "Nhap qua ki tu. Qui dinh phai <10!!!" << endl;
		}
		else
			break;
	} while (1);

	do
	{
		cout << "- Nhap ten khoa(toi da 30 ki tu): ";
		gets(khoa.tenKhoa);

		if (strlen(khoa.tenKhoa) > 30)
		{
			cout << "Nhap qua ki tu. Qui dinh phai <30!!!" << endl;
		}
		else
			break;
	} while (1);
	cout << "- Nhap nam thanh lap: ";
	gets(khoa.namThanhLap);
	return khoa;
}

void NhapNhieuKhoa(NODEKHOA &t)
{
	int tt = 1;
	KHOA khoa;
	do
	{
		cout << "Nhap Thong Tin Khoa: \n";
		khoa = Nhap1Khoa(t);
		InsertKhoa(t, khoa);
		cout << "Tiep tuc nhap (0/1)?: " << endl;
		cin >> tt;
		if (tt == 0)
			break;
	} while (1);
}
void DiTimNodeTheMang(NODEKHOA &X, NODEKHOA &Y)
{

	if (Y->left != NULL)
	{
		DiTimNodeTheMang(X, Y->left);
	}
	else
	{
		X->info = Y->info;
		X = Y;
		Y = Y->right;
	}
}

void XoaNode(NODEKHOA &T, Khoa k)
{

	if (T == NULL)
	{
		return;
	}
	else
	{

		if (SoSanhMa(T->info, k) > 0)
		{
			return XoaNode(T->left, k);
		}
		else if (SoSanhMa(T->info, k) < 0)
		{
			return XoaNode(T->right, k);
		}
		else
		{
			NODEKHOA X = T;
			if (T->left == NULL)
			{

				T = T->right;
			}
			else if (T->right == NULL)
			{

				T = T->left;
			}
			else
			{
				DiTimNodeTheMang(X, T->right);
			}
			delete X;
		}
	}
}

int CapNhatKhoa(NODEKHOA &t, char maKhoa[10])
{
	char tenCT[20];
	NODEKHOA p = TimKhoaTheoMa(t, maKhoa);
	cout << "Cap Nhat Ten Khoa: " << endl;
	gets(p->info.tenKhoa);
	cout << "Cap Nhat Nam Thanh Lap Khoa: " << endl;
	gets(p->info.namThanhLap);

	return 1;
}

void LNR(NODEKHOA t)
{
	if (t != NULL)
	{
		LNR(t->left);
		XuatKhoa(t->info);
		LNR(t->right);
	}
}



//fstream fileIn("DSLH.txt", ios::in|ios::binary);
//	LopHoc lh;
//	while(fileIn.read(reinterpret_cast<char *>(&lh),sizeof(LopHoc))){
//		NodeLopHoc *node = TaoNodeLH(lh);
//		AddHeadLH(dslh, node);
//	}

void DocFileKhoa_NhiPhan(NODEKHOA &t)
{
	Khoa k;
	fstream f;
	f.open("DSKHOA.txt", ios::in|ios::binary);
	if (f == NULL)
		return;
	while(f.read(reinterpret_cast<char *>(&k),sizeof(Khoa))){
		InsertKhoa(t, k);
	}
		
//	while (!f.eof())
//	{
//		Khoa KHOA;
//		getline(f, data);
//		if (data.size() == 0)
//			break;
//		strcpy(KHOA.maKhoa, data.c_str());
//		getline(f, data);
//		strcpy(KHOA.tenKhoa, data.c_str());
//		getline(f, data);
//		strcpy(KHOA.namThanhLap, data.c_str());
//		//	f.ignore();
//		InsertKhoa(t, KHOA); //them moi vao BST
//	}
	f.close();
}

void GhiFileKHOA(NODEKHOA t, ofstream &f)
{
	if (t != NULL)
	{
		f << t->info.maKhoa << endl
		  << t->info.tenKhoa << endl
		  << t->info.namThanhLap << endl;
		GhiFileKHOA(t->left, f);
		GhiFileKHOA(t->right, f);
	}
}

void GhiFileKHOA_NHIPHAN(NODEKHOA t, ofstream &f)
{
	if (t != NULL)
	{
		f.write(reinterpret_cast<char *>(&t->info),sizeof(Khoa));
		GhiFileKHOA_NHIPHAN(t->left, f);
		GhiFileKHOA_NHIPHAN(t->right, f);
	}
}
void Ghi_NLR_KHOA_NHIPHAN(NODEKHOA t)
{
	ofstream f;
	f.open("DSKHOA.txt", ios::out|ios::binary);

	GhiFileKHOA_NHIPHAN(t, f);
	f.close();
}

void Ghi_NLR_KHOA(NODEKHOA t)
{
	ofstream f;
	f.open("DSKHOA.txt", ios_base::out);

	GhiFileKHOA(t, f);
	f.close();
}
