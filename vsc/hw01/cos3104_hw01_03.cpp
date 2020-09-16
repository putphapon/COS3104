#include <iostream>
using namespace std;

int i;
int m = 5000;
int n = 1024;

void f(int i, int* y){
    delete y;
    if(i == 0) return;
    cout << "Count "<< i << " : " << m << "k : begin "<< y << endl;

    int* x = new int[m*n];
    f(i-1,x);
}

int main(){
    cout << "input 15000 : ";
    cin >> i;       //15000

    int* x = new int[m*n];
    f(i,x);
    return 0;
}

/*
    result :
    -   โปรแกรมวนทำงานครบตามรอบที่ input เข้าไป (15,000) และจบการทำงาน

    analyze :
    -   โปรแกรมรับ input จำนวนตามโจทย์ (15,000)
        มีการประกาศตัวแปร point array int ซึ่งเป็นค่า address ชี้ไปที่ object array int จำนวน 5,000k ช่อง
        โปรแกรมเรียกใช้ฟังก์ชั่น f(i,x) 
        โดย i คือ parameter ของ input และ x คือ parameter ของ point array int
        ภายในฟังก์ชั่นมีการทำงานคือ delete object ที่ point array int ที่ถูกส่งเข้ามา เพื่อคืนค่า heap ของ object array int
        จากนั้น ตรวจสอบ i ว่ามีค่าเท่า 0 หรือไม่ ถ้าใช่ให้ return จบการทำงานฟังก์ชั่น
        ถาไม่ใช่ ให้ประกาศตัวแปร point array int พร้อมสร้าง object array int อีกจำนวน 5,000k ช่อง
        แล้วเรียกใช้ฟังก์ชั่นซ้ำ โดยส่งตัวแปร i-1 และ point array int ทำงานไปเรื่อย ๆ จนกระทั่ง i เท่ากับ 0 จึงจะจบการทำงาน
    
    -   พบว่าโปรแกรมสามารถวนทำงานจนครบจำนวนที่ถูก input (15,000) เข้าไป

    -   เนื่องจากคำสั่งประกาศตัวแปร pointer array int เป็นการประกาศ address ที่ชี้ไปยัง object array int โดยใช้พื้นที่ heap
        ในภาษา c++ การจะคืนพื้นที่ heap เพื่อนำมาใช้ใหม่ จะต้องมีคำสั่ง delete เสมอ
        ซึ่งการทำงานของโปรแกรมนี้ มีการประกาศ (new) แล้วคืนพื้นที่ (delete) ตัวแปรไปเรื่อย ๆ
        จึงทำให้สามารถวนทำงานจนครบจำนวนที่ถูก input เข้าไปครั้งแรก ทำงานจนจบสมบูรณ์ได้
*/