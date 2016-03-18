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

int T;
int M1,D1,M2,D2;

void nextday(int& m,int &d) {
	int day[]={31,29,31,30,31,30,31,31,30,31,30,31};
	d++;
	if(d>day[m-1]) m++,d=1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>M1>>D1>>M2>>D2;
		set<pair<int,int>> S;
		while(M1<M2 || (M1==M2&&D1<=D2)) {
			int g=__gcd(M1,D1);
			S.insert({M1/g,D1/g});
			
			nextday(M1,D1);
		}
		cout<<S.size()<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
