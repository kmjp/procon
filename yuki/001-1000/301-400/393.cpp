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

int D;
int N1,N2;
int M,A[6060];
int from[101010];
int to[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	while(D--) {
		cin>>N1>>N2>>M;
		FOR(i,M) cin>>A[i];
		sort(A,A+M);
		
		MINUS(from);
		from[N1]=N2;
		for(i=0;i<M;i++) {
			MINUS(to);
			int ok=0;
			for(x=0;x<=N1;x++) if(from[x]>=0) {
				if(x>=A[i]) to[x-A[i]] = max(to[x-A[i]],from[x]), ok++;
				if(from[x]>=A[i]) to[x]=max(to[x],from[x]-A[i]), ok++;
			}
			if(ok==0) {
				_P("%d\n",i);
				break;
			}
			swap(from,to);
		}
		if(i==M) _P("%d\n",M);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
