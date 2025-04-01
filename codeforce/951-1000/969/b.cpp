	#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N;
ll W;
int P[202020],D[202020];
vector<int> E[202020];
ll V[202020];
int NE[202020];
vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>W;
		FOR(i,N) {
			E[i].clear();
			ev[i].clear();
			V[i]--;
			NE[i]=0;
		}
		for(i=1;i<N;i++) {
			cin>>P[i];
			P[i]--;
			D[i]=D[P[i]]+1;
			E[P[i]].push_back(i);
		}
		FOR(i,N) {
			x=i;
			y=(x+1)%N;
			while(D[x]>D[y]) {
				ev[x].push_back(i);
				x=P[x];
				NE[i]++;
			}
			while(D[x]<D[y]) {
				ev[y].push_back(i);
				y=P[y];
				NE[i]++;
			}
			while(x!=y) {
				ev[y].push_back(i);
				y=P[y];
				ev[x].push_back(i);
				x=P[x];
				NE[i]+=2;
			}
		}
		
		ll unfix=W*N;
		ll fix=0;
		int num=N;
		FOR(i,N-1) {
			ll X,Y;
			cin>>X>>Y;
			X--;
			FORR(v,ev[X]) {
				fix+=Y;
				NE[v]--;
				if(NE[v]==0) num--;
			}
			W-=Y;
			ll sum=fix+W*num;
			cout<<sum<<" ";
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
