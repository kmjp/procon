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
vector<int> E[101010];
int num[101010];
int L;
vector<int> C;

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=E[cur].size()==1;
	
	FORR(r,E[cur]) if(r!=pre) {
		res=min(res,dfs_center(r,cur));
		ma=max(ma,num[r]);
		num[cur]+=num[r];
	}
	if(E[cur].size()>=2) res=min(res,make_pair(max(ma,L-num[cur]),cur));
	return res;
}

void dfs2(int cur,int pre) {
	if(E[cur].size()==1) C.push_back(cur+1);
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	if(N==2) {
		_P("1\n");
		_P("1 2\n");
		return;
	}
	
	int L=0;
	FOR(i,N) if(E[i].size()==1) L++;
	FOR(i,N) if(E[i].size()>=2) {
		auto p=dfs_center(i,-1);
		x=p.first;
		break;
	}
	
	dfs2(x,-1);
	if(C.size()%2) C.push_back(C.back());
	x=C.size()/2;
	cout<<x<<endl;
	FOR(i,x) cout<<C[i]<<" "<<C[i+x]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
