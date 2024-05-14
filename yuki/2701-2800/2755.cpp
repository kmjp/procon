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

int B,C;
int found[606*606];
int rev[606];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B>>C;
	int ret=0;
	
	FOR(x,B) FOR(y,B) if(x*y%B==1) rev[x]=y;
	
	FOR(i,B*B) {
		if(__gcd(i/B,B)>1) continue;
		if(i%B%C) continue;
		if(found[i]) continue;
		ret++;
		if(ret>100) {
			cout<<"100+"<<endl;
			return;
		}
		FOR(j,B*B) {
			if(__gcd(j/B,B)>1) continue;
			if(j%B%C) continue;
			int a=i/B;
			int b=(i/B*(j%B)+(i%B)+B-(j%B))*rev[j/B]%B;
			found[a*B+b]=1;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
