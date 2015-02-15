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

int N,S1,S2;
int A[50001],B[50001];
vector<int> AL[50001],BL[50001];

int dodo(int cx,int cy,int d) {
	int sq=sqrt(d)+1;
	int res=0;
	int x,y;
	for(x=1;x<=sq&&cx+x<=50000;x++) if(AL[cx+x].size() && d/x>0)
		res+=upper_bound(ALL(AL[cx+x]),cy+d/x)-upper_bound(ALL(AL[cx+x]),cy);
	for(y=1;y<=sq&&cy+y<=50000;y++) if(cx+d/y>cx+sq && BL[cy+y].size())
		res+=upper_bound(ALL(BL[cy+y]),cx+d/y)-upper_bound(ALL(BL[cy+y]),cx+sq);
	return res;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>S1>>S2;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		AL[A[i]].push_back(B[i]);
		BL[B[i]].push_back(A[i]);
	}
	FOR(i,50001) sort(ALL(AL[i])),sort(ALL(BL[i]));
	
	ll ret=0;
	FOR(x,N) ret+=dodo(A[x],B[x],S2)-dodo(A[x],B[x],S1-1);
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
