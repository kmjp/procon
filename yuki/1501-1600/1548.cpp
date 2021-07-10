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
template<class V,int NV> class SegTree_sum {
public:
	vector<V> val,sum;
	
	SegTree_sum(){val.resize(NV*2); sum.resize(NV*2,-1);};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		if(val[k]>=0) return val[k]*(min(y,r)-max(l,x))%mo;
		return (getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1))%mo;
	}
	
	void update(int x,int y,int v,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return;
		if(x<=l&&r<=y) {
			val[k]=v;
			sum[k]=1LL*v*(r-l)%mo;
		}
		else {
			if(val[k]!=-1) {
				update(l,(l+r)/2,val[k],l,(l+r)/2,k*2);
				update((l+r)/2,r,val[k],(l+r)/2,r,k*2+1);
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[2*k]+sum[2*k+1])%mo;
		}
	}
};
SegTree_sum<ll,1<<18> st[5];
int N,Q;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		ll v,w=1;
		cin>>v;
		FOR(j,5) {
			st[j].update(i,i+1,w);
			w=w*v%mo;
		}
	}
	cin>>Q;
	while(Q--) {
		int U,V,W;
		cin>>i>>U>>V>>W;
		U--,V--,W--;
		if(U>V) swap(U,V);
		if(W<U||V<W) swap(U,V);
		if(i==0) {
			ll v,w=1;
			cin>>v;
			FOR(j,5) {
				if(U<V) {
					st[j].update(U,V+1,w);
				}
				else {
					st[j].update(0,V+1,w);
					st[j].update(U,N,w);
				}
				w=w*v%mo;
			}
		}
		else {
			ll S[5]={};
			FOR(j,5) {
				if(U<V) {
					S[j]=st[j].getval(U,V+1);
				}
				else {
					S[j]=(st[j].getval(0,V+1)+st[j].getval(U,N))%mo;
				}
			}
			ll M=S[1]*modpow(S[0])%mo;
			ll s;
			if(i==1) s=S[1]-S[0]*M%mo;
			if(i==2) s=S[2]-2*S[1]*M%mo+S[0]*M%mo*M%mo;
			if(i==3) s=S[3]-3*S[2]*M%mo+3*S[1]*M%mo*M%mo-S[0]*M%mo*M%mo*M%mo;
			if(i==4) s=S[4]-4*S[3]*M%mo+6*S[2]*M%mo*M%mo-4*S[1]*M%mo*M%mo*M%mo+S[0]*M%mo*M%mo*M%mo*M%mo;
			s=(s%mo+mo)%mo*modpow(S[0])%mo;
			cout<<s<<endl;
			
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
