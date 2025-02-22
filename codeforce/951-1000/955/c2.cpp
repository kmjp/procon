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

int T,N,L,R;
int A[202020];
ll S[202020];
vector<int> add[202020],del[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>R;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
		}
		FOR(i,N+2) {
			add[i].clear();
			del[i].clear();
		}
		multiset<int> cand={0};
		int ma=0;
		FOR(i,N+1) {
			FORR(a,add[i]) cand.insert(a);
			FORR(a,del[i]) cand.erase(cand.find(a));
			x=max(ma,*cand.rbegin());
			ma=max(ma,x);
			int a=lower_bound(S,S+N+1,S[i]+L)-S;
			int b=lower_bound(S,S+N+1,S[i]+R+1)-S;
			add[a].push_back(x+1);
			del[b].push_back(x+1);
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
