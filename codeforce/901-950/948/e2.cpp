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

int T;
int N;
int ask(int i,int j) {
	string s;
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	cin>>s;
	return s=="YES";
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		vector<int> A,B,C;
		
		cin>>N;
		A={0};
		for(i=1;i<N;i++) {
			if(C.size()) {
				if(ask(C.back(),i)) {
					C.push_back(i);
				}
				else if(ask(A.back(),i)) {
					FORR(c,C) B.push_back(c);
					A.push_back(i);
					C.clear();
				}
				else {
					FORR(c,C) A.push_back(c);
					B.push_back(i);
					C.clear();
				}
			}
			else if(B.empty()) {
				if(ask(A.back(),i)) {
					A.push_back(i);
				}
				else {
					B.push_back(i);
				}
			}
			else {
				x=ask(A.back(),i);
				y=ask(B.back(),i);
				if(x&&y) C.push_back(i);
				else if(x) A.push_back(i);
				else B.push_back(i);
			}
		}
		int D[102]={};
		FORR(b,B) D[b]=1;
		
		cout<<"! ";
		FOR(i,N) cout<<D[i]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
