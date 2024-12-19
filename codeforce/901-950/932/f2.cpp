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

int T;
int N;
vector<int> E[202020];
int mi[202020],ma[202020];
vector<pair<int,int>> ret[202020];
int id;
int L[202020],R[202020];

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

void dfs(int cur,int pre) {
	L[cur]=id++;
	mi[cur]=ma[cur]=cur;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		chmin(mi[cur],mi[e]);
		chmax(ma[cur],ma[e]);
	}
	R[cur]=id;
}

int getid(int x,vector<int>& V,int s) {
	x=lower_bound(ALL(V),x)-V.begin();
	if(s==0) return x-1;
	if(x==V.size()) x=0;
	return x;
}

void dfs2(int cur,int pre,int Pmi,int Pma) {
	vector<int> mis,mas;
	vector<pair<int,int>> V;
	vector<int> ids;
	FORR(e,E[cur]) if(e!=pre) {
		ids.push_back(L[e]-1);
		V.push_back({mi[e],ma[e]});
		mis.push_back(mi[e]);
		mas.push_back(ma[e]);
	}
	if(cur) {
		mis.push_back(Pmi),mas.push_back(Pma);
		V.push_back({Pmi,Pma});
		ids.push_back(R[cur]-1);
	}
	mis.push_back(cur);
	mas.push_back(cur);
	
	ret[cur].clear();
	if(V.size()>1) {
		uf.reinit(V.size());
		int lef=V.size();
		FORR2(a,b,V) {
			if(a>0&&a-1!=cur) {
				int a1=getid(L[a],ids,cur);
				int a2=getid(L[a-1],ids,cur);
				if(uf[a1]!=uf[a2]) {
					uf(a1,a2);
					ret[cur].push_back({a-1,a});
					lef--;
				}
			}
			if(b<N-1&&b+1!=cur) {
				int a1=getid(L[b],ids,cur);
				int a2=getid(L[b+1],ids,cur);
				if(uf[a1]!=uf[a2]) {
					uf(a1,a2);
					ret[cur].push_back({b,b+1});
					lef--;
				}
			}
		}
		if(lef==2) ret[cur].push_back({cur-1,cur+1});
	}
	
	
	sort(ALL(mis));
	sort(ALL(mas));
	reverse(ALL(mas));
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur,mis[mi[e]==mis[0]],mas[ma[e]==mas[0]]);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		id=0;
		dfs(0,0);
		dfs2(0,0,N,0);
		FOR(i,N) {
			int sum=0;
			FORR2(a,b,ret[i]) sum+=b-a;
			cout<<sum<<" "<<ret[i].size()<<endl;
			FORR2(a,b,ret[i]) cout<<a+1<<" "<<b+1<<endl;
		}
	}
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
