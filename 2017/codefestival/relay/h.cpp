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

int Q;
ll X[303];
ll ma;
int P[7]={2,3,5,7,11,13,17};
int R[7]={8,5,3,2,2,2,2};
int V[7]={0,0,0,0,0,0,0};

void hoge(ll m) {
	ll tot=0;
	int i,j,k;
	ll cnt[303]={};
	
	for(i=1;i<=300;i++) {
		int x=i;
		int ng=0;
		FOR(j,7) {
			FOR(k,V[j]) if(x%P[j]==0) x/=P[j];
			if(x%P[j]==0) ng=1;
		}
		if(ng==0) {
			if(x==1) tot+=X[i];
			else cnt[x]+=X[i];
		}
	}
	
	for(i=1;i<=300;i++) tot+=max(0LL,cnt[i]);
	ma=max(ma,tot);
}

void dfs(int cur,ll mul) {
	
	if(cur==7) {
		hoge(mul);
		return;
	}
	
	dfs(cur+1,mul);
	if(R[cur]) {
		R[cur]--;
		V[cur]++;
		dfs(cur,mul*P[cur]);
		V[cur]--;
		R[cur]++;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		X[x]+=y;
	}
	
	dfs(0,1);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
