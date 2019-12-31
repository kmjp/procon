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

int N;
int P[101000],in[101000],mama[101000];
vector<int> E[101000];
set<pair<int,int> > S[101000];
map<int,int> M[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>j;
		x--,y--;
		E[x].push_back(y);
		if(j==2) E[y].push_back(x);
	}
	
	priority_queue<pair<int,int> > Q;
	FOR(i,N) Q.push(make_pair(0,i));
	
	while(Q.size()) {
		auto e=Q.top();
		int cur=e.second;
		Q.pop();
		if(e.first<mama[cur]) continue;
		
		FORR(tar,E[cur]) {
			x = 0;
			if(S[cur].size()) {
				if(S[cur].rbegin()->second != tar) x=S[cur].rbegin()->first;
				else if(S[cur].size()>1) x=S[cur].begin()->first;
			}
			if(M[tar][cur]<x+1) {
				S[tar].erase(make_pair(M[tar][cur],cur));
				M[tar][cur]=x+1;
				mama[tar]=max(mama[tar],x+1);
				
				if(S[tar].size()<2 || S[tar].begin()->first < x+1) {
					S[tar].insert(make_pair(M[tar][cur],cur));
					if(S[tar].size()>2) S[tar].erase(S[tar].begin());
					Q.push(make_pair(mama[tar],tar));
				}
			}
		}
	}
	cout<<*max_element(mama,mama+N)-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
