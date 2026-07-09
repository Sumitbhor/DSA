
using System.Security.AccessControl;

namespace SearchingSorting;

public class Searching
{
    public int linearSearch(int[] Arr, int target)

    {
    
        for (int i = 0; i<Arr.Length; i++)
        {
            if (Arr[i] == target)
            {
                return i ;
            }
        }
        return -1 ;
    }

    public int BinarySearch(int []Arr, int target)
    {
        int left = 0 ;
        int right= Arr.Length-1 ;
        int mid ;
        Sorting sort= new Sorting();
        Arr= sort.BubbleSort(Arr);
        while (left <= right)
        {
            mid =(left+ right)/2 ;
            if(Arr[mid]== target)
            {
                return mid ;
            }
            else if (Arr[mid] > target)
            {
                right= mid-1;
            }
            else if (Arr[mid] < target)
            {
                left = mid+1 ;
            }
            
        }
        return -1 ;
    }
}