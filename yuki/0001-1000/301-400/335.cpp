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
int A[1010];
ll ma=0;
int best=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		FOR(x,N) cin>>A[x];
		ll tot=0;
		
		FOR(x,N) {
			set<int> L,M,R;
			FOR(y,x) L.insert(A[y]);
			for(y=x+1;y<N;y++) R.insert(A[y]);
			for(y=x+1;y<N;y++) {
				int sc=0;
				
				R.erase(A[y]);
				if(L.size()) {
					if(A[x]<A[y] && *L.rbegin()>A[x]) sc=max(A[y],*L.rbegin());
					if(A[x]>A[y] && *L.begin()<A[x])  sc=max(sc,A[x]);
				}
				if(M.size()) {
					if(*M.rbegin()>max(A[x],A[y]))    sc=max(sc,*M.rbegin());
					if(*M.begin()<min(A[x],A[y]))     sc=max(sc,max(A[x],A[y]));
				}
				if(R.size()) {
					if(A[x]>A[y] && *R.rbegin()>A[y]) sc=max(sc,max(A[x],*R.rbegin()));
					if(A[x]<A[y] && *R.begin()<A[y])  sc=max(sc,A[y]);
				}
				
				tot+=sc;
				M.insert(A[y]);
			}
		}
		
		if(tot>ma) ma=tot,best=i;
	}
	cout<<best<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
