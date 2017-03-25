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

ll mo=1000000007;
const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll ret=0;

int GX,GY,K;
int X[10],Y[10],N[10];
vector<int> R;


void dfs(int id, int cx,int cy) {
	if(id==K) {
		if(cx!=GX || cy!=GY) return;
		
		int sum=0;
		FORR(r,R) sum+=r;
		ll t = fact[sum];
		FORR(r,R) t = t*factr[r]%mo;
		(ret = ret + t)%=mo;
		
	}
	else {
		int i;
		FOR(i,N[id]+1) {
			R.push_back(i);
			dfs(id+1,cx+X[id]*i,cy+Y[id]*i);
			R.pop_back();
		}
		
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>GX>>GY>>K;
	FOR(i,K) cin>>X[i]>>Y[i]>>N[i];
	
	dfs(0,0,0);
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
