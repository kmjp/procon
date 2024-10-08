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

int T,N,M;
int L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		map<int,vector<int>> ev;
		FOR(i,N) {
			cin>>L[i]>>R[i];
			R[i]++;
			ev[L[i]].push_back(i);
			ev[R[i]].push_back(N+i);
		}
		int cnt=0;
		int c1=0,cm=0;
		int ma=0;
		FORR2(a,b,ev) {
			FORR(e,b) {
				if(e<N) {
					cnt++;
					if(L[e]==1) c1++;
					if(R[e]==M+1) cm++;
				}
				else {
					e-=N;
					cnt--;
					if(L[e]==1) c1--;
					if(R[e]==M+1) cm--;
				}
			}
			ma=max(ma,cnt-c1);
			ma=max(ma,cnt-cm);
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
