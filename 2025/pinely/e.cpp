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
string S;
const ll mo=998244353;
ll ret;

ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll hoge(string S) {
	ll ret=0;
	int i;
	
	//êÊì™(N-K-1)Ç™1
	FOR(i,N-K+1) if(S[i]=='0') break;
	if(i==N-K+1) {
		int C[3]={};
		for(i=N-K+1;i<N;i++) {
			if(S[i]=='0') C[0]++;
			if(S[i]=='1') C[1]++;
			if(S[i]=='?') C[2]++;
		}
		for(int pos=0;pos<=K-1;pos++) if(pos*2>K-1) {
			ret+=comb(C[2],pos-C[1]);
		}
	}
	int F0=N;
	FOR(i,N) if(S[i]=='0') {
		F0=i;
		break;
	}
	//cout<<S<<" "<<ret<<endl;
	int C[3]={};
	for(i=N-1;i>=0;i--) {
		int j=N-1-(N-1-i)%(K-1);
		if(C[0]+C[1]+C[2]==K-1&&C[0]<=K/2&&C[1]<=K/2&&F0>i) {
			if(i==0||S[j]=='0') ret+=comb(C[2],K/2-C[1]);
			else if(S[j]=='?') ret+=comb(C[2]-1,K/2-C[1]);
			//cout<<"#"<<i<<" "<<j<<" "<<S<<" "<<C[0]<<C[1]<<C[2]<<" "<<ret<<endl;
		}
		if(C[0]+C[1]+C[2]==K-1) {
			j=N-1-(N-1-i)%(K-1);
			if(i!=j) {
				if(S[j]=='0') C[0]--;
				if(S[j]=='1') C[1]--;
				if(S[j]=='?') C[2]--;
				if(S[i]=='0') {
					if(S[j]=='1') break;
					S[j]='0';
				}
				if(S[i]=='1') {
					if(S[j]=='0') break;
					S[j]='1';
				}
				S[i]=S[j];
			}
			
		}
		if(S[i]=='0') C[0]++;
		if(S[i]=='1') C[1]++;
		if(S[i]=='?') C[2]++;
		
	}
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		
		ll ret=hoge(S);
		FORR(c,S) {
			if(c=='0') c='1';
			else if(c=='1') c='0';
		}
		ret+=hoge(S);
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
