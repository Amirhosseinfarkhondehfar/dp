#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,m;
	cin>>n>>m;
	vector<long long>all(n+1+3);
	for(long long i=1;i<=n;i++){
		all[i]=i;
	}
	all[n+1]=all[n+2]=n;
	vector<long long>fib(n+3);
	fib[1]=1;
	fib[2]=2;
	for(long long j=3;j<=n+1;j++){
		fib[j]=fib[j-1]+fib[j-2];
	}
	while(m>0){
		long long j=1;
		for(;;j++){
			if(fib[j]>=m){
				break;
			}
		}
		swap(all[n-j+1],all[n-j+2]);
		m-=fib[j]-fib[max(j-2,0ll)];
	}
	for(long long i=1;i<=n;i++){
	    cout<<all[i]<<" ";
	}
	cout<<endl;
}
