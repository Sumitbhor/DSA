#include <iostream>
using namespace std;

class DynamicArray{
    private :
    int *arr;
    int size;

    public : 
    DynamicArray(){
        arr= nullptr;
        size =0;
    }

    void insert(int value){
        int *temp = new int [size+1];
        for (int i = 0; i < size; i++)
        {
            temp[i]=arr[i];
        }
        
        temp[size]=value ;

        delete[] arr;

        arr=temp;

        size++;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Array is Empty\n";
            return;
        }

        cout << "Array Elements : ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void update(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid Index\n";
            return;
        }

        arr[index] = value;
        cout << "Updated Successfully\n";
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid Index\n";
            return;
        }

        int *temp = new int[size - 1];

        int j = 0;

        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                temp[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = temp;
        size--;

        cout << "Deleted Successfully\n";
    }

     ~DynamicArray()
    {
        delete[] arr;
    }

};

int main()
{
    DynamicArray obj;

    int choice;
    int value, index;

    do
    {
        cout << "\n========== Dynamic Array CRUD ==========\n";
        cout << "1. Insert Element\n";
        cout << "2. Display Elements\n";
        cout << "3. Update Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.insert(value);
            cout << "Element inserted successfully.\n";
            break;

        case 2:
            obj.display();
            break;

        case 3:
            cout << "Enter index to update: ";
            cin >> index;

            cout << "Enter new value: ";
            cin >> value;

            obj.update(index, value);
            break;

        case 4:
            cout << "Enter index to delete: ";
            cin >> index;

            obj.remove(index);
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}