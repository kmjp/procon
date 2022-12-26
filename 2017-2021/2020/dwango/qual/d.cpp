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
int A[101010];
vector<int> R;
set<int> S;
int C[101010];
set<pair<int,int>> cnt;

void dfs(int ng) {
	int x,y;
	if(S.empty()) {
		FORR(r,R) cout<<r+1<<" ";
		cout<<endl;
		exit(0);
	}
	
	if(S.size()==2) {
		x=*S.begin();
		y=*S.rbegin();
		if(A[x]==y && A[y]==x) return;
	}
	
	if(cnt.rbegin()->first==S.size()-1) {
		y=cnt.rbegin()->second;
		if(y!=ng) {
			S.erase(y);
			R.push_back(y);
			cnt.erase({C[y],y});
			if(S.count(A[y])) {
				cnt.erase({C[A[y]],A[y]});
				C[A[y]]--;
				cnt.insert({C[A[y]],A[y]});
			}
			dfs(A[y]);
			if(S.count(A[y])) {
				cnt.erase({C[A[y]],A[y]});
				C[A[y]]++;
				cnt.insert({C[A[y]],A[y]});
			}
			cnt.insert({C[y],y});
			R.pop_back();
			S.insert(y);
		}
	}
	else {
		x=0;
		while(1) {
			auto it=S.lower_bound(x);
			int y=*it;
			if(it==S.end()) return;
			
			if(y!=ng) {
				S.erase(it);
				R.push_back(y);
				cnt.erase({C[y],y});
				if(S.count(A[y])) {
					cnt.erase({C[A[y]],A[y]});
					C[A[y]]--;
					cnt.insert({C[A[y]],A[y]});
				}
				dfs(A[y]);
				if(S.count(A[y])) {
					cnt.erase({C[A[y]],A[y]});
					C[A[y]]++;
					cnt.insert({C[A[y]],A[y]});
				}
				cnt.insert({C[y],y});
				R.pop_back();
				S.insert(y);
			}
			x=y+1;
		}
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		C[A[i]]++;
		S.insert(i);
	}
	
	FOR(i,N) cnt.insert({C[i],i});
	
	dfs(-1);
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
