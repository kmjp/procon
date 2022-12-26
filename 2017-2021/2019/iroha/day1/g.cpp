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

int N,M,K;;
int A[1010];

ll from[366][366];
ll to[366][366];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	
	FOR(x,366) FOR(y,366) from[x][y]=-1LL<<60;
	from[0][K-1]=0;
	FOR(i,N) {
		FOR(x,366) FOR(y,366) to[x][y]=-1LL<<60;
		FOR(x,365) FOR(y,366) {
			if(y) to[x][y-1]=max(to[x][y-1],from[x][y]);
			to[x+1][K-1]=max(to[x+1][K-1],from[x][y]+A[i]);
		}
		swap(from,to);
	}
	ll ma=-1;
	FOR(y,366) ma=max(ma,from[M][y]);
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
