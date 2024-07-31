#include <iostream>
//Giai thuat mang 100 phan tu neu chon sv 30 gv 30 thi dn chi cho phep chon toi da 40.
using namespace std;
class doituong;
class daihoctaichinhmarketing
{
private:
    int i = 0;
    static const int n = 100;//Problem use static because the compiler did not know value of variable n in array dt[n] at compile time int main() daihoctaichinhmarekting dhtcm; dhtcm.nhap(). The variable int n = 3 did not run in compile time when instances dhtcm.nhap(). Solution is we use static const int n = 3 to share it for all instances of class, at this time in main() function when run and class instance dhtcm.nhap() because the variable n is already shared in all instances, so compile time will understand the variable n and put it for size of array.
    //static const int n = 3; defines a compile-time(compile time is change source code to byte code, example change source code int n = 3; to byte bit 00000001) constant. Static int n = 3; defines a runtime(runtime is run program. Example run program and input a = 1; b = 1; kq = a + b; output is 2).
    //Conclusion: 1. Const because define a compiletime, at compile time they need to know the variable n to put it in array *dt[n]. 2.Static because at compile time dhtcm.nhap() they do not understand the variable n in instance dhtcm because variable n is not shared for all instance of class it is only in in class daihoctaichinhmarketing, so we need to use static to shared it for all instances of class . And when run program compile time instances dhtcm.nhap(), compiler will understand variable n because they already shared for all instances like dhtcm of class daihoctaichinhmarketing.
    doituong *dt[n];//Dùng con trỏ *dt để đa xạ. Đa xạ là cơ chế thực hiện thông qua con trỏ đối tượng.
    int soluongsinhvien;
    int soluonggiangvien;
    int soluongdoanhnghiep;
public:
    void nhap();
    void xuat();
};
class doituong
{
protected:
    string maso;
    string hoten;
public:
    virtual void nhap();
    virtual void xuat();
};
class sinhvien:public doituong
{
public:
    void nhap();
    void xuat();
};
class giangvien:public doituong
{
public:
    void nhap();
    void xuat();
};
class doanhnghiep:public doituong
{
public:
    void nhap();
    void xuat();
};
int main()
{
    cout << "Quan ly sinh vien thuc hanh nghe nghiep " << endl;
    daihoctaichinhmarketing dhtcm;
    dhtcm.nhap();
    dhtcm.xuat();
    return 0;
}
void daihoctaichinhmarketing::nhap()
{

    cout << "Nhap so luong sinh vien tham gia ky thuc tap: ";
    cin >> soluongsinhvien;
    while((soluongsinhvien<0)||((n-soluongsinhvien)<0))
    {
        cout << "Loi vuot gioi han mang, vui long nhap so luong tu 0 den " << n << endl;
        cout << "Nhap so luong sinh vien tham gia ky thuc tap: ";
        cin >> soluongsinhvien;
    }
    for (int dieukien = 0; dieukien < soluongsinhvien;dieukien++)
    {
        dt[i]= new sinhvien;
        dt[i]->nhap();
        i++;
    }
    cout << "Nhap so luong giang vien tham gia ky thuc tap: ";
    cin >> soluonggiangvien;
    while((soluonggiangvien<0)||((n-(soluongsinhvien+soluonggiangvien))<0))
    {
        cout << "Loi vuot gioi han mang, vui long nhap so luong tu 0 den " << (n-soluongsinhvien) << endl;
        cout << "Nhap so luong giang vien tham gia ky thuc tap: ";
        cin >> soluonggiangvien;
    }
    for (int dieukien = 0; dieukien < soluonggiangvien;dieukien++)
    {
        dt[i] = new giangvien;
        dt[i]->nhap();
        i++;
    }
    cout << "Nhap so luong doanh nghiep tham gia ky thuc tap: ";
    cin >> soluongdoanhnghiep;
    while((soluongdoanhnghiep<0)||(n -(soluongsinhvien+soluonggiangvien+soluongdoanhnghiep) < 0))
    {
        cout << "Loi vuot gioi han mang, vui long nhap so luong tu 0 den " << (n - (soluongsinhvien+soluonggiangvien)) << endl;
        cout << "Nhap so luong doanh nghiep tham gia ky thuc tap: ";
        cin >> soluongdoanhnghiep;
    }
    for (int dieukien = 0; dieukien < soluongdoanhnghiep;dieukien++)
    {
        dt[i] = new doanhnghiep;
        dt[i]->nhap();
        i++;
    }
}
void daihoctaichinhmarketing::xuat()
{
   for(int j = 0; j<i;j++)
   {
      dt[j]->xuat();
   }
}
void doituong::nhap(){}
void doituong::xuat(){}
void sinhvien::nhap()
{
    cout << "Nhap ma so sinh vien: ";
    cin >> maso;
    cout << "Nhap ho ten sinh vien: ";
    cin >> hoten;
}
void sinhvien::xuat()
{
    cout << "Ma so sinh vien la: " << maso << endl;
    cout << "Ho ten sinh vien la: " << hoten << endl;
}
void giangvien::nhap()
{
    cout << "Nhap ma so giang vien: ";
    cin >> maso;
    cout << "Nhap ho ten giang vien: ";
    cin >> hoten;
}
void giangvien::xuat()
{
    cout << "Ma so giang vien la: " << maso << endl;
    cout << "Ho ten giang vien la: " << hoten << endl;
}
void doanhnghiep::nhap()
{
    cout << "Nhap ma so doanh nghiep: ";
    cin >> maso;
    cout << "Nhap ho ten doanh nghiep: ";
    cin >> hoten;
}
void doanhnghiep::xuat()
{
    cout << "Ma so doanh nghiep la: " << maso << endl;
    cout << "Ho ten doanh nghiep la: " << hoten << endl;
}
