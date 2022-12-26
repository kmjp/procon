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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		int i;
		FOR(i,8) l[i]+=r[i];
		return l;
	}
	
	SegTree_1(){
		val.resize(NV*2);
	};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return V();
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //上書きかチェック
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<array<ll,8>,1<<20> st;

int N;
ll X[101010],Y[101010];
vector<ll> ev[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		st.update(Y[i],{0LL,0LL,0LL,0LL,1LL,X[i],Y[i],Y[i]*X[i]});
		ev[X[i]].push_back(Y[i]);
	}
	ll mi=1LL<<60;
	FOR(i,1000005) if(ev[i].size()) {
		auto a=st.getval(0,(1<<20)-1);
		ll v=a[0]*i-a[1]+a[5]-a[4]*i;
		if(v==0) {
			mi=0;
			break;
		}
		y=(1<<20)-1;
		ll sv;
		for(j=19;j>=0;j--) {
			int t=y-(1<<j);
			auto a=st.getval(0,t+1);
			ll v2=a[0]*i-a[1]+a[5]-a[4]*i;
			if(v2>=v/2) y=t, sv=v2;
		}
		
		a=st.getval(0,y+1);
		ll S=y*a[5]-a[4]*i*y-a[7]+i*a[6];  //右下
		S+=a[0]*i*y-a[1]*y-a[2]*i+a[3];  // 左下
		a=st.getval(y,(1<<20)-1);
		S+=a[7]-i*a[6]-a[5]*y+a[4]*i*y;  // 右上
		S+=a[1]*y-a[3]-a[0]*i*y+i*a[2];  // 左上
		
		mi=min(mi,S);
		
		FORR(e,ev[i]) {
			st.update(e,{1LL,i,e,i*e,-1,-i,-e,-i*e});
		}
	}
	cout<<(ll)mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
