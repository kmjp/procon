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
string S;

set<int> C[26];
int step[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FOR(i,N) if(S[i]!='?') {
		C[S[i]-'a'].insert(i);
	}
	MINUS(step);
	int cur=0;
	while(1) {
		int pos=-1;
		while(1) {
			for(j=25;j>=0;j--) {
				auto it=C[j].lower_bound(pos);
				
				if(it!=C[j].end()) {
					step[*it]=cur;
					pos=*it;
					C[j].erase(it);
					break;
				}
			}
			if(j<0) break;
		}
		if(pos==-1) break;
		cur++;
	}
	cur--;
	char c='a';
	for(i=N-1;i>=0;i--) {
		if(S[i]=='?') S[i]=c;
		if(step[i]==cur) c=max(c,S[i]);
	}
	
	cout<<S<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
