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
string S[101010];
map<pair<int,int>,vector<pair<int,pair<int,int>>>> M[101010];

int dfs(int pos,int L,int R) {
	vector<pair<int,pair<int,int>>> V;
	
	if(pos==K) return 0;
	
	for(int x=L;x<R;) {
		int LL=x;
		while(LL<R && S[LL][pos]==S[x][pos]) LL++;
		V.push_back({dfs(pos+1,x,LL),{x,LL}});
		x=LL;
	}
	
	sort(ALL(V));
	reverse(ALL(V));
	int ma=1,i;
	FOR(i,V.size()) ma=max(ma,V[i].first+i+1);
	
	M[pos][{L,R}]=V;
	return ma+1;
}

void dfs2(int pos,int L,int R) {
	if(pos==K) exit(0);
	
	auto V=M[pos][{L,R}];
	int x;
	FORR(v,V) {
		cout<<S[v.second.first][pos]<<endl;
		cin>>x;
		if(x) dfs2(pos+1,v.second.first,v.second.second);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>S[i];
	sort(S,S+N);
	
	dfs(0,0,N);
	dfs2(0,0,N);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
