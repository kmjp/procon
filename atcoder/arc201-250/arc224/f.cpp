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

int T,N,K;
ll A[202020];
const ll mo=998244353;


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
		cin>>N>>K;
		ll AOR=0;
		FOR(i,N) {
			cin>>A[i];
			AOR|=A[i];
		}
		
		ll A1=0;
		FOR(i,K) A1|=A[N-1-i];
		
		ll A0=(1LL<<60)-1-A1;
		
		ll sum=0;
		ll cur=0;
		FOR(i,K+1) (cur+=comb(N,i))%=mo;
		vector<array<ll,3>> F,T;
		F.push_back({0,K,cur});
		
		
		
		for(i=N-1;i>=0;i--) {
			T.clear();
			FORR(v,F) {
				ll flag=v[0];
				ll lef=v[1];
				ll cur=v[2];
				
				//0となるもののうち未確定
				ll f0=((1LL<<60)-1-flag)&A0;
				ll f1=((1LL<<60)-1-flag)&A1;
				
				//andを取ってよい
				if((f1&((1LL<<60)-1-A[i]))==0) {
					// nが減る
					ll ncur=(cur+comb(i,lef))*(mo+1)/2%mo;
					ll nflag=flag|(f0&((1LL<<60)-1-A[i]));
					
					if((nflag&AOR)==AOR) sum+=ncur;
					else T.push_back({nflag,lef,ncur});
				}
				if((f0&A[i])==0&&lef) {
					//nもkも減る
					ll ncur=(cur+mo-comb(i,lef))*(mo+1)/2%mo;
					ll nflag=flag|(f1&A[i]);
					
					if((nflag&AOR)==AOR) sum+=ncur;
					else T.push_back({nflag,lef-1,ncur});
				}
				
			}
			swap(F,T);
		}
		FORR(v,F) {
			ll flag=v[0];
			ll cur=v[2];
			//最後まで確定しないが、1は確定しきった場合
			if((flag&A1)==A1) sum+=cur;
		}
		
		
		cout<<sum%mo<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
