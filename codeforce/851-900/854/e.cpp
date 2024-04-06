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


int T,H,W;
string S[55];

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
UF<2525> uf;

int TL[2525];
int TR[2525];
int TT[2525];
int TB[2525];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
		}
		while(1) {
			set<int> CR,CC;
			FOR(y,H) CR.insert(y);
			FOR(x,W) CC.insert(x);
			while(CR.size()||CC.size()) {
				set<int> NR,NC;
				FORR(y,CR) {
					int L=W,R=-1;
					FOR(x,W) if(S[y][x]=='#') L=min(L,x),R=max(R,x);
					for(x=L;x<=R;x++) {
						if(S[y][x]=='.') NR.insert(y),NC.insert(x);
						S[y][x]='#';
					}
				}
				FORR(x,CC) {
					int L=H,R=-1;
					FOR(y,H) if(S[y][x]=='#') L=min(L,y),R=max(R,y);
					for(y=L;y<=R;y++) {
						if(S[y][x]=='.') NR.insert(y),NC.insert(x);
						S[y][x]='#';
					}
				}
				swap(CR,NR);
				swap(CC,NC);
			}
			uf.reinit(H*W);
			FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
				TL[y*W+x]=W;
				TT[y*W+x]=H;
				TR[y*W+x]=TB[y*W+x]=-1;
				if(y&&S[y-1][x]=='#') uf(y*W+x,(y-1)*W+x);
				if(x&&S[y][x-1]=='#') uf(y*W+x,y*W+x-1);
			}
			set<int> SS;
			FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
				int v=uf[y*W+x];
				SS.insert(v);
				TL[v]=min(TL[v],x);
				TR[v]=max(TR[v],x);
				TT[v]=min(TT[v],y);
				TB[v]=max(TB[v],y);
			}
			if(SS.size()==1) break;
			assert(SS.size()==2);
			int a=*SS.begin();
			SS.erase(SS.begin());
			int b=*SS.begin();
			SS.erase(SS.begin());
			if(TR[a]>TL[b]) swap(a,b);
			if(TB[a]<TT[b]) {
				for(i=TR[a];i<=TL[b];i++) S[TB[a]][i]='#';
				for(i=TB[a];i<=TT[b];i++) S[i][TL[b]]='#';
			}
			else {
				for(i=TR[a];i<=TL[b];i++) S[TT[a]][i]='#';
				for(i=TT[a];i>=TB[b];i--) S[i][TL[b]]='#';
			}
			
		}
		FOR(y,H) cout<<S[y]<<endl;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
