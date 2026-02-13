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

ll p2[10],p5[10];
map<int,pair<int,int>> M;

int X,Y;

void turn(int nx) {
	X=nx;
	cout<<X<<endl;
	if(X==Y) exit(0);
	cin>>Y;
	if(X==Y) exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p5[0]=1;
	FOR(i,9) {
		p2[i+1]=2*p2[i];
		p5[i+1]=5*p5[i];
	}
	FOR(x,10) FOR(y,10) M[p2[x]*p5[y]]={x,y};
	
	cin>>X>>Y;
	while(1) {
		x=M[X].first;
		y=M[X].second;
		if(x<7) turn(X*2);
		else if(x>7) turn(X/2);
		else if(y<9) turn(X*5);
		else break;
	}
	x=M[X].first+M[X].second;
	y=M[Y].first+M[Y].second;
	if(abs(x-y)%2) {
		turn(X*2);
		turn(X*2);
	}
	else {
		turn(X*4);
	}
	while(1) {
		x=M[X].first+M[X].second;
		y=M[Y].first+M[Y].second;
		assert(abs(x-y)%2);
		if(M[X].first-M[Y].first>M[X].second-M[Y].second) {
			turn(X/2);
		}
		else {
			turn(X/5);
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
