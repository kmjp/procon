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

int N,Q;
int A[101010],B[101010];

vector<pair<int,int>> R[101010];

int ok(int v,vector<pair<int,int>> R) {
	FORR2(a,b,R) if(a<=v&&v<=b) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) cin>>A[i];
	FOR(i,Q) cin>>B[i];
	R[0]={{1,N}};
	FOR(i,Q) {
		vector<pair<int,int>> V,W;
		
		FORR(p,R[i]) {
			auto r=p;
			r.first=max(1,r.first-1);
			r.second=min(N,r.second+1);
			if(V.size()&&V.back().second+1>=r.first) {
				V.back().second=r.second;
			}
			else V.push_back(r);
		}
		FORR(r,V) {
			if(r.first<=A[i]&&A[i]<=r.second) {
				W.push_back({r.first,A[i]-1});
				W.push_back({A[i]+1,r.second});
			}
			else {
				W.push_back(r);
			}
		}
		V.clear();
		FORR(r,W) {
			if(r.first<=B[i]&&B[i]<=r.second) {
				V.push_back({r.first,B[i]-1});
				V.push_back({B[i]+1,r.second});
			}
			else {
				V.push_back(r);
			}
		}
		FORR(r,V) {
			if(r.first<=r.second) R[i+1].push_back(r);
		}
		
	}
	
	if(R[Q].empty()) {
		cout<<"NO"<<endl;
	}
	else {
		int cur=R[Q][0].first;
		vector<int> ret;
		ret.push_back(cur);
		for(i=Q-1;i>=0;i--) {
			for(x=max(1,cur-1);x<=min(N,cur+1);x++) if(ok(x,R[i])) {
				cur=x;
				break;
			}
			ret.push_back(cur);
		}
		reverse(ALL(ret));
		cout<<"YES"<<endl;
		FORR(r,ret) cout<<r<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
