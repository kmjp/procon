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

int T;
int N;
vector<int> E[101010];
int num[101010];

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre) {
		res=min(res,dfs_center(r,cur));
		ma=max(ma,num[r]);
		num[cur]+=num[r];
	}
	return min(res,make_pair(max(ma,N-num[cur]),cur));
}

void dfs(int cur,int pre,vector<int>& V) {
	V.push_back(cur+1);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,V);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		pair<int,int> p=dfs_center(0,-1);
		int cent=p.second;
		vector<vector<int>> V;
		int ma=0;
		FORR(e,E[cent]) {
			vector<int> VV;
			dfs(e,cent,VV);
			reverse(ALL(VV));
			if(V.size() && VV.size()>V[ma].size()) ma=V.size();
			V.push_back(VV);
		}
		if(V[ma].size()==1) {
			cout<<-1<<endl;
			continue;
		}
		else {
			vector<int> V2,R;
			for(i=ma;i<V.size();i++) FORR(e,V[i]) V2.push_back(e);
			for(i=0;i<ma;i++) FORR(e,V[i]) V2.push_back(e);
			R.push_back(cent+1);
			x=0;
			FOR(i,V2.size()) {
				R.push_back(V2[x]);
				if(V2.size()%2==0) {
					x+=V2.size()/2;
					if(x>=V2.size()) {
						x-=V2.size()-1;
					}
				}
				else {
					x=(x+(V2.size()+1)/2)%V2.size();
				}
				
			}
			FOR(i,R.size()) {
				cout<<R[i];
				if(i<R.size()-1) cout<<" ";
			}
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
