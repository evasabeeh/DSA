#include<bits/stdc++.h>
using namespace std;
                            // for 1-indexed max heap array
class heap{
    public:
    int arr[100];
    int size=0;

    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }
            else
            return;
        }
    }
    void deleteHeap(){
        if(size==0)
        return;

        arr[1]=arr[size];           // first swap the last element to the root
        size--;

        int i=1;                    // take root node to correct position
        while(i<size){
            int left=2*i, right=2*i+1;

            if(left<size && arr[i]<arr[left]){
                swap(arr[i], arr[left]);
                i=left;
            }
            else if(right<size && arr[i]<right){
                swap(arr[i], arr[right]);
                i=right;
            }
            else
            return;
        }
    }
    void heapify(int arr[], int n, int i){       // recursive method to make heap out of binary tree and maintains the heap property
        int largest=i;
        int left=2*i, right=2*i+1;              // 2*i+1, 2*i+2    for 0-indexed

        if(left<=n && arr[largest]<arr[left])
        largest=left;

        if(right<=n && arr[largest]<arr[right])
        largest=right;

        if(largest!=i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void print(){
        for(int i=1;i<=size;i++)
        cout<<arr[i]<<" ";

        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deleteHeap();
    h.print();

    int arr[6]={-1, 54, 53, 55, 52, 50};
    int n=5;
    for(int i=n/2;i>0;i--)
    h.heapify(arr, n, i);

    for(int i=1;i<=n;i++)         // after heapify
    cout<<arr[i]<<" ";
    cout<<endl;
}



// heap height:    (int) log2(N)