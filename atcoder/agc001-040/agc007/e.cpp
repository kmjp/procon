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
vector<pair<int,int>> E[202020];
vector<pair<ll,ll>> S[202020];
ll ret;

int ok(ll v) {
	int i;
	for(i=N-1;i>=0;i--) {
		if(E[i].empty()) {
			S[i]={{0,0}};
		}
		else {
			int d1=E[i][0].second;
			int d2=E[i][1].second;
			vector<pair<ll,ll>>& s1=S[E[i][0].first];
			vector<pair<ll,ll>>& s2=S[E[i][1].first];
			vector<pair<ll,ll>> T;
			
			if(s2.size()<s1.size()) swap(s1,s2), swap(d1,d2);
			
			int R=0;
			FORR(r1,s1) {
				ll d=v-(r1.second+d1+d2);
				while(R<s2.size()-1&&s2[R+1].first<=d) R++;
				while(R>=0&&s2[R].first>d) R--;
				if(R>=0) T.push_back({r1.first+d1,s2[R].second+d2});
			}
			R=s2.size()-1;
			FORR(r1,s1) {
				ll d=v-(r1.first+d1+d2);
				while(R>=1&&s2[R-1].second<=d) R--;
				while(R<s2.size()&&s2[R].second>d) R++;
				if(R<s2.size()) T.push_back({s2[R].first+d2,r1.second+d1});
			}
			
			sort(ALL(T));
			S[i].clear();
			FORR(t,T) if(S[i].empty() || S[i].back().second>t.second) S[i].push_back(t);
		}
	}
	return S[0].size();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back({i+1,y});
	}
	
	ret=(1LL<<40)-1;
	for(i=39;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
