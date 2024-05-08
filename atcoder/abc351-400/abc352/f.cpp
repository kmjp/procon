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
int E[16][16];
int mask[16];
bitset<1<<16> B;
int ret[16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1][y-1]=-k;
		E[y-1][x-1]=k;
		mask[x-1]|=1<<(y-1);
		mask[y-1]|=1<<(x-1);
	}
	
	FOR(i,N) FOR(k,N) FOR(x,N) FOR(y,N) if(E[x][k]&&E[k][y]) E[x][y]=E[x][k]+E[k][y], mask[x]|=1<<y;
	
	vector<pair<int,int>> cand;
	FOR(i,N) {
		int m=1;
		FOR(x,N) {
			if(E[i][x]<0) break;
			if(E[i][x]>0) m|=1<<E[i][x];
		}
		if(x==N) cand.push_back({i,m});
	}
	
	MINUS(ret);
	FORR2(i,m,cand) {
		B.reset();
		B[0]=1;
		queue<int> Q;
		Q.push(0);
		FORR2(i2,m2,cand) if(i2!=i) {
			queue<int> Q2;
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FOR(j,N) if(((m2<<j)&cur)==0&&((m2<<j)|cur)<(1<<N)&&B[((m2<<j)|cur)]==0) {
					B[((m2<<j)|cur)]=1;
					Q2.push((m2<<j)|cur);
				}
			}
			swap(Q2,Q);
		}
		int cand=0;
		FOR(j,N) if((m<<j)<1<<N&&B[(1<<N)-1-(m<<j)]) cand|=1<<j;
		if(__builtin_popcount(cand)==1) {
			x=0;
			while(cand>1) cand/=2,x++;
			ret[i]=x+1;
			FOR(j,N) if(E[i][j]!=0) ret[j]=x+1+E[i][j];
		}
		
		
	}
	FOR(i,N) cout<<ret[i]<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
