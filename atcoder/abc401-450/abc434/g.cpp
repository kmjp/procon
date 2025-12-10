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

const ll mo=998244353;
ll p10[(1<<23)+10];
ll r10[(1<<23)+10];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	ll dfs(int id,int len) {
		if(len==0) return 0;
		if(val[id][1]==len) return val[id][2];
		if(val[2*id+1][1]>=len) return dfs(2*id+1,len);
		int lef=len-val[2*id+1][1];
		
		// lef+bŒ…
		assert(lef+val[2*id+1][0]<=val[2*id][1]);
		ll lv=dfs(2*id,lef+val[2*id+1][0]);
		// ¶‚Ì‰ºb‚¯‚½‚ðŽæ‚é
		ll bv=val[2*id][2]-(val[id][2]-val[2*id+1][2])*r10[val[2*id+1][1]]%mo*p10[val[2*id+1][0]]%mo;
		
		ll v=(lv-bv)*r10[val[2*id+1][0]]%mo*p10[val[2*id+1][1]]+val[2*id+1][2];
		return (v%mo+mo)%mo;
	}
	V comp(int lid,V l,V r){
		V m={0,0,0};
		if(l[1]<=r[0]) {
			m[0]=l[0]+r[0]-l[1];
			m[1]=r[1];
			m[2]=r[2];
		}
		else if(r[0]==0) {
			m[0]=l[0];
			m[1]=l[1]+r[1];
			m[2]=(l[2]*p10[r[1]]+r[2])%mo;
		}
		else {
			m[0]=l[0];
			m[1]=r[1]+l[1]-r[0];
			
			// ‰ºbŒ…
			ll lv=dfs(lid,r[0]);
			// ¶‚Ì‰ºb‚¯‚½‚ðˆø‚¢‚½‚à‚Ì
			ll bv=(l[2]-lv+mo)*r10[r[0]]%mo;
			m[2]=(r[2]+bv*p10[r[1]])%mo;
			
		}
		return m;
	};
	
	SegTree_ma(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(k*2, getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, char v) {
		entry += NV;
		if(v=='B') {
			val[entry]={1,0,0};
		}
		else {
			val[entry]={0,1,v-'0'};
		}
		while(entry>1) entry>>=1, val[entry]=comp(entry*2,val[entry*2],val[entry*2+1]);
	}
};
SegTree_ma<array<ll,3>,1<<23> st;

int N,Q;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=r10[0]=1;
	
	p10[1]=10;
	r10[1]=modpow(10);
	for(i=2;i<(1<<23)+5;i++) {
		p10[i]=p10[i-1]*p10[1]%mo;
		r10[i]=r10[i-1]*r10[1]%mo;
	}
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		if(S[i]=='B') {
			st.val[(1<<23)+i]={1,0,0};
		}
		else {
			st.val[(1<<23)+i]={0,1,S[i]-'0'};
		}
	}
	for(i=(1<<23)-1;i>=1;i--) st.val[i]=st.comp(2*i,st.val[2*i],st.val[2*i+1]);
	
	while(Q--) {
		cin>>i>>x;
		if(i==1) {
			string c;
			cin>>c;
			st.update(x-1,c[0]);
		}
		else {
			cin>>y;
			auto p=st.getval(x-1,y,0);
			if(p[1]==0) cout<<-1<<endl;
			else cout<<p[2]<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
