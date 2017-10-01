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

int T;
int N;
int P[101010];
int Q[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int L,R;
		FOR(i,N) cin>>P[i];
		int mi=1<<30;
		FOR(i,2) {
			FOR(x,N) {
				if(i==0) Q[x]=P[x];
				else Q[x]=P[N-1-x];
				if(Q[x]==N/2) L=x;
				if(Q[x]==N/2+1) R=x;
			}
			int cost=0;
			if(L!=0) {
				cost++;
				swap(Q[0],Q[L]);
				if(R==0) swap(L,R);
				else L=0;
			}
			if(R!=N-1) {
				cost++;
				swap(Q[R],Q[N-1]);
			}
			
			for(x=1;x<N-1;x+=2) if(Q[x]<=N/2) cost++;
			mi=min(mi,cost);
		}
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
