/*
    RAMESH CHANDRA 17 SEP 2015
    BINARY INDEX TREE
    INDEX UPDATE AND RANGE QUERY
    http://facebook.com/rameshc10695
*/
#include<bits/stdc++.h>
using namespace std;
int Getsum_From_Tree(int BIT[],int idx){

    int sum=0;
    while(idx){

        sum+=BIT[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
void Update_Tree(int BIT[],int maxIdx,int idx,int value){

    while(idx && idx<maxIdx){

        BIT[idx]+=value;
        idx+=(idx & -idx);
    }
    return;
}
void  Build_Tree(int arr[],int BIT[],int size){

    memset(BIT,0,sizeof(BIT));
    //To build tree
    for(int i=0;i<size;i++)
        Update_Tree(BIT,size+1,i+1,arr[i]);
    return ;
}
int main(){


    int size;
    cout<< "Size : ";
    cin >> size;

    int arr[size];

    cout<<"Array : ";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int BIT[size+1];
    Build_Tree(arr,BIT,size);

    /*
        here two types of query
        1. Update A[i] to some value : O(logn)
        2.Get Sum from L to R index : O(logn)
    */
    int Q;
    cout<<"Number of Queries : ";
    cin >> Q;

    while(Q--){
        int q;
        cout<<"\t1. Add Value"<<endl;
        cout<<"\t2.Get Sum"<<endl;
        cin >>q;

        if(q==1){

            int val,idx;
            cout<<"Index : ";
            cin >> idx ;
            cout<<"Value : ";
            cin>> val;
            arr[idx-1]=val;

            Update_Tree(BIT,size+1,idx,val);
        }
        else {
            int L,R;
            cout<<"Range of Index : ";
            cin >> L  >> R;

            cout<<Getsum_From_Tree(BIT,R)-Getsum_From_Tree(BIT,L-1)<<endl;
        }
        cout<<"CURR_ARRAY: ";
        for(int i=0;i<size;i++) cout<<arr[i]<<" "; cout<<endl;
        cout<<"CURR_BIT  : ";
        for(int i=0;i<size;i++) cout<<BIT[i+1]<<" "; cout<<endl;
    }
    return 0;
}
