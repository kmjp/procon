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
	void dump(int num=um) { //グループ分けした配列を作る
		int i;
		FOR(i,num) G[i].clear();
		FOR(i,num) G[operator[](i)].push_back(i);
	}
};

UF<10101> uf;

int H,W,N;
int num[101010][2];

ll Fmi[5050];
ll Fma[5050];
ll Tmi[5050];
ll Tma[5050];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>y>>x;
		y--,x--;
		uf(y,H+x);
	}
	FOR(y,H) num[uf[y]][0]++;
	FOR(x,W) num[uf[H+x]][1]++;
	
	for(y=1;y<=H;y++) Fmi[y]=1<<20,Fma[y]=-1<<20;
	FOR(i,H+W) {
		if(num[i][0]&&num[i][1]) {
			x=num[i][0];
			
			FOR(y,H+1) Tmi[y]=Fmi[y],Tma[y]=Fma[y];
			FOR(y,H+1) if(y+x<=H) {
				Tmi[y+x]=min(Tmi[y+x],Fmi[y]+num[i][1]);
				Tma[y+x]=max(Tma[y+x],Fma[y]+num[i][1]);
			}
			swap(Fma,Tma);
			swap(Fmi,Tmi);
		}
		else if(num[i][0]) {
			assert(num[i][0]==1);
			for(y=H;y>=1;y--) {
				Fmi[y]=min(Fmi[y],Fmi[y-1]);
				Fma[y]=max(Fma[y],Fma[y-1]);
			}
		}
		else if(num[i][1]) {
			assert(num[i][1]==1);
			FOR(y,H) {
				Fma[y]++;
			}
			
		}
	}
	
	int ret=0;
	FOR(y,H+1) for(x=Fmi[y];x<=Fma[y];x++) ret=max(ret,y*(W-x)+x*(H-y));
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
