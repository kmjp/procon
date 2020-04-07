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

int N,K,C;
string S;

int A[202020];
vector<int> L,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>C>>S;
	C++;
	L.push_back(-1<<20);
	FOR(i,N) if(S[i]=='o') {
		if(L.back()+C<=i) L.push_back(i);
	}
	R.push_back(-1<<20);
	for(i=N-1;i>=0;i--) if(S[i]=='o') {
		if(i+C<=-R.back()) R.push_back(-i);
	}
	FORR(r,R) r=-r;
	reverse(ALL(R));
	
	FOR(i,N) if(S[i]=='o') {
		x=lower_bound(ALL(L),i)-L.begin()-1;
		y=L[x];
		j=lower_bound(ALL(R),max(y+C,i+1))-R.begin();
		j=R.size()-1-j;
		if(x+j<K) cout<<i+1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
