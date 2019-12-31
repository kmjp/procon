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
ll S,C;

set<pair<ll,ll> > SS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	SS.insert({2LL<<60,1LL<<60});
	
	cin>>N;
	FOR(i,N) {
		cin>>S>>C;
		ll OS=S;
		auto ss=SS.lower_bound({S,0});
		
		if(ss->second<=OS) {
			C+=ss->first-ss->second+1;
			S=OS=ss->second;
			SS.erase(ss);
		}
		
		while(C>0) {
			auto ss=SS.lower_bound({S,0});
			
			if(S+C==ss->second) {
				ll a=ss->first;
				SS.erase(ss);
				SS.insert({a,OS});
				cout<<S+C-1<<endl;
				break;
			}
			
			if(S+C-1 < ss->second-1) {
				SS.insert({S+C-1,OS});
				cout<<S+C-1<<endl;
				break;
			}
			
			C-=ss->second-S;
			S=ss->first+1;
			SS.erase(ss);
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
