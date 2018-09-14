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

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

template<class V,int NV> class SegTree_IdPair {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	void init(){ val.clear(); val.resize(NV*2,{def,NV}); }
	SegTree_IdPair(){ init(); };
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v,int id) {
		entry += NV;
		val[entry]=comp(val[entry],make_pair(v,id));
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};


template<int um> class ManhattanMST {
	UF<um> uf;
	SegTree_IdPair<ll,um*2> st[2];
	public:
	vector<pair<int,int>> P;
	vector<int> E;
	vector<pair<int,pair<int,int>>> Es;
	void add(int x,int y) {
		P.push_back({x,y});
	}
	void mst() {
		int N=P.size();
		int i,j;
		vector<pair<int,int>> cand[2];
		vector<int> Xs,Ys;
		FOR(i,N) {
			cand[0].push_back({P[i].first+P[i].second,i});
			cand[1].push_back({-P[i].first+P[i].second,i});
			Xs.push_back(P[i].first);
			Ys.push_back(P[i].second);
		}
		sort(ALL(Xs)); sort(ALL(Ys));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		Ys.erase(unique(ALL(Ys)),Ys.end());
		Es.clear();
		
		sort(ALL(cand[0]));
		st[0].init(); st[1].init();
		FORR(c,cand[0]) {
			int id=c.second;
			int x=lower_bound(ALL(Xs),P[id].first)-Xs.begin();
			int y=lower_bound(ALL(Ys),P[id].second)-Ys.begin();
			auto xp=st[0].getval(x,N), yp=st[1].getval(y,N);
			if(xp.second<N) Es.push_back({xp.first-(Xs[x]-Ys[y]),{id,xp.second}});
			if(yp.second<N) Es.push_back({yp.first-(Ys[y]-Xs[x]),{id,yp.second}});
			
			st[0].update(x,Xs[x]-Ys[y],id);
			st[1].update(y,Ys[y]-Xs[x],id);
		}
		sort(ALL(cand[1]));
		st[0].init(); st[1].init();
		FORR(c,cand[1]) {
			int id=c.second;
			int x=lower_bound(ALL(Xs),P[id].first)-Xs.begin();
			int y=lower_bound(ALL(Ys),P[id].second)-Ys.begin();
			auto xp=st[0].getval(0,x+1), yp=st[1].getval(y,N);
			if(xp.second<N) Es.push_back({xp.first-(-Xs[x]-Ys[y]),{id,xp.second}});
			if(yp.second<N) Es.push_back({yp.first-(Xs[x]+Ys[y]),{id,yp.second}});
			
			st[0].update(x,-Xs[x]-Ys[y],id);
			st[1].update(y,Xs[x]+Ys[y],id);
		}
		
		uf.reinit();
		vector<pair<int,pair<int,int>>> Es2;
		swap(Es2,Es);
		sort(ALL(Es2));
		FORR(e,Es2) {
			if(uf[e.second.first]!=uf[e.second.second]) {
				Es.push_back(e);
				uf(e.second.first,e.second.second);
			}
		}
	}
	
};



int N;
int X[252525],Y[252525];
ManhattanMST<1<<18> mst;
UF<252525> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> V[2];
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		mst.add(X[i],Y[i]);
	}
	
	mst.mst();
	ll ret=0;
	FORR(v,mst.Es) {
		if(uf[v.second.first]!=uf[v.second.second]) {
			ret+=1LL*(v.first/2)*uf.count(v.second.first)*uf.count(v.second.second);
			//cout<<v.second.first<<" "<<v.second.second<<" "<<v.first<<"*"<<uf.count(v.second.first)<<"*"<<uf.count(v.second.second)<<endl;
			uf(v.second.first,v.second.second);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
