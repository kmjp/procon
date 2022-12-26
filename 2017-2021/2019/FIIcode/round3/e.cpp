#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int C[101010];
vector<int> E[200005];
int P[18][200005],D[200005];

vector<int> Cev[101010];
vector<pair<int,int>> ev[101010];
int T[202020],V[202020],CC[202020];
int CS[101010];

unordered_map<int,int> M;
int ret[101010];

vector<pair<int,int>> S;
unordered_map<ll,int> memo;

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	ll k=((1LL*a)<<30)+b;
	if(memo.count(k)) return memo[k];
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=17;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=17;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return memo[k]=D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];
}

template<int NV> class SegTree_2 {
public:
	vector<vector<int>> val;
	SegTree_2(){val.resize(NV*2);};
	
	
	void update(int x,int y, int v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].push_back(v);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
	
	void dfs(int L=0,int R=NV,int k=1) {
		FORR(v,val[k]) {
			if(S.empty()) {
				S.push_back({v,v});
			}
			else {
				int x=S.back().first;
				int y=S.back().second;
				int xy=dist(x,y);
				int xv=dist(x,v);
				int yv=dist(y,v);
				if(xy>=xv&&xy>=yv) {
					S.push_back({x,y});
				}
				else if(xv>=xy&&xv>=yv) {
					S.push_back({x,v});
				}
				else {
					S.push_back({y,v});
				}
			}
		}
		if(L+1==R) {
			if(M.count(L)) {
				ret[M[L]]=dist(S.back().first,S.back().second);
			}
		}
		else {
			dfs(L,(L+R)/2,k*2);
			dfs((L+R)/2,R,k*2+1);
		}
		FORR(v,val[k]) {
			S.pop_back();
		}
	}
	
};
SegTree_2<1<<19> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		ev[i].push_back({0,C[i]});
		Cev[i+1].push_back(0);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		x--;
		y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	for(i=1;i<=Q;i++) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>V[i]>>CC[i];
			V[i]--;
			Cev[ev[V[i]].back().second].push_back(i);
			Cev[CC[i]].push_back(i);
			ev[V[i]].push_back({i,CC[i]});
		}
		else {
			cin>>CC[i];
			Cev[CC[i]].push_back(i);
		}
	}
	for(i=1;i<=N;i++) {
		Cev[i].push_back(Q+1);
		CS[i]=CS[i-1]+Cev[i-1].size();
	}
	FOR(i,N) {
		ev[i].push_back({Q+1,1});
		FOR(j,ev[i].size()-1) {
			int c=ev[i][j].second;
			x=ev[i][j].first;
			y=ev[i][j+1].first;
			x=lower_bound(ALL(Cev[c]),x)-Cev[c].begin()+CS[c];
			y=lower_bound(ALL(Cev[c]),y)-Cev[c].begin()+CS[c];
			st.update(x,y,i);
			
		}
		
	}
	for(i=1;i<=Q;i++) {
		if(T[i]==2) {
			int c=CC[i];
			x=lower_bound(ALL(Cev[c]),i)-Cev[c].begin()+CS[c];
			M[x]=i;
		}
	}
	st.dfs();
	for(i=1;i<=Q;i++) if(T[i]==2) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
