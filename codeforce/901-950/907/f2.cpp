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

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return ret*mul[k]+add[k]*(y-x);
	}
	void propagate(int k,int s) {
		mul[k*2]*=mul[k];
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		add[k*2]+=add[k];
		sum[k*2]+=add[k]*s/2;
		mul[k*2+1]*=mul[k];
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		add[k*2+1]+=add[k];
		sum[k*2+1]+=add[k]*s/2;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mul[k]*=v;
			add[k]*=v;
			sum[k]*=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum[k]+=(r-l)*v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
};

SegTree_MulAdd<ll, 1<<19> st;
int id,L[505050],R[505050];
vector<int> C[505050];
int T,Q;
int t[505050],V[505050],X[505050];

void dfs(int cur) {
	L[cur]=id++;
	FORR(e,C[cur]) dfs(e);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		st.domul(0,1<<19,0);
		cin>>Q;
		FOR(i,Q) {
			C[i].clear();
		}
		int sz=1;
		FOR(i,Q) {
			cin>>t[i]>>V[i];
			V[i]--;
			if(t[i]==1) {
				X[i]=sz;
				C[V[i]].push_back(sz++);
			}
			else {
				cin>>X[i];
			}
		}
		id=0;
		dfs(0);
		FOR(i,Q) {
			if(t[i]==1) {
				st.domul(L[X[i]],R[X[i]],0);
			}
			else {
				st.doadd(L[V[i]],R[V[i]],X[i]);
			}
		}
		FOR(i,sz) cout<<st.getval(L[i],L[i]+1)<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
