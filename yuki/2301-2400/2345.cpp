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
int T,N,M;
int C[202020];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
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
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+2) C[i]=0;
		FOR(i,N) {
			cin>>x;
			C[x]++;
		}
		int L=0,R=0;
		ll ret=1;
		int num=0;
		for(i=N-1;i>=0;i--) if(C[i]) {
			
			int cur=C[i];
			int lef=N-L-R-cur;
			if(lef==0) {
				if(max(L,R)==i) {
					num++;
				}
				else if(N%2==0&&i==N/2) {
					num+=2;
					ret=ret*comb(cur,N/2-L)%mo;
				}
				else {
					ret=0;
				}
			}
			else if(L==R) {
				if(L*2>=N||R*2>=N) ret=0;
				if(lef+L==i) {
					L+=cur;
					num++;
					ret=ret*2%mo;
				}
				else if(cur%2==0&&L+cur/2+lef==i) {
					L+=cur/2;
					R+=cur/2;
					ret=ret*comb(cur,cur/2)%mo;
					num+=2;
				}
				else {
					ret=0;
				}
			}
			else {
				if(L*2>=N||R*2>=N) ret=0;
				if(L+lef==i&&L+lef>=R) {
					R+=cur;
					num++;
				}
				else if(R+lef==i&&R+lef>=L) {
					L+=cur;
					num++;
				}
				else if((L+R+cur)%2==0&&abs(R-L)<=cur&&i==(N-lef)/2+lef) {
					ret=ret*comb(cur,(N-lef)/2-L)%mo;
					L=R=(N-lef)/2;
					num+=2;
				}
				else {
					ret=0;
				}
			}
		}
		ret=ret*comb(M,num)%mo;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
