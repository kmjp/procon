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
int A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	vector<int> P;
	FOR(i,31) if(N&(1<<i)) P.push_back(1<<i);
	
	if(P.size()==1) {
		cout<<"-1 -1 -1"<<endl;
	}
	else {
		FOR(i,P.size()) {
			if(i==0) {
				A|=P[i];
				B|=P[i];
			}
			else {
				A|=P[i];
				C|=P[i];
			}
		}
	}
	
	cout<<A<<" "<<B<<" "<<C<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
