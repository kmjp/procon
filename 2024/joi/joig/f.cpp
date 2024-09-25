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
int L[101010],R[101010];
int S[101010];
vector<int> ev[302020];
int TR[303030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<21> st;
int Q;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> Rbit,Lbit;

int P[202020],X[202020];

int ret[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Vs={0};
	vector<pair<int,int>> evs;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		Vs.push_back(L[i]);
		Vs.push_back(R[i]);
		evs.push_back({-(R[i]-L[i]),i});
	}
	sort(ALL(Vs));
	Vs.erase(unique(ALL(Vs)),Vs.end());
	FOR(i,N) {
		L[i]=lower_bound(ALL(Vs),L[i])-Vs.begin();
		R[i]=lower_bound(ALL(Vs),R[i])-Vs.begin();
		ev[L[i]].push_back(i);
		ev[R[i]].push_back(i+N);
	}
	multiset<int> Ls;
	FOR(i,Vs.size()) {
		TR[i]=1<<30;
		FORR(v,ev[i]) if(v>=N) Ls.erase(Ls.find(L[v-N]));
		FORR(v,ev[i]) if(v>=N) {
			if(Ls.empty()) TR[i]=0;
			else TR[i]=Vs[i]-Vs[*Ls.begin()];
		}
		FORR(v,ev[i]) if(v<N) Ls.insert(L[v]);
		st.update(i,TR[i]);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>P[i]>>X[i];
		P[i]--;
		evs.push_back({-X[i],i+N});
	}
	sort(ALL(evs));
	int c1=0;
	FORR2(x,ci,evs) {
		if(ci<N) {
			Rbit.add(R[ci],1);
			Lbit.add(L[ci],1);
			c1++;
		}
		else {
			int p=P[ci-N];
			int x=X[ci-N];
			
			if(Vs[R[p]]-Vs[L[p]]<x) {
				ret[ci-N]=1;
				continue;
			}
			
			int a=Vs[L[p]]+x,b=R[p];
			for(i=19;i>=0;i--) if(st.getval(b,b+(1<<i))>=x) b+=(1<<i);
			a=lower_bound(ALL(Vs),a)-Vs.begin()-1;
			b=lower_bound(ALL(Vs),Vs[b]-x+1)-Vs.begin()-1;
			ret[ci-N]+=c1;
			ret[ci-N]-=Rbit(a);
			ret[ci-N]-=Lbit(1<<19)-Lbit(b);
			
		}
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
