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

int N,K;
ll R;
ll hoge(int p) {
	ll ret=0;
	int i;
	for(i=1;i<=N;i++) {
		ret+=max(0,N-(max(i+K,p+1)-1));
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>R;
	if(R==0) {
		for(i=1;i<=N;i++) cout<<i<<" ";
		cout<<endl;
		return;
	}
	
	
	ll v=hoge(1);
	if(R>v) return _P("No Luck\n");
	if(R==v) {
		for(i=N;i>=1;i--) cout<<i<<" ";
		cout<<endl;
		return;
	}
	
	int p=1;
	for(i=20;i>=0;i--) {
		if(p+(1<<i)>=N) continue;
		if(hoge(p+(1<<i))>=R) p+=1<<i;
	}
	
	vector<int> V;
	for(i=N;i>=p+1;i--) V.push_back(i);
	for(i=1;i<=p;i++) V.push_back(i);
	R-=hoge(p);
	for(i=N-p-1;R;i++) {
		if(V[i+1]+K<=V[i]) {
			R++;
		}
		swap(V[i+1],V[i]);
	}
	
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
