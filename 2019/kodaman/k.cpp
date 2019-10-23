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

int N,H,A,B;
int in[303030];
int out[303030];
int sum[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) {
		cin>>x>>y;
		in[x+1]++;
		out[y+1]++;
		sum[x+1]++;
		sum[y+1]--;
	}
	
	map<int,vector<int>> M;
	for(i=1;i<=H+1;i++) {
		in[i]+=in[i-1];
		out[i]+=out[i-1];
		sum[i]+=sum[i-1];
		if(i<=H) M[sum[i]].push_back(i-1);
	}
	vector<int> V;
	FORR(m,M) V.push_back(m.first);
	reverse(ALL(V));
	
	
	cin>>A;
	FOR(i,A) {
		cin>>x>>y;
		cout<<(in[y+1]-in[x+1])<<" "<<(out[y+1]-out[x+1])<<endl;
	}
	cin>>B;
	FOR(i,B) {
		cin>>x;
		auto v=M[V[x-1]];
		cout<<V[x-1]<<" "<<v.size();
		FORR(vv,v) cout<<" "<<vv;
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
