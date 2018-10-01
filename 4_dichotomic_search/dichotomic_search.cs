using System;
using System.Collections.Generic;

namespace DichotomicSearch
{
    public class Program
    {
        public static void Main()
        {
            // Initialize test sets using char
            // Results: '', 'e'
            Dictionary<char, char[]> charsets = new Dictionary<char, char[]>()
            {
                {
                    'z',
                    new char[] { 'a', 'b', 'd', 'e', 'g', 'h', 'j', 'l', 'm', 'q', 'x' }
                },
                {
                    'e',
                    new char[] { 'a','b','d','e','g','h','j','l','m','q','x' }
                }
            };
            foreach (char key in charsets.Keys)
            {
                Console.WriteLine("Result: " + DichotomicSearch(charsets[key], key));
            }

            // Initialize test sets using int
            // Results: 0, 0, 3
            Dictionary<int, int[]> numbersets = new Dictionary<int, int[]>()
            {
                {
                    20,
                    new int[] { 1, 2, 3, 5, 6, 10, 15 }
                },
                {
                    4,
                    new int[] { 1, 2, 3, 5, 6, 10, 15 }
                },
                {
                    3,
                    new int[] { 1, 2, 3, 5, 6, 10, 15 }
                }
            };
            foreach (int key in numbersets.Keys)
            {
                Console.WriteLine("Result: " + DichotomicSearch(numbersets[key], key));
            }
        }

        private static T DichotomicSearch<T>(T[] items, T val) where T : IComparable<T>
        {
            int min = 0;
            int max = items.Length - 1;
            while (min <= max)
            {
                int mid = (min + max) / 2;
                if (val.Equals(items[mid]))
                {
                    return val;
                }
                else if (val.CompareTo(items[mid]) < 0)
                {
                    max = mid - 1;
                }
                else
                {
                    min = mid + 1;
                }
            }
            // We return the default value instead of null since chars and ints are not nullable.
            // Default char: '', Default int: 0
            return default(T);
        }
    }
}
