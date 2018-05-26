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

int N,K,Q;
int A[2020];
int mi=1<<30;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N) {
		vector<int> P;
		vector<int> V;
		FOR(j,N) {
			if(A[j]<A[i]) {
				if(V.size()>=K) {
					sort(ALL(V));
					FOR(x,V.size()-K+1) P.push_back(V[x]);
				}
				V.clear();
			}
			else {
				V.push_back(A[j]);
			}
		}
		if(V.size()>=K) {
			sort(ALL(V));
			FOR(x,V.size()-K+1) P.push_back(V[x]);
		}
		if(P.size()<Q) continue;
		sort(ALL(P));
		mi=min(mi,P[Q-1]-P[0]);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
