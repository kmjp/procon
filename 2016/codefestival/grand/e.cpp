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

int N;
int X[15],Y[15],A[15];
double AS[1<<15],DS[1<<15],V[1<<15];
double D[15][15];
vector<int> C[1<<15];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>A[i];
	FOR(x,N) FOR(y,N) D[x][y]=hypot(X[x]-X[y],Y[x]-Y[y]);
	
	for(int mask=1;mask<1<<N;mask++) {
		FOR(i,N) if(mask&(1<<i)) {
			AS[mask]+=A[i];
			C[mask].push_back(i);
		}
			
		if(__builtin_popcount(mask)==1) {
			V[mask]=AS[mask];
			continue;
		}
		
		DS[mask]=1e10;
		for(int smask=(mask-1)&mask; smask>0; smask=(smask-1)&mask) {
			FORR(x,C[smask]) FORR(y,C[smask^mask]) {
				DS[mask]=min(DS[mask],DS[smask]+DS[mask^smask]+D[x][y]);
			}
		}
		V[mask]=(AS[mask]-DS[mask])/__builtin_popcount(mask);
		for(int smask=(mask-1)&mask; smask>0; smask=(smask-1)&mask) {
			V[mask]=max(V[mask],min(V[smask],V[mask^smask]));
		}
	}
	_P("%.12lf\n",V[(1<<N)-1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
