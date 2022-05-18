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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	multiset<int> M;
	int C1=0;
	FOR(i,N) if(S[i]=='R') {
		FOR(j,N) {
			if(i-(j+1)<0) break;
			if(i+(j+1)>=N) break;
			if(S[i-(j+1)]!='A') break;
			if(S[i+(j+1)]!='C') break;
		}
		if(j) {
			if(j==1) C1++;
			else M.insert(j);
		}
	}
	
	for(i=1;i<=N;i++) {
		if(C1==0&&M.empty()) {
			cout<<i-1<<endl;
			return;
		}
		
		if(i%2==1) {
			if(M.size()) {
				x=*M.begin();
				M.erase(M.begin());
				x--;
				if(x>1) M.insert(x);
				else C1++;
			}
			else {
				C1--;
			}
		}
		else {
			if(C1) {
				C1--;
			}
			else {
				M.erase(M.begin());
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
