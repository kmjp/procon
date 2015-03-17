#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int ma;
vector<pair<ll,int> > E;
int num[505000];

void solve() {
	int i,j,k,l,r; ll x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		E.emplace_back(x-y,i+202000);
		E.emplace_back(x+y,i);
	}
	sort(E.begin(),E.end());
	FORR(e,E) {
		if(e.second>201000) num[e.second-202000]=ma+1;
		else ma=max(ma,num[e.second]);
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
