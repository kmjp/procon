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

int N,K,X;
int A[55];
set<vector<int>> S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	reverse(A,A+N);
	vector<int> V(N);
	V[0]=K;
	priority_queue<pair<ll,vector<int>>> P;
	P.push({1LL*A[0]*K,V});
	S.insert(V);
	FOR(i,X) {
		auto p=P.top();
		P.pop();
		cout<<p.first<<endl;
		FOR(j,N-1) {
			if(p.second[j]) {
				p.first-=A[j];
				p.first+=A[j+1];
				p.second[j]--;
				p.second[j+1]++;
				if(S.count(p.second)==0) {
					S.insert(p.second);
					P.push(p);
				}
				p.first+=A[j];
				p.first-=A[j+1];
				p.second[j]++;
				p.second[j+1]--;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
