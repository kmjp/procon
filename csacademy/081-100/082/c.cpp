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

int N,S;
ll A[101010];
ll D[101010],L;
set<int> C;

ll dist(int a,int b) {
	if(a>b) swap(a,b);
	return min(D[b]-D[a],L+D[a]-D[b]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) {
		cin>>x;
		D[i+1]=D[i]+x;
		C.insert(i+N);
		C.insert(i);
		C.insert(i-N);
	}
	L=D[i];
	
	int cur=S-1;
	ll ret=0;
	while(C.size()>3) {
		C.erase(cur);
		C.erase(cur+N);
		C.erase(cur-N);
		
		int LL,RR;
		auto it=C.lower_bound(cur);
		RR=(*it+2*N)%N;
		it--;
		LL=(*it+2*N)%N;
		
		if(LL>RR) swap(LL,RR);
		int nex;
		if(dist(cur,LL)<=dist(cur,RR)) nex=LL;
		else nex=RR;
		ret+=dist(cur,nex);
		cur=nex;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
