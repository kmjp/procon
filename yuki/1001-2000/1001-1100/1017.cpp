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
int A[151515];

map<int,vector<int>> V;
vector<int> R;

void dfs(int cur,int sum) {
	if(R.size()==12) {
		V[sum]=R;
		return;
	}
	
	R.push_back(0);
	dfs(cur+1,sum);
	R.back()=A[cur];
	dfs(cur+1,sum+A[cur]);
	R.back()=-A[cur];
	dfs(cur+1,sum-A[cur]);
	R.pop_back();
}

void dfs2(int cur,int sum) {
	if(R.size()==12) {
		
		if(V.count(-sum)) {
			vector<int> R2=V[-sum];
			int ok=0;
			FORR(r,R) if(r!=0) ok++;
			FORR(r,R2) if(r!=0) ok++;
			if(ok) {
				int i;
				cout<<"Yes"<<endl;
				FOR(i,N) {
					if(i<12) cout<<R2[i]<<" ";
					else if(i<24) cout<<R[i-12]<<" ";
					else cout<<"0 ";
				}
				exit(0);
				
			}
			
		}
		return;
	}
	
	R.push_back(0);
	dfs2(cur+1,sum);
	R.back()=A[cur];
	dfs2(cur+1,sum+A[cur]);
	R.back()=-A[cur];
	dfs2(cur+1,sum-A[cur]);
	R.pop_back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	dfs(0,0);
	dfs2(12,0);
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
