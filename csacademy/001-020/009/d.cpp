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
int A[101010];
ll S[101010];
int st[101010];
set<pair<ll,int>> SS;
set<int> E;

void ins(int s,int e) {
	if(s>e) return;
	st[e]=s;
	E.insert(e);
	SS.insert({S[e+1]-S[s],e});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	
	ins(0,N-1);
	
	FOR(i,N) {
		cout<<SS.rbegin()->first<<endl;
		cin>>x;
		x--;
		
		y=*E.lower_bound(x);
		SS.erase({S[y+1]-S[st[y]],y});
		E.erase(y);
		
		ins(st[y],x-1);
		ins(x+1,y);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
