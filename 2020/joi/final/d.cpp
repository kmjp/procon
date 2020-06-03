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
ll U[505050],V[505050],C[505050],DD[505050];
vector<pair<int,int>> E[2][202];
ll D[2][2][202];
int req[505050];
int vis[202];

vector<pair<int,ll>> E2[202];
ll D2[2][202];

ll hoge() {
	int i,loop;
	
	FOR(loop,2) {
		int vis[202]={};
		FOR(i,N) D2[loop][i]=1LL<<60;
		int first=(loop==0)?0:N-1;
		D2[loop][first]=0;
		
		while(1) {
			int tar=-1;
			ll mi=1LL<<60;
			FOR(i,N) if(vis[i]==0 && D2[loop][i]<mi) mi=D2[loop][i], tar=i;
			if(tar==-1) break;
			vis[tar]=1;
			FORR(e,E2[tar]) if(D2[loop][e.first]>mi+e.second) {
				D2[loop][e.first]=mi+e.second;
			}
		}
		
	}
	
	return D2[0][N-1]+D2[1][0];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i]>>DD[i];
		U[i]--;
		V[i]--;
		C[i]*=1000;
		C[i]++;
		DD[i]*=1000;
		E[0][U[i]].push_back({i,V[i]});
		E[1][V[i]].push_back({i,U[i]});
	}
	
	FOR(i,N) FOR(x,2) FOR(y,2) D[x][y][i]=1LL<<60;
	D[0][0][0]=D[1][0][N-1]=D[0][1][0]=D[1][1][N-1]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,0});
	Q.push({0,2*N+N-1});
	Q.push({0,N});
	Q.push({0,2*N+N+N-1});
	
	while(Q.size()) {
		int from=Q.top().second/(2*N);
		int ei=Q.top().second/N%2;
		int cur=Q.top().second%N;
		ll co=-Q.top().first;
		Q.pop();
		if(D[from][ei][cur]!=co) continue;
		FORR(e,E[ei][cur]) {
			if(D[from][ei][e.second]>co+C[e.first]) {
				D[from][ei][e.second]=co+C[e.first];
				Q.push({-D[from][ei][e.second], from*2*N+ei*N+e.second});
			}
		}
	}

	ll mi=D[0][0][N-1]+D[1][0][0];
	
	
	
	if(D[0][0][N-1]<1LL<<60) {
		int cur=0;
		while(cur<N-1) {
			FORR(e,E[0][cur]) if(D[1][1][cur]-C[e.first]==D[1][1][e.second]) {
				req[e.first]=1;
				cur=e.second;
				break;
			}
		}
	}
	if(D[1][0][0]<1LL<<60) {
		int cur=N-1;
		while(cur>0) {
			FORR(e,E[0][cur]) if(D[0][1][cur]-C[e.first]==D[0][1][e.second]) {
				req[e.first]=1;
				cur=e.second;
				break;
			}
		}
	}
	FOR(i,M) {
		if(req[i]) {
			FOR(x,N) E2[x].clear();
			FOR(x,M) {
				if(i!=x) E2[U[x]].push_back({V[x],C[x]});
				else E2[V[x]].push_back({U[x],C[x]});
			}
			mi=min(mi,hoge()+DD[i]);
		}
		else {
			mi=min(mi,DD[i]+min(D[0][0][N-1],D[0][0][V[i]]+C[i]+D[1][1][U[i]])+min(D[1][0][0],D[1][0][V[i]]+C[i]+D[0][1][U[i]]));
		}
	}
	
	
	if(mi>=1LL<<60) mi=-1;
	else mi/=1000;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
