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
vector<int> A;

int win(vector<int> V) {
	int num[2]={};
	int odd;
	
	FORR(r,V) {
		num[r%2]++;
		if(r%2==1) odd=r;
	}
	
	if(num[0]%2==1) return 1;
	if(num[1]>1 || odd==1) return 0;
	int g=0;
	FORR(r,V) {
		if(r==odd) r--;
		g=__gcd(g,r);
	}
	FORR(r,V) r/=g;
	return win(V)^1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	A.resize(N);
	FOR(i,N) cin>>A[i];
	
	if(win(A)) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
