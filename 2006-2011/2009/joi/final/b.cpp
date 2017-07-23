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

int D,N,M;
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>N>>M;
	V.push_back(0);
	V.push_back(D);
	V.push_back(2*D);
	FOR(i,N-1) {
		cin>>x;
		V.push_back(x);
		V.push_back(D+x);
		V.push_back(2*D+x);
	}
	sort(ALL(V));
	int ret=0;
	FOR(i,M) {
		cin>>x;
		y = lower_bound(ALL(V),D+x)-V.begin();
		
		ret += min(V[y]-(D+x),(D+x)-V[y-1]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
