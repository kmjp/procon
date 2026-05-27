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
};
UF<202020> uf;

int T,N,M,K;
vector<pair<int,int>> E[202020];
vector<vector<int>> Es;
map<int,int> V;
int D[202020];


struct Node {
	ll v;
	Node *L,*R;
	Node() { v=0, L=R=NULL;}
};

Node head;
void add(Node* now,ll v,int level,ll val) { // v‚ðvalŒÂ’Ç‰Á
	now->v+=val;
	if(level==-1) return;
	if(v&(1LL<<level)) {
		if(now->R==NULL) now->R=new Node();
		add(now->R,v,level-1,val);
	}
	else {
		if(now->L==NULL) now->L=new Node();
		add(now->L,v,level-1,val);
	}
}

ll ask(Node* now,ll K,ll v,int level) {
	ll ret=0;
	if(now==NULL || level<0) return 0;
	if(now->v==0) return 0;
	if(K&(1LL<<level)) {
		if(v&(1LL<<level)) {
			if(now->R) ret+=now->R->v;
			ret+=ask(now->L,K,v,level-1);
		}
		else {
			if(now->L) ret+=now->L->v;
			ret+=ask(now->R,K,v,level-1);
			
		}
	}
	else {
		if(v&(1LL<<level)) {
			ret+=ask(now->R,K,v,level-1);
		}
		else {
			ret+=ask(now->L,K,v,level-1);
		}
	}
	return ret;
}


void dfs(int cur,int pre,int d) {
	D[cur]=d;
	FORR2(e,c,E[cur]) if(e!=pre) dfs(e,cur,d^c);
}

template<class C> int gf2_rank(vector<C>& V) { /* input */
	int i,j;
	int N=V.size();
	FOR(i,N) {
		int x=max_element(V.begin()+i,V.end())-V.begin();
		if(V[x]==0) break;
		swap(V[i],V[x]);
		C msb=1;
		while(msb<<1 <= V[i]) msb<<=1;
		FOR(j,N) if(j!=i) if(V[j]&msb) V[j]^=V[i];
	}
	return N-count(V.begin(),V.end(),0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		uf.reinit(N);
		FOR(i,N) E[i].clear();
		Es.clear();
		FOR(i,M) {
			cin>>x>>y>>k;
			x--,y--;
			if(uf[x]!=uf[y]) {
				uf(x,y);
				E[x].push_back({y,k});
				E[y].push_back({x,k});
			}
			else {
				Es.push_back({x,y,k});
			}
		}
		dfs(0,0,0);
		vector<int> C;
		FORR(e,Es) {
			C.push_back(D[e[0]]^D[e[1]]^e[2]);
		}
		int r=gf2_rank(C);
		C.resize(r);
		FORR(c,C) {
			int msb=0;
			FOR(i,30) if(c&(1<<i)) msb=i;
			FOR(i,N) if(D[i]&(1<<msb)) D[i]^=c;
		}
		
		ll ret=0;
		head=Node();
		FOR(i,N) {
			x=D[i];
			ret+=ask(&head,K+1,x,30);
			add(&head,x,30,1);
		}
		cout<<ret<<endl;
		
	}
		
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
