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

int N,Q,K;
string S;
int A[2020];
ll need[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		cin>>A[i];
		need[i+1]=1LL<<60;
	}
	
	FOR(i,N) {
		ll sum=0;
		int b=0;
		for(j=i;j<N;j++) {
			sum+=A[j];
			if(S[j]=='E') b++;
			need[b]=min(need[b],sum);
		}
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>K;
		int ma=0;
		FOR(j,N+1) if(need[j]<=K) ma=max(ma,j);
		cout<<ma<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
