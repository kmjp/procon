#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
string S;
double A;
vector<ll> V;
ll num[60][60];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A;
		ll B=A*1000000000LL+0.5;
		
		int a2=0,a5=0;
		while(B%2==0) a2++,B/=2;
		while(B%5==0) a5++,B/=5;
		num[a2][a5]++;
	}
	
	ll ret=0;
	int x2,y2;
	FOR(x,60) FOR(y,60) FOR(x2,60) FOR(y2,60) {
		if(x+x2>=18 && y+y2>=18) {
			if(x==x2&&y==y2) {
				ret+=num[x][y]*(num[x][y]-1);
			}
			else {
				ret+=num[x][y]*num[x2][y2];
			}
		}
	}
	ret/=2;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
