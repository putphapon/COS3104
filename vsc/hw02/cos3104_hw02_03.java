package vsc.hw02;

public class cos3104_hw02_03 {
  public static int fun(MyInt k){
    k.setNum(k.getNum() + 4);
    return 3 * k.getNum() - 1;
  }

  public static void main(final String[] args) {

    MyInt i = new MyInt(10);
    MyInt j = new MyInt(10);
    int sum1 = 0 , sum2 = 0;

    System.out.println("\n___PRE___\ni = "+ i.getNum() +"\nj = "+ j.getNum());
    System.out.println("\nsum1 = "+ sum1 +"\nsum2 = "+ sum2);
    
    sum1 = (i.getNum()/2) + fun(i);
    sum2 = fun(j) + (j.getNum()/2);
    
    System.out.println("\n___POST___\ni = "+ i.getNum() +"\nj = "+ j.getNum());
    System.out.println("\nsum1 = "+ sum1 +"\nsum2 = "+ sum2);
  }
}