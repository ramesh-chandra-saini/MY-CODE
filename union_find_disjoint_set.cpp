/*
  morgan stanley
  hackerrank
  union find disjoint set
  26 sep 2015
*/
#include<bits/stdc++.h>
using namespace std;

// modified root function.

int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}

//modified initialize function:
void initialize( int Arr[ ], int size[],int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }

}

void weighted_union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}
bool _find(int Arr[],int A,int B)
{
    if( root(Arr,A)==root(Arr,B) )       //if A and B have same root,means they are connected.
    return true;
    else
    return false;
}
int main(){

    int N,Q;

    scanf("%d%d",&N,&Q);

    int w[N];

    set< pair<int,int> > wset; wset.clear();
    for(int i=0;i<N;i++){

        scanf("%d",&w[i]);
        wset.insert(make_pair(w[i],i));
    }

    int Arr[N];
    int size[N];
    int A,B;

    initialize(Arr,size,N);

    bool flag;

    int weight;
    int idx;
    while(Q--){

        scanf("%d%d",&A,&B);
        A-=1;B-=1; //0-based indexed

        int root_A=root(Arr,A);
        int root_B=root(Arr,B);

        flag=_find(Arr,A,B);
        
        if(!flag){

            weight=w[root_A];
			idx=root_A;
			wset.erase(make_pair(weight,idx));
			
			weight=w[root_B];
			idx=root_B;
			wset.erase(make_pair(weight,idx));
			
			if(size[root_A]>size[root_B]){

				w[root_A]+=w[root_B];
				Arr[ root_B ] = Arr[root_A];
                size[root_A] += size[root_B];
				wset.insert(make_pair(w[root_A],root_A));
            }
            else if(size[root_B]>size[root_A]){
            
				w[root_B]+=w[root_A];
				Arr[ root_A]=Arr[root_B];
				size[ root_B]+=size[root_A];
				wset.insert(make_pair(w[root_B],root_B));		
            }
            else if(root_A<root_B){
            		
				w[root_A]+=w[root_B];
				Arr[ root_B ] = Arr[root_A];
                size[root_A] += size[root_B];
				wset.insert(make_pair(w[root_A],root_A));
					
				}
			else{

				w[root_B]+=w[root_A];
				Arr[ root_A]=Arr[root_B];
				size[ root_B]+=size[root_A];
				wset.insert(make_pair(w[root_B],root_B));					
			}
            printf("%d\n",wset.begin()->first);
        }
    }
    return 0;
}
