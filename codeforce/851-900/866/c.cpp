#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
vector<int> E[202020];
int dp[202020];
int C[202020];
int D[202020];
int dfs(int cur,int pre) {
	C[cur]=1;
	if(cur!=pre) D[cur]=D[pre]+1;
	
	int nm=0;
	int x=1;
	FORR(e,E[cur]) if(e!=pre) {
		x=dfs(e,cur);
		C[cur]+=C[e];
		if(C[e]>1) nm++;
		if(x==0) return 0;
	}
	
	if(nm>1+(D[cur]==1)) return 0;
	return 1;
}

vector<int> V;

void dfs2(int cur,int pre,int order) {
	
	if(D[cur]==1) {
		
		FORR(e,E[cur]) if(e!=pre&&C[e]>1) {
			dfs2(e,cur,0);
			C[e]=0;
			break;
		}
		V.push_back(cur);
		FORR(e,E[cur]) if(e!=pre&&C[e]>1) {
			dfs2(e,cur,1);
		}
		FORR(e,E[cur]) if(e!=pre&&C[e]==1) {
			V.push_back(e);
		}
	}
	else {
		if(order==0) {
			V.push_back(cur);
			FORR(e,E[cur]) if(e!=pre&&C[e]>1) {
				dfs2(e,cur,1);
			}
			FORR(e,E[cur]) if(e!=pre&&C[e]==1) {
				V.push_back(e);
			}
		}
		else {
			FORR(e,E[cur]) if(e!=pre&&C[e]==1) {
				V.push_back(e);
			}
			FORR(e,E[cur]) if(e!=pre&&C[e]>1) {
				dfs2(e,cur,0);
			}
			V.push_back(cur);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,N) if(E[i].size()==1) break;
	x=dfs(i,i);
	if(x==0) {
		cout<<"No"<<endl;
		return;
	}
	
	dfs2(E[i][0],i,1);
	cout<<"Yes"<<endl;
	FORR(v,V) cout<<v+1<<" ";
	cout<<i+1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
