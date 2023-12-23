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

int H,W;
string S[1010];
int T[1010][1010];
const ll mo=998244353;
int NG;

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<1<<22> uf;

vector<pair<int,int>> cand[1<<22];
ll sum;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void add(int cur,int TL,int TR,pair<int,int> p,int CL,int CR) {
	if(CL>=CR) return;
	if(TL>CR) return;
	if(TR<=CL) return;
	TL=max(TL,CL);
	TR=min(TR,CR);
	if(TL==CL&&TR==CR) {
		cand[cur].push_back(p);
	}
	else {
		if(CR-CL>1) {
			int CM=(CL+CR)/2;
			add(cur*2,TL,TR,p,CL,CM);
			add(cur*2+1,TL,TR,p,CM,CR);
		}
	}
}

void dfs(int cur,int CL,int CR,int num) {
	if(CL>=CR) return;
	int step=0;
	int d[4]={0,1,0,-1},i;
	int cnum=num;
	FORR2(cy,cx,cand[cur]) {
		T[cy][cx]=1;
		cnum++;
		FOR(i,4) {
			int ty=cy+d[i];
			int tx=cx+d[i^1];
			if(T[ty][tx]&&uf[ty*2000+tx]!=uf[cy*2000+cx]) {
				step++;
				cnum--;
				uf(ty*2000+tx,cy*2000+cx);
			}
		}
	}
	if(CL+1==CR) {
		sum+=cnum;
	}
	else {
		int CM=(CL+CR)/2;
		dfs(cur*2,CL,CM,cnum);
		dfs(cur*2+1,CM,CR,cnum);
	}
	FORR2(cy,cx,cand[cur]) {
		T[cy][cx]=0;
	}
	while(step--) uf.pop();
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int NR=0;
	FOR(y,H) {
		cin>>S[y+1];
		FORR(c,S[y+1]) if(c=='#') NG++;
		S[y+1]='.'+S[y+1]+'.';
	}
	S[0]=S[H+1]=string(W+2,'.');
	H+=2;
	W+=2;
	
	int id=0;
	FOR(y,H) FOR(x,W) if(S[y][x]=='#') {
		add(1,0,id,{y,x},0,NG);
		add(1,id+1,NG,{y,x},0,NG);
		id++;
	}
	
	
	dfs(1,0,NG,0);
	
	
	
	sum=sum%mo*modpow(NG);
	cout<<sum%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
