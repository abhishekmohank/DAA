#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int* A,int p,int r){
    int x=A[r];
    int i=p-1;

    for(int j=p;j<=r-1;j++){
        if(A[j]<=x){
            i=i+1;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}
void quick_sort(int A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
    
}

int main(){
    int n;
    cout<<"Emter the number of elemnts : ";
    cin>>n;
    int* A = new int[n];
    for(int i=0;i<n;i++){
        A[i]=rand()%500;
    }
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
    
    auto start = high_resolution_clock::now();
    quick_sort(A,0,n-1);
    auto stop = high_resolution_clock::now();

    // for(int i=0;i<n;i++)
    //     cout<<A[i]<<" ";
    
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\n\nTime taken to sort : "<<duration.count()<<" microseconds"<<endl;

    auto st = high_resolution_clock::now();
    quick_sort(A,0,n-1);
    auto sp = high_resolution_clock::now();

    // for(int i=0;i<n;i++)
    //     cout<<A[i]<<" ";
    
    auto drtn = duration_cast<microseconds>(sp - st);
    cout<<"\n\nTime taken to sort : "<<drtn.count()<<" microseconds"<<endl;

    return 0;
}
