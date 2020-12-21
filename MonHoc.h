#include <iostream>
#include <string.h>
#include <fstream>
#include "Khoa.h"
#pragma once
using namespace std;

struct MonHoc
{
	char maMH[10];
	char tenMH[30];
	char maKhoa[10];
};
typedef struct MonHoc MONHOC;

struct NodeMH
{
	MONHOC info;
	struct NodeMH *left;
	struct NodeMH *right;
};
typedef struct NodeMH *NODEMH;

void KhoiTaoCay(NODEMH &t)
{
	t = NULL;
}

void Free(NODEMH t)
{
	if (t == NULL)
		return;
	Free(t->left);
	Free(t->right);
	Free(t);
}

int SoSanhMa(MONHOC mh1, MONHOC mh2)
{
	return strcmp(mh1.maMH, mh2.maMH);
}
void InsertMH(NODEMH &t, MONHOC mh)
{

	if (t == NULL)
	{
		NodeMH *q = new NodeMH;
		q->info = mh;
		q->left = NULL;
		q->right = NULL;
		t = q;
	}
	else
	{
		if (SoSanhMa(t->info, mh) > 0)
		{
			return InsertMH(t->left, mh);
		}

		else if (SoSanhMa(t->info, mh) < 0)
		{
			return InsertMH(t->right, mh);
		}
	}
}
void Xuat1MH(MonHoc MONHOC)
{
	cout << "- Ma Mon Hoc: " << MONHOC.maMH << endl;
	cout << "- Tem Mon Hoc: " << MONHOC.tenMH << endl;
	//	cout << "- Nam Ket Thuc: " << MONHOC.namKT << endl;

	//	cout<<" ____________________________________________"<<endl;
	//	cout<<"|    Ma Chuong Trinh  |    Ten Chuong Trinh  |"<<endl;
	//	cout<<"|_____________________|______________________|"<<endl;
	//	cout<<"|"<<KHOAHOC.maKhoaHoc<<"                  "<<KHOAHOC.namBD<<"                   |"<<endl;
	//	cout<<"|_____________________|______________________|"<<endl;
	//	cout<<"|_____________________|______________________|";
}
void NLR(NODEMH t)
{
	if (t != NULL)
	{
		Xuat1MH(t->info);
		NLR(t->left);
		NLR(t->right);
	}
}
NODEMH TimMHTheoMaMH(NODEMH &t, char *maMH)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(t->info.maMH, maMH) > 0)
		TimMHTheoMaMH(t->left, maMH);
	else if (strcmp(t->info.maMH, maMH) < 0)
		TimMHTheoMaMH(t->right, maMH);
	else
		return t;
}
NODEMH TimKHTheoMaMH(NODEMH &t, char *maMH)
{
	if (t == NULL)
		return NULL;
	else if (strcmp(t->info.maMH, maMH) > 0)
		TimKHTheoMaMH(t->left, maMH);
	else if (strcmp(t->info.maMH, maMH) < 0)
		TimKHTheoMaMH(t->right, maMH);
	else
		return t;
}

MONHOC Nhap1MH(NODEKHOA &t)
{
	MONHOC mh;

	fflush(stdin);
	cout << "- Nhap ma mon hoc: ";
	gets(mh.maMH);
	cout << "- Nhap ten mon hoc: ";
	gets(mh.tenMH);

	do
	{
		cout << "- Nhap ma khoa: ";
		gets(mh.maKhoa);
		NODEKHOA kt = TimKhoaTheoMa(t, mh.maKhoa);
		if (kt == NULL)
		{
			cout << "Ma Khoa Khong Ton Tai!!!!" << endl;
		}
		else
			break;
	} while (1);

	return mh;
}

void NhapNhieuMH(NODEMH &t, NODEKHOA &t2)
{
	int tt = 1;
	MONHOC mh;

	do
	{
		cout << "Nhap Thong Tin Mon Hoc: \n";
		mh = Nhap1MH(t2);
		InsertMH(t, mh);
		cout << "Tiep tuc nhap (0/1)?: " << endl;
		cin >> tt;
		if (tt == 0)
			break;
	} while (1);
}
void DiTimNodeTheMang(NODEMH &X, NODEMH &Y)
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

void XoaNode(NODEMH &T, MonHoc mh)
{

	if (T == NULL)
	{
		return;
	}
	else
	{

		if (SoSanhMa(T->info, mh) > 0)
		{
			return XoaNode(T->left, mh);
		}
		else if (SoSanhMa(T->info, mh) < 0)
		{
			return XoaNode(T->right, mh);
		}
		else
		{
			NODEMH X = T;
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

int CapNhatMH(NODEMH &t, char maMH[10])
{
	char tenCT[20];
	NODEMH p = TimKHTheoMaMH(t, maMH);
	cout << "Cap Nhat Ten Mon Hoc: " << endl;
	gets(p->info.tenMH);

	return 1;
}

void LNR(NODEMH t)
{
	if (t != NULL)
	{

		NLR(t->left);
		Xuat1MH(t->info);
		NLR(t->right);
	}
}

void DocFileMH(NODEMH &t)
{
	string data;
	fstream f;
	f.open("DSMONHOC.txt", ios::in);
	if (f == NULL)
		return;
	while (!f.eof())
	{
		MonHoc MH;
		getline(f, data);
		if (data.size() == 0)
			break;
		strcpy(MH.maMH, data.c_str());
		getline(f, data);
		strcpy(MH.tenMH, data.c_str());
		getline(f, data);
		strcpy(MH.maKhoa, data.c_str());
		//	f.ignore();
		InsertMH(t, MH); //them moi vao BST
	}
	f.close();
}

void DocFileMonHoc_NhiPhan(NODEMH &t)
{
	MonHoc mh;
	fstream f;
	f.open("DSMH.txt", ios::in|ios::binary);
	if (f == NULL)
		return;
	while(f.read(reinterpret_cast<char *>(&mh),sizeof(MonHoc))){
		InsertMH(t, mh);
	}
	f.close();
}

void GhiFileMONHOC_NHIPHAN(NODEMH t, ofstream &f)
{
	if (t != NULL)
	{
		f.write(reinterpret_cast<char *>(&t->info),sizeof(MonHoc));
		GhiFileMONHOC_NHIPHAN(t->left, f);
		GhiFileMONHOC_NHIPHAN(t->right, f);
	}
}
void Ghi_NLR_MONHOC_NHIPHAN(NODEMH t)
{
	ofstream f;
	f.open("DSMH.txt", ios::out|ios::binary);

	GhiFileMONHOC_NHIPHAN(t, f);
	f.close();
}

void GhiFileMH(NODEMH t, ofstream &f)
{
	if (t != NULL)
	{
		f << t->info.maMH << endl
		  << t->info.tenMH << endl
		  << t->info.maKhoa << endl;
		GhiFileMH(t->left, f);
		GhiFileMH(t->right, f);
	}
}

void Ghi_NLR_MH(NODEMH t)
{
	ofstream f;
	f.open("DSMONHOC.txt", ios_base::out);

	GhiFileMH(t, f);
	f.close();
}
