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


int N,M;
string S;
vector<int> E[505050];
int TE[505050];
int can[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(TE);
	cin>>N>>M>>S;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y);
		can[x-1]++,can[y]++;
	}
	set<int> T;
	int pre=-1;
	FOR(i,N) if(can[i]) {
		FORR(e,E[i]) T.insert(e);
		if(pre>=0 && TE[pre]>i) {
			T.insert(TE[pre]);
			TE[pre]=i;
		}
		while(T.size() && *T.begin()<=i) T.erase(T.begin());
		if(T.size()) {
			TE[i]=*T.begin();
			T.erase(T.begin());
			pre=i;
		}
	}
	
	int cur=0;
	while(cur<N) {
		if(TE[cur]==-1) {
			if(S[cur]=='0') return _P("No\n");
			cur++;
		}
		else {
			int C[2]={};
			for(i=cur;i<TE[cur];i++) C[S[i]-'0']++;
			if(C[0]&&C[1]) return _P("No\n");
			cur=TE[cur];
		}
	}
	_P("Yes\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
