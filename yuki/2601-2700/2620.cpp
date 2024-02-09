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

ll L;
int N;
ll A[1010];
int p2[1010],p3[1010];

const int prime_max = 2000000;
int MU[prime_max+1];
int num[prime_max+1];

void mebius() {
	int i,j;
	for(i=1;i<=prime_max;i++) MU[i]=1, num[i]=i;
	for(int i=2;i<=prime_max;i++) if(num[i]==i) {
		for(j=i;j<=prime_max;j+=i) {
			int x=0;
			MU[j]=-MU[j];
			while(num[j]%i==0) {
				x++;
				num[j]/=i;
			}
			if(x>=2) MU[j]=0;
		}
	}
}

ll G(ll L,int a,int b) {
	static ll memo[1<<20][2][2];
	if(L==0) return 0;
	if(memo[L][a][b]) return memo[L][a][b];
	ll ret=0;
	for(ll i=1;i*i<=L;i++) {
		ll k=0;
		if(i%2==0&&a) k=0;
		else if(i%3==0&&b) k=0;
		else {
			ll pat=L/(i*i);
			k=pat;
			if(a) k-=pat/2;
			if(b) k-=pat/3;
			if(a&&b) k+=pat/6;
		}
		
		ret+=MU[i]*k;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int C[60][60]={};
	mebius();
	cin>>L>>N;
	FOR(i,N) {
		cin>>A[i];
		while(A[i]%2==0) {
			p2[i]++;
			A[i]/=2;
		}
		while(A[i]%3==0) {
			p3[i]++;
			A[i]/=3;
		}
		C[p2[i]][p3[i]]++;
	}
	
	ll ret=0;
	int mask;
	FOR(i,56) FOR(j,56) {
		FOR(mask,1<<4) if(mask) {
			int num=0;
			if(mask&1) num+=C[i][j];
			if(mask&2) num+=C[i][j+1];
			if(mask&4) num+=C[i+1][j];
			if(mask&8) num+=C[i+1][j+1];
			if(num==__builtin_popcount(mask)) {
				if(mask==2||mask==4||mask==8) continue;
				if(mask==12||mask==10) continue;
				ll V=L;
				FOR(k,i+((mask&12)>0)) V/=2;
				FOR(k,j+((mask&10)>0)) V/=3;
				V=G(V,((mask&12)>0),((mask&10)>0));
				FOR(k,__builtin_popcount(mask)-1) V=V*-2;
				ret+=V;
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
