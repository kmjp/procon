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

int N,Q;
int X[101010],W[101010];
int Y[101010];
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ll L=0,R=0;
	ll sum=0;
	vector<pair<int,int>> ev;
	FOR(i,N) {
		cin>>X[i]>>W[i];
		sum+=1LL*X[i]*W[i];
		R+=W[i];
		ev.push_back({X[i],i});
	}
	FOR(i,Q) {
		cin>>Y[i];
		ev.push_back({Y[i],i+N});
	}
	int cur=0;
	sort(ALL(ev));
	FORR(e,ev) {
		ll dx=e.first-cur;
		sum+=L*dx;
		sum-=R*dx;
		cur=e.first;
		
		x=e.second;
		if(x<N) L+=W[x],R-=W[x];
		else ret[x-N]=sum;
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
