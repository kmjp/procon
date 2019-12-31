#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

string S,S2;
string K;
int ok[256],id[256],unk,kn;
double memo[51][51];

double dodo(int left,int cand) {
	int i,j;
	if(left==0) return 0;
	if(left>cand) return 0;
	if(memo[left][cand]>=0) return memo[left][cand];
	
	memo[left][cand]=(1+dodo(left-1,cand-1))/cand + (3+dodo(left-1,cand-1))*(left-1)/cand + (2+dodo(left,cand-1))*(cand-left)/cand;
	
	return memo[left][cand];
}

void solve() {
	int f,i,j,k,l,x,y;
	int ret=0;
	cin>>S>>K;
	unk=36-K.size();
	ITR(it,K) ok[*it]=1;
	MINUS(id);
	
	FOR(x,51) FOR(y,51) memo[x][y]=-1;
	
	FOR(i,S.size()) {
		if(ok[S[i]]) ret++;
		else {
			ok[S[i]]=1;
			kn++;
		}
	}
	
	_P("%.12lf\n",ret+dodo(kn,unk));
	
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


