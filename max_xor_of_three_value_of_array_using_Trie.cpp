/*
    FIND MAXIMUM XOR OF 3 ELEMENTS OF ARRAT
*/

/*
    RAMESH CHANDRA 17 SEP 2015
    PROBLEM : https://www.codechef.com/problems/CHXORR
    DATA STRUCTURE : TRIE
    BITWISE PROGRAMMING
    TIME COMPLEXITY : O(N^2logN)
*/

#include<bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)

//structure of trie
typedef struct Trie{

    struct Trie * zero;
    struct Trie * one;
} trie;

//create a new node
trie * getNode(){

    trie * _new=(trie*)malloc(sizeof(trie));
    _new->zero=_new->one=NULL;
    return _new;
}

//insert new value
void _insert(trie *it,int value,int bits){

    int bitwise[bits],i,j;

    for(j=bits-1;j>=0;j--,value=(value>>1)){
        bitwise[j]=value%2;
    }

    for(i=0;i<bits;i++){

        if(bitwise[i]==0){

            if(!it->zero){

                it->zero=getNode();
            }
            it=it->zero;
        }
        else{

            if(!it->one){

                it->one=getNode();
            }
            it=it->one;
        }
    }
}

int _cal_Xor(trie * it,int value,int bits){


    int bitwise[bits],i,j;

    for(j=bits-1;j>=0;j--,value=(value>>1)){
        bitwise[j]=value%2;
    }
    //for(i=0;i<bits;i++) cout<<bitwise[i]; cout<<")"<<endl;
    trie* it2=it;

    int ans=0;//final ans

   //calculate maximum xor with C
    for(i=0;i<bits;i++){

        ans=(ans<<1);
        if(bitwise[i]==0){

            if(it2->one){
                ans++;
                it2=it2->one;
            }
            else{

                it2=it2->zero;
            }
        }
        else{

            if(it2->zero){

                ans++;
                it2=it2->zero;
            }
            else{

                it2=it2->one;
            }
        }
    }
    return ans;
}

int main(){


    int T,N,C,_max,i,j,bits;
    read(T);
    int arr[2001];
    while(T--){

        read(N);

        _max=INT_MIN;
        for(i=0;i<N;i++){

            read(arr[i]);
            _max=max(_max,arr[i]);
        }

        bits=0;
        do{
            ++bits;
            _max=(_max>>1);
        } while(_max);

        //just make Trie
        trie * _trie=getNode();
        //insert one node first
        _insert(_trie,arr[0],bits);


        //Final ans to console
        int ans=INT_MIN;
        for(i=1;i<N-1 ;i++){

            for(j=i+1;j<N ;j++){

                // xor of two element
                C=arr[i] xor arr[j];
                ans=max(ans,_cal_Xor(_trie,C,bits));
            }
            _insert(_trie,arr[i],bits);
        }
        write(ans);
    }
    return 0;
}
