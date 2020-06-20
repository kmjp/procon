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
int P[(1<<18)+1];
int D[1<<19];
int V[1<<19],W[1<<19];
int Q;
int T[1<<19],L[1<<19];
ll ret[1<<19];
vector<int> tar[1<<19];

vector<int> VV[1<<19];
vector<pair<int,ll>> cand[1<<19];

const int DI=12;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		if(i>1) {
			P[i]=i/2;
			D[i]=D[i/2]+1;
			VV[i]=VV[i/2];
		}
		VV[i].push_back(i);
		cin>>V[i]>>W[i];
		
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>L[i];
		tar[T[i]].push_back(i);
	}
	
	
	
	for(i=1;i<1<<DI;i++) if(i<=N) {
		vector<pair<ll,ll>> A;
		int len=VV[i].size();
		int mask;
		FOR(mask,1<<len) {
			int v=0,w=0;
			FOR(j,len) if(mask&(1<<j)) v+=V[VV[i][j]],w+=W[VV[i][j]];
			if(w<=100000) A.push_back({w,v});
		}
		
		sort(ALL(A));
		cand[i].push_back({0,0});
		FORR(a,A) {
			while(cand[i].size() && cand[i].back().first==a.first) cand[i].pop_back();
			if(cand[i].empty() || cand[i].back().second<a.second) {
				cand[i].push_back(a);
			}
		}
		
		FORR(t,tar[i]) {
			x=lower_bound(ALL(cand[i]),make_pair(L[t]+1,0LL))-cand[i].begin();
			x--;
			ret[t]=cand[i][x].second;
		}
	}
	
	for(i=1<<DI;i<1<<18;i++) if(i<=N) {
		vector<int> C;
		int p=0;
		FORR(c,VV[i]) {
			if(D[c]>=DI) C.push_back(c);
			else p=max(p,c);
		}
		
		
		FORR(t,tar[i]) {
			int len=C.size();
			int mask;
			FOR(mask,1<<len) {
				int v=0,w=0;
				FOR(j,len) if(mask&(1<<j)) v+=V[C[j]],w+=W[C[j]];
				if(w<=L[t]) {
					x=lower_bound(ALL(cand[p]),make_pair(L[t]-w+1,0LL))-cand[p].begin();
					x--;
					ret[t]=max(ret[t],cand[p][x].second+v);
				}
			}
		}
		
	}
	
	
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
