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

ll mo;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int N;
ll F[201010];
ll FS[201010];
ll G[101010];

ll sum1[201010];
int sumA[201010][332];
int sumB[101010][332];

vector<int> di[101010];

ll getG(int d,int c) {
	ll ret=FS[d+c]-FS[max(d,c-1)];
	if(ret<0) ret+=mo;
	return ret;
}

ll getS(int p,int c) {
	ll ret=0;
	if(p>=330) {
		int i;
		for(i=1;i*p<=N;i++) {
			ret+=getG(p*i,c);
		}
	}
	else {
		int num=N/p;
		ret=(sumA[num*p+c][p]-sumA[c][p]-sumA[num*p][p]);
		int le=(c-1)/p;
		ret+=sumA[le*p][p];
		ret-=le*FS[c-1];
		ret=(ret%mo+mo)%mo;
		
	}
	return ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>mo;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	for(i=1;i<=N;i++) {
		for(j=i;j<=N;j+=i) di[j].push_back(i);
		sort(ALL(di[i]));
	}
	
	for(i=2;i<=2*N;i++) {
		if(i<=N) F[i]=modpow(N,N-i)*fact[N-2]%mo*factr[N-i]%mo;
		(FS[i]=FS[i-1]+F[i])%=mo;
	}
	ll add=0;
	for(i=N;i>=1;i--) {
		(add+=F[i+2])%=mo;
		(G[i]=G[i+1]+add)%=mo;
	}
	
	
	
	for(int L=1;L<=N;L++) {
		// L–¢–ž‚Ì‚Æ‚±‚ë‚Í“ž’B•s‰Â
		sum1[1]+=N+1-L;
		sum1[L]-=N+1-L;
		if(L<=330) {
			for(int d=1;d*L<=N;d++) {
				int add=0;
				for(x=1;x<L;x+=d) {
					sum1[d*L+x]++;
					++add;
				}
				sum1[(d+1)*L]-=add;
				
			}
		}
		else {
			for(int d=1;d*L<=N;d++){
				FOR(x,min(d,L-1)) {
					sumA[d*L+1+x][d]++;
					int add=(d+1)*L-(d*L+1+x);
					int dif=(add+d-1)/d;
					if((d*L+1+x)+dif*d<=N) {
						sumA[(d*L+1+x)+dif*d][d]--;
						sumB[(d*L+1+x)+dif*d][d]-=dif;
					}
				}
				
			}
		}
	}
	for(i=1;i<=N;i++) {
		sum1[i]+=sum1[i-1];
	}
	for(j=1;j<=330;j++) {
		ll a=0,b=0;
		for(i=j;i<=N;i++) {
			if(i>=j) {
				sumA[i][j]+=sumA[i-j][j];
				sumB[i][j]+=sumB[i-j][j];
			}
			(sumB[i][j]+=sumA[i][j])%=mo;
			sum1[i]+=sumB[i][j];
		}
	}
	ll ret=0;
	ll pat=0;
	ll SR=0;
	ll SL=1LL*N*(N+1)/2%mo;
	for(i=1;i<=N;i++) {
		// 2‚ª•Â˜HŠO
		(ret+=(SL+mo-sum1[i])%mo*G[i])%=mo;
		// 2‚ª•Â˜H“à
		(pat+=(1LL*i*(i+1)/2-1)%mo*F[i])%=mo;
		// L=i‚Æ‚µ‚½‚Æ‚«R>L‚Æ‚È‚éR‚Ì”
		SR+=N-i;
	}
	// 2‚ª•Â˜H“à‚ÅL>R
	(ret+=SR%mo*pat)%=mo;
	
	// 2‚ª•Â˜H“à‚©‚ÂL=R
	/*
	for(int d=1;d<=N-1;d++) for(int c=1;c<=N;c++) {
		ll g=(FS[d+c]+mo-FS[max(d,c-1)])%mo;
		for(int L=1;L<=N;L++) if(d%__gcd(c,L)==0) (ret+=g)%=mo;
	}
	*/
	for(j=1;j<=330;j++) {
		for(i=1;i<=2*N;i++) {
			sumA[i][j]=FS[i];
			if(i>=j) (sumA[i][j]+=sumA[i-j][j])%=mo;
		}
	}
	for(i=1;i<=N;i++) {
		vector<ll> V;
		FORR(d,di[i]) V.push_back(N/d);
		for(x=V.size()-1;x>=0;x--) for(y=x+1;y<V.size();y++) if(di[i][y]%di[i][x]==0) V[x]-=V[y];
		FOR(x,V.size()) (ret+=V[x]*getS(di[i][x],i))%=mo;
	}
	
	
	ret=ret*N%mo*(N-1)%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
