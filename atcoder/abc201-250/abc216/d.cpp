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

int N,M;

vector<int> A[202020];
vector<int> C[202020];
set<int> cand;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>k;
		FOR(j,k) {
			cin>>x;
			x--;
			A[i].push_back(x);
		}
		C[A[i].back()].push_back(i);
		if(C[A[i].back()].size()==2) {
			cand.insert(A[i].back());
		}
	}
	
	while(cand.size()) {
		x=*cand.begin();
		cand.erase(cand.begin());
		FORR(k,C[x]) {
			A[k].pop_back();
			if(A[k].size()) {
				C[A[k].back()].push_back(k);
				if(C[A[k].back()].size()==2) {
					cand.insert(A[k].back());
				}
			}
		}
	}
	FOR(i,M) {
		if(A[i].size()) {
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
