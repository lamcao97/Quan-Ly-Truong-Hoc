#include<iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "MonHoc.h"
#include "SinhVien.h"
#pragma once
using namespace std;

struct KetQua {
	char MaSV[10];
	char MaMH[10];
	float diem;
	int lanThi;
};

struct NodeKetQua
{
	KetQua ketqua;
	NodeKetQua *pNext;
};
typedef struct NodeKetQua* NODEKETQUA;

struct DSKQ{
	NodeKetQua *head, *tail;
};

void InitKQ(DSKQ &dskq)
{
	dskq.head = dskq.tail = NULL;
}
int IsEmptyKQ(DSKQ dskq)
{
	if (dskq.head == NULL)
		return 1;
	return 0;
}

NodeKetQua* TaoNodeKQ(KetQua kq){
   NodeKetQua* node = new NodeKetQua;
   if (node) {
      node->ketqua = kq;
      node->pNext = NULL;
   }
   return node;
   
}

void AddHeadKQ(DSKQ &dskq, NodeKetQua* pNew)
{
	if (IsEmptyKQ(dskq))
	{
		dskq.head = dskq.tail = pNew;
	}
	else
	{
		pNew->pNext = dskq.head;
		dskq.head = pNew;
	}
}
void AddTailKQ(DSKQ &dskq, NodeKetQua* node) {
   if (!dskq.head)
      dskq.head = dskq.tail = node;
   else {
      dskq.tail->pNext = node;
      dskq.tail = node;
   }
}
 
void AddAfterKQ(DSKQ &dskq, NodeKetQua *node){
	NodeKetQua *pos;		//vi tri node truoc
	for(NodeKetQua *p = dskq.head; p != NULL; p = p ->pNext) {
		if(node->ketqua.diem < p->ketqua.diem) {
		break;	
		}
		pos = p;
	}
	node->pNext=pos->pNext;
	pos->pNext=node;
}


void Nhap1KQ(KetQua &kq,NODEMH &t,DSSV &dssv)
{	
	fflush(stdin);
	do
	{	
		cout<<"- Nhap ma sinh vien: ";
		gets(kq.MaSV);
//		NODEKHOA kt =TimKhoaTheoMa(t,lh.maKhoa);
		NodeSV* kt = TimSVTheoMa(dssv,kq.MaSV);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	do
	{	
		cout<<"- Nhap ma mon hoc: ";
		gets(kq.MaMH);
//		NODEKHOA kt =TimKhoaTheoMa(t,lh.maKhoa);
		NodeMH* kt = TimKHTheoMaMH(t,kq.MaMH);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	cout<<"- Nhap diem cua sinh vien: ";
	cin>>kq.diem;
	cout<<"- Nhap so lan thi: ";
	cin>>kq.lanThi;
	
}
void Xuat1KQ(KetQua kq)
{
	cout<<"- Ma so sinh vien : "<<kq.MaSV<<endl;
	cout<<"- Ma so mon hoc : "<<kq.MaMH<<endl;
	cout<<"- Diem mon hoc : "<<kq.diem<<endl;
	cout<<"- Lan Thi : "<<kq.lanThi<<endl;
}

//void Nhap1SVVaoDS(DSSV &dssv,DSLH &dslh){
//	
//	fflush(stdin);
//	SinhVien sv;
////	InitSV(dssv);
//	
//	Nhap1SV(sv,dslh);
//	
//	NodeSV* pNew = TaoNodeSV(sv);
//	AddHeadSV(dssv, pNew);
////	if(dssv.head == NULL || (strcmp(dssv.head->sinhvien.MaSV, sv.MaSV) > 0)){
////		AddHeadSV(dssv, pNew);
////	}
////	else if((strcmp(dssv.tail->sinhvien.MaSV, sv.MaSV) < 0)){
////		AddTailSV(dssv, pNew);
////	}
////	else{
////		AddAfterSV(dssv, pNew);
////	}
//	
//}

void NhapNhieuKQ(DSKQ &dskq,NODEMH &t,DSSV &dssv)
{	
//	fflush(stdin);
	int tt = 1;
	KetQua kq;
	do 
	{
		fflush(stdin);
		cout<<"Nhap Thong Tin Ket Qua: \n";

		Nhap1KQ(kq,t,dssv);
		NodeKetQua* pNew = TaoNodeKQ(kq);
		AddHeadKQ(dskq,pNew);
//		if(dskq.head == NULL || (dskq.head->ketqua.diem > kq.diem) )){
//			AddHeadKQ(dskq, pNew);
//			}
//		else if(dskq.head->ketqua.diem < kq.diem)){
//			AddTailKQ(dskq, pNew);
//			}
//		else{
//			AddAfterSV(dssv, pNew);
//			}
		cout<<"Tiep tuc nhap (0/1)?: "<<endl;
		cin>>tt;
		if(tt==0)
			break;
	} while(1);
		
}

void XuatNhieuKQ(DSKQ dskq)
{
	
	if(dskq.head ==NULL){
		cout<<"Danh sach rong!!!!"<<endl;
	}
	else{
		NodeKetQua *p = dskq.head;
		while(p)
		{
			Xuat1KQ(p->ketqua);
			cout<<"\n";
			p = p->pNext;
		}
	}
	
}

void DocFileKetQuaNhiPhan(DSKQ &dskq){
	
	fstream fileIn("DSKQ.txt", ios::in|ios::binary);
	KetQua kq;
	while(fileIn.read(reinterpret_cast<char *>(&kq),sizeof(KetQua))){
		NodeKetQua *node = TaoNodeKQ(kq);
		AddHeadKQ(dskq, node);
	}
}

void GhiFileKetQuaNhiPhan(DSKQ dskq){
	KetQua kq;
	fstream fileOut("DSKQ.txt", ios::out|ios::binary);
	for(NodeKetQua* p=dskq.head;p!=NULL;p=p->pNext){
		fileOut.write(reinterpret_cast<char *>(&p->ketqua),sizeof(KetQua));
	}
}

void DocFileKQ(DSKQ &dskq) {
	
	string data;
	fstream f; 
	f.open("DSKETQUA.txt", ios::in);
	if(f == NULL) return;
	while(!f.eof()) {
		
		KetQua kq;
		getline(f,data);
		if(data.size() == 0) break;
		strcpy(kq.MaSV, data.c_str());
		
		getline(f,data);	strcpy(kq.MaMH, data.c_str());
//		getline(f,data);	strcpy(sinhvien.maLop, data.c_str());
//		getline(f,data);	strcpy(sinhvien.namSinh, data.c_str());
//		getline(f,data);	strcpy(sinhvien->gioiTinh, data.c_str());
		
		f >> kq.diem;
		
		f >> kq.lanThi;
		
		f.ignore();
		NodeKetQua *node = TaoNodeKQ(kq);
		
		AddHeadKQ(dskq, node);
		
	}
	f.close();
}
void GhiFileKQ(DSKQ dskq) {
	fstream f;
	f.open("DSKETQUA.txt", ios::out);
	while(dskq.head!=NULL){
		f << dskq.head->ketqua.MaSV << endl ;
		f << dskq.head->ketqua.MaMH << endl ;
		f << dskq.head->ketqua.diem << endl ;
		f << dskq.head->ketqua.lanThi << endl ;
		dskq.head = dskq.head->pNext;
	}
	
	f.close();
}
