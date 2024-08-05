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
    //Compile time before runtime.
    //Conclusion: 1. const because variable n will understand at compile time, static because share it for all instance in class for when run program int main() daihoctaichinhmarketing dhtcm.nhap() they will understand variable n = 100 because already share via static.
    static doituong *dt[n];//Dùng con trỏ *dt để đa xạ. Đa xạ là cơ chế thực hiện thông qua con trỏ đối tượng.
    //static doituong *dt[n]. Use static because if i want to call dt = dhtcm.laydt() in class sinhvien. However instance dhtcm is not inherited by sinhvien, so we use static to saved dt as a global variable of class daihoctaichinhmarketing and when we call to get, we get that global variable of class daihoctaichinhmarketing, not instance variable. Instance variable non static is use for class sinhvien in inherited from class daihoctaichinhmarketing.
    static int soluongsinhvien;//When using static if i want to call method getsoluongsinhvien(), i need to use daihoctaichinhmarketing::getsoluongsinhvien() instead of using daihoctaichinhmarketing dhtcm.getsoluongsinhvien(). Because static is global variable in class so use daihoctaichinhmarekting::getsoluongsinhvien to global variable soluongsinhvien of class daihoctaichinhmarketing instead of not using static is for local variable of each instance of class daihoctaichinhmarketing, instance i using daihoctaichinhmarketing dhtcm.getsoluongsinhvien(), dhtcm is a instance.
    static int soluonggiangvien;
    static int soluongdoanhnghiep;
    static int soluongdangkythuctap;
    doituong* sv[n];
    doituong* gv[n];
    doituong* dn[n];
