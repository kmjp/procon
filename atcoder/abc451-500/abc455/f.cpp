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
const ll mo=998244353;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> add,sum, sc;
	SegTree_3(){
		int i;
		add.resize(NV*2,0);
		sum.resize(NV*2,0); sc.resize(NV*2,0);
	};
	
	pair<V,V> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {0,0};
		if(x<=l && r<=y) return {sum[k],sc[k]};
		if(add[k]) {
			update(l,(l+r)/2,add[k],l,(l+r)/2,k*2);
			update((l+r)/2,r,add[k],(l+r)/2,r,k*2+1);
			add[k]=0;
			sum[k]=(sum[2*k]+sum[2*k+1])%mo;
			sc[k]=(sc[2*k]+sc[2*k+1]+sum[2*k]*sum[2*k+1])%mo;
		}
		
		auto p=getval(x,y,l,(l+r)/2,k*2);
		auto q=getval(x,y,(l+r)/2,r,k*2+1);
		ll sum=(p.first+q.first)%mo;
		ll sc=(p.second+q.second+p.first*q.first)%mo;
		
		return {sum,sc};
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			(add[k]+=v)%=mo;
			(sc[k]+=v*sum[k]%mo*(r-l-1))%=mo;
			(sc[k]+=v*v%mo*(1LL*(r-l)*(r-l-1)/2%mo))%=mo;
			(sum[k]+=1LL*(r-l)*v)%=mo;
		}
		else if(l < y && x < r) {
			update(l,(l+r)/2,add[k],l,(l+r)/2,k*2);
			update((l+r)/2,r,add[k],(l+r)/2,r,k*2+1);
			add[k]=0;
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[2*k]+sum[2*k+1])%mo;
			sc[k]=(sc[2*k]+sc[2*k+1]+sum[2*k]*sum[2*k+1])%mo;
		}
	}
};
SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>x>>y>>k;
		k%=mo;
		st.update(x,y+1,k);
		auto p=st.getval(x,y+1);
		cout<<p.second<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
