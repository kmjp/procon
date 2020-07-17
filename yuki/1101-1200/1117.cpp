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

int N,K,M;
int A[3030];
ll S[3030];

ll from[3030],to[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	
	FOR(i,N) from[i+1]=-1LL<<60;
	from[0]=0;
	while(K--) {
		FOR(i,N+1) to[i]=-1LL<<60;
		deque<pair<ll,int>> D[2];
		D[0].push_back({from[0],0});
		D[1].push_back({from[0],0});
		for(i=1;i<=N;i++) {
			while(D[0].size() && D[0].front().second+M<i) D[0].pop_front();
			while(D[1].size() && D[1].front().second+M<i) D[1].pop_front();
			to[i]=max(to[i],D[0].front().first+S[i]);
			to[i]=max(to[i],D[1].front().first-S[i]);
			while(D[0].size()&&D[0].back().first<=from[i]-S[i]) D[0].pop_back();
			D[0].push_back({from[i]-S[i],i});
			while(D[1].size()&&D[1].back().first<=from[i]+S[i]) D[1].pop_back();
			D[1].push_back({from[i]+S[i],i});
		}
		swap(from,to);
	}
	cout<<from[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
