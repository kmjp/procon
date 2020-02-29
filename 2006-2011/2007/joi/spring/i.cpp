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
short R[10101];
bool vis[10101];
short ret[10101];

vector<vector<short>> cand[10101];
vector<short> tr;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>R[i];
		R[i]--;
	}
	FOR(i,N) if(vis[i]==0) {
		vector<short> V;
		V.push_back(i);
		while(1) {
			vis[V.back()]=1;
			if(R[V.back()]==i) break;
			V.push_back(R[V.back()]);
		}
		if(V.size()==1) {
			ret[i]=i;
		}
		else {
			cand[V.size()].push_back(V);
		}
	}
	
	for(i=1;i<=N;i++) if(cand[i].size()) {
		for(x=1;x<=N;x++) if(K%x==0 && __gcd(K/x,i)==1) break;
		y=K/x;
		for(j=1;j<i;j++) if(j*y%i==1) break;
		if(j==i) return _P("0\n");
		while(cand[i].size()>=x) {
			FOR(k,i) FOR(l,x) tr.push_back(cand[i][l][k*j%i]);
			reverse(ALL(cand[i]));
			FOR(k,x) cand[i].pop_back();
			FOR(k,tr.size()) ret[tr[k]]=tr[(k+1)%tr.size()];
			tr.clear();
		}
		if(cand[i].size()) return _P("0\n");
	}
	
	FOR(i,N) cout<<ret[i]+1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
