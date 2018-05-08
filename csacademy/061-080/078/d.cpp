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

int H,W,Q;
vector<ll> A[202020];

const int NV=1<<15;
vector<ll> val[NV*2];

vector<ll> merge(vector<ll> A,vector<ll> B) {
	vector<ll> C(H*H,-1LL<<60);
	int L,M,R;
	FOR(L,H) FOR(M,H) FOR(R,H) {
		if(M)     C[L*H+R]=max(C[L*H+R],A[L*H+M]+B[(M-1)*H+R]);
		          C[L*H+R]=max(C[L*H+R],A[L*H+M]+B[(M+0)*H+R]);
		if(M+1<H) C[L*H+R]=max(C[L*H+R],A[L*H+M]+B[(M+1)*H+R]);
	}
	return C;
}


void update(int entry) {
	entry += NV;
	while(entry>1) entry>>=1, val[entry]=merge(val[entry*2],val[entry*2+1]);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(x,NV) {
		if(x<W) val[NV+x].resize(H*H,-1LL<<60);
		else val[NV+x].resize(H*H,0);
		val[x].resize(H*H,0);
	}
	FOR(y,H) FOR(x,W) {
		cin>>j;
		val[NV+x][y*H+y]=j;
	}
	for(i=NV-1;i>=1;i--) val[i]=merge(val[i*2],val[i*2+1]);
	
	FOR(i,Q) {
		cin>>y>>x>>j;
		y--,x--;
		val[NV+x][y*H+y]=j;
		update(x);
		
		cout<<*max_element(ALL(val[1]))<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
