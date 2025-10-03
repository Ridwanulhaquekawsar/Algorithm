#include<bits/stdc++.h>
using namespace std;
int N; vector<int>arr;

void conquer(int l,int mid,int r){
    int n=mid-l+1,k=l,i=0; vector<int>l_arr(n);
    while(i<n){
        l_arr[i++]=arr[k++];
    }
    
    int m=r-mid,j=0; k=mid+1; vector<int>r_arr(m);
    while(j<m){
        r_arr[j++]=arr[k++];
    }
    
    i=0,j=0; int curr=l;
    while(i<n && j<m){
        if(l_arr[i]<r_arr[j]){
            arr[curr++]=l_arr[i++];
        }else{
            arr[curr++]=r_arr[j++];
        }
    }
    
    while(i<n){
        arr[curr++]=l_arr[i++];
    }
    
    while(j<m){
        arr[curr++]=r_arr[j++];
    }
}

void devide(int l,int r){
    if(l==r){return;}
    
    int mid=(l+r)/2; devide(l,mid); devide(mid+1,r);
    
    conquer(l,mid,r);
}

void do_this(){
    cin>>N; arr.resize(N); int i=0;
    while(i<N){
        cin>>arr[i++];
    }
    
    devide(0,N-1);
    
    for(auto x : arr){
        cout<<x<<" ";
    }
}

int main(){
    do_this();
    return 0;
}
