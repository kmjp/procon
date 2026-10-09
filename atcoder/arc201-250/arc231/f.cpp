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
vector<int> cand[19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cand[1]={1};
	cand[2]={1,2,3};
	for(i=3;i<=18;i++) {
		vector<int> leaf,leaf2;
		FOR(x,(1<<(i-2))-1) cand[i].push_back(cand[i-1][x]*2);
		FOR(j,1<<(i-3)) {
			x=cand[i][cand[i].size()-(1<<(i-3))+j]/2;
			leaf.push_back(cand[i][0]-x);
			leaf.push_back(cand[i][0]+x);
		}
		FORR(a,leaf) {
			cand[i].push_back(a);
			leaf2.push_back((3<<(i-2))-(a+1)/2);
			leaf2.push_back((3<<(i-2))+a/2);
		}
		FORR(a,leaf2) cand[i].push_back(a);
		
		
	}
	FORR(v,cand[N]) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
