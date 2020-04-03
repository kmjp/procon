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

int N,K;
int A[20];
vector<int> V[1<<16];
int F[2050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		V[1<<i].push_back(A[i]);
	}
	
	for(i=1;i<=2020;i++) {
		F[i]=i;
		while(F[i]%K==0) F[i]/=K;
	}
	
	int mask;
	FOR(mask,1<<N) if(__builtin_popcount(mask)>=2) {
		for(int i=mask; i>0; i=(i-1)&mask) {
			j=mask^i;
			if(j>i&&i&&j) {
				FORR(a,V[i]) FORR(b,V[j]) V[mask].push_back(F[a+b]);
			}
		}
		sort(ALL(V[mask]));
		V[mask].erase(unique(ALL(V[mask])),V[mask].end());
		cout<<mask<<" "<<V[mask].size()<<endl;
	}
	
	if(V[(1<<N)-1][0]==1) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
