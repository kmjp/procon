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
template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<2020> uf;
ll C[1010][2];
vector<int> E[1010];
ll D[1010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		uf(x*2,y*2+1);
		uf(x*2+1,y*2);
		E[x].push_back(y);
		E[y].push_back(x);
		
	}
	FOR(i,N) cin>>C[i][0];
	FOR(i,N) cin>>C[i][1];
	ll ret=0;
	if(uf[0]==uf[1]) {
		FOR(i,N) ret+=max(C[i][0],C[i][1]);
		
		ll mi=1LL<<60;
		
		FOR(i,N) {
			FOR(x,2) {
				FOR(j,N) D[j][0]=D[j][1]=1LL<<60;
				
				D[i][x]=max(C[i][0],C[i][1])-C[i][x];
				priority_queue<pair<ll,int>> Q;
				Q.push({-D[i][x],i*2+x});
				while(Q.size()) {
					ll co=-Q.top().first;
					int cur=Q.top().second/2;
					int id=Q.top().second%2;
					Q.pop();
					if(D[cur][id]!=co) continue;
					FORR(e,E[cur]) {
						ll sc=co+max(C[e][0],C[e][1])-C[e][id^1];
						if(D[e][id^1]>sc) {
							D[e][id^1]=sc;
							Q.push({-sc,e*2+(id^1)});
						}
					}
				}
				FORR(e,E[i]) mi=min(mi,D[e][x]);
			}
		}
		
		ret-=mi;
		
	}
	else {
		ll S[2]={};
		FOR(i,N) {
			S[0]+=C[i][uf[0]==uf[2*i]];
			S[1]+=C[i][uf[0]!=uf[2*i]];
		}
		ret=max(S[0],S[1]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
