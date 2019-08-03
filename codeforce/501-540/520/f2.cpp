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
vector<int> E[2][303030];

int num[303030],from[303030];
int reach[2][303030];
int vis[303030];
int ID[2][303030];
int OP[303030];
vector<int> semicand[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[0][x-1].push_back(y-1);
		E[1][y-1].push_back(x-1);
	}
	
	priority_queue<pair<int,int>> Q;
	MINUS(from);
	FOR(i,N) if(E[1][i].empty()) Q.push({0,i});
	
	while(Q.size()) {
		int cur=Q.top().second;
		int now=-Q.top().first;
		Q.pop();
		if(num[cur]!=now) continue;
		FORR(e,E[0][cur]) {
			if(num[e]<now+1) {
				num[e]=now+1;
				from[e]=cur;
				Q.push({-num[e],e});
			}
		}
	}
	x=max_element(num,num+N)-num;
	vector<int> P;
	while(x>=0) P.push_back(x), OP[x]=1, x=from[x];
	
	FOR(i,N) ID[0][i]=-1, ID[1][i]=P.size();
	
	FOR(i,2) {
		ZERO(vis);
		FOR(j,P.size()) {
			int p=P[j];
			queue<int> Q;
			Q.push(p);
			vis[p]=1;
			if(j) reach[i][p]+=reach[i][P[j-1]]+1;
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				
				FORR(e,E[i][p]) if(vis[e]==0) {
					if(i==0) ID[i][e]=P.size()-1-j;
					else ID[i][e]=j;
					vis[e]=1;
					Q.push(e);
					reach[i][p]++;
				}
			}
		}
		reverse(ALL(P));
	}
	
	int ret=0;
	FOR(i,N) if(OP[i]==0 && ID[0][i]+2==ID[1][i]) semicand[ID[0][i]+1].push_back(i);
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
