void heapify(int arr[],int n, int i) {
  int largest = i;
  int left = i*2;
  int right = i*2 + 1;

  if( left<n && arr[left]>arr[largest] ) {
    largest = left;
  }
  if( right<n && arr[right]>arr[largest] ) {
    largest = right;
  }

  if(largest != i) {
    swap(arr[largest],arr[i]);
    heapify(arr, n, largest);
  }
}

int main() {
  int arr[6] = {-1,54,53,55,52,50}
  int n = 5;
  for(int i = n/2; i>0; i--) {
    heapify(arr, n, i);
  }
}
