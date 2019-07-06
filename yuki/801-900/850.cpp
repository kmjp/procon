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

int lose[333];
int ask(int x,int y) {
	int r;
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>r;
	return r;
}

int ans(int a) {
	cout<<"! "<<a<<endl;
	exit(0);
}

int win(int L,int R) {
	if(L+1>=R) return L;
	int M=(L+R)/2;
	
	int x=win(L,M);
	int y=win(M,R);
	if(ask(x,y)==x) {
		lose[y]=x;
		return x;
	}
	else {
		lose[x]=y;
		return y;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=win(1,N+1);
	
	vector<int> V;
	for(i=1;i<=N;i++) if(lose[i]==x) V.push_back(i);
	
	int cur=V[0];
	for(i=1;i<V.size();i++) cur=ask(cur,V[i]);
	ans(cur);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
