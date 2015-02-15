#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

struct RollingHash {
	static const ll mul0=10009,mul1=10007;
	static const ll add0=1000010007, add1=1003333331;
	string s; int l;
	ll hash_[300],pmo_[300];
	void init(string s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=0; pmo_[0]=1;
		FOR(i,l) pmo_[i+1]=pmo_[i]*mul0;
		FOR(i,l) hash_[i+1]=(hash_[i]*mul0+add0+s[i]);
	}
	ll hash(int l,int r) { // s[l..r]
		return hash_[r+1]-hash_[l]*pmo_[r+1-l];
	}
};

int R,C;
string S[2][300];
ll ret;
RollingHash rh[2][260];


void solve() {
	int i,j,k,l,r,x,y; string s;
	int x1,x2,y1,y2,mx,my;
	cin>>R>>C;
	
	FOR(y,R) {
		cin>>S[0][y];
		S[1][y]=S[0][y];
		reverse(S[1][y].begin(),S[1][y].end());
		rh[0][y].init(S[0][y]);
		rh[1][y].init(S[1][y]);
	}
	
	FOR(x1,C) for(x2=x1+1;x2<C;x2++) {
		FOR(y,R) {
			int t=y,b=y+1; //even
			while(t>=0 && b<R && rh[0][t].hash(x1,x2)==rh[1][b].hash(C-1-x2,C-1-x1)) ret++,t--,b++;
			t=b=y; // odd
			while(t>=0 && b<R && rh[0][t].hash(x1,x2)==rh[1][b].hash(C-1-x2,C-1-x1)) ret+=(t!=y),t--,b++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
