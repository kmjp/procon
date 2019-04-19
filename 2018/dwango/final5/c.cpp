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
UF<101010> uf;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=1<<30;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return min(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v, int k) {
		entry += NV;
		val[entry]=min(val[entry],make_pair(v,k));
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<18> st;
int N;
vector<int> C;
int L[101010],R[101010];
vector<int> G[101010];
pair<int,int> tar[101010];
vector<int> LV[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	C.push_back(0);
	FOR(i,N) {
		cin>>L[i]>>R[i];
		C.push_back(L[i]);
		C.push_back(R[i]);
	}
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	FOR(i,N) {
		L[i]=lower_bound(ALL(C),L[i])-C.begin();
		R[i]=lower_bound(ALL(C),R[i])-C.begin();
		LV[L[i]].push_back(i);
	}
	
	ll ret=0;
	while(uf.count(0)<N) {
		FOR(i,N) {
			G[i].clear();
			tar[i]={1<<30,-1};
		}
		FOR(i,N) G[uf[i]].push_back(i);
		FOR(i,st.val.size()) st.val[i]={1<<30,-1};
		map<int,int> Ls,Rs;
		FOR(i,N) if(G[i].size()) {
			FORR(e,G[i]) {
				auto it=Ls.lower_bound(R[e]);
				if(it!=Ls.begin()) {
					it--;
					if(it->first>=L[e] && C[R[e]]-C[it->first]<tar[e].first) {
						tar[e]={C[R[e]]-C[it->first], it->second};
					}
				}
				it=Rs.lower_bound(L[e]+1);
				if(it!=Rs.end()) {
					if(it->first<=R[e] && C[it->first]-C[L[e]]<tar[e].first) {
						tar[e]={C[it->first]-C[L[e]], it->second};
					}
				}
				tar[e]=min(tar[e],st.getval(L[e],R[e]));
			}
			FORR(e,G[i]) {
				Ls[L[e]]=i;
				Rs[R[e]]=i;
				st.update(L[e],C[R[e]]-C[L[e]],uf[e]);
			}
		}
		FOR(i,st.val.size()) st.val[i]={1<<30,-1};
		Ls.clear();
		Rs.clear();
		for(i=N-1;i>=0;i--) {
			FORR(e,G[i]) {
				auto it=Ls.lower_bound(R[e]);
				if(it!=Ls.begin()) {
					it--;
					if(it->first>=L[e] && C[R[e]]-C[it->first]<tar[e].first) {
						tar[e]={C[R[e]]-C[it->first], it->second};
					}
				}
				it=Rs.lower_bound(L[e]+1);
				if(it!=Rs.end()) {
					if(it->first<=R[e] && C[it->first]-C[L[e]]<tar[e].first) {
						tar[e]={C[it->first]-C[L[e]], it->second};
					}
				}
				tar[e]=min(tar[e],st.getval(L[e],R[e]));
			}
			FORR(e,G[i]) {
				Ls[L[e]]=i;
				Rs[R[e]]=i;
				st.update(L[e],C[R[e]]-C[L[e]],uf[e]);
			}
		}
		
		pair<int,int> RC[3]={{-1,-1},{-1,-1},{-1,-1}};
		FOR(i,C.size()) if(LV[i].size()) {
			FORR(e,LV[i]) {
				RC[2]={R[e],uf[e]};
				sort(RC,RC+3);
				reverse(RC,RC+3);
				if(RC[0].second==RC[1].second) RC[1]=RC[2];
			}
			FORR(e,LV[i]) {
				if(RC[0].second!=uf[e] && RC[0].first>=R[e]) tar[e]=min(tar[e],{C[R[e]]-C[L[e]],RC[0].second});
				if(RC[1].second!=uf[e] && RC[1].first>=R[e]) tar[e]=min(tar[e],{C[R[e]]-C[L[e]],RC[1].second});
			}
		}
		
		int add=0;
		FOR(i,N) tar[uf[i]]=min(tar[uf[i]],tar[i]);
		FOR(i,N) if(i==uf[i]) {
			if(tar[i].second>=0 && uf[i]!=uf[tar[i].second]) {
				add++;
				ret+=tar[i].first;
				uf(i,tar[i].second);
			}
		}
		if(add==0) return _P("-1\n");
		
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
