#include <iostream>
#include <queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    // T.C = O(logn)
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // T.C = O(logn)
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Heap is empty!!"<<endl;
            return;
        }

        // swap root element with last element
        arr[1] = arr[size];

        //delete last element
        size--;

        //take root element to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }

    }
};

// T.C = O(logn)
void heapify(int arr[],int n,int i){
    
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

// T.C = O(nlogn)
void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}

int main()
{   
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[] = {-1,10,20,15,40,50,100,25,45};
    int n = 8;

    // Build max heap [T.C = O(n)]
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }

    heapSort(arr,n);
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //maxheap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(4);

    cout<<"Element at top is:"<<pq.top()<<endl;
    pq.pop();
    cout << "Element at top is:" << pq.top() << endl;

    //minheap
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(5);
    pq1.push(4);
    pq1.push(10);

    cout << "Element at top is:" << pq1.top() << endl;
    pq1.pop();
    cout << "Element at top is:" << pq1.top() << endl;

    return 0;
}