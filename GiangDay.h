#include<iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "ChuongTrinh.h"
#include "Khoa.h"
#include "MonHoc.h"
#pragma once
using namespace std;

struct GiangDay {
	char maCTr[10];
	char maKhoa[10];
	char maMH[10]; 
	int hocKy;
	int namHoc;
	int soTietLT;
	int soTietTH;
	int soTinChi;
};
struct NodeGD
{
	GiangDay giangday;
	NodeGD *pNext;
};
typedef struct NodeGD* NODEGD;

struct DSGD{
	NodeGD *head, *tail;
};

void InitGD(DSGD &dsgd)
{
	dsgd.head = dsgd.tail = NULL;
}
int IsEmptyGD(DSGD dsgd)
{
	if (dsgd.head == NULL)
		return 1;
	return 0;
}

NodeGD* TaoNodeGD(GiangDay gd){
   NodeGD* node = new NodeGD;
   if (node) {
      node->giangday = gd;
      node->pNext = NULL;
   }
   return node;
   
}

void AddHeadGD(DSGD &dsgd, NodeGD* pNew)
{
	if (IsEmptyGD(dsgd))
	{
		dsgd.head = dsgd.tail = pNew;
	}
	else
	{
		pNew->pNext = dsgd.head;
		dsgd.head = pNew;
	}
}
void AddTailGD(DSGD &dsgd, NodeGD* node) {
   if (!dsgd.head)
      dsgd.head = dsgd.tail = node;
   else {
      dsgd.tail->pNext = node;
      dsgd.tail = node;
   }
}
 
//void AddAfterKQ(DSGD &dsgd, NodeKetQua *node){
//	NodeGD *pos;		//vi tri node truoc
//	for(NodeGD *p = dsgd.head; p != NULL; p = p ->pNext) {
//		if(node->giangday.diem < p->ketqua.diem) {
//		break;	
//		}
//		pos = p;
//	}
//	node->pNext=pos->pNext;
//	pos->pNext=node;
//}


void Nhap1GD(GiangDay &gd,DSCTR dsctr,NODEKHOA khoa,NODEMH mh)
{	
	fflush(stdin);
	do
	{	
		cout<<"- Nhap ma chuong trinh: ";
		gets(gd.maCTr);
//		NODEKHOA kt =TimKhoaTheoMa(t,lh.maKhoa);
		NodeCTR* kt = TimCTRTheoMa(dsctr,gd.maCTr);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	do
	{	
		cout<<"- Nhap ma khoa: ";
		gets(gd.maKhoa);
		NodeKHOA* kt = TimKhoaTheoMa(khoa,gd.maKhoa);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	do
	{	
		cout<<"- Nhap ma mon hoc: ";
		gets(gd.maMH);
		NodeMH* kt = TimKHTheoMaMH(mh,gd.maMH);
		if(kt==NULL){
			cout<<"Ma Chuong Trinh Khong Ton Tai!!!!"<<endl;
		}else
			break;
	} while (1);
	
	cout<<"- Nhap hoc ki: ";
	cin>>gd.hocKy;
	cout<<"- Nhap nam hoc: ";
	cin>>gd.namHoc;
	cout<<"- Nhap so tiet ly thuyet: ";
	cin>>gd.soTietLT;
	cout<<"- Nhap so tiet thuc hanh: ";
	cin>>gd.soTietTH;
	cout<<"- Nhap tin chi: ";
	cin>>gd.soTinChi;
}
void Xuat1GD(GiangDay gd)
{
	cout<<"- Ma chuong trinh : "<<gd.maCTr<<endl;
	cout<<"- Ma khoa : "<<gd.maKhoa<<endl;
	cout<<"- Ma mon hoc : "<<gd.maMH<<endl;
	cout<<"- Hoc ki : "<<gd.hocKy<<endl;
	cout<<"- Nam hoc : "<<gd.namHoc<<endl;
	cout<<"- So tiet ly thuyet : "<<gd.soTietLT<<endl;
	cout<<"- So tiet thuc hanh : "<<gd.soTietTH<<endl;
	cout<<"- So tin chi : "<<gd.soTinChi<<endl;
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

void NhapNhieuGD(DSGD &dsgd,DSCTR dsctr,NODEKHOA khoa, NODEMH mh)
{	
//	fflush(stdin);
	int tt = 1;
	GiangDay gd;
	do 
	{
		fflush(stdin);
		cout<<"Nhap Thong Tin Giang Day: \n";

		Nhap1GD(gd,dsctr,khoa,mh);
		NodeGD* pNew = TaoNodeGD(gd);
		AddHeadGD(dsgd,pNew);
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

void XuatNhieuGD(DSGD dsgd)
{
	
	if(dsgd.head ==NULL){
		cout<<"Danh sach rong!!!!"<<endl;
	}
	else{
		NodeGD *p = dsgd.head;
		while(p)
		{
			Xuat1GD(p->giangday);
			cout<<"\n";
			p = p->pNext;
		}
	}
	
}

void DocFileGiangDayNhiPhan(DSGD &dsgd){
	
	fstream fileIn("DSGD.txt", ios::in|ios::binary);
	GiangDay gd;
	while(fileIn.read(reinterpret_cast<char *>(&gd),sizeof(GiangDay))){
		NodeGD *node = TaoNodeGD(gd);
		AddHeadGD(dsgd, node);
	}
}

void GhiFileGiangDayNhiPhan(DSGD dsgd){
	GiangDay gd;
	fstream fileOut("DSGD.txt", ios::out|ios::binary);
	for(NodeGD* p=dsgd.head;p!=NULL;p=p->pNext){
		fileOut.write(reinterpret_cast<char *>(&p->giangday),sizeof(GiangDay));
	}
}

void DocFileGD(DSGD &dsgd) {
	
	string data;
	fstream f; 
	f.open("DSGIANGDAY.txt", ios::in);
	if(f == NULL) return;
	while(!f.eof()) {
		
		GiangDay gd;
		getline(f,data);
		if(data.size() == 0) break;
		strcpy(gd.maCTr, data.c_str());
		
		getline(f,data);	strcpy(gd.maKhoa, data.c_str());
		getline(f,data);	strcpy(gd.maMH, data.c_str());
		
		f >> gd.hocKy;
		
		f >> gd.namHoc;
		
		f >> gd.soTietLT;
		
		f >> gd.soTietTH;
		
		f >> gd.soTinChi;
		
		f.ignore();
		NodeGD *node = TaoNodeGD(gd);
		
		AddHeadGD(dsgd, node);
		
	}
	f.close();
}
void GhiFileGD(DSGD dsgd) {
	fstream f;
	f.open("DSGIANGDAY.txt", ios::out);
	while(dsgd.head!=NULL){
		f << dsgd.head->giangday.maCTr << endl ;
		f << dsgd.head->giangday.maKhoa << endl ;
		f << dsgd.head->giangday.maMH << endl ;
		f << dsgd.head->giangday.hocKy << endl ;
		f << dsgd.head->giangday.namHoc << endl ;
		f << dsgd.head->giangday.soTietLT << endl ;
		f << dsgd.head->giangday.soTietTH << endl ;
		f << dsgd.head->giangday.soTinChi << endl ;		
		
		dsgd.head = dsgd.head->pNext;
	}
	
	f.close();
}
