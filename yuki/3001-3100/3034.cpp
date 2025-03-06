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
int vis[1010];
int E[3030][3030];

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
UF<3030> uf,Luf[3030];
set<int> L[3030];
vector<bitset<3032>> D2,D1;
vector<int> L2,L1;
map<pair<int,int>,int> Eid;

void add(vector<bitset<3032>>& D,vector<int>& L,bitset<3032> B) {
	int nc=3032;
	int i,j;
	FOR(i,3032) if(B[i]) {
		nc=i;
		break;
	}
	FOR(j,D.size()) {
		if(nc>=3032) return;
		if(nc<L[j]) {
			L.insert(L.begin()+j,nc);
			D.insert(D.begin()+j,B);
			return;
		}
		if(nc==L[j]) {
			B^=D[j];
			nc=3032;
			FOR(i,3032) if(B[i]) {
				nc=i;
				break;
			}
		}
	}
	if(nc<3032) {
		D.push_back(B);
		L.push_back(nc);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	while(M--) {
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--,c--;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		vis[a]=vis[b]=vis[c]=1;
		uf(a,b);
		uf(a,c);
		Luf[a](b,c);
		Luf[b](a,c);
		Luf[c](a,b);
		L[a].insert(b);
		L[a].insert(c);
		L[b].insert(a);
		L[b].insert(c);
		L[c].insert(a);
		L[c].insert(b);
		E[a][b]=E[b][a]=E[a][c]=E[c][a]=E[b][c]=E[c][b]=1;
		
		int num=0;
		int sum=0;
		FOR(i,N) if(vis[i]) {
			num++;
			sum=uf.count(i);
		}
		
		bitset<3032> AE,AF;
		if(Eid.count({a,b})==0) {
			x=Eid.size();
			Eid[{a,b}]=x;
			AE[a]=AE[b]=1;
			add(D1,L1,AE);
			AE[a]=AE[b]=0;
		}
		if(Eid.count({a,c})==0) {
			x=Eid.size();
			Eid[{a,c}]=x;
			AE[a]=AE[c]=1;
			add(D1,L1,AE);
			AE[a]=AE[c]=0;
		}
		if(Eid.count({b,c})==0) {
			x=Eid.size();
			Eid[{b,c}]=x;
			AE[b]=AE[c]=1;
			add(D1,L1,AE);
			AE[b]=AE[c]=0;
		}
		AF[Eid[{a,b}]]=1;
		AF[Eid[{a,c}]]=1;
		AF[Eid[{b,c}]]=1;
		add(D2,L2,AF);
		
		int co=num==sum;
		
		int imd2=D2.size();
		int imd1=D1.size();
		int kerd1=Eid.size()-imd1;
		int h1 = (kerd1==imd2);
		
		int lk=1;
		FOR(i,N) if(vis[i]) {
			if(Luf[i].count(*L[i].begin())!=L[i].size()) lk=0;
		}
		
		
		
		if(!co) cout<<"CO"<<endl;
		else if(!h1) cout<<"H1"<<endl;
		else if(!lk) cout<<"LK"<<endl;
		else cout<<"CM"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
