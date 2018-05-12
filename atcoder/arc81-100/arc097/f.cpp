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
set<int> E[101010];
string C;
int dp[101010];
int ma;

int dfs(int cur,int pre) {
	vector<int> V(2,0);
	FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur));
	sort(ALL(V));
	reverse(ALL(V));
	
	ma=max(ma,C[cur]+V[0]+V[1]);
	return C[cur]+V[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	int ret=0;
	cin>>C;
	FOR(i,N) {
		C[i]=C[i]=='W';
		ret+=C[i];
	}
	if(ret==0) return _P("0\n");
	if(ret==1) return _P("1\n");
	
	queue<int> Q;
	FOR(i,N) if(E[i].size()==1) Q.push(i);
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		if(C[x]==0) {
			C[x]=2;
			y=*E[x].begin();
			E[y].erase(x);
			if(E[y].size()==1) Q.push(y);
		}
	}
	ret=-2;
	int root;
	FOR(i,N) if(C[i]!=2) {
		C[i]^=(E[i].size()%2);
		//cout<<i<<" "<<(int)C[i]<<endl;
		ret+=2+C[i];
		root=i;
	}
	dfs(root,-1);
	//cout<<ret<<" "<<ma<<endl;
	cout<<ret-2*ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
