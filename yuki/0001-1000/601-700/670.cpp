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

using ull = unsigned long long;

ull seed;
int next() {
	seed = seed ^ (seed << 13);
	seed = seed ^ (seed >> 7);
	seed = seed ^ (seed << 17);
	return (seed >> 33);
}

int N,Q;
int A[201010];
const int D=15;
vector<int> bucket[1<<(31-D)];
int S[5+(1<<(31-D))];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>seed;
	FOR(i,10000) next();
	FOR(i,N) {
		x=next();
		bucket[x>>D].push_back(x);
		S[1+(x>>D)]++;
	}
	FOR(i,3+(1<<(31-D))) S[i+1]+=S[i];
	
	ll ret=0;
	FOR(i,Q) {
		x = next();
		int num=S[x>>D];
		FORR(v,bucket[x>>D]) if(v<x) num++;
		ret^=num*1LL*i;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
