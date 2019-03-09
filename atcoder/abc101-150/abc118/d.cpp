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

int N,M;
int D[10]={0,2,5,5,4,5,6,3,7,6};
int C[10];

int num[101010];
int best[101010];

int hoge(int L) {
	if(L==0) return 0;
	if(num[L]!=-1) return num[L];
	
	num[L]=-101010;
	int i;
	
	FOR(i,10) if(C[i] && L>=C[i]) {
		int cand=hoge(L-C[i]);
		if(cand+1>=num[L]) num[L]=cand+1, best[L]=i;
	}
	return num[L];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x;
		C[x]=D[x];
	}
	MINUS(num);
	
	string S;
	hoge(N);
	while(N) {
		x=best[N];
		S.push_back('0'+x);
		N-=D[best[N]];
	}
	sort(ALL(S));
	reverse(ALL(S));
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
