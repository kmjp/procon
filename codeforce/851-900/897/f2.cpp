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

int N;
vector<int> E[1202020];
int start[20],siz[20];
vector<vector<int>> A;
vector<int> S;
vector<ll> H;

unordered_set<ll> Hs;
vector<pair<int,int>> RE;
int D[20];
int ma;
ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000021};
	static ll sa=0,sb=0;
	
	if(sa==0) {
		srand(time(NULL));sa=rand()%(123456789);sb=rand()%(123456789);
	}
	
	sort(ALL(T));
	ll a=sa,b=sb;
	int add=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a*=h+add++)%=momo[0];
		(b*=l+add++)%=momo[1];
	}
	return (a<<32)+b;
}


void dfs(int lef,int pos,vector<int>& C,int& num) {
	if(num<=0) return;
	if(lef==0) {
		A.push_back(C);
		vector<ll> TH;
		FORR(c,C) TH.push_back(H[c]);
		H.push_back(tree_normalize(TH));
		num--;
		return;
	}
	pos=min(pos,start[lef]+siz[lef]-1);
	while(pos>=0) {
		C.push_back(pos);
		dfs(lef-S[pos],pos,C,num);
		C.pop_back();
		pos--;
	}
}

ll dfs2(int cur,int pre) {
	vector<ll> H;
	FORR(e,E[cur]) if(e!=pre) H.push_back(dfs2(e,cur));
	ll v=tree_normalize(H);
	Hs.insert(v);
	return v;
}

void dfs3(int cur,int& nex,int id) {
	FORR(c,A[id]) {
		int e=nex++;
		RE.push_back({cur,e});
		D[e]=D[cur]+1;
		if(D[e]>D[ma]) ma=e;
		
		dfs3(e,nex,c);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	start[1]=0;
	siz[1]=1;
	S.push_back(1);
	H.push_back(tree_normalize({}));
	
	A.resize(1);
	for(i=2;i<=17;i++) {
		start[i]=start[i-1]+siz[i-1];
		vector<int> C;
		x=1000001-S.size();
		dfs(i-1,A.size()-1,C,x);
		while(S.size()<A.size()) S.push_back(i);
		siz[i]=A.size()-start[i];
	}
	
	dfs2(0,0);
	FOR(i,1000001) {
		if(S[i]>N) {
			FOR(i,N) FORR(e,E[i]) if(e>i) cout<<i+1<<" "<<e+1<<"\n";
			return;
		}
		if(Hs.count(H[i])==0) break;
	}
	
	int nex=1;
	dfs3(0,nex,i);
	FORR2(a,b,RE) a+=N-nex, b+=N-nex;
	FOR(i,N-nex) RE.push_back({i,i+1});
	
	FORR2(a,b,RE) cout<<a+1<<" "<<b+1<<"\n";


	
	
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
