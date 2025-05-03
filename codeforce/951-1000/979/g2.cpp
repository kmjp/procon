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

int T,N;
int L[1010101],R[1010101],LS[1010101];
ll p2[2020202];
const ll mo=998244353;

int X[1010101],Y[1010101];
vector<pair<int,pair<int,int>>> cand;

ll comb(ll N_, ll C_) {
	const int NUM_=2400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,2010101) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>L[i]>>R[i];
			LS[i+1]=0;
		}
		ll ret=0;
		FOR(j,2) {
			vector<pair<int,int>> V;
			FOR(i,N) {
				V.push_back({R[i],L[i]});
				LS[i+1]=0;
			}
			sort(ALL(V));
			FOR(i,N) {
				L[i]=V[i].second, R[i]=V[i].first;
				LS[L[i]]++;
			}
			FOR(i,N) LS[i+1]+=LS[i];
			x=y=0;
			ll cur=1;
			FOR(i,N) {
				X[i]=i;
				Y[i]=N-LS[R[i]];
				while(x>X[i]) (cur-=comb(y,x--))%=mo;
				while(y>X[i]+Y[i]) cur=(cur+comb(--y,x))*(mo+1)/2%mo;
				while(y<X[i]+Y[i]) cur=(2*cur-comb(y++,x))%mo;
				while(x<X[i]) (cur+=comb(y,++x))%=mo;
				cur=(cur%mo+mo)%mo;
				if(j==0) {
					(ret+=(mo-R[i])*(p2[X[i]+Y[i]]-cur)%mo*p2[N-1-X[i]-Y[i]])%=mo;
				}
				else {
					(ret+=(N+1-R[i])*(p2[X[i]+Y[i]]-cur)%mo*p2[N-1-X[i]-Y[i]])%=mo;
				}
			}
			
			FOR(i,N) {
				L[i]=N+1-L[i];
				R[i]=N+1-R[i];
				swap(L[i],R[i]);
			}
		}
		cout<<(ret%mo+mo)%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
