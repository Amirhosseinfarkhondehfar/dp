#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
vector<int>maxp,maxs;
int n,m;
string s,ss;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++)
	{
		cin>>n>>m;
		cin>>s>>ss;
		dp.clear();
		maxp.clear();
		maxs.clear();
		dp.resize(s.size(),vector<int>(ss.size()));
		maxp.resize(s.size(),-1);
		maxs.resize(s.size(),1e9);
		int j=0;
		for(int i=0;i<s.size();i++){
			maxp[i]=maxp[max(0,i-1)];
			if(j==(int)ss.size()){
				continue;
			}
			if(s[i]==ss[j]){
				maxp[i]=j;
				j++;
			}
		}
		j=(int)ss.size()-1;
		for(int i=s.size()-1;i>=0;i--){
			maxs[i]=maxs[min((int)s.size()-1,i+1)];
			if(j==-1){
				continue;
			}
			if(s[i]==ss[j]){
				maxs[i]=j;
				j--;
			}
		}
		if(maxp[s.size()-1]!=(int)ss.size()-1){
			cout<<-1<<endl;
			continue;
		}
		int result=s.size();
		for(int i=0;i<s.size();i++){
			for(int j=0;j<(int)ss.size();j++){
				if(maxp[i]<j){
					dp[i][j]=1e9;
					continue;
				}
				if(i==0){
					if(s[i]==ss[j]){
						dp[i][j]=0;
					}
					else{
						dp[i][j]=2;
					}
					continue;
				}
				if(j==0){
					if(s[i]==ss[j]){
						dp[i][j]=i*2;
					}
					else{
						dp[i][j]=i+1+(i+1-(j+1));
					}
					continue;
				}
				if(s[i]==ss[j]){
					dp[i][j]=dp[i-1][j-1];
				}
				else{
					dp[i][j]=i+1+(i+1-(j+1));
				}
			}
		}
		result=min(result,dp[s.size()-1][(int)ss.size()-1]+min(1,dp[s.size()-1][(int)ss.size()-1]));
		for(int i=s.size()-1;i>0;i--){
			result=min(result,dp[i-1][(int)ss.size()-1]+((int)s.size()-1-i+1)+min(1,dp[i-1][(int)ss.size()-1]));
			if(maxs[i]<=0){
		    	result=min(result,i*2+((int)s.size()-1-i+min(1,i*2)));
			}
			for(int j=(int)ss.size()-1;j>0;j--){
				if(j<maxs[i]){
					break;
				}
				result=min(result,dp[i-1][j-1]+((int)s.size()-1-i+1)+min(1,dp[i-1][j-1]));
			}
		}
		cout<<result<<endl;
	}
}
