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


ll N;
string S[101010];
pair<string,int> P[101010];
int ID[101010];
ll M,X,D;

int com[101010][20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		P[i]={S[i],i};
	}
	sort(P,P+N);
	FOR(i,N) ID[P[i].second]=i;
	FOR(i,N-1) {
		x=P[i].second;
		y=P[i+1].second;
		FOR(r,min(S[x].size(),S[y].size())) if(S[x][r]!=S[y][r]) break;
		com[i][0]=r;
	}
	for(x=1;x<=19;x++) FOR(i,N-1) if(i+(1<<(x-1))<N) com[i][x]=min(com[i][x-1],com[i+(1<<(x-1))][x-1]);
	
	ll ret=0;
	cin>>M>>X>>D;
	for(int k=1;k<=M;k++) {
		x=X/(N-1);
		y=X%(N-1);
		if(x>y) swap(x,y);
		else y++;
		X = (X+D) % (N*(N-1));
		
		x=ID[x];
		y=ID[y];
		if(x>y) swap(x,y);
		
		r=0;
		while(1<<(1+r)<=y-x) r++;
		
		ret += min(com[x][r],com[y-(1<<r)][r]);
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
