#include<iostream>
#include<string.h>
#include "DoubleLinkedListh.h"
#include "Date.h"
#include "Employee.h"

Employee a{ "Thai Tuan Duong", "H20223927", "Hanh Chinh", Date{18,8,2004}, "Nhan vien", "0915963236"};
Employee b{ "Nguyen Minh Quan", "K20224109", "Kinh Doanh", Date{17,10,2004}, "Truong Phong", "091231233" };
Employee c{ "Truong Thanh Phong", "N20222134", "Nhan Su", Date{9,5,2004}, "Pho Truong Phong", "0356234678" };
Employee d{ "Dinh Tuan Anh", "H20223844", "Hanh Chinh", Date{19,8,2004}, "Nhan vien", "0231321323" };
Employee e{ "Ho Quoc Khanh", "K20227621", "Kinh Doanh", Date{11,12,2004}, "Nhan vien", "0432456487" };
Employee f{ "Dang Duc Thinh", "H20227293", "Nhan Su", Date{30,4,2004}, "Truong Phong", "0231233123" };

void Menu(DoubleLinkedList& H) {
	while (1) {
		cout << "1. Them nhan vien";
		cout << "2. Lay thong tin nhan vien bang ma nhan vien";
		cout << "3. Xoa nhan vien";
		cout << "4. Hien thi toan bo danh sach nhan vien";

		int m;
		cout << "Nhap lua chon: ";  cin >> m;
		switch (m)
		{

		case 1: {
			Employee a;
			InitEmployee(a);
			CinInfEmployee(a);
			Node* P = MakeNode(a);
			InsertBegin(H, P->employee);
			break;
		}

		case 2: {
			string s;
			cout << "Nhap ma nhan vien: "; cin >> s;
			Node* P = H.Head;
			while (P->nextR)
			{
				if (P->employee.MaNhanVien == s) { 
					CoutE(P->employee); 
					break;
				}
				P = P->nextR;
			}
			if (P->employee.MaNhanVien == s) { 
				CoutE(P->employee); 
				break;
			}
			cout << "Nhap thanh cong!";
		}

		case 3: {
			string s;
			cout << "Vui long nhap ma nhan vien muon xoa: "; cin >> s;
			Node* P = H.Head;
			while (P->nextR) {
				if (P->employee.MaNhanVien == s) {
					DeleteSelected(H, P);
					break;
				}
				P = P->nextR;
			}
			if (P->employee.MaNhanVien == s) {
				DeleteSelected(H, P);
				break;
			}
			cout << "Khong tim thay nhan vien nay!";
		}

		case 4: {
			Node* P = H.Head;
			while (P->nextR) {
				CoutE(P->employee);
				P = P->nextR;
			}
			CoutE(P->employee);
			break;
		}

		default:
			cout << "Vui long nhap lai yeu cau!";
			break;
		}

	}
}

int main() {
	DoubleLinkedList DL;
	InitDoubleLinkedList(DL);
	InsertBegin(DL, a);
	InsertBegin(DL, b);
	InsertBegin(DL, c);
	InsertBegin(DL, d);
	InsertBegin(DL, e);
	InsertBegin(DL, f);
	Menu(DL);
}