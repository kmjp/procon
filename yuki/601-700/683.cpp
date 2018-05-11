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

ll A,B;

set<pair<ll,ll>> S;

void dfs(ll a,ll b) {
	if(a<0 || b<0) return;
	if(S.count({a,b})) return;
	S.insert({a,b});
	if(a==0 || b==0) {
		cout<<"Yes"<<endl;
		exit(0);
	}
	
	if(a%2==0) dfs(a/2,b-1);
	if(b%2==0) dfs(a-1,b/2);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	dfs(A,B);
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
