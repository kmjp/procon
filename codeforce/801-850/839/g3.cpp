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
ll X,Y,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y;
		int win=0;
		vector<ll> S;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]<=X) {
				win++;
			}
			else {
				S.push_back(A[i]);
			}
		}
		sort(ALL(S));
		reverse(ALL(S));
		ll step=0;
		while(S.size()) {
			while(S.size()&&X+win>=S.back()) {
				S.pop_back();
				win++;
			}
			if(X+win>=Y) break;
			if(X+win<Y&&S.size()>=win) {
				step=-1;
				break;
			}
			ll gap=win-S.size();
			if(Y<=S.back()) {
				ll loop=(Y-win-X+gap-1)/gap;
				step+=loop*N;
				X+=gap*loop;
			}
			else {
				ll loop=(S.back()-win-X+gap-1)/gap;
				step+=loop*N;
				X+=gap*loop;
			}
		}
		if(step==-1) {
			cout<<-1<<endl;
			continue;
		}
		step+=Y-X;
		cout<<step<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
