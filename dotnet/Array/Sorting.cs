namespace SearchingSorting;

public class Sorting
{
    
    public int[] BubbleSort(int[] arr)
    {
        for (int i = 0; i < arr.Length - 1; i++)
        {
            for (int j = 0; j < arr.Length -i- 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        return arr;
    }

    public int[] SelectionSort(int[] Arr)
    {
        
        int n = Arr.Length;
        int temp ;
        for (int i =0; i < n-1; i++)
        {
            int minIndex =i;
            for (int j=i+1; j<n; j++)
            {
                if (Arr[minIndex] > Arr[j])
                {
                    minIndex = j ;
                }
            }
            temp = Arr[i];
            Arr[i]= Arr[minIndex];
            Arr[minIndex]= temp ;
        }
        return Arr ;
    }
}