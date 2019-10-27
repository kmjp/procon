#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<int> E[606];
double dp[606],dp2[606];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
	}
	
	for(i=N-2;i>=0;i--) {
		FORR(e,E[i]) dp[i]+=1+dp[e];
		dp[i]/=E[i].size();
	}
	
	FOR(i,N) dp2[i]=dp[i];
	
	double ret=dp[0];
	for(i=N-2;i>=0;i--) if(E[i].size()>=2) {
		vector<double> V;
		FORR(e,E[i]) V.push_back(dp[e]);
		sort(ALL(V));
		V.pop_back();
		
		dp2[i]=0;
		FORR(v,V) dp2[i]+=1+v;
		dp2[i]/=V.size();
		
		for(j=i-1;j>=0;j--) {
			dp2[j]=0;
			FORR(e,E[j]) dp2[j]+=1+dp2[e];
			dp2[j]/=E[j].size();
		}
		ret=min(ret,dp2[0]);
		

		
		for(j=i;j>=0;j--) dp2[j]=dp[j];
	}
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
