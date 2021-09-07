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

int N,K;

ll from[2][66][909][63];
ll to[2][66][909][63];

ll comb(int P_,int Q_) {
	static const int N_=1020;
	static ll C_[N_][N_];
	
	if(C_[0][0]==0) {
		int i,j;
		FOR(i,N_) C_[i][0]=C_[i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[i][j]=(C_[i-1][j-1]+C_[i-1][j]);
	}
	if(P_<0 || P_>N_ || Q_<0 || Q_>P_) return 0;
	return C_[P_][Q_];
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	N=2*N+1;
	ll ret=0;
	int up=1;
	for(i=1;i<=N;i++) {
		if(i*(i-1)/2<=K) from[0][N-i][K-(i*(i-1)/2)][i+1]=1;
	}
	
	while(up) {
		ZERO(to);
		up=0;
		
		for(i=0;i<=N;i++) for(x=0;x<=K;x++) for(y=0;y<=N;y++) if(from[0][i][x][y]||from[1][i][x][y]) {
			up=1;
			if(i==0&&x==0&&y==0) ret+=from[1][i][x][y];
			if(y>=2) to[1][i][x][y-2]+=from[0][i][x][y];
			if(y>0) {
				for(j=y;j<=min(i,2*N);j++) {
					int add=j*(j-1)/2;
					if(add>x) break;
					to[0][i-j][x-add][j-y+2]+=from[0][i][x][y]*hcomb(y,j-y);
					to[1][i-j][x-add][j-y]+=from[1][i][x][y]*hcomb(y,j-y);
				}
			}
		}
		swap(from,to);
		
	}
	
	
	
	
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
