#include <iostream>
#include <string.h>
#include <fstream>
#include "Khoa.h"
#include "KhoaHoc.h"
#include "ChuongTrinh.h"
#pragma once

using namespace std;

struct LopHoc {
	char maLop[10];
	char maKhoa[10];
	char maKhoaHoc[10];
	char maChuongTrinh[10];
	int soThuTu;
};

struct NodeLopHoc
{
	LopHoc lophoc;
	NodeLopHoc *pNext;
};
typedef struct NodeLopHoc* NODELOPHOC;

struct DSLH{
	NodeLopHoc *head, *tail;
};

NodeLopHoc* TaoNodeLH(LopHoc lh){
   NodeLopHoc* node = new NodeLopHoc;
   if (node) {
      node->lophoc = lh;
      node->pNext = NULL;
   }
   return node;
}

//---------------------------
 void InitLH(DSLH &dslh)
{
	dslh.head = dslh.tail = NULL;
}
int IsEmptyLH(DSLH dslh)
{
	if (dslh.head == NULL)
		return 1;
	return 0;
}

void AddHeadLH(DSLH &dslh, NodeLopHoc* pNew)
{
	if (IsEmptyLH(dslh))
	{
		dslh.head = dslh.tail = pNew;
	}
	else
	{
		pNew->pNext = dslh.head;
		dslh.head = pNew;
	}
}

void AddTailLH(DSLH &dslh, NodeLopHoc* node) {
   if (!dslh.head)
      dslh.head = dslh.tail = node;
   else {
      dslh.tail->pNext = node;
      dslh.tail = node;
   }
}
 
void AddAfterLH(DSLH &dslh, NodeLopHoc* node){
	NodeLopHoc *pos;		//vi tri node truoc
	for(NodeLopHoc *p = dslh.head; p != NULL; p = p ->pNext) {
		if(strcmp(node->lophoc.maLop, p->lophoc.maLop) < 0) {
		break;	
		}
		pos = p;
	}
	node->pNext=pos->pNext;
	pos->pNext=node;
}

NodeLopHoc *TimLHTheoMa(DSLH dslh,char *maLH)
{
	NodeLopHoc *p = dslh.head;
	while(p)
	{
		if(strcmp(p->lophoc.maLop,maLH)==0)
			return p;
		p=p->pNext;
	}
	return NULL;
}

//NodeLopHoc *TimLHTheoTen(DSLH dslh,char tenLH[10])
//{
//	NodeLopHoc *p = dslh.head;
//	while(p)
//	{
//		if(strcmp(p->lophoc.,maLH)==0)
//			return p;
//		p=p->pNext;
//	}
//	return NULL;
//}

//void HoanVi(LopHoc &a, LopHoc &b)
//{
//	LopHoc tam=a;
//	a=b;
//	b=tam;
//}
//NodeLopHoc *Min(DSLH dslh, NodeLopHoc *p)
//{
//	NodeLopHoc *pMin=p;
//	NodeLopHoc *k=p->pNext;
//	while(k)
//	{
//		if(strcmp(k->chuongtrinh.tenCTr,pMin->chuongtrinh.tenCTr)<0)
//		
//			pMin=k;
//		k=k->pNext;
//	}
//	return pMin;
//}
//void Sort(DSCTR &dsctr)
//{
//	NodeCTR *p=dsctr.head;
//	while(p!=dsctr.tail)
//	{
//		NodeCTR *pMin=Min(dsctr, p);
//		HoanVi(p->chuongtrinh, pMin->chuongtrinh);
//		p=p->pNext;
//	}
//}

void DeleteHead(DSLH &dslh)
{
	NodeLopHoc *pDel = dslh.head;
	dslh.head = pDel -> pNext;
		
	if(dslh.head == NULL)
		dslh.tail = NULL;
	
	free(pDel);
}
NodeLopHoc *PrevNodeP(DSLH dslh, NodeLopHoc *p)
{
	if(p == dslh.head)
		return NULL;
	NodeLopHoc *pTruoc = dslh.head;
	while(pTruoc->pNext != p)
		pTruoc = pTruoc -> pNext;
	return pTruoc;
}
void DeleteTail(DSLH &dslh)
{
	if(dslh.head==dslh.tail)
		DeleteHead(dslh);
	else
	{
		NodeLopHoc *pDel = dslh.tail;
		NodeLopHoc *pTruoc = PrevNodeP(dslh, pDel);
		pTruoc -> pNext = NULL;
		dslh.tail = pTruoc;
		free(pDel);
	}
}
void DeleteNode(DSLH &dslh, NodeLopHoc *pDel)
{
	if(pDel==dslh.head)
		DeleteHead(dslh);
	else if(pDel==dslh.tail)
		DeleteTail(dslh);
	else
	{
		NodeLopHoc *pPrev=PrevNodeP(dslh, pDel);
		pPrev->pNext=pDel->pNext;
		free(pDel);
	}	
}

int XoaX(DSLH &dslh, char maLH[10])
{
	NodeLopHoc *pX = TimLHTheoMa(dslh, maLH);
	if(pX == NULL)
		return 0;
	DeleteNode(dslh, pX);
	return 1;
}
//int CapNhatLH(DSCTR &dsctr,char maCT[10])
//{
//	char tenCT[20];
//	NodeCTR *pX = TimCTRTheoMa(dsctr, maCT);
//	cout<<"Cap Nhat Ten Chuong Trinh: "<<endl;
//	gets(pX->chuongtrinh.tenCTr);
////	do
////	{	
////		cout<<"- Nhap Gioi Tinh(0 hoac 1) : "<<endl;
////		cin>>pX->sinhvien.gioiTinh;
////		if(pX->sinhvien.gioiTinh != 0 && pX->sinhvien.gioiTinh != 1){
////			cout<<"Nhap Lai!!!";
////		}
////		else
////			break;
////	}while(true);
//	return 1;
//}



