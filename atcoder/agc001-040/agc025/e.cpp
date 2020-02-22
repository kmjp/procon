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
vector<int> E[2020];

int EE[2020][2],TE[2020][2];
set<int> VE[2020];
vector<int> EL[2020];
int dir[2020];
int cnt[2020][2020];

void shrink(int cur) {
	FORR(c,EL[cur]) dir[c%M] = c/M;
}

int dfs(int cur,int pre,int tar) {
	if(cur==tar) {
		cnt[pre][cur]++;
		return 1;
	}
	else {
		int ok=0;
		FORR(e,E[cur]) if(e!=pre) ok+=dfs(e,cur,tar);
		if(ok&&pre) cnt[pre][cur]++;
		return ok>=1;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(1,1,0);
	FOR(i,M) {
		cin>>EE[i][0]>>EE[i][1];
		dfs(EE[i][0],0,EE[i][1]);
		TE[i][0]=EE[i][0];
		TE[i][1]=EE[i][1];
		VE[EE[i][0]].insert(i);
		VE[EE[i][1]].insert(i+M);
		EL[i].push_back(i);
	}
	
	
	int ret=0;
	for(y=1;y<=N;y++) for(x=1;x<y;x++) ret+=min(2,cnt[x][y]+cnt[y][x]);
	cout<<ret<<endl;
	
	while(true) {
		for(i=1;i<=N;i++) if(E[i].size()==1) break;
		if(i>N) break;
		int cur=i;
		vector<int> delcand;
		FORR(v,VE[cur]) if(v<M && VE[cur].count(v+M)) {
			delcand.push_back(v);
			shrink(v);
		}
		FORR(d,delcand) VE[cur].erase(d),VE[cur].erase(d+M);
		
		
		int p=E[cur][0];
		if(VE[cur].size()>=2) {
			int a=*VE[cur].begin()%M;
			
			VE[TE[a][0]].erase(a);
			VE[TE[a][1]].erase(a+M);
			int b=*VE[cur].begin()%M;
			VE[TE[b][0]].erase(b);
			VE[TE[b][1]].erase(b+M);
			
			if(TE[a][0]==cur) {
				FORR(e,EL[a]) {
					if(e>=M) e-=M;
					else e+=M;
				}
				swap(TE[a][0],TE[a][1]);
			}
			if(TE[b][1]==cur) {
				FORR(e,EL[b]) {
					if(e>=M) e-=M;
					else e+=M;
				}
				swap(TE[b][0],TE[b][1]);
			}
			TE[a][1]=TE[b][1];
			FORR(e,EL[b]) EL[a].push_back(e);
			EL[b].clear();
			VE[TE[a][0]].insert(a);
			VE[TE[a][1]].insert(a+M);
		}
		FORR(v,VE[cur]) {
			TE[v%M][v/M]=p;
			VE[p].insert(v);
		}
		VE[cur].clear();
		E[p].erase(remove(ALL(E[p]),cur),E[p].end());
		E[cur].clear();
	}
	
	for(i=1;i<=N;i++) FORR(v,VE[i]) shrink(v);
	FOR(i,M) cout<<EE[i][dir[i]]<<" "<<EE[i][dir[i]^1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
