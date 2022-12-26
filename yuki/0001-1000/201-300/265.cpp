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

int N,D;
string S;
int E[101010];

vector<ll> dodo(int L,int R) {
	vector<ll> ret(11,0), C(11,0);
	int i;
	
	if(L>=R) return ret;
	if(S[L]=='+') return dodo(L+1,R);
	
	if(S[L]=='d') {
		ret=dodo(L+2,E[L]);
		FOR(i,10) ret[i]=(i+1)*ret[i+1];
		ret[10]=0;
		L=E[L]+1;
	}
	else {
		int cur=1;
		int di=0;
		while(L<R) {
			if(S[L]=='x') di++;
			else cur*=S[L]-'0';
			
			L++;
			if(L>=R || S[L]!='*') {
				L++;
				break;
			}
			L++;
		}
		ret[di]=cur;
	}
	
	C=dodo(L,R);
	FOR(i,11) ret[i]+=C[i];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>D>>S;
	
	vector<int> v;
	FOR(i,N) {
		if(S[i]=='d') v.push_back(i);
		if(S[i]=='}') E[v.back()]=i, v.pop_back();
	}
	
	vector<ll> V=dodo(0,S.size());
	FOR(i,D+1) _P("%lld%c",V[i],(i==D)?'\n':' ');
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
