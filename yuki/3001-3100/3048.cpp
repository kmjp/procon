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

ll X,N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>N;
	N++;
	ll cur=1;
	while(X<0) {
		ll add=(cur+cur+999)*1000/2;
		if(X+add>0||cur+1000>N) break;
		X+=add;
		cur+=1000;
	}
	while(X<0&&cur<N) X+=cur++;

	while(X>0) {
		ll add=(cur+cur+999)*1000/2;
		if(X-add<=0||cur+1000>N) break;
		X-=add;
		cur+=1000;
	}
	while(X>0&&cur<N) X-=cur++;
	
	if((N-cur)%2) {
		if(X<=0) X+=cur++;
		else X-=cur++;
	}
	
	if(X<=0) cout<<X-(N-cur)/2<<endl;
	else cout<<X+(N-cur)/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
