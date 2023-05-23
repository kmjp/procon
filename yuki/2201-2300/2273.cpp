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

ll OA[101010];
int N,Q,C;
ll mo;
int S[20];
int num[101010][20];
vector<int> cand;
ll phi;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt[20];

template<class V, int ME> class BITm {
public:
	V bit[1<<ME];
	BITm(){ for(int i=0;i<1<<ME;i++) bit[i]=1;}
	V operator()(int e) {if(e<0) return 1;V s=1;e++;while(e) (s*=bit[e-1])%=mo,e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]*=v)%=mo,e+=e&-e;}
};
BITm<ll,20> btm;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo>>Q;
	ll M=mo;
	phi=mo;
	for(i=2;i*i<=M;i++) if(M%i==0) {
		phi=phi/i*(i-1);
		cand.push_back(i);
		while(M%i==0) {
			S[C]++;
			M/=i;
		}
		C++;
	}
	if(M>1) {
		cand.push_back(M);
		phi=phi/M*(M-1);
		S[C]=1;
		C++;
	}
		
	
	FOR(i,N) {
		cin>>OA[i];
		ll a=OA[i];
		if(a) {
			FOR(j,C) {
				while(a%cand[j]==0) a/=cand[j], num[i][j]++;
				bt[j].add(i,num[i][j]);
			}
			btm.add(i,a%mo);
		}
		else {
			FOR(j,C) {
				num[i][j]=S[j];
				bt[j].add(i,num[i][j]);
			}
			btm.add(i,1);
		}
	}
	while(Q--) {
		int J,M,A,B;
		cin>>J>>M>>A>>B;
		
		if(M==0) {
			OA[J]=0;
			FOR(j,C) {
				num[J][j]=S[j];
				bt[j].add(J,num[J][j]);
			}
		}
		
		if(OA[J]) {
			int ok=0;
			if(M==mo) {
				ok=1;
				FOR(i,C) if(num[J][i]<S[i]) ok=0;
			}
			if(ok==0) {
				FOR(i,C) while(M%cand[i]==0) {
					M/=cand[i];
					num[J][i]++;
					bt[i].add(J,1);
				}
				btm.add(J,M%mo);
			}
			else {
				FOR(i,C) {
					num[J][i]-=S[i];
					bt[i].add(J,-S[i]);
				}
			}
		}
		
		ll a=btm(B)*modpow(btm(A-1),phi-1)%mo;
		FOR(j,C) {
			ll b=modpow(cand[j],bt[j](B)-bt[j](A-1));
			a=a*b%mo;
		}
		cout<<a<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
