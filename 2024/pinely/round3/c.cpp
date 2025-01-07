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

int T,N;
int L[101010];
int R[101010];
int C[101010];
int P[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> S;
		
		FOR(i,N) {
			cin>>x;
			S.push_back({x,0});
		}
		FOR(i,N) {
			cin>>x;
			S.push_back({x,1});
		}
		
		sort(ALL(S));
		vector<int> ret;
		vector<int> A;
		FORR2(a,b,S) {
			if(b==0) A.push_back(a);
			else {
				ret.push_back(a-A.back());
				A.pop_back();
			}
		}
		
		FOR(i,N) cin>>C[i];
		sort(C,C+N);
		reverse(C,C+N);
		sort(ALL(ret));
		ll sum=0;
		FOR(i,N) sum+=1LL*ret[i]*C[i];
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
