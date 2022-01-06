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
vector<int> A[202020],B[202020];
int UC[505050];
set<int> UB[505050],WA[505050];
int BC[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			y--;
			A[i].push_back(y);
		}
		cin>>x;
		FOR(j,x) {
			cin>>y;
			y--;
			B[i].push_back(y);
			UB[y].insert(i);
		}
	}
	vector<int> R;
	queue<int> Q;
	FOR(i,N) {
		FORR(v,A[i]) if(UB[v].size()) UC[i]++, WA[v].insert(i);
		if(UC[i]==0) Q.push(i);
	}
	
	while(Q.size()) {
		int cur=Q.front();
		R.push_back(cur);
		Q.pop();
		
		FORR(v,B[cur]) {
			UB[v].erase(cur);
			if(UB[v].empty()) {
				FORR(w,WA[v]) {
					UC[w]--;
					if(UC[w]==0) Q.push(w);
				}
			}
		}
	}
	
	if(R.size()!=N) {
		cout<<"-1"<<endl;
	}
	else {
		FOR(i,N) {
			if(i) cout<<" ";
			cout<<R[i]+1;
		}
		cout<<endl;
	}
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
