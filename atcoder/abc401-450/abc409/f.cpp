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

int N,Q;
int X[3515],Y[3515];
int D[3515][3515];
template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
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
UF<3515> uf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>X[i]>>Y[i];
	priority_queue<pair<int,int>> PQ;
	FOR(y,N) FOR(x,y) {
		D[x][y]=D[y][x]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
		PQ.push({-D[x][y],x*10000+y});
		
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>X[N]>>Y[N];
			FOR(i,N) {
				D[i][N]=D[N][i]=abs(X[N]-X[i])+abs(Y[N]-Y[i]);
				PQ.push({-D[i][N],i*10000+N});
			}
			N++;
		}
		else if(i==2) {
			k=-1;
			while(PQ.size()) {
				auto p=PQ.top();
				x=p.second/10000;
				y=p.second%10000;
				PQ.pop();
				if(uf[x]==uf[y]) continue;
				uf(x,y);
				k=-p.first;
				while(PQ.size()&&PQ.top().first==-k) {
					auto p=PQ.top();
					PQ.pop();
					x=p.second/10000;
					y=p.second%10000;
					uf(x,y);
				}
				break;
				
			}
			cout<<k<<endl;
		}
		else if(i==3) {
			cin>>x>>y;
			if(uf[x-1]==uf[y-1]) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
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
