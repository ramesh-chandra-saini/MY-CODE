/*
    RAMESH CHANDRA 20 SEP 2015
    NATIONAL INSTITUTE OF TECHNOLOGY
    KARNATAKA SURATHKAL
    BINARY INDEXED TREE
    https://www.facebook.com/rameshc10695
    
*/
#include<bits/stdc++.h>
using namespace std;

int _get_sum_from_bit(int bit[],int idx){

    int sum=0;

    while(idx){

        sum+=bit[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
void update_bit(int bit[],int maxidx,int idx,int value){

    while(idx && idx<maxidx){

        bit[idx]+=value;
        idx+=(idx & -idx);
    }
}
void build_bit(int bit[],int size,int arr[] ){

    for(int i=0;i<size;++i){

        bit[i]=0;
    }
    for(int i=1;i<size;i++){

      update_bit(bit,size,i,arr[i]);
    }
}
int main(){


    int size;
    cout<<"Size : ";

    cin >> size;

    ++size; //because i will process 1-index based Query
    int arr[size];

    cout<<"ARRAY : ";

    for(int i=1;i<size;i++){

        cin >> arr[i];
    }

    int BIT[size]; //create BIT
    build_bit(BIT,size,arr);
    int Query;

    cout<<"Query : ";
    cin >> Query;

    cout<<"Query 1: To update ith index to given value ....1 index value"<<endl;
    cout<<"Query 2 : To get sum between given range ........2 left  right"<<endl;
    /*
        Query 1: To update ith index to given value
        Query 2 : To get sum between given range
    */
    int _query;
     cout<<"Process Queries"<<endl;
     
    while(Query){


            cin >> _query;

            if(_query==1){

                int index;int value;

                cin >> index;

                cin >> value;
                //to update ith index element to value
                 update_bit(BIT,size,index,(value-arr[index]) );
                 
                 //here why I have subtract arr[index] from value
                 //because i will add value - arr[index] to all
                 //other wise I have to perform two update query to do same
                 //first i will make arr[index] to zero
                 //then add value to arr[index]..now which one better
                 
                 arr[index]=arr[index]+(value-arr[index]);
            }
            else{

                int L,R;
                cin >> L >> R;
                cout<<_get_sum_from_bit(BIT,R)-_get_sum_from_bit(BIT,L-1)<<endl;
                
                //why L-1 ?? because we want to calculate sum from L to R inclusive
            }
    }
    return 0;
}
