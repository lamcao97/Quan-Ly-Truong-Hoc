#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#pragma once

using namespace std;

struct KhoaHoc
{
	char maKhoaHoc[10];
	char namKT[5];
	char namBD[5];
};
typedef struct KhoaHoc KHOAHOC;

struct NodeKHOAHOC
{
	KHOAHOC info;
	struct NodeKHOAHOC *left;
	struct NodeKHOAHOC *right;
};
typedef struct NodeKHOAHOC *NODEKHOAHOC;

void KhoiTaoCay(NODEKHOAHOC &t)
{
	t = NULL;
}

void Free(NODEKHOAHOC t)
{
	if (t == NULL)
		return;
	Free(t->left);
	Free(t->right);
	Free(t);
}
int SoSanhMa(KHOAHOC kh1, KHOAHOC kh2)
{
	return strcmp(kh1.maKhoaHoc, kh2.maKhoaHoc);
}
void InsertKH(NODEKHOAHOC &t, KHOAHOC kh)
{

	if (t == NULL)
	{
		NodeKHOAHOC *q = new NodeKHOAHOC;
		q->info = kh;
		q->left = NULL;
		q->right = NULL;
		t = q;
	}
	else
	{
		if (SoSanhMa(t->info, kh) > 0)
		{
			return InsertKH(t->left, kh);
		}

		else if (SoSanhMa(t->info, kh) < 0)
		{
			return InsertKH(t->right, kh);
		}
	}
}
void Xuat1KH(KhoaHoc KHOAHOC)
{
	cout << "| " << setw(15) << left << KHOAHOC.maKhoaHoc << setw(15) << left << KHOAHOC.namBD << setw(13) << left << KHOAHOC.namKT << "|" << endl;
	//	cout<<" ____________________________________________"<<endl;
	//	cout<<"|    Ma Chuong Trinh  |    Ten Chuong Trinh  |"<<endl;
	//	cout<<"|_____________________|______________________|"<<endl;
	//	cout<<"|"<<KHOAHOC.maKhoaHoc<<"                  "<<KHOAHOC.namBD<<"                   |"<<endl;
	//	cout<<"|_____________________|______________________|"<<endl;
	//	cout<<"|_____________________|______________________|";
}
void NLR(NODEKHOAHOC t)
{
	if (t != NULL)
	{
		Xuat1KH(t->info);
		NLR(t->left);
		NLR(t->right);
	}
}
NODEKHOAHOC TimKHTheoMa(NODEKHOAHOC &t, char *maKH)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(t->info.maKhoaHoc, maKH) > 0)
		TimKHTheoMa(t->left, maKH);
	else if (strcmp(t->info.maKhoaHoc, maKH) < 0)
		TimKHTheoMa(t->right, maKH);
	else
		return t;
}

KHOAHOC Nhap1KH()
{
	KHOAHOC kh;
	fflush(stdin);
	cout << "- Nhap ma khoa hoc: ";
	gets(kh.maKhoaHoc);
	cout << "- Nhap nam bat dau khoa hoc: ";
	gets(kh.namBD);
	cout << "- Nhap nam ket thuc khoa hoc: ";
	gets(kh.namKT);
	return kh;
}

void NhapNhieuKH(NODEKHOAHOC &t)
{
	int tt = 1;
	KHOAHOC kh;
	do
	{
		cout << "Nhap Thong Tin Khoa: \n";
		kh = Nhap1KH();
		InsertKH(t, kh);
		cout << "Tiep tuc nhap (0/1)?: " << endl;
		cin >> tt;
		if (tt == 0)
			break;
	} while (1);
}
void DiTimNodeTheMang(NODEKHOAHOC &X, NODEKHOAHOC &Y)
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

void XoaNode(NODEKHOAHOC &T, KhoaHoc kh)
{

	if (T == NULL)
	{
		return;
	}
	else
	{

		if (SoSanhMa(T->info, kh) > 0)
		{
			return XoaNode(T->left, kh);
		}
		else if (SoSanhMa(T->info, kh) < 0)
		{
			return XoaNode(T->right, kh);
		}
		else
		{
			NODEKHOAHOC X = T;
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

int CapNhatKhoa(NODEKHOAHOC &t, char maKH[10])
{
	char tenCT[20];
	NODEKHOAHOC p = TimKHTheoMa(t, maKH);
	cout << "Cap Nhat Nam Bat Dau: " << endl;
	gets(p->info.namBD);
	cout << "Cap Nhat Nam Ket Thuc: " << endl;
	gets(p->info.namKT);

	return 1;
}

void LNR(NODEKHOAHOC t)
{
	if (t != NULL)
	{

		NLR(t->left);
		Xuat1KH(t->info);
		NLR(t->right);
	}
}

void DocFileKH(NODEKHOAHOC &t)
{
	string data;
	fstream f;
	f.open("DSKHOAHOC.txt", ios::in);
	if (f == NULL)
		return;
	while (!f.eof())
	{
		KhoaHoc KH;
		getline(f, data);
		if (data.size() == 0)
			break;
		strcpy(KH.maKhoaHoc, data.c_str());
		getline(f, data);
		strcpy(KH.namBD, data.c_str());
		getline(f, data);
		strcpy(KH.namKT, data.c_str());
		//	f.ignore();
		InsertKH(t, KH); //them moi vao BST
	}
	f.close();
}

void DocFileKhoaHoc_NhiPhan(NODEKHOAHOC &t)
{
	KhoaHoc kh;
	fstream f;
	f.open("DSKH.txt", ios::in|ios::binary);
	if (f == NULL)
		return;
	while(f.read(reinterpret_cast<char *>(&kh),sizeof(KhoaHoc))){
		InsertKH(t, kh);
	}
	f.close();
}

void GhiFileKHOAHOC_NHIPHAN(NODEKHOAHOC t, ofstream &f)
{
	if (t != NULL)
	{
		f.write(reinterpret_cast<char *>(&t->info),sizeof(KhoaHoc));
		GhiFileKHOAHOC_NHIPHAN(t->left, f);
		GhiFileKHOAHOC_NHIPHAN(t->right, f);
	}
}
void Ghi_NLR_KHOAHOC_NHIPHAN(NODEKHOAHOC t)
{
	ofstream f;
	f.open("DSKH.txt", ios::out|ios::binary);

	GhiFileKHOAHOC_NHIPHAN(t, f);
	f.close();
}


void GhiFileKH(NODEKHOAHOC t, ofstream &f)
{
	if (t != NULL)
	{
		f << t->info.maKhoaHoc << endl
		  << t->info.namBD << endl
		  << t->info.namKT << endl;
		GhiFileKH(t->left, f);
		GhiFileKH(t->right, f);
	}
}

void Ghi_NLR_KH(NODEKHOAHOC t)
{
	ofstream f;
	f.open("DSKHOAHOC.txt", ios_base::out);

	GhiFileKH(t, f);
	f.close();
}
