using System;

namespace HelloWorld
{
    class Program
    {
        public static void Main()
        {
            PrintMessage("Hello, World.");
        }

        static void PrintMessage(string message)
        {
            // prints the first line of output
            Console.WriteLine("Hello, World.");

            // prints the last line of output
            Console.WriteLine(message);
        }
    }
}