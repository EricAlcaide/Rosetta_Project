using System;
using System.Collections.Generic;
using System.Linq;

namespace Fibonacci
{
    public class Program
    {
        public static void Main()
        {
            IEnumerator<int> fibEnumerator = Fibonacci().GetEnumerator();

            int[] expectedResult = new int[] { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
            int[] actualResult = new int[expectedResult.Length];

            fibEnumerator.MoveNext();

            for (int i = 0; i < expectedResult.Length; i++)
            {
                Console.WriteLine("{0,2}: {1}", i + 1, fibEnumerator.Current);
                actualResult[i] = fibEnumerator.Current;
                fibEnumerator.MoveNext();
            }
            
        }

        // Fibonacci using a Generator
        private static IEnumerable<int> Fibonacci()
        {
            int first = 0;
            int second = 1;

            while (true)
            {
                int aux = first;
                first = second;
                second = second + aux;
                yield return second;
            }
        }
    }
}
