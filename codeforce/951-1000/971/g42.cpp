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
int N,K,Q;
int A[202020];
ll B[202020];
int nex[202020],pre[202020];

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
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

int L[202020],R[202020];
ll ret[202020];

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
	int lower_bound(V val) { //’P’²‘‰Á‚ÌŽž‚Ì‚ÝŽg‚¦‚é
		V v0=0,v1=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) {
			if((ent+(1<<i)-1)*(v0+bit[0][ent+(1<<i)-1])+(v1+bit[1][ent+(1<<i)-1])<val) {
				v0+=bit[0][ent+(1<<i)-1];
				v1+=bit[1][ent+(1<<i)-1];
				ent+=(1<<i);
			}
		}
		return ent;
	}
};
BIT_r<ll,20> bt;

vector<int> add[202020];
vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>Q;
		map<int,int> C;
		multiset<int> S;
		FOR(i,N) {
			cin>>A[i];
			A[i]-=i;
			B[i]=0;
			x=A[i];
			if(C.count(x)) {
				S.erase(S.find(C[x]));
			}
			C[x]++;
			S.insert(C[x]);
			if(i>=K-1) {
				if(i>K-1) {
					x=A[i-K];
					S.erase(S.find(C[x]));
					C[x]--;
					S.insert(C[x]);
				}
				B[i-(K-1)]=K-*S.rbegin();
			}
			ev[i].clear();
			add[i].clear();
			ev[i].clear();
		}
		vector<pair<int,int>> V={{-1,0}};
		FOR(i,N) if(i+K<=N) {
			st.update(i,B[i]);
			while(V.back().first>B[i]) V.pop_back();
			pre[i]=V.back().second;
			V.push_back({B[i],i+1});
			add[pre[i]].push_back(i);
		}
		V={{-1,N-K+1}};
		for(i=N-K;i>=0;i--) {
			while(V.back().first>=B[i]) V.pop_back();
			nex[i]=V.back().second;
			V.push_back({B[i],i});
		}
		
		
		FOR(i,Q) {
			cin>>L[i]>>R[i];
			L[i]--;
			R[i]-=(K-1);
			
			
			ret[i]=0;
			auto p=st.getval(L[i],R[i]);
			x=p.second;
			if(pre[x]<L[i]&&R[i]<nex[x]) ret[i]=B[x]*(x-L[i]+1)*(R[i]-x);
			ev[L[i]].push_back(i);
		}
		
		
		for(i=N-K+1;i>=0;i--) {
			FORR(e,add[i]) if(e+1<=nex[e]-1) {
				bt.add(e+1,nex[e]-1,B[e]*(e-pre[e]+1));
				bt.add(nex[e],nex[e],-B[e]*(e-pre[e]+1)*(nex[e]-e-1));
			}
			add[i].clear();
			FORR(e,ev[i]) ret[e]+=bt.total(R[e]);
			ev[i].clear();
		}
		
		FOR(i,N+10) bt.add(i,i,-bt.total(i));
		
		FOR(i,N) if(i+K<=N) {
			add[nex[i]].push_back(i);
		}
		FOR(i,Q) {
			ev[R[i]].push_back(i);
		}
		FOR(i,N-K+2) {
			FORR(e,add[i]) bt.add(pre[e],e,B[e]*(nex[e]-e));
			add[i].clear();
			FORR(e,ev[i]) ret[e]+=bt.total(N)-bt.total(L[e]-1);
			ev[i].clear();
		}
		
		
		
		
		
		FOR(i,Q) {
			/*
			for(x=L[i];x<R[i];x++) cout<<B[x];
			cout<<" ";
			*/
			cout<<ret[i]<<endl;
		}
		FOR(i,N+10) bt.add(i,i,-bt.total(i));
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
