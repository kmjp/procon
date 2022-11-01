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

int N,X,Y;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	vector<int> Ys;
	vector<int> Xs;
	FOR(i,N) {
		cin>>x;
		if(i==0) {
			X-=x;
		}
		else if(i%2==1) {
			Ys.push_back(x);
		}
		else {
			Xs.push_back(x);
		}
	}
	
	bitset<1<<20> XX,YY;
	XX[1<<19]=1;
	YY[1<<19]=1;
	FORR(x,Xs) XX=(XX<<x)|(XX>>x);
	FORR(x,Ys) YY=(YY<<x)|(YY>>x);
	if(XX[X+(1<<19)]&&YY[Y+(1<<19)]) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
