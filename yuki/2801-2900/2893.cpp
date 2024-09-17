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

int T,N;
ll F[28];

vector<int> L[20] = {
	{},
	{1},
	{1,2},
	{2,3},
	{3,4},
	{3,5},
	{5,6},
	{6,7},
	{4,5,6,8},
	{5,9},
	{7,10},
	{9,11},
	{1,4,6,12},
	{1,3,4,13},
	{1,3,5,14},
	{14,15},
	{4,13,15,16},
	{14,17},
	{11,18},
	{1,2,6,19},
};

int nex[4<<20];
int add[4<<20];
int addf[4<<20];
int pos[4<<20];

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
UF<1<<20> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,20) {
		F[i]=(1LL<<(i+1))+i;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(N==2) {
			cout<<"ab"<<endl;
			continue;
		}
		if(N==3) {
			cout<<"abb"<<endl;
			continue;
		}
		if(N==4) {
			cout<<"aabb"<<endl;
			continue;
		}
		if(N==5) {
			cout<<"aabba"<<endl;
			continue;
		}
		int tar=0;
		FOR(i,28) {
			if(N<=F[i]) {
				x=i-1;
				break;
			}
		}
		vector<int> V;
		FOR(i,x) V.push_back(0);
		V.push_back(1);
		FOR(i,(2<<x)-(x+1)) {
			int add=0;
			FORR(a,L[x+1]) add^=V[V.size()-a];
			V.push_back(add);
		}
		reverse(ALL(V));
		uf.reinit(4<<x);
		FOR(i,4<<x) nex[i]=add[i]=addf[i]=0, pos[i]=-1;
		FOR(i,(2<<x)) {
			int a=0;
			FOR(j,x+2) a=a*2+V[(i+j)%V.size()];
			nex[a]=-1;
			a=0;
			FOR(j,x+1) a=a*2+V[(i+j)%V.size()];
			pos[a]=i;
		}
		FOR(i,(4<<x)) if(nex[i]==0) {
			int a=i*2%(4<<x);
			int b=(i*2+1)%(4<<x);
			if(nex[a]==-1) nex[i]=b;
			else nex[i]=a;
			uf(i,nex[i]);
		}
		int nadd=N-(V.size()+x+1);
		int st=-1;
		FOR(i,2<<x) {
			int a=0;
			FOR(j,x+1) a=a*2+V[(i+j)%V.size()];
			int b=-1;
			if(nex[a*2+1]!=-1&&uf[a*2+1]==a*2+1) b=a*2+1;
			if(nex[a*2+0]!=-1&&uf[a*2+0]==a*2+0) b=a*2+0;
			if(b!=-1) {
				addf[a]=uf.count(b);
				add[a]=min(nadd,addf[a]);
				nadd-=add[a];
				pos[a]=i;
				if(nadd==0) {
					rotate(V.begin(),V.begin()+i,V.end());
					break;
				}
			}
		}
		
		FOR(i,x+1) V.push_back(V[i]);
		y=0;
		FOR(i,V.size()) {
			cout<<(char)('a'+V[i]);
			y=(y*2+V[i])%(2<<x);
			if(i>=x+1) {
				int cur=y;
				FOR(j,add[y]) {
					if(nex[(cur*2)%(4<<x)]>=0) {
						cur=(cur*2)%(2<<x);
					}
					else {
						cur=(cur*2+1)%(2<<x);
					}
					cout<<(char)('a'+cur%2);
					
				}
			}
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
