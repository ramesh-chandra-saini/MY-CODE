/*
    RAMESH CHANDRA 2 OCT 2015
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL
    https://www.facebook.com/rameshc10695

    Types of Queries : 02
    Query-1).Update A[i]=j;
    Query-2).Get sum of given index range
*/
#include<bits/stdc++.h>
using namespace std;
int build_segTree(int segTree[],int node,int arr[],int L,int R){

    if(L>R) return 0;///Invalide Interval
    if(L==R)return (segTree[node]=arr[L]);///Only One Element
    ///Devide this segment into to part one is Left and other one is Right
    return (segTree[node]=build_segTree(segTree,1+2*node,arr,L,(L+R)/2)
                        +build_segTree(segTree,2+2*node,arr,1+(L+R)/2,R));
}
int update_segTree(int segTree[],int node,int L,int R,int arr[],int idx,int value){

    if(L>R ) return 0;///Invalide Interval
    if(L==idx && idx==R) return (segTree[node]=(arr[L]=value));///Right index for update
    return (segTree[node]=((idx>(L+R)/2)? segTree[1+2*node]:update_segTree(segTree,1+2*node,L,(L+R)/2,arr,idx,value))
                     +((idx<1+(L+R)/2)? segTree[2+2*node]:update_segTree(segTree,2+2*node,1+(L+R)/2,R,arr,idx,value)));
}
int getSum_segTree(int segTree[],int node,int curr_L,int curr_R,int L,int R){

    if(curr_L>curr_R || curr_R<L || curr_L>R) return 0;
    if(L<=curr_L && curr_R<=R) return segTree[node];
    return getSum_segTree(segTree,1+2*node,curr_L,(curr_L+curr_R)/2,L,R)
        +getSum_segTree(segTree,2+2*node,1+(curr_L+curr_R)/2,curr_R,L,R);
}
int main(){

    int size;
    cout<<"Size :";
    cin>>size;

    int arr[size];
    cout<<"Array :";
    for(int i=0;i<size;i++){

        cin>>arr[i];
    }

    int segTree[2*size];
    memset(segTree,0,sizeof(segTree));

    build_segTree(segTree,0,arr,0,size-1);

    cout<<"Menu\n\t1.Update index value\n\t2.Getsum L R\n\t0.Exit"<<endl;
    cout<<"0-Based Index"<<endl;

    int choice,x,y;
    do{

        cin>>choice>>x>>y;

        switch(choice){

            case 1: update_segTree(segTree,0,0,size-1,arr,x,y);
            break;
            case 2: cout<<getSum_segTree(segTree,0,0,size-1,x,y)<<endl;
            break;
            default : cout<<"Invalid Query Type"<<endl;
        }
    }
    while(choice);

    return 0;
}
