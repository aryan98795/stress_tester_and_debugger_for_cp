#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
int T;cin>>T;while(T--){
int n,m;cin>>n>>m;
int A[n];
for(int&a:A)
cin>>a;
sort(A,A+n);
int l = 0,r = 0;
int ans = 1e9;
map<int,int>M;
while(r<n) {
// include
for(int i=1;i<=sqrt(A[r]);i++){
if(A[r]%i!=0)continue;
if(i<=m)
M[i]++;
if(i!=sqrt(A[r]) and A[r]/i<=m)M[A[r]/i]++;
}
while(M.size() == m){
ans = min(ans,A[r]-A[l]);
for(int i=1;i<=sqrt(A[l]);i++){
if(A[l]%i!=0)continue;
if(i<=m){
if(--M[i]==0)M.erase(i);
}
if(i!=sqrt(A[l]) and (A[l]/i<=m)){
if(--M[A[l]/i]==0)M.erase(A[l]/i);
}
}
l++;
}
r++;
}
cout<<(ans==1e9?-1:ans)<<endl;
}
return 0;
}