public:
    void nhap();
    void xuat();
    void dangky();
    bool timkiemtheomaso(string);
    static int laysoluongsinhvien();
    static int laysoluonggiangvien();
    static int laysoluongdoanhnghiep();
    static doituong** laydt();
};
class doituong
{
protected:
    string maso;
    string hoten;
public:
    virtual void nhap();
    virtual void xuat();
    virtual string laymaso();
    virtual string layhoten();
    virtual string taomasosinhvien(string&);
    virtual string taohotensinhvien(string&);
    virtual string taomasogiangvien(string&);
    virtual string taohotengiangvien(string&);
    virtual string taomasodoanhnghiep(string&);
    virtual string taohotendoanhnghiep(string&);
};
class sinhvien:public doituong
{
public:
    void nhap();
    void xuat();
    string laymaso();
    string layhoten();
    string taomasosinhvien(string&);
    string taohotensinhvien(string&);
};
class giangvien:public doituong
{
public:
    void nhap();
    void xuat();
    string laymaso();
    string layhoten();
    string taomasogiangvien(string&);
    string taohotengiangvien(string&);
};
class doanhnghiep:public doituong
{
public:
    void nhap();
    void xuat();
    string laymaso();
    string layhoten();
    string taomasodoanhnghiep(string&);
    string taohotendoanhnghiep(string&);

};
int daihoctaichinhmarketing::soluongsinhvien = 0;//Why?
int daihoctaichinhmarketing::soluonggiangvien = 0;
int daihoctaichinhmarketing::soluongdoanhnghiep = 0;
int daihoctaichinhmarketing::soluongdangkythuctap = 0;
doituong* daihoctaichinhmarketing::dt[n] = {nullptr};//Initialize all elements of array to nullptr.
int main()
{
    cout << "Quan ly sinh vien thuc hanh nghe nghiep " << endl;
    daihoctaichinhmarketing dhtcm;
    dhtcm.nhap();
    dhtcm.dangky();
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
   cout << "Danh sach thuc hanh nghe nghiep la: " << endl;
   for(int i=0;i<soluongdangkythuctap;i++)
   {
       sv[i]->xuat();
       gv[i]->xuat();
       dn[i]->xuat();

   }
}
void daihoctaichinhmarketing::dangky()
{
    string masosinhvien;
    string masogiangvien;
    string masodoanhnghiep;
    cout << "Nhap so luong dang ky thuc tap: ";
    cin >> soluongdangkythuctap;
    //Kiemtra.
    for(int i=0;i<soluongdangkythuctap;i++)
    {
        cout << "Chon ma so sinh vien can dang ky: ";
        cin >> masosinhvien;
        if(timkiemtheomaso(masosinhvien)==1)
        {
            sv[i] = new sinhvien;//When init doituong* dk[i] it is a null pointer which is not allocate memory(0x00ff) so when i call method taomasosinhvien() they do not understand which memory to call for method taomasosinhvien(), so i need to allocate memory first by using doituong* dk[n] = new sinh vien; In this time var dk[n] will allocate memory and when i call method taomasosinhvien(), it is work because they understand which memory to call for method taomasosinhvien().
            sv[i]->taomasosinhvien(masosinhvien);
            sv[i]->taohotensinhvien(masosinhvien);
        }
        cout << "Chon ma so giang vien can dang ky: ";
        cin >> masogiangvien;
        if(timkiemtheomaso(masogiangvien)==1)
        {
            gv[i] = new giangvien;
            gv[i]->taomasogiangvien(masogiangvien);
            gv[i]->taohotengiangvien(masogiangvien);
        }
        cout << "Chon ma so doanh nghiep can dang ky: ";
        cin >> masodoanhnghiep;
        if(timkiemtheomaso(masodoanhnghiep)==1)
        {
            dn[i] = new doanhnghiep;
            dn[i]->taomasodoanhnghiep(masodoanhnghiep);
            dn[i]->taohotendoanhnghiep(masodoanhnghiep);
        }
    }

}
bool daihoctaichinhmarketing::timkiemtheomaso(string masotimkiem)
{
    for(int i = 0;i<(soluongsinhvien+soluonggiangvien+soluongdoanhnghiep);i++)
    {
        if(dt[i]->laymaso()==masotimkiem)
            return 1;
    }
    return 0;
}
int daihoctaichinhmarketing::laysoluongsinhvien()
{
    return soluongsinhvien;
}
int daihoctaichinhmarketing::laysoluonggiangvien()
{
    return soluonggiangvien;
}
int daihoctaichinhmarketing::laysoluongdoanhnghiep()
{
    return soluongdoanhnghiep;
}
doituong** daihoctaichinhmarketing::laydt()
{
    return dt;
}
void doituong::nhap(){}
void doituong::xuat(){}
string doituong::laymaso(){}
string doituong::layhoten(){}
string doituong::taomasosinhvien(string& masosinhvien){}
string doituong::taohotensinhvien(string& masosinhvien){}
string doituong::taomasogiangvien(string& masogiangvien){}
string doituong::taohotengiangvien(string& masogiangvien){}
string doituong::taomasodoanhnghiep(string& masodoanhnghiep){}
string doituong::taohotendoanhnghiep(string& hotendoanhnghiep){}
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
string sinhvien::laymaso()
{
    return maso;
}
string sinhvien::layhoten()
{
    return hoten;
}
string sinhvien::taomasosinhvien(string& masosinhvien)
{
    maso = masosinhvien;
    return maso;
}
string sinhvien::taohotensinhvien(string& masosinhvien)
{
    daihoctaichinhmarketing dhtcm;
    doituong** dt;
    dt = dhtcm.laydt();
    for(int i = 0;i<(daihoctaichinhmarketing::laysoluongsinhvien()+daihoctaichinhmarketing::laysoluongdoanhnghiep()+daihoctaichinhmarketing::laysoluonggiangvien());i++)
    {
        if(dt[i]->laymaso()==masosinhvien)
            hoten = dt[i]->layhoten();
    }
    return hoten;
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
string giangvien::laymaso()
{
    return maso;
}
string giangvien::layhoten()
{
    return hoten;
}
string giangvien::taomasogiangvien(string& masogiangvien)
{
    maso = masogiangvien;
    return maso;
}
string giangvien::taohotengiangvien(string& masogiangvien)
{
    daihoctaichinhmarketing dhtcm;
    doituong** dt;
    dt = dhtcm.laydt();
    for(int i = 0;i<(daihoctaichinhmarketing::laysoluongsinhvien()+daihoctaichinhmarketing::laysoluongdoanhnghiep()+daihoctaichinhmarketing::laysoluonggiangvien());i++)
    {
        if(dt[i]->laymaso()==masogiangvien)
            hoten = dt[i]->layhoten();
    }
    return hoten;
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
string doanhnghiep::laymaso()
{
    return maso;
}
string doanhnghiep::layhoten()
{
    return hoten;
}
string doanhnghiep::taomasodoanhnghiep(string& masodoanhnghiep)
{
    maso = masodoanhnghiep;
    return maso;
}
string doanhnghiep::taohotendoanhnghiep(string& masodoanhnghiep)
{
    daihoctaichinhmarketing dhtcm;
    doituong** dt;
    dt = dhtcm.laydt();
    for(int i = 0;i<(daihoctaichinhmarketing::laysoluongsinhvien()+daihoctaichinhmarketing::laysoluongdoanhnghiep()+daihoctaichinhmarketing::laysoluonggiangvien());i++)
    {
        if(dt[i]->laymaso()==masodoanhnghiep)
            hoten = dt[i]->layhoten();
    }
    return hoten;
}
//Kết luận:
//- Quy trình: Khi tới đợt thực hành nghề nghiệp, khoa cntt sẽ chọn danh sách sinh viên,mời giảng viên hướng dẫn,mời doanh nghiệp tham gia kỳ thực hành nghề nghiệp. Sau đó, sinh viên đăng ký giảng viên, doanh nghiệp mà mình mong muốn. Cuối cùng, tổng hợp danh sách thực hành nghề nghiệp bao gồm sinh viên đăng ký giảng viên nào, doanh nghiệp nào.
//- Sơ đồ lớp: https://app.diagrams.net/#Hphuochogit%2FQuanlysinhvienthuchanhnghenghiep%2Fmaster%2FQuanlysinhvienthuchanhnghenghiep.drawio#%7B%22pageId%22%3A%22C5RBs43oDa-KdzZeNtuy%22%7D.
//- Sử dụng cơ chế đa xạ trong việc nhập, xuất, đăng ký.
