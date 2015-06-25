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

int N,M,K;
int W[101010],SS[101010],EN[101010];
vector<int> E[101010];
double sc[101010];
double ma=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,K) cin>>x, W[x-1]=1;
	FOR(i,N) EN[i]=1-W[i];
	while(M--) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	set<pair<double,int> > S;
	FOR(i,N) if(EN[i] && E[i].size()) {
		FORR(r,E[i]) SS[i]+=EN[r];
		sc[i]=SS[i]*1.0/E[i].size();
		S.insert({sc[i],i});
	}
	
	while(S.size()) {
		auto r=*S.begin();
		S.erase(S.begin());
		if(ma<r.first) ma=r.first;
		x=r.second;
		EN[x]=0;
		FORR(r2,E[x]) if(EN[r2]) {
			S.erase({sc[r2],r2});
			SS[r2]--;
			sc[r2]=SS[r2]*1.0/E[r2].size();
			S.insert({sc[r2],r2});
		}
	}
	FOR(i,N) EN[i]=1-W[i];
	
	FOR(i,N) if(EN[i] && E[i].size()) {
		SS[i]=0;
		FORR(r,E[i]) SS[i]+=EN[r];
		sc[i]=SS[i]*1.0/E[i].size();
		S.insert({sc[i],i});
	}
	
	
	while(S.size()) {
		auto r=*S.begin();
		S.erase(S.begin());
		if(ma==r.first) {
			x=0;
			FOR(i,N) x+=EN[i];
			_P("%d\n",x);
			FOR(i,N) if(EN[i]) _P("%d ",i+1);
			_P("\n");
			return;
		}
		x=r.second;
		EN[x]=0;
		FORR(r2,E[x]) if(EN[r2]) {
			S.erase({sc[r2],r2});
			SS[r2]--;
			sc[r2]=SS[r2]*1.0/E[r2].size();
			S.insert({sc[r2],r2});
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
