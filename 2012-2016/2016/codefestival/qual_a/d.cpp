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

int H,W;
int N;
int Y[101010],X[101010],A[101010];

ll XX[101010],YY[101010];
vector<pair<int,int>> XL[101010];
vector<pair<int,int>> YL[101010];

vector<int> LR[101010];
vector<int> UD[101010];

ll mix,miy;
int did[101010];

void dfs(int cur) {
	int cx=X[cur];
	int cy=Y[cur];
	
	if(XX[cx]!=-1LL<<60 && YY[cy]!=-1LL<<60 && XX[cx]+YY[cy]!=A[cur]) {
		cout<<"No"<<endl;
		exit(0);
	}
	if(did[cur]) return;
	did[cur]=1;
	
	if(XX[cx]==-1LL<<60 && YY[cy]==-1LL<<60) {
		XX[cx]=A[cur];
		YY[cy]=0;
		mix=XX[cx];
		miy=YY[cy];
	}
	if(XX[cx]==-1LL<<60) {
		XX[cx]=YY[cy]-A[cur];
		mix=min(XX[cx],mix);
	}
	if(YY[cy]==-1LL<<60) {
		YY[cy]=XX[cx]-A[cur];
		miy=min(YY[cy],miy);
	}
	
	FORR(e,LR[cur]) {
		XX[X[e]] = XX[cx] + (A[e] - A[cur]);
		mix=min(XX[X[e]],mix);
		dfs(e);
	}
	FORR(e,UD[cur]) {
		YY[Y[e]] = YY[cy] + (A[e] - A[cur]);
		miy=min(YY[Y[e]],miy);
		dfs(e);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,101000) XX[i]=YY[i]=-1LL<<60;
	
	cin>>H>>W>>N;
	FOR(i,N) {
		cin>>Y[i]>>X[i]>>A[i];
		Y[i]--;
		X[i]--;
		YL[Y[i]].push_back({X[i],i});
		XL[X[i]].push_back({Y[i],i});
	}
	FOR(y,H) if(YL[y].size()>1) {
		sort(ALL(YL[y]));
		FOR(i,YL[y].size()-1) {
			LR[YL[y][i].second].push_back(YL[y][i+1].second);
			LR[YL[y][i+1].second].push_back(YL[y][i].second);
		}
	}
	FOR(x,W) if(XL[x].size()>1) {
		sort(ALL(XL[x]));
		FOR(i,XL[x].size()-1) {
			UD[XL[x][i].second].push_back(XL[x][i+1].second);
			UD[XL[x][i+1].second].push_back(XL[x][i].second);
		}
	}
	
	FOR(i,N) if(XX[X[i]]==-1LL<<60 && YY[Y[i]]==-1LL<<60) {
		dfs(i);
		if(mix+miy<0) {
			cout<<"No"<<endl;
			return;
		}
	}
	
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
