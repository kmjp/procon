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
set<int> S[101010];
int T[101010];
vector<int> C;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		S[x-1].insert(y-1);
		S[y-1].insert(x-1);
	}
	FOR(i,N) {
		cin>>x;
		C.push_back(x);
	}
	sort(ALL(C));
	set<pair<int,int>> cand;
	FOR(i,N) cand.insert({(int)S[i].size(),i});
	ll ret=0;
	FORR(c,C) {
		x=cand.begin()->second;
		cand.erase(cand.begin());
		T[x]=c;
		ret+=1LL*c*S[x].size();
		FORR(s,S[x]) {
			cand.erase({(int)S[s].size(),s});
			S[s].erase(x);
			cand.insert({(int)S[s].size(),s});
		}
	}
	
	cout<<ret<<endl;
	FOR(i,N) cout<<T[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
