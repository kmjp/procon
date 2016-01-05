#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M;
int A[4040],B[4040];
int in[4040],out[4040];
int st,en;
ll fact[8080];
int self[4040];

ll mo=1000000007;
int id[4040],rid[4040];
int edge[4040][4040];
ll mat[4040][4040];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		vector<int> V;
		for(y=x;y<N;y++) if(mat[y][x]) V.push_back(y);
		if(V.size()==0) return 0;
		y=V[rand()%V.size()];
		
		if(y!=x) {
			FOR(z,N) swap(mat[x][z],mat[y][z]);
			ret=(mo-ret)%mo;
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x]);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) if(mat[x][z]) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	fact[0]=1;
	FOR(i,8000) fact[i+1]=fact[i]*(i+1)%mo;
	
	cin>>N>>M;
	FOR(i,N) {
		FOR(j,N) edge[i][j]=-1;
		in[i]=out[i]=edge[i][i]=N-1;
		self[i]=1;
	}
	
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		
		if(x==y) {
			self[x]=0;
		}
		else {
			out[x]--;
			in[y]--;
			edge[x][y]=0;
			edge[y][y]--;
		}
	}
	
	x=0;
	st=en=-1;
	
	FOR(i,N) {
		if(in[i]==0 && out[i]==0 && self[i]==0) id[i]=-1;
		else id[i]=x, rid[x]=i, x++;
		if(abs(in[i]-out[i])>1) return _P("0\n");
		if(in[i]==out[i]+1) {
			if(en!=-1) return _P("0\n");
			en=i;
		}
		if(out[i]==in[i]+1){
			if(st!=-1) return _P("0\n");
			st=i;
		}
	}
	if(x==0 || x==1) return _P("1\n");
	
	
	ll pat=1;
	N=x;
	if(st>=0) { // odd
		in[st]++;
		out[en]++;
		FOR(i,N) if(self[rid[i]]) pat = pat*in[rid[i]] % mo;
		edge[en][st]--;
		edge[st][st]++;
	}
	else {
		ll tot=1;
		FOR(i,N) if(self[rid[i]]) tot = tot*in[rid[i]] % mo;
		pat=0;
		FOR(i,N) {
			if(self[rid[i]]) (pat += tot*(in[rid[i]]+1)%mo) %= mo;
			else (pat += tot*in[rid[i]]) %= mo;
		}
	}
	
	ll deg=1;
	FOR(i,N) deg = deg*fact[in[rid[i]]-1]%mo;
	FOR(i,N) FOR(j,N) mat[i][j]=edge[rid[i]][rid[j]];
	cout<<(pat*deg%mo*det_mo(N-1)%mo)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
