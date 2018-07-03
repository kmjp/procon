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
int L[101010],R[101010];
map<ll,ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];
	
	M[L[0]]=M[R[0]]=0;
	
	for(i=1;i<N;i++) {
		if(R[i]>M.rbegin()->first) {
			ll x=M.rbegin()->second+(R[i]-M.rbegin()->first);
			M[R[i]]=x;
		}
		else if(R[i]<M.begin()->first) {
			ll x=M.begin()->second+(M.begin()->first-R[i]);
			M[R[i]]=x;
		}
		else {
			auto it=M.lower_bound(R[i]+1);
			auto it2=it;
			it--;
			
			if(it->second==it2->second) M[R[i]]=it->second;
			else if(it->second<it2->second) M[R[i]]=it->second+(R[i]-it->first);
			else M[R[i]]=it->second-(R[i]-it->first);
		}
		if(L[i]>M.rbegin()->first) {
			ll x=M.rbegin()->second+(L[i]-M.rbegin()->first);
			M[L[i]]=x;
		}
		if(L[i]<M.begin()->first) {
			ll x=M.begin()->second+(M.begin()->first-L[i]);
			M[L[i]]=x;
		}
		else {
			auto it=M.lower_bound(L[i]+1);
			auto it2=it;
			it--;
			
			if(it->second==it2->second) M[L[i]]=it->second;
			else if(it->second<it2->second) M[L[i]]=it->second+(L[i]-it->first);
			else M[L[i]]=it->second-(L[i]-it->first);
		}
		
		while(M.begin()->first<L[i]) M.erase(M.begin());
		while(M.rbegin()->first>R[i]) M.erase(M.rbegin()->first);
		
		
	}
	
	ll mi=1LL<<60;
	FORR(m,M) mi=min(mi,m.second);
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
