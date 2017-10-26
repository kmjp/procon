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

int N,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<vector<int>> V;
	
	cin>>N>>K;
	if(K==0) {
		if(N==1) {
			;
		}
		else if(N==2 || N==3) {
			return _P("-1\n");
		}
		else if(N==4) {
			V.push_back({0,1,1});
			V.push_back({1,2,1});
			V.push_back({2,3,1});
			V.push_back({1,3,2});
			V.push_back({3,0,2});
			V.push_back({0,2,2});
		}
		else if(N==6) {
			V.push_back({0,1,1});
			V.push_back({1,2,1});
			V.push_back({2,3,1});
			V.push_back({3,4,1});
			V.push_back({4,5,1});
			V.push_back({0,2,2});
			V.push_back({2,5,2});
			V.push_back({5,3,2});
			V.push_back({3,1,2});
			V.push_back({1,4,2});
		}
		else {
			for(x=2;x<=N;x++) if(__gcd(x,N)==1) {
				FOR(i,N-1) V.push_back({i,(i+1)%N,1});
				FOR(i,N-1) V.push_back({i,(i+x)%N,2});
				break;
			}
		}
	}
	else {
		FOR(i,K) V.push_back({i,i+1,2});
		for(i=K+1;i<N;i++) {
			V.push_back({0,i,1});
			V.push_back({K,i,3});
		}
	}
	
	_P("%d\n",V.size());
	FORR(v,V) _P("%d %d %d\n",v[0]+1,v[1]+1,v[2]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
