#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,P,Q,R;
int X[500],Y[500],Z[500];
int mat[20][20];
ll ma;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P>>Q>>R;
	FOR(i,R) {
		cin>>X[i]>>Y[i]>>Z[i];
		mat[X[i]-1][Y[i]-1]=Z[i];
	}
	
	int mask;
	FOR(mask,1<<N) {
		if(__builtin_popcount(mask)!=P) continue;
		vector<int> V;
		
		FOR(i,M) {
			int t=0;
			FOR(j,N) if(mask&(1<<j)) t+=mat[j][i];
			V.push_back(t);
		}
		ll tot=0;
		sort(V.begin(),V.end());
		reverse(V.begin(),V.end());
		FOR(i,Q) tot+=V[i];
		ma=max(ma,tot);
		
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
