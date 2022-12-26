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
vector<int> E[202020];
vector<double> V[202020];
double T[202020];
int PE[202020];
double ret[202020];

double dfs(int cur,int pre) {
	V[cur].resize(E[cur].size());
	int i;
	int num=0;
	FOR(i,E[cur].size()) {
		int e=E[cur][i];
		if(e==pre) {
			PE[cur]=i;
		}
		else {
			V[cur][i] = 1+dfs(e,cur);
			T[cur] += V[cur][i];
			num++;
		}
	}
	
	if(T[cur]==0) return 0;
	return T[cur] / num;
}

void dfs2(int cur,int pre,double par) {
	if(PE[cur]>=0) {
		V[cur][PE[cur]]=par;
		T[cur] += par;
	}
	
	int i;
	FOR(i,E[cur].size()) {
		int e=E[cur][i];
		if(e!=pre) {
			if(E[cur].size()==1) dfs2(e,cur,1);
			else dfs2(e,cur,(T[cur]-V[cur][i])/(E[cur].size()-1)+1);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(PE);
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	double tot=dfs(0,-1);
	dfs2(0,-1,0);
	
	FOR(i,N) _P("%.12lf\n",T[i]/E[i].size());
	/*
	FOR(i,N) {
		_P("%d : %lf : ",i,T[i]);
		FOR(j,E[i].size()) _P("%d:%lf ",E[i][j],V[i][j]);
		_P("\n");
	}*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
