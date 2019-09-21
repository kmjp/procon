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
vector<int> R[1010];
vector<int> L[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>x>>j>>k;
		ret+=L[x].size();
		L[x].push_back(j);
		R[x].push_back(k);
	}
	FOR(i,1001) {
		sort(ALL(L[i]));
		sort(ALL(R[i]));
	}
	FOR(y,1001) FOR(x,y) {
		int mor=R[x].size()-(lower_bound(ALL(R[x]),y)-R[x].begin());
		int le=lower_bound(ALL(L[y]),x+1)-L[y].begin();
		ret+=1LL*le*mor;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
