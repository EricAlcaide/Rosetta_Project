using System;
using System.Diagnostics; // For Assert() function

namespace Rosseta_Project
{
    class Factorialize
    {
        static void Main(string[] args)
        {
            Debug.Assert( factorialize(0)  == 1);
            Debug.Assert( factorialize(5)  == 120);
            Debug.Assert( factorialize(7)  == 5040);
            Debug.Assert( factorialize(9)  == 362880);
            Debug.Assert( factorialize(10) == 3628800);
            Debug.Assert( factorialize(15) == 1307674368000);
        }

        // Using Int64 for big numbers.
        static Int64 factorialize(Int64 n)
        {
            Int64 result = 1;
            for (var i = n; i > 1; i--) { result *= i; }
            return result;
        }
    }
}
