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
vector<int> P[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) {
		cout<<-1<<endl;
		return;
	}
	
	if(N%3==2) {
		P[0]={1,4};
		P[1]={3,6};
		P[2]={5,2};
	}
	else if(N%3==0) {
		P[0]={1,2,9};
		P[1]={6,8,7};
		P[2]={3,4,5};
	}
	else {
		P[0]={1,2,4,11};
		P[1]={7,9,10,12};
		P[2]={8,5,6,3};
	}
	
	x=P[0].size();
	while(x<N) {
		P[0].push_back(3*x+1);
		P[0].push_back(3*x+2);
		P[0].push_back(3*x+9);
		P[1].push_back(3*x+6);
		P[1].push_back(3*x+8);
		P[1].push_back(3*x+7);
		P[2].push_back(3*x+3);
		P[2].push_back(3*x+4);
		P[2].push_back(3*x+5);
		x+=3;
	}
	
	FOR(i,3) FORR(a,P[i]) cout<<a<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
