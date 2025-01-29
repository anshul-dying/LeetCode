// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    //Merging arrays into single array
    int size = nums1Size + nums2Size;
    int num[size];
    for(int j = 0; j < nums1Size; j++)num[j] = nums1[j];
    for(int j = 0; j < nums2Size; j++) num[nums1Size + j] = nums2[j];

    //sorting merged array
    bubbleSort(num, size);

    //printing sorted
    // for(int i = 0; i < size; i++)
    // {
    //     printf("%d ", num[i]);
    // }

    //finding median
    int mid = (size+1)/2;
    printf("%d", mid);
    float median = 0;
    if(size % 2 != 0)
    {
        median = num[mid-1];
    }
    else
    {
        median = ((float)num[mid-1] + (float)num[mid])/2;
    }
     

    return median;
}