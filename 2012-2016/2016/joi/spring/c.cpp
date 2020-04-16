#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[3];
const ll mo=1000000007;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll dp[2020][4060][2];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N;
	FOR(y,3) cin>>S[y];
	if(S[0][0]=='x') return _P("0\n");
	if(S[2][0]=='x') return _P("0\n");
	if(S[0][N-1]=='x') return _P("0\n");
	if(S[0][N-1]=='x') return _P("0\n");
	FOR(x,N-1) {
		if(S[0][x]=='x'&&S[0][x+1]=='x') return _P("0\n");
		if(S[2][x]=='x'&&S[2][x+1]=='x') return _P("0\n");
	}
	ll ret=1;
	ll num=0;
	FOR(x,N) {
		if(S[1][x]=='x') {
			
			int d=S[0][x]=='x';
			d+=S[1][x]=='x';
			d+=S[2][x]=='x';
			
			for(k=1;k<d;k++) dp[x][k][1]=fact[d-1];
			dp[x][d][0]=fact[d-1];
			x++;
			
			for(;;x++) {
				if(x>=N || S[1][x]=='o') break;
				int c=S[0][x]=='x';
				c+=S[1][x]=='x';
				c+=S[2][x]=='x';
				for(j=1;j<=d;j++) {
					(dp[x-1][j][0]+=dp[x-1][j-1][0])%=mo;
					(dp[x-1][j][1]+=dp[x-1][j-1][1])%=mo;
				}
				for(j=0;j<=d;j++) for(k=1;k<=c;k++) {
					if(k==c) {
						ll tmp=0;
						//for(y=0;y<=d;y++) tmp+=dp[x-1][y][0];
						//for(y=j+1;y<=d;y++) tmp+=dp[x-1][y][1];
						tmp=(dp[x-1][d][0]+dp[x-1][d][1]-dp[x-1][j][1]+mo)%mo;
						(dp[x][j+k][0]+=fact[c-1]*comb(j+k-1,k-1)%mo*tmp)%=mo;
					}
					else {
						ll tmp=dp[x-1][j][0];
						//for(y=0;y<=j;y++) tmp+=dp[x-1][y][0];
						tmp%=mo;
						(dp[x][j+k][1]+=fact[c-1]*comb(j+k-1,k-1)%mo*comb(c+d-(j+k),c-k)%mo*tmp)%=mo;
					}
				}
				d+=c;
			}
			
			x--;
			ll tmp=0;
			for(y=0;y<=d;y++) tmp+=dp[x][y][0]+dp[x][y][1];
			tmp%=mo;
			ret=ret*comb(num+d,d)%mo*tmp%mo;
			num+=d;
		}
		else {
			if(S[0][x]=='x') ret=ret*(++num)%mo;
			if(S[2][x]=='x') ret=ret*(++num)%mo;
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
