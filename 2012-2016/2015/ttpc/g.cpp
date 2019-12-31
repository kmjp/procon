#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

char did[17][17][17][17][17][17];
int L;
string S;

void dfs(int cur,vector<int>& v) {
	if(cur==L) {
		if(v[0]+v[1]+v[2]+v[3]+v[4]+v[5]) return;
		_P("Yes\n");
		exit(0); 
	}
	
	if(did[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]]) return;
	did[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]] = 1;
	int i;
	if(S[cur]=='t') {
		i=0; if(v[i]&&v[i+1]<L/6) v[i]--, v[i+1]++, dfs(cur+1,v), v[i]++, v[i+1]--;
		i=2; if(v[i]&&v[i+1]<L/6) v[i]--, v[i+1]++, dfs(cur+1,v), v[i]++, v[i+1]--;
	}
	else if(S[cur]=='i') {
		i=1; if(v[i]&&v[i+1]<L/6) v[i]--, v[i+1]++, dfs(cur+1,v), v[i]++, v[i+1]--;
	}
	else if(S[cur]=='e') {
		i=3; if(v[i]&&v[i+1]<L/6) v[i]--, v[i+1]++, dfs(cur+1,v), v[i]++, v[i+1]--;
	}
	else if(S[cur]=='c') {
		i=4; if(v[i]&&v[i+1]<L/6) v[i]--, v[i+1]++, dfs(cur+1,v), v[i]++, v[i+1]--;
	}
	else if(S[cur]=='h') {
		i=5; if(v[i]) v[i]--, dfs(cur+1,v), v[i]++;
	}
	else {
		_P("No\n");
		exit(0);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	if(L%6) return _P("No\n");
	
	vector<int> v(6,0);
	v[0]=L/6;
	dfs(0,v);
	
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
