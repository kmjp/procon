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

int H,W,K;

map<int,vector<pair<int,int>>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	ll ret=1LL*H*W;
	
	while(K--){
		cin>>y>>i>>j;
		M[y].push_back({i,j});
	}
	FORR(r,M) {
		auto V=r.second;
		sort(ALL(V));
		
		ll st=-1,en=-1;
		FORR(e,V) {
			if(en<e.first) {
				ret -= en-st;
				st=e.first;
				en=e.second+1;
			}
			else {
				en=max(en,e.second+1LL);
			}
		}
		ret -= en-st;
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
