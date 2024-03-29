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

int N,M,Q;
ll A[202020];
vector<int> add[202020],del[202020];
int L[202020],R[202020],X[202020];

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

map<int,vector<int>> cand;
map<int,vector<int>> query;
int vis[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	multiset<int> C={M};
	FOR(i,Q) {
		cin>>L[i]>>R[i]>>X[i];
		add[L[i]].push_back(X[i]);
		del[R[i]].push_back(X[i]);
		query[X[i]].push_back(i);
	}
	for(i=1;i<=N;i++) {
		FORR(a,add[i]) C.insert(a);
		A[i]=*C.begin();
		cand[A[i]].push_back(i);
		FORR(a,del[i]) C.erase(C.find(a));
	}
	ll ret=1;
	FORR2(a,b,query) {
		st.domul(0,N+1,0);
		st.doadd(0,1,1);
		set<int> T;
		map<int,int> M;
		FORR(c,cand[a]) T.insert(c);
		FORR(i,b) {
			T.insert(R[i]);
			M[R[i]]=max(M[R[i]],L[i]);
		}
		FORR(t,T) {
			if(A[t]==a) {
				vis[t]=1;
				ll v=st.getval(0,t);
				st.domul(0,t,a);
				st.doadd(t,t+1,v);
			}
			st.domul(0,M[t],0);
		}
		ret=ret*st.getval(0,N+1)%mo;
		
	}
	for(i=1;i<=N;i++) if(vis[i]==0) ret=ret*(M+1)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
