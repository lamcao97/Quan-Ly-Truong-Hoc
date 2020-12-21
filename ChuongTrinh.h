#include<iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#pragma once

using namespace std;

struct ChuongTrinh {
	char MaCTr[15];
	char tenCTr[30];
};

struct NodeCTR
{
	ChuongTrinh chuongtrinh;
	NodeCTR *pNext;
};
typedef struct NodeCTR* NODECTR;

struct DSCTR{
	NodeCTR *head, *tail;
};

NodeCTR* TaoNodeCTR(ChuongTrinh ctr){
   NodeCTR* node = new NodeCTR;
   if (node) {
      node->chuongtrinh = ctr;
      node->pNext = NULL;
   }
   return node;
}

//---------------------------
 void InitCTR(DSCTR &dsctr)
{
	dsctr.head = dsctr.tail = NULL;
}
int IsEmptyCTR(DSCTR dsctr)
{
	if (dsctr.head == NULL)
		return 1;
	return 0;
}

void AddHeadCTR(DSCTR &dsctr, NodeCTR* pNew)
{
	if (IsEmptyCTR(dsctr))
	{
		dsctr.head = dsctr.tail = pNew;
	}
	else
	{
		pNew->pNext = dsctr.head;
		dsctr.head = pNew;
	}
}

void AddTailCTR(DSCTR &dsctr, NodeCTR* node) {
   if (!dsctr.head)
      dsctr.head = dsctr.tail = node;
   else {
      dsctr.tail->pNext = node;
      dsctr.tail = node;
   }
}
 
void AddAfterCTR(DSCTR &dsctr, NodeCTR* node){
	NodeCTR *pos;		//vi tri node truoc
	for(NodeCTR *p = dsctr.head; p != NULL; p = p ->pNext) {
		if(strcmp(node->chuongtrinh.MaCTr, p->chuongtrinh.MaCTr) < 0) {
		break;	
		}
		pos = p;
	}
	node->pNext=pos->pNext;
	pos->pNext=node;
}

NodeCTR *TimCTRTheoMa(DSCTR dsctr,char maCT[10])
{
	NodeCTR *p = dsctr.head;
	while(p)
	{
		if(strcmp(p->chuongtrinh.MaCTr,maCT)==0)
			return p;
		p=p->pNext;
	}
	return NULL;
}
NodeCTR *TimCTRTheoTen(DSCTR dsctr,char tenCT[10])
{
	NodeCTR *p = dsctr.head;
	while(p)
	{
		if(strcmp(p->chuongtrinh.tenCTr,tenCT)==0)
			return p;
		p=p->pNext;
	}
	return NULL;
}

void HoanVi(ChuongTrinh &a, ChuongTrinh &b)
{
	ChuongTrinh tam=a;
	a=b;
	b=tam;
}
NodeCTR *Min(DSCTR dsctr, NodeCTR *p)
{
	NodeCTR *pMin=p;
	NodeCTR *k=p->pNext;
	while(k)
	{
		if(strcmp(k->chuongtrinh.tenCTr,pMin->chuongtrinh.tenCTr)<0)
		
			pMin=k;
		k=k->pNext;
	}
	return pMin;
}
void Sort(DSCTR &dsctr)
{
	NodeCTR *p=dsctr.head;
	while(p!=dsctr.tail)
	{
		NodeCTR *pMin=Min(dsctr, p);
		HoanVi(p->chuongtrinh, pMin->chuongtrinh);
		p=p->pNext;
	}
}

void DeleteHead(DSCTR &dsctr)
{
	NodeCTR *pDel = dsctr.head;
	dsctr.head = pDel -> pNext;
		
	if(dsctr.head == NULL)
		dsctr.tail = NULL;
	
	free(pDel);
}
NodeCTR *PrevNodeP(DSCTR dsctr, NodeCTR *p)
{
	if(p == dsctr.head)
		return NULL;
	NodeCTR *pTruoc = dsctr.head;
	while(pTruoc->pNext != p)
		pTruoc = pTruoc -> pNext;
	return pTruoc;
}
void DeleteTail(DSCTR &dsctr)
{
	if(dsctr.head==dsctr.tail)
		DeleteHead(dsctr);
	else
	{
		NodeCTR *pDel = dsctr.tail;
		NodeCTR *pTruoc = PrevNodeP(dsctr, pDel);
		pTruoc -> pNext = NULL;
		dsctr.tail = pTruoc;
		free(pDel);
	}
}
void DeleteNode(DSCTR &dsctr, NodeCTR *pDel)
{
	if(pDel==dsctr.head)
		DeleteHead(dsctr);
	else if(pDel==dsctr.tail)
		DeleteTail(dsctr);
	else
	{
		NodeCTR *pPrev=PrevNodeP(dsctr, pDel);
		pPrev->pNext=pDel->pNext;
		free(pDel);
	}	
}

