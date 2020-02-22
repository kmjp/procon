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
int P[1010];
vector<int> E[1010];
int X[1010];
int A[1010],B[1010];

int from[5050];
int to[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		E[--P[i+1]].push_back(i+1);
	}
	FOR(i,N) cin>>X[i];
	
	for(i=N-1;i>=0;i--) {
		FOR(x,5050) from[x]=1LL<<30;
		from[0]=0;
		FORR(e,E[i]) {
			FOR(x,5050) to[x]=1LL<<30;
			FOR(x,5002) if(from[x]<1LL<<30) {
				to[min(5001,x+A[e])]=min({to[min(5001,x+A[e])],from[x]+B[e],5001});
				to[min(5001,x+B[e])]=min({to[min(5001,x+B[e])],from[x]+A[e],5001});
			}
			swap(from,to);
		}
		B[i]=1LL<<30;
		A[i]=X[i];
		FOR(x,X[i]+1) B[i]=min(B[i],from[x]);
		if(B[i]==1LL<<30) return _P("IMPOSSIBLE\n");
	}
	
	cout<<"POSSIBLE"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
