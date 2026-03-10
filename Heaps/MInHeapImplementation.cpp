class minHeap {
public:

    // Constructor for the class.
    vector<int> arr;
    int size;
    minHeap() {
        // Write your code here.
        size = 0;
        arr.push_back(-1);
    }
    minHeap(int n) {
        size = 0;
        arr.push_back(-1);
    }
    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
     if(size==0) return -1;
     // step1 : put lastelemenet into first index;
     int minEle = arr[1];
     arr[1] = arr[size];
     // step2:remove last element;
     arr.pop_back();
     size--;
     // step3 : propogate node to its correct position
      int i = 1;
      while(i<=size){
        int left = 2*i;
        int right = 2*i+1;
        int smallest = i;
        if(left<=size && arr[left]<arr[smallest]){
            smallest = left;
        }
        if(right<=size && arr[right]<arr[smallest]){
           smallest = right;
        }
        if(smallest != i){
            swap(arr[smallest],arr[i]);
            i = smallest;
        }
        else{
            break;
        }
      }
     return minEle;
    }
    void heapify(vector<int> &arr,int n , int i ){
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left<=n && arr[smallest]>arr[left]){
        smallest = left;
    }
    if(right<=n && arr[smallest]>arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr,n,smallest);
    }
    else{
        return;
    }
}

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind <=0 || ind > size) return;
        // step1 : put index element to last index element
        arr[ind] = arr[size];
        // step2: delete last element
        size--;
        arr.pop_back();
        //step3: propagate node to its correct positon use heapify algo
        int n = size;
        for(int i = n/2;i>0;i--){
            heapify(arr,size,i);
        }
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        arr.push_back(val);
        size++;
        int index = size;
        while(index>1){
            int parent = index/2;
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }
};
