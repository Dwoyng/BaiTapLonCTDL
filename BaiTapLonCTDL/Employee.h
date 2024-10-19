#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "Date.h"
using namespace std;



struct Employee {
	string Name;
	string MaNhanVien;
	string PhongBan;
	Date Birth;
	string ChucVu;
	string SoDienThoai;
	
	Employee&  operator=(const Employee& b) {
		Name = b.Name;
		MaNhanVien = b.MaNhanVien;
		PhongBan = b.PhongBan;
		Birth = b.Birth;
		ChucVu = b.ChucVu;
		SoDienThoai = b.SoDienThoai;
}
	
};

void InitEmployee(Employee& a) {
	a.MaNhanVien = a.ChucVu = a.Name = a.PhongBan = a.SoDienThoai = " ";
	InitDate(a.Birth);
}

void CinE(Employee& a) {
	cout << "Nhap ho va ten: ";
	cin.ignore();
	getline(cin, a.Name);
	cout << '\n';
	cout << "Nhap ngay sinh:";
	int d, m, y;
	cin >> d >> m >> y;
	SetDate(a.Birth, d, m, y);
	cout << '\n';
	cout << "Nhap chuc vu: ";
	cin.ignore();
	getline(cin, a.ChucVu);
	cout << '\n';
	cout << "Nhap ma nhan vien: ";
	cin.ignore();
	getline(cin, a.MaNhanVien);
	cout << '\n';
	cout << "Nhap so dien thoai: ";
	cin.ignore();
	getline(cin, a.SoDienThoai);
	cout << '\n';
	cout << "Nhap phong ban: ";
	cin.ignore();
	getline(cin, a.PhongBan);
	cout << '\n';
}

string SearchingDepartment(Employee& a) {
	switch (a.MaNhanVien[0])
	{
	case 'K': return "KinhDoanh";
	case 'N': return "NhanSu";
	case'H': return "KinhDoanh";
	default:
		break;
	}
}

void CinInfEmployee(Employee& a) {
	string outline = SearchingDepartment(a);
	int day = a.Birth.Day;
	int month = a.Birth.Month;
	int year = a.Birth.Year;
	string name = a.Name;
	CinE(a);
	ofstream file;
	file.open("C:\\Users\\ADMIN\\Arduino IDE\\BaiTapLonCTDL\\" + outline + "\\" + name, ios::app);
	if (file.is_open()) {
		file << a.Name << endl
			<< a.ChucVu << endl
			<< day << '/' << month << '/' << year << endl
			<< a.MaNhanVien << endl
			<< a.PhongBan << endl
			<< a.SoDienThoai << endl;
		file.close();
		cout << "Ghi thanh cong!";
	}
	else {
		"Khong tim thay phong nay!";
	}
}

void CoutE(Employee& a) {
	cout << "Ho va Ten: " << a.Name << endl
		<< "Chuc Vu: " << a.ChucVu << endl
		<< "Ma Nhan Vien; " << a.MaNhanVien << endl
		<< "Phong: " << a.PhongBan << endl
		<< "Ngay Sinh: "; CoutDate(a.Birth); cout << endl;
	cout << "So Dien Thoai: " << a.SoDienThoai << endl;
}

bool operator==(const Employee& a, const Employee& b) {
	if (a.Birth == b.Birth && a.ChucVu == b.ChucVu && a.MaNhanVien == b.MaNhanVien && a.Name == b.Name && a.PhongBan == b.PhongBan && a.SoDienThoai == b.SoDienThoai) return true;
	return false;
}
