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

int N;
int A[55],pos[55];

vector<pair<int,int>> R;

void doswap(int s,int t) {
	R.emplace_back(min(s,t),max(s,t));
	swap(A[s],A[t]);
	pos[A[t]]=t;
	pos[A[s]]=s;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1], pos[A[i+1]]=i+1;
	while(N>1) {
		while(A[N]!=N) {
			if(pos[1]<pos[N]) {
				for(i=pos[N]+1;i<=N;i++) if(i-A[i]>=1) break;
				
				while(i-A[i]>=pos[N]) {
					x=A[i];
					doswap(i,i-A[i]);
					i -= x;
				}
				
				if(i<pos[N]) continue;
				if(i-A[i]<1) continue;
				
				int tar=i-A[i];
				while(pos[1]<tar) doswap(pos[1],pos[1]+1);
				while(pos[1]>tar) doswap(pos[1],pos[1]-1);
				
				doswap(pos[1],i);
			}
			
			while(pos[1]>pos[N]) doswap(pos[1]-1,pos[1]);
		}
		N--;
	}
	_P("%d\n",R.size());
	FORR(r,R) _P("%d %d\n",r.first,r.second);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
