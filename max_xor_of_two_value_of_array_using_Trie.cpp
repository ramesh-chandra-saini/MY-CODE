/*
    RAMESH CHANDRA 17 SEP 2015
    BINARY INDEX TREE
    INDEX UPDATE AND RANGE QUERY
    http://facebook.com/rameshc10695
*/

/*
    To calculate Maximum value of A[i] xor A[j] where i!=j
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct TrieNode{

    struct TrieNode *zero;
    struct TrieNode *one;
} trienode;
trienode * getNode(){
    trienode * New=(trienode*)malloc(sizeof(trienode));
    New->one=New->zero=NULL;
    return New;
}
void _insertValue(trienode * it,int value,int bit){

     int bitwise[bit];

     for(int j=bit-1;j>=0;j--,value/=2){

        bitwise[j]=value%2;
     }

     for(int i=0;i<bit;i++){

        if(bitwise[i]==0){

            if(!it->zero)
                it->zero= getNode();
            it=it->zero;
        }
        else{

            if(!it->one)
                it->one=getNode();
            it=it->one;
        }
     }
     return;
}
int _getXor(trienode * it2,int value,int bit){

     trienode * it=it2;
     int bitwise[bit];

     for(int j=bit-1;j>=0;j--,value/=2){

        bitwise[j]=value%2;
     }
     int ans[bit];

     for(int i=0;i<bit;i++){
        if(bitwise[i]==0){

            if(it->one){

                ans[i]=0 xor 1;
                it=it->one;
            }
            else{

                ans[i]=0 xor 0;
                it=it->zero;
            }
        }
        else{

            if(it->zero){

                ans[i]=1 xor 0;
                it=it->zero;
            }
            else{

                ans[i]=1 xor 1;
                it=it->one;
            }
        }
     }
     int _ans=0;

     for(int i=0;i<bit;i++)
        _ans=_ans*2+ans[i];
    return _ans;
}
int main(){


    int size;
    cout<< "Size : ";
    cin >> size;

    int arr[size];

    cout<<"Array : ";
    for(int i=0;i<size;i++)
        cin >> arr[i];

    int _max=INT_MIN;

    for(int i=0;i<size;i++)
        _max=max(_max,arr[i]);

    int _bits=0;

    do{
        _bits++;
        _max/=2;
    }
    while(_max);

   trienode * _trienode =getNode();

   int ans=INT_MIN;

   //just put one node into trie
   _insertValue(_trienode,arr[0],_bits);

    for(int i=1;i<size;i++){

        ans=max(ans,_getXor(_trienode,arr[i],_bits));
        _insertValue(_trienode,arr[i],_bits);
    }
    cout<<ans<<endl;

    return 0;
}
