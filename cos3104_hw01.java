//import java.util.Scanner;
// Scanner input = new Scanner(System.in);
// System.out.println("input 15000 : ");
// int i = Integer.parseInt(input.nextLine());
// for(int a = Integer.parseInt(i) ; a > 0 ; a--) {
//   f(a);
// }


public class cos3104_hw01 {
  static int m = 5000;
  static int n = 1024;

  public static void f(int i) {
    int[] x = new int[m*n];
    System.out.println("Count "+i+" : "+ m +"k");
    f(i+1);
  }
  
  public static void main(String[] args) {
    f(0);
  }
}

/*
    result :
    -   เรียกใช้ f(i) โดยฟังก์ชั่นเรียกใช้ซ้ำ (recursive) ได้ 99 รอบ 
        แล้วโปรแกรมจบการทำงาน พร้อมข้อความว่า
        Exception in thread "main" java.lang.OutOfMemoryError: Java heap space

    analyze :
    -   โปรแกรมเรียกใช้ฟังก์ชั่น f(i) โดยภายในฟังก์ชั่น มีคำสั่งประกาศตัวแปร pointer array int
        โดยจองจำนวน 5,000k ช่อง และเรียกใช้ฟังกชั่นซ้ำ อีก i+1 ครั้ง 

    -   ทำให้ฟังก์ชั่นมีการประกาศตัวแปร pointer array int อีกจำนวน 5,000k แล้วเรียกใช้ฟังก์ชั่นซ้ำอีกไปเรื่อย ๆ
        จนโปรแกรมเรียกใช้ซ้ำได้ 99 รอบ ก่อนจบการทำงาน พร้อมข้อความ 
        Exception in thread "main" java.lang.OutOfMemoryError: Java heap space

    -   รวมจำนวน array int ได้ 99*5,000k ช่อง (int size = 4bytes : 4*(99*5,000k) = 1,980,000kb ~ 2Gb)

    -   เนื่องจากคำสั่ง new บนภาษา java 
        เป็นการประกาศตัวแปร เพื่อเก็บค่า address ที่ไปชี้ตำแหน่ง object บนพื้นที่ heap
        สาเหตุที่โปรแกรมวนเรียกใช้งานฟังก์ชั่นได้เพียง 99 รอบ
        เพราะ lifetime ของ object array int ที่มีการจองก่อนหน้ายังคงอยู่
        ไม่ได้มีคำสั่งคืนพื้นที่ด้วยคำสั่ง delete ก่อนการเรียกใช้ฟังก์ชั่นซ้ำ
        ส่งผลให้พื้นที่ heap เต็ม โปรแกรมจึงจบการทำงาน
*/