void Nhap1LH(LopHoc &lh,NODEKHOA &t,NODEKHOAHOC &t2,DSCTR &dsctr)
{	
	fflush(stdin);
	cout<<"- Nhap Ma Lop Hoc: ";
	gets(lh.maLop);
	do
	{	
		cout<<"- Nhap ma khoa: ";
		gets(lh.maKhoa);
		NODEKHOA kt =TimKhoaTheoMa(t,lh.maKhoa);
		if(kt==NULL){
			cout<<"Ma Khoa Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	do
	{	
		cout<<"- Nhap ma khoa hoc: ";
		gets(lh.maKhoaHoc);
		NODEKHOAHOC kt =TimKHTheoMa(t2,lh.maKhoaHoc);
		if(kt==NULL){
			cout<<"Ma Khoa Hoc Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	do
	{	
		cout<<"- Nhap ma chuong trinh: ";
		gets(lh.maChuongTrinh);
//		NODEKHOA kt =TimKhoaTheoMa(t,lh.maKhoa);
		NodeCTR* kt = TimCTRTheoMa(dsctr,lh.maChuongTrinh);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	cout<<"- Nhap so thu tu: ";
	cin>>lh.soThuTu;
//	cout<<"- Nhap Ten Chuong Trinh : ";
//	gets(lh.tenCTr);
}
void Xuat1LH(LopHoc lh)
{	
	cout<<"- Ma Lop Hoc: "<<lh.maLop<<endl;
	cout<<"- Ma Khoa: "<<lh.maKhoa<<endl;
	cout<<"- Ma Khoa Hoc : "<<lh.maKhoaHoc<<endl;
	cout<<"- Ma Chuong Trinh : "<<lh.maChuongTrinh<<endl;	
	cout<<"- So Thu Tu : "<<lh.soThuTu<<endl;
//	cout<<" ____________________________________________"<<endl;
//	cout<<"|    Ma Chuong Trinh  |    Ten Chuong Trinh  |"<<endl;
//	cout<<"|_____________________|______________________|"<<endl;
//	cout<<"|"<<ctr.MaCTr<<"                  "<<ctr.tenCTr<<"                   |"<<endl;
//	cout<<"|_____________________|______________________|"<<endl;
//	cout<<"|_____________________|______________________|";
}

void NhapNhieuLH(DSLH &dslh,NODEKHOA &t,NODEKHOAHOC &t2,DSCTR &dsctr)
{
	int tt = 1;
	LopHoc lh;
//	InitLH(dslh);
	do 
	{
		cout<<"Nhap Thong Tin Lop Hoc: \n";
		Nhap1LH(lh,t,t2,dsctr);
		NodeLopHoc* pNew = TaoNodeLH(lh);
		AddHeadLH(dslh, pNew);
		cout<<"Tiep tuc nhap (0/1)?: "<<endl;
		cin>>tt;
		if(tt==0)
			break;
	} while(1);
}
void XuatNhieuLH(DSLH dslh)
{
	NodeLopHoc *p = dslh.head;
	while(p)
	{
		Xuat1LH(p->lophoc);
		cout<<"\n";
		p = p->pNext;
	}
}

void DocFileLopHocNhiPhan(DSLH &dslh){
	
	fstream fileIn("DSLH.txt", ios::in|ios::binary);
	LopHoc lh;
	while(fileIn.read(reinterpret_cast<char *>(&lh),sizeof(LopHoc))){
		NodeLopHoc *node = TaoNodeLH(lh);
		AddHeadLH(dslh, node);
	}
}

void GhiFileLopHocNhiPhan(DSLH dslh){
	LopHoc lh;
	fstream fileOut("DSLH.txt", ios::out|ios::binary);
	for(NodeLopHoc* p=dslh.head;p!=NULL;p=p->pNext){
		fileOut.write(reinterpret_cast<char *>(&p->lophoc),sizeof(LopHoc));
	}
}

void DocFileLH(DSLH &dslh) {
	
	string data;
	fstream f; 
	f.open("DSLOPHOC.txt", ios::in);
	if(f == NULL) return;

	while(!f.eof()) {
		
		LopHoc lophoc;
		getline(f,data);
		if(data.size() == 0) break;
		strcpy(lophoc.maLop, data.c_str());
		
		getline(f,data);	strcpy(lophoc.maKhoa, data.c_str());
		getline(f,data);	strcpy(lophoc.maKhoaHoc, data.c_str());
		getline(f,data);	strcpy(lophoc.maChuongTrinh, data.c_str());
		
//		f.ignore();
		f >> lophoc.soThuTu;
		f.ignore();
		NodeLopHoc *node = TaoNodeLH(lophoc);
		AddHeadLH(dslh, node);
	}
	f.close();
}

void GhiFileLH(DSLH dslh) {
	fstream f;
	f.open("DSLOPHOC.txt", ios::out);
	while(dslh.head!=NULL){
		f << dslh.head->lophoc.maLop << endl ;
		f << dslh.head->lophoc.maKhoa << endl ;
		f << dslh.head->lophoc.maKhoaHoc << endl ;
		f << dslh.head->lophoc.maChuongTrinh << endl ;
		f << dslh.head->lophoc.soThuTu << endl ;
		dslh.head = dslh.head->pNext;
	}
	
	f.close();
}
