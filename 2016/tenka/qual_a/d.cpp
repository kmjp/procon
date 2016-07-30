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
vector<int> E[26];
char hoge[101][101];

int did[26];
int X[26];
int Y[26];
map<int,int> XX,YY;

void dfs(int cur,int dist,int ngmask) {
	int i;
	did[cur]=1;
	XX[X[cur]]=YY[Y[cur]]=0;
	
	FOR(i,4) if((ngmask&(1<<i))==0) {
		int dd[4]={-1,0,1,0};
		FORR(e,E[cur]) if(did[e]==0) {
			X[e] = X[cur] + dd[i]*dist;
			Y[e] = Y[cur] + dd[i^1]*dist;
			dfs(e,dist/2,(i<2)?(1<<(i+2)):(1<<(i-2)));
			break;
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y,z; string s,t;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>s>>t;
		x=s[0]-'A';
		y=t[0]-'A';
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(y,100) FOR(x,100) hoge[y][x]='.';
	
	dfs(0,1<<27,0);
	x=y=0;
	FORR(r,XX) r.second=x, x+=2;
	FORR(r,YY) r.second=y, y+=2;
	
	FOR(i,N) X[i]=XX[X[i]],Y[i]=YY[Y[i]], hoge[Y[i]][X[i]]='A'+i;
	FOR(i,N) {
		FORR(r,E[i]) {
			if(Y[i]<Y[r]) for(y=Y[i]+1;y<Y[r];y++) hoge[y][X[i]]='|';
			if(X[i]<X[r]) for(x=X[i]+1;x<X[r];x++) hoge[Y[i]][x]='-';
		}
	}
	cout<<"100 100"<<endl;
	FOR(y,100) cout<<hoge[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
