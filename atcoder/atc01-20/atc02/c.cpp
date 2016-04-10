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
int W[201010];
int T[201010];

int lef[201010],rig[201010];
int depth[201010];
set<pair<int,int>> SS;
set<pair<int,int>> R[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>W[i];
	
	FOR(i,N) lef[i]=max(i-1,0), rig[i]=min(N-1,i+1);
	
	FOR(i,N-1) {
		R[i].insert({W[i],i});
		R[i].insert({W[i+1],i+1});
		T[i]=W[i]+W[i+1];
		SS.insert({T[i],i});
	}
	
	int nex=N;
	while(SS.size()) {
		auto r=*SS.begin();
		SS.erase(SS.begin());
		x=r.second;
		if(R[x].size()==1) break;
		
		auto rx=R[x].begin()->second;
		R[x].erase(R[x].begin());
		auto ry=R[x].begin()->second;
		R[x].erase(R[x].begin());
		
		lef[nex]=rx;
		rig[nex]=ry;
		W[nex]=W[rx]+W[ry];
		R[x].insert({W[nex],nex});
		
		if((rx==x || ry==x) && x){
			// merge lef
			y=lef[x];
			rig[y]=rig[x];
			lef[rig[x]]=y;
			SS.erase({T[y],y});
			R[y].erase({W[x],x});
			if(R[y].size()<R[x].size()) swap(R[x],R[y]);
			FORR(r,R[x]) R[y].insert(r);
			R[x].clear();
			rig[x]=-1;
			x=y;
		}
		if((rx==rig[x] || ry==rig[x]) && rig[x]<N-1){
			// merge right
			y=rig[x];
			lef[rig[y]]=x;
			rig[x]=rig[y];
			SS.erase({T[y],y});
			R[y].erase({W[y],y});
			if(R[y].size()>R[x].size()) swap(R[x],R[y]);
			FORR(r,R[y]) R[x].insert(r);
			R[y].clear();
			rig[y]=-1;
		}
		
		auto it=R[x].begin();
		T[x]=it->first + (++it)->first;
		SS.insert({T[x],x});
		nex++;
	}
	
	for(i=nex-1;i>=N;i--) depth[lef[i]]=depth[rig[i]]=depth[i]+1;
	
	
	ll ret=0;
	FOR(i,N) ret+=depth[i]*W[i];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

