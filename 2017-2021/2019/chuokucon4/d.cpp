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

int T,H;
int TL,TR,HL,HR;
int N;
int A[21],B[21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T>>H>>TL>>TR>>HL>>HR;
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	int mi=101;
	for(int mask=0;mask<1<<N;mask++) {
		int CT=T,CH=H;
		FOR(i,N) if(mask&(1<<i)) CT+=A[i],CH+=B[i];
		if(TL<=CT && CT<=TR && HL<=CH && CH<=HR) mi=min(mi,__builtin_popcount(mask));
	}
	if(mi==101) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
