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
string S[51];
int C[51][51],G[51][51];

double dp[2600][2600];

void dfs(int x,int y,int px,int py) {
	C[y][x]=1;
	if(x==N-1&&y==N-1) {
		G[y][x]=1;
		return;
	}
	
	int i;
	int d[4]={1,0,-1,0};
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=N||tx<0||tx>=N) continue;
		if(ty==py&&tx==px) continue;
		if(S[ty][tx]=='#') continue;
		dfs(tx,ty,x,y);
		C[y][x]+=C[ty][tx];
		G[y][x]+=G[ty][tx];
	}
}

vector<double> dfs2(int x,int y,int px,int py) {
	if(x==N-1&&y==N-1) {
		return {0,1.0};
	}
	
	int ox=x+(x-px);
	int oy=y+(y-py);
	int add=0;
	//cout<<"!"<<x<<" "<<y<<" "<<px<<" "<<py<<" "<<ox<<" "<<oy<<endl;
	if(ox>=0&&oy>=0&&ox<N&&oy<N&&S[oy][ox]!='#') {
		if(G[oy][ox]) {
			return dfs2(ox,oy,x,y);
		}
		add=C[oy][ox];
	}
	
	vector<double> tmp;
	int num=0;
	int i;
	int d[4]={1,0,-1,0};
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty<0||ty>=N||tx<0||tx>=N) continue;
		if(ty==py&&tx==px) continue;
		if(ty==oy&&tx==ox) continue;
		if(S[ty][tx]=='#') continue;
		if(G[ty][tx]) {
			assert(tmp.empty());
			tmp=dfs2(tx,ty,x,y);
		}
		else {
			assert(num==0);
			num=C[ty][tx];
		}
	}
	
	vector<double> ret(tmp.size()+num+add);
	int a,b;
	FOR(a,tmp.size()) FOR(b,num+1) dp[a][b]=0;
	dp[0][0]=1;
	FOR(a,tmp.size()) FOR(b,num+1) if(dp[a][b]) {
		if(a+1<tmp.size()&&b+1<=num) {
			dp[a+1][b]+=dp[a][b]/2;
			dp[a][b+1]+=dp[a][b]/2;
		}
		else {
			dp[a+1][b]+=dp[a][b];
			dp[a][b+1]+=dp[a][b];
		}
		ret[add+a+b]+=dp[a][b]*tmp[a];
	}
	/*
	cout<<y<<" "<<x<<" : ";
	FORR(r,ret) cout<<r<<" ";
	cout<<endl;
	*/
	return ret;
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) cin>>S[y];
	
	dfs(0,0,0,0);
	auto A=dfs2(0,0,-1,0);
	
	double ret=0;
	for(i=1;i<A.size();i++) ret+=(A[i]-A[i-1])*i;
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
