using System.Globalization;

namespace SearchingSorting;

public class Array
{
    public static void Main(string[] args)
    {   
        Console.WriteLine("Enter total elements in array ");
        int n = Convert.ToInt32(Console.ReadLine());
        int[] Arr = new int[n];
        Searching search = new Searching();
        Sorting sort = new Sorting();
        
        for (int i=0 ; i < n; i++){
        Console.Write("Enter element"+i+":");
        Arr[i]= Convert.ToInt32(Console.ReadLine());
        }
        while(true){
        Console.WriteLine("*****Menu*****");
        Console.WriteLine("1.Sorting");
        Console.WriteLine("2.Searching");
        Console.WriteLine("Enter your choice");
        int choice = Convert.ToInt32(Console.ReadLine());
        switch (choice)
        {
            case 1:
                Console.WriteLine("*****Sorting Menu*****");
                Console.WriteLine("1.Bubble Sort");
                Console.WriteLine("2.Selection Sort");
                Console.WriteLine("Enter your choice");
                int sortChoice = Convert.ToInt32(Console.ReadLine());
                switch (sortChoice)
                {
                    case 1:
                        int[] sortedArr = sort.BubbleSort(Arr);
                        Console.WriteLine("Sorted Array using Bubble Sort:");
                        foreach (int num in sortedArr)
                        {
                            Console.Write(num + " ");
                        }
                        break;
                    case 2:
                        int[] sortedArr2 = sort.SelectionSort(Arr);
                        Console.WriteLine("Sorted Array using Selection Sort:");
                        foreach (int num in sortedArr2)
                        {
                            Console.Write(num + " ");
                        }
                        break;
                    default:
                        Console.WriteLine("Invalid choice for sorting.");
                        break;
                }
                break;
            case 2:
                Console.WriteLine("*****Searching Menu*****");
                Console.WriteLine("1.Linear Search");
                Console.WriteLine("2.Binary Search");
                Console.WriteLine("Enter your choice");
                int searchChoice = Convert.ToInt32(Console.ReadLine());
                switch (searchChoice)
                {
                    case 1:
                        Console.WriteLine("Enter the target value to search:");
                        int targetLinear = Convert.ToInt32(Console.ReadLine());
                        int linearResult = search.linearSearch(Arr, targetLinear);
                        if (linearResult != -1)
                            Console.WriteLine($"Element found at index: {linearResult}");
                        else
                            Console.WriteLine("Element not found.");
                        break;
                    case 2:
                        Console.WriteLine("Enter the target value to search:");
                        int targetBinary = Convert.ToInt32(Console.ReadLine());
                        int binaryResult = search.BinarySearch(Arr, targetBinary);
                        if (binaryResult != -1)
                            Console.WriteLine($"Element found at index: {binaryResult}");
                        else
                            Console.WriteLine("Element not found.");
                        break;
                    default:
                        Console.WriteLine("Invalid choice for searching.");
                        break;
                }
                break;
            default:
                Console.WriteLine("Invalid choice.");
                break;
        }
        }
    }
}
    