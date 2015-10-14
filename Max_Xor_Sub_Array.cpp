/*
    Author : Ramesh Chandra
    National Institute Of Technology Karnataka Surathkal
    www.facebook.com/rameshc10695

    Find maximum xor sub array
    Time Complexity : O(NlogN)
*/
#include<bits/stdc++.h>
using namespace std;

#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)

typedef struct _Trie {

    struct _Trie *zero;
    struct _Trie *one;
} Trie;

Trie *getNode(){

    Trie *_new= (Trie*)malloc(sizeof(Trie));
    _new->zero=_new->one=NULL;
    return _new;
}

void _reverse(vector<bool> &A){

    int size=A.size();
    bool temp;
    for(int i=0;i<size;i++){
        temp=A[i]; A[i]=A[size-1-i]; A[size-1-i]=temp;
    }
}
void _insert(Trie *trie, int value, int bits){

    vector<bool>  binary; binary.clear();
    for(int i=0;i<bits;i++,value>>=1)
        binary.push_back(value&1);

    _reverse(binary);
    for(int i=0;i<bits;i++){

        if(binary[i]){

            if(trie->one==NULL) trie->one=getNode();
            trie=trie->one;
        }
        else{

            if(trie->zero==NULL) trie->zero=getNode();
            trie=trie->zero;
        }
    }
}
int getXor(Trie *trie,int value,int bits){

    vector<bool>  binary; binary.clear();

    for(int i=0;i<bits;i++,value>>=1)
        binary.push_back(value&1);

    _reverse(binary);
     int ans=0;

    for(int i=0;i<bits;i++){

         ans=(ans<<1);
        if(binary[i]){

            if(trie->zero!=NULL)
                ans++,trie=trie->zero;
            else
                trie=trie->one;
        }
        else{

            if(trie->one!=NULL)
                ans++,trie=trie->one;
            else
                trie=trie->zero;
        }
    }
    return ans;
}
int main(){

    int T,N;
    read(T);

    while(T--){

        read(N);
        int arr[N];

        int maxValue=INT_MIN;
        for(int i=0;i<N;i++){
            read(arr[i]);
            maxValue=max(maxValue,arr[i]);
        }

        int bits=0;
        do{

            bits++;
            maxValue>>=1;
        } while(maxValue);

        Trie *trie=getNode();

        int cum_xor=0;
        int ans=0;

        _insert(trie,0,bits);

        for(int i=0;i<N;i++){

            cum_xor^=arr[i];
            _insert(trie,cum_xor,bits);
            ans=max(ans,getXor(trie,cum_xor,bits));
        }
        printf("%d\n",ans);
    }
    return 0;
}
