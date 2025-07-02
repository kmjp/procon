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
int ret[403430];

template<int um> class UF_pop {
	public:
	int num;
	vector<int> par,rank,cnt; vector<array<int,9>> hist;
	UF_pop() {par=rank=vector<int>(um,0); num=um; cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num_=um) {int i; hist.clear(); num=num_; FOR(i,num) rank[i]=0,par[i]=i,cnt[i]=1;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	int count(int x) {return cnt[operator[](x)];}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2]; cnt[a[0]]=a[3];
			par[a[4]]=a[5]; rank[a[4]]=a[6]; cnt[a[4]]=a[7];
			num=a[8];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],cnt[x],y,par[y],rank[y],cnt[y],num});
		if(x==y) return;
		num--;
		if(rank[x]<rank[y]) par[x]=y, cnt[y]+=cnt[x];
		else rank[x]+=(rank[x]==rank[y]), par[y]=x, cnt[x]+=cnt[y];
	}
};

UF_pop<404040> ufAB,ufB;


template<class V,int NV> class SegTree_dfs {
public:
	vector<vector<V>> ev;
	SegTree_dfs(){ev.resize(NV*2);};
	
	void dfs(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x||l>=y) return;
		//イベントをする
		FORR(e,ev[k]) {
			if(e[0]==0) ufAB(e[1],e[2]);
			ufB(e[1],e[2]);
		}
		
		if(r-l>1) {
			dfs(x,y,l,(l+r)/2,k*2);
			dfs(x,y,(l+r)/2,r,k*2+1);
		}
		else {
			ret[l]=ufAB.num-ufB.num;
		}
		//イベントを巻き戻す
		FORR(e,ev[k]) {
			if(e[0]==0) ufAB.pop();
			ufB.pop();
		}
		
	}
	
	void add_event(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			ev[k].push_back(v);
		}
		else if(l < y && x < r) {
			add_event(x,y,v,l,(l+r)/2,k*2);
			add_event(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_dfs<array<int,3>,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ufAB.reinit(N);
	ufB.reinit(N);
	map<pair<int,int>,int> pre[2];
	FOR(i,Q) {
		cin>>s>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		k=s=="B";
		
		if(pre[k].count({x,y})) {
			st.add_event(pre[k][{x,y}],i,{k,x,y});
			pre[k].erase({x,y});
		}
		else {
			pre[k][{x,y}]=i;
		}
	}
	FOR(k,2) FORR2(a,b,pre[k]) st.add_event(b,Q,{k,a.first,a.second});
	st.dfs(0,Q);
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
