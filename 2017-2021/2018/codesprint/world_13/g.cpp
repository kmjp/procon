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

int N,Q,K;
int P[101010];
int C[101010];
int S[101010];
int BP[101010];
const int DI=330;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>C[i];
	for(i=1;i<N;i++) cin>>P[i], P[i]--;
	
	FOR(i,N) {
		if(i && i/DI == P[i]/DI) {
			S[i]=S[P[i]]+C[i];
			BP[i]=BP[P[i]];
		}
		else {
			S[i]=C[i];
			BP[i]=i;
		}
	}
	
	while(Q--) {
		cin>>s;
		if(s=="T" || s=="C") {
			if(s=="T") {
				cin>>x;
				x--;
				C[x]^=1;
			}
			else {
				cin>>x>>y;
				x--,y--;
				P[x]=y;
			}
			for(i=x/DI*DI;i<min(N,(x/DI+1)*DI);i++) {
				if(i && i/DI == P[i]/DI) {
					S[i]=S[P[i]]+C[i];
					BP[i]=BP[P[i]];
				}
				else {
					S[i]=C[i];
					BP[i]=i;
				}
			}
		}
		else {
			cin>>x>>y>>K;
			x--,y--;
			int tx=x,ty=y,sx=0,sy=0,num=0;
			while(BP[tx]!=BP[ty]) {
				if(tx>ty) sx+=S[tx], tx=P[BP[tx]];
				else sy+=S[ty], ty=P[BP[ty]];
			}
			while(tx!=ty) {
				if(tx>ty) sx+=C[tx],tx=P[tx];
				else sy+=C[ty],ty=P[ty];
			}
			sy+=C[ty];
			
			if(sx+sy<K) {
				cout<<-1<<endl;
			}
			else if(K<=sx) {
				hogege:
				while(K>S[x]) {
					K-=S[x];
					x=P[BP[x]];
				}
				while(K) {
					K-=C[x];
					if(K==0) break;
					x=P[x];
				}
				cout<<x+1<<endl;
			}
			else {
				K=sy+1-(K-sx);
				x=y;
				goto hogege;
			}
			
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
