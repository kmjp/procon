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
vector<int> E[202020];
int P[202020];
int C[202020],L[202020],R[202020],R2[202020];
int id;
const ll mo=998244353;

int rev2=(mo+1)/2;
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
		return (ret*mul[k]+add[k]*(y-x))%mo;
	}
	void propagate(int k,int s) {
		(mul[k*2]*=mul[k])%=mo;
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		(add[k*2]+=add[k])%=mo;
		(sum[k*2]+=add[k]*s%mo*rev2)%=mo;
		(mul[k*2+1]*=mul[k])%=mo;
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		(add[k*2+1]+=add[k])%=mo;
		(sum[k*2+1]+=add[k]*s%mo*rev2)%=mo;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(add[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(add[k]+=v)%=mo;
			(sum[k]+=(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			(sum[k]=sum[k*2]+sum[k*2+1])%=mo;
		}
	}
};
SegTree_MulAdd<ll,1<<18> st;

void dfs(int cur,int pre) {
	P[cur]=pre;
	L[cur]=id;
	int i;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) E[cur].erase(E[cur].begin()+i);
	
	FORR(e,E[cur]) C[e]=id++;
	R2[cur]=id;
	FORR(e,E[cur]) dfs(e,cur);
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	C[0]=id++;
	dfs(0,0);
	FOR(i,N) {
		cin>>x;
		st.doadd(C[i],C[i]+1,x);
	}
	while(Q--) {
		int V,K,c,d;
		cin>>i>>V;
		V--;
		if(i==1) {
			cout<<st.getval(C[V],C[V]+1)<<endl;
		}
		else if(i==2) {
			cin>>K>>c>>d;
			st.domul(L[V],R2[V],c);
			st.doadd(L[V],R2[V],d);
			st.domul(C[V],C[V]+1,c);
			st.doadd(C[V],C[V]+1,d);
			if(V) {
				st.domul(C[P[V]],C[P[V]]+1,c);
				st.doadd(C[P[V]],C[P[V]]+1,d);
			}
		}
		else {
			cin>>c>>d;
			st.domul(L[V],R[V],c);
			st.doadd(L[V],R[V],d);
			st.domul(C[V],C[V]+1,c);
			st.doadd(C[V],C[V]+1,d);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
