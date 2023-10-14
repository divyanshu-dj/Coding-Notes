void heapSort(int arr[], int n) {
  int t = n;

  while(t > 1) {
    //step 1: swap
    swap(arr[1],arr[n]);
    n--;
    heapify(arr, n, 1);
  }
}
