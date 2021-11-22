#include <iostream>
#include <fstream>

using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


//merging the whole
void merge(int arr[], int left_idx, int mid, int right_idx)
{
    int n1 = mid - left_idx+1; //size of the left array elements
    int n2 = right_idx - mid; //size of the right array elements

    //take temporary arrays
    int temp1[n1];
    int temp2[n2];

    //enter elements in the temporary array
    for(int i=0; i<n1; i++)
    {
        temp1[i] = arr[left_idx + i];
    }

    for(int i =0; i<n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }

    int i=0; //transverse the left array
    int j = 0; // transverse the right array
    int k = left_idx; //transverse the array from l to r

    while(i<n1 && j<n2)
    {
        if(temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }

    //there will  be some elements left in the array bc they got nth to compare them with
    //so we make sure that we are able to take all them inside the array in some way
    while(i<n1)
    {
        arr[k] = temp1[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k] = temp2[j];
        k++;
        j++;
    }

}

void mergeSort(int arr[], int left_index, int right_index)
{
    if(left_index < right_index)
    {
        int mid = (left_index + right_index) / 2;
        mergeSort(arr, left_index, mid);
        mergeSort(arr, mid+1, right_index);

        merge(arr, left_index, mid, right_index);
    }
}

int main()
{
    ifstream file("input.txt");
  if(file.fail()){
    cout<<"File couldn't be opened!"<<endl;
    return 0;
  }
  
  int t;
  file>>t;
  int size, temp;
  
  int i=0;
  while(i<t)
  {
    cout<<endl;
    cout << "Test Case " << i + 1 << ":" << endl;
    file >> size;
    cout <<"Input size " << size << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
      file >> temp;
      arr[i] = temp;
    }
    mergeSort(arr, 0, size-1); 
    printArray(arr,  size);
    cout<<endl;
    i++;
  }
  

  file.close();  

    return 0;
}
