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
vector<int> E[1010];
int M;
int ID[1010][1010];
int G[1010][1010];
int P[1010][1010];
int D[2][1010];
int A[202020],B[202020];

void dfs(int cur,int org) {
	G[org][cur]=1;
	FORR(e,E[cur]) if(G[org][e]==0) dfs(e,org);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(ID);
	
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back(B[i]);
		ID[A[i]][B[i]]=i;
	}
	
	FOR(i,N) dfs(i,i);
	FOR(i,N) {
		FOR(j,2) {
			FOR(x,N) D[j][x]=-1<<30;
			priority_queue<pair<int,int>> PQ;
			FOR(x,N) if(ID[i][x]>=0) {
				D[j][x]=ID[i][x];
				if(j) D[j][x]=-D[j][x];
				PQ.push({D[j][x],x});
			}
			
			while(PQ.size()) {
				int cur=PQ.top().second;
				int sc=PQ.top().first;
				PQ.pop();
				
				if(D[j][cur]!=sc) continue;
				FORR(e,E[cur]) if(D[j][e]<sc) {
					if(e==i) continue;
					D[j][e]=sc;
					PQ.push({sc,e});
				}
			}
		}
		FOR(x,N) {
			if(D[0][x]!=-1<<30 && D[0][x]!=-D[1][x]) P[i][x]=1;
		}
	}
	
	FOR(i,M) {
		if(P[A[i]][B[i]]==G[B[i]][A[i]]) cout<<"same"<<endl;
		else cout<<"diff"<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
