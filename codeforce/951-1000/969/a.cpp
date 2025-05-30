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
vector<int> E[202020];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		cin>>S;
		int C[4]={};
		FOR(i,N) if(i) {
			if(E[i].size()==1) {
				if(S[i]=='0') C[0]++;
				if(S[i]=='1') C[1]++;
				if(S[i]=='?') C[2]++;
			}
			else {
				if(S[i]=='?') C[3]++;
			}
		}
		int ma=0;
		if(S[0]=='0') {
			ma=C[1]+(C[2]+1)/2;
		}
		else if(S[0]=='1') {
			ma=C[0]+(C[2]+1)/2;
		}
		else {
			ma=max(C[0]+C[2]/2,C[1]+C[2]/2);
			if(C[3]%2==1&&C[2]%2) ma=max(ma,min(C[0]+C[2]/2+1,C[1]+C[2]/2+1));
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
