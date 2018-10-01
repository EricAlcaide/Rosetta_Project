using System;
using System.Collections.Generic;

namespace Factorialize
{
    public class Program
    {
        public static void Main()
        {
            Dictionary<int, int> expectedResults = new Dictionary<int, int>()
            {
                { 0, 1 },
                { 5, 120 },
                { 7, 5040 },
                { 9, 362880 }
            };

            foreach (int key in expectedResults.Keys)
            {
                int factorializedNumber = Factorialize(key);
                Console.WriteLine("==================================");
                Console.WriteLine("Input:     {0}", key);
                Console.WriteLine("Expected:  {0}", expectedResults[key]);
                Console.WriteLine("Actual:    {0}", factorializedNumber);
                Console.WriteLine("==================================\n");
            }
        }

        private static int Factorialize(int number)
        {
            int result = 1;
            for (int product = number; product > 0; product--)
            {
                result *= product;
            }
            return result;
        }
    }
}
