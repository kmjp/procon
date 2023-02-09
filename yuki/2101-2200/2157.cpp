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

int N,M;
int D[1515][1515];

int ok(int v) {
	vector<int> F(M,1);
	int i;
	FOR(i,N-1) {
		vector<int> G;
		int num=0;
		int j,L,R;
		for(j=0,L=R=0;j<M;j++) {
			while(R<M&&D[i][R]<=D[i+1][j]) num+=F[R++];
			while(L<M&&D[i][L]+v<D[i+1][j]) num-=F[L++];
			G.push_back(num>0);
		}
		
		swap(F,G);
	}
	
	return count(ALL(F),1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) {
		FOR(x,M) cin>>D[y][x];
		sort(D[y],D[y]+M);
	}
	ll ret=(1LL<<30)-1;
	if(ok(ret)==0) {
		cout<<-1<<endl;
	}
	else {
		for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
