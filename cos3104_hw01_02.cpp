#include <iostream>
using namespace std;

int m = 5000;
int n = 1024;

void f(int i){
    int* x = new int[m*n]; //(int size = 4bytes)

    if( x == NULL) return;
    cout << "Count "<< i << " : " << m << "k : begin " << x << endl;
    f(i+1);
}

int main(){
    f(0);
    return 0;
}


/*
    result : 
    -   เรียกใช้ f(i) โดยฟังก์ชั่นเรียกใช้ซ้ำ (recursive) ได้ 100 รอบ 
        แล้วโปรแกรมจบการทำงาน พร้อมข้อความเตือนว่า
        terminate called after throwing an instance of 'std::bad_alloc'
        what():  std::bad_alloc

    analyze :
    -   โปรแกรมเรียกใช้ฟังก์ชั่น f(i) โดยภายในฟังก์ชั่น มีคำสั่งประกาศตัวแปร pointer array int 
        โดยจองจำนวน 5,000k ช่อง และเรียกใช้ฟังกชั่นซ้ำ อีก i+1 ครั้ง 
        ทำให้ฟังก์ชั่นมีการประกาศตัวแปร pointer array int อีกจำนวน 5,000k แล้วเรียกใช้ฟังก์ชั่นซ้ำอีกไปเรื่อย ๆ
        จนโปรแกรมเรียกใช้ซ้ำได้ 100 รอบ ก่อนจบการทำงาน พร้อมข้อความ std::bad_alloc

    -   รวมจำนวน array int ได้ 100*5,000k ช่อง (int size = 4bytes : 4*(100*5,000k) = 2,000,000kb ~ 2Gb)

    -   เนื่องจากคำสั่งประกาศตัวแปร pointer array int เป็นคำสั่งที่มองตัวแปรเป็น object โดยเข้าใช้พื้นที่ส่วน heap
        สาเหตุที่โปรแกรมวนเรียกใช้งานฟังก์ชั่นได้เพียง 100 รอบ
        เพราะ lifetime ของ object array int ที่มีการจองก่อนหน้ายังคงอยู่
        ไม่ได้มีคำสั่งคืนพื้นที่ (delete) หรือการคืนพื้นที่อย่างอัตโนมัติ ก่อนการเรียกใช้ฟังก์ชั่นซ้ำ
        ส่งผลให้พื้นที่ส่วน heap เต็ม โปรแกรมจึงจบการทำงาน
*/