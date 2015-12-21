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

int N,M;
ll X[202020],T[202020],C[202020];
ll P[202020],B[202020];
pair<int,int> F[202020];
set<pair<ll,int> > S;
set<pair<ll,int> > rem;

void extend(int x,int v) {
	S.erase({X[x]+T[x],x});
	while(1) {
		auto it=S.lower_bound({X[x]+T[x],0});
		if(it==S.end() || it->first>X[x]+T[x]+v) break;
		S.erase(it);
	}
	T[x]+=v;
	C[x]++;
	S.insert({X[x]+T[x],x});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i]>>T[i], F[i]={X[i],i};
	FOR(i,M) cin>>P[i]>>B[i];
	
	sort(F,F+N);
	FOR(i,N) {
		x=F[i].second;
		if(S.empty() || S.rbegin()->first<X[x]+T[x]) S.insert({X[x]+T[x],x});
	}
	
	FOR(i,M) {
		cin>>P[i]>>B[i];
		auto it = S.lower_bound({P[i],0});
		if(it!=S.end() && X[it->second]<=P[i]) {
			x=it->second;
			extend(x,B[i]);
			
			while(1) {
				auto rit=rem.lower_bound({X[x],0});
				if(rit==rem.end() || rit->first>X[x]+T[x]) break;
				extend(x,B[rit->second]);
				rem.erase(rit);
			}
		}
		else {
			rem.insert({P[i],i});
		}
	}
	FOR(i,N) cout<<C[i]<<" "<<T[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
