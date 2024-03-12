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
int C;
int OV,V;
int sum,step;
int ask(int num) {
	sum+=num;
	cout<<"- "<<num<<endl;
	if(OV) {
		V-=num;
		num=__builtin_popcount(V);
		cout<<"## "<<V<<endl;
	}
	else {
		cin>>num;
	}
	step++;
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V=OV;
	
	cin>>T;
	while(T--) {
		if(V) {
			C=__builtin_popcount(V);
		}
		else {
			cin>>C;
		}
		
		sum=step=0;
		int cur=0;
		while(C) {
			x=ask(1<<cur);
			if(x==C-1) {
				C=x;
				cur++;
			}
			else {
				int d=x-C+1;
				C=ask(((1<<d)-1)<<cur);
				cur+=d+1;
			}
		}
		cout<<"! "<<sum<<endl;
		cerr<<"$ "<<step<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