int XoaX(DSCTR &dsctr, char maCT[10])
{
	NodeCTR *pX = TimCTRTheoMa(dsctr, maCT);
	if(pX == NULL)
		return 0;
	DeleteNode(dsctr, pX);
	return 1;
}
int CapNhatCTR(DSCTR &dsctr,char maCT[10])
{
	char tenCT[20];
	NodeCTR *pX = TimCTRTheoMa(dsctr, maCT);
	cout<<"Cap Nhat Ten Chuong Trinh: "<<endl;
	gets(pX->chuongtrinh.tenCTr);
//	do
//	{	
//		cout<<"- Nhap Gioi Tinh(0 hoac 1) : "<<endl;
//		cin>>pX->sinhvien.gioiTinh;
//		if(pX->sinhvien.gioiTinh != 0 && pX->sinhvien.gioiTinh != 1){
//			cout<<"Nhap Lai!!!";
//		}
//		else
//			break;
//	}while(true);
	return 1;
}



void Nhap1CTR(ChuongTrinh &ctr)
{	
	fflush(stdin);
	cout<<"- Nhap Ma Chuong Trinh: ";
	gets(ctr.MaCTr);
	cout<<"- Nhap Ten Chuong Trinh : ";
	gets(ctr.tenCTr);
}
void Xuat1CTR(ChuongTrinh ctr)
{
	cout<<"- Ma Chuong Trinh: "<<ctr.MaCTr<<endl;
	cout<<"- Ten Chuong Trinh : "<<ctr.tenCTr<<endl;
//	cout<<" ____________________________________________"<<endl;
//	cout<<"|    Ma Chuong Trinh  |    Ten Chuong Trinh  |"<<endl;
//	cout<<"|_____________________|______________________|"<<endl;
//	cout<<"|"<<ctr.MaCTr<<"                  "<<ctr.tenCTr<<"                   |"<<endl;
//	cout<<"|_____________________|______________________|"<<endl;
//	cout<<"|_____________________|______________________|";
}

void NhapNhieuCTR(DSCTR &dsctr)
{
	int tt = 1;
	ChuongTrinh ctr;
//	InitCTR(dsctr);
	do 
	{
		cout<<"Nhap Thong Tin Sinh Vien: \n";
		Nhap1CTR(ctr);
		NodeCTR* pNew = TaoNodeCTR(ctr);
		AddHeadCTR(dsctr, pNew);
		cout<<"Tiep tuc nhap (0/1)?: "<<endl;
		cin>>tt;
		if(tt==0)
			break;
	} while(1);
}
void XuatNhieuCTR(DSCTR dsctr)
{
	NodeCTR *p = dsctr.head;
	while(p)
	{
		Xuat1CTR(p->chuongtrinh);
		cout<<"\n";
		p = p->pNext;
	}
}

void DocFileChuongTrinhNhiPhan(DSCTR &dsctr){
	
	fstream fileIn("DSCT.txt", ios::in|ios::binary);
	ChuongTrinh ctr;
	while(fileIn.read(reinterpret_cast<char *>(&ctr),sizeof(ChuongTrinh))){
		NodeCTR *node = TaoNodeCTR(ctr);
		AddHeadCTR(dsctr, node);
	}
}

void GhiFileChuongTrinhNhiPhan(DSCTR dsctr){
	ChuongTrinh ctr;
	fstream fileOut("DSCT.txt", ios::out|ios::binary);
	for(NodeCTR* p=dsctr.head;p!=NULL;p=p->pNext){
		fileOut.write(reinterpret_cast<char *>(&p->chuongtrinh),sizeof(ChuongTrinh));
	}
}

void DocFileChuongTrinh(DSCTR &dsctr) {
	string data;
	fstream f; 
	f.open("DSCTR.txt", ios::in);
	if(f == NULL) return;
	while(!f.eof()) {
		
		ChuongTrinh chuongtrinh;
		getline(f,data);
		if(data.size() == 0) break;
		strcpy(chuongtrinh.MaCTr, data.c_str());
		
		getline(f,data);	strcpy(chuongtrinh.tenCTr, data.c_str());

//		f.ignore();
		NodeCTR *node = TaoNodeCTR(chuongtrinh);
		AddTailCTR(dsctr, node);
	}
	f.close();
}

void GhiFileChuongTrinh(DSCTR dsctr) {
	fstream f;
	f.open("DSCTR.txt", ios::out);
	while(dsctr.head!=NULL){
		f << dsctr.head->chuongtrinh.MaCTr << endl ;
		f << dsctr.head->chuongtrinh.tenCTr << endl ;
		dsctr.head = dsctr.head->pNext;
	}
	
	f.close();
}
