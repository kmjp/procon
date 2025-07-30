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

static ll const def=-1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;

ll N,A;
ll X[202020],Y[202020],V[202020];
vector<ll> Ys;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	A*=2;
	map<ll,vector<int>> ev;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>V[i];
		X[i]*=2;
		Y[i]*=2;
		ev[X[i]-A-1].push_back(-1);
		ev[X[i]-A+1].push_back(-1);
		ev[X[i]-A].push_back(i);
		ev[X[i]+1].push_back(i+N);
		ev[X[i]].push_back(-1);
		ev[X[i]-1].push_back(-1);
		Ys.push_back(Y[i]+1);
		Ys.push_back(Y[i]);
		Ys.push_back(Y[i]-1);
		Ys.push_back(Y[i]-A-1);
		Ys.push_back(Y[i]-A);
		Ys.push_back(Y[i]-A+1);
	}
	sort(ALL(Ys));
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	ll ret=0;
	FORR2(x,is,ev) {
		FORR(i,is) if(i>=0) {
			if(i<N) {
				int s=lower_bound(ALL(Ys),Y[i]-A)-Ys.begin();
				int e=lower_bound(ALL(Ys),Y[i])-Ys.begin();
				st.update(s,e+1,V[i]);
			}
			else {
				i-=N;
				int s=lower_bound(ALL(Ys),Y[i]-A)-Ys.begin();
				int e=lower_bound(ALL(Ys),Y[i])-Ys.begin();
				st.update(s,e+1,-V[i]);
			}
		}
		ret=max(ret,st.getval(0,Ys.size()));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
