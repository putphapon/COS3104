using System;

namespace cos3104_hw02_04
{
  class cos3104_hw02_04
  {
    public static int fun(ref int k)
    {
      k += 4;
      return 3 * k - 1;
    }

    static void Main(string[] args)
    {
      int i = 10, j = 10, sum1 = 0 , sum2 = 0;
      Console.WriteLine("\n___PRE___\ni = "+ i +"\nj = "+ j);
      Console.WriteLine("\nsum1 = "+ sum1 + "\nsum2 = " + sum2);

      sum1 = (i/2) + fun(ref i);
      sum2 = fun(ref j) + (j/2);

      Console.WriteLine("\n___POST___\ni = "+ i +"\nj = "+ j);
      Console.WriteLine("\nsum1 = "+ sum1 + "\nsum2 = " + sum2);
    }
  }
}