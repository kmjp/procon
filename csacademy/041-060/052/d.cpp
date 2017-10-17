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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int T;
	cin>>T;
	while(T--) {
		int num=0,ask=0;
		int col[10]={}, row[10]={},did[100]={};
		
		for(i=0;i<=99;i+=11) {
			cout<<i<<endl;
			ask++;
			did[i]++;
			cin>>x;
			if(x==1) {
				num++;
				col[i%10]++;
				row[i/10]++;
				row[(i/10+1)%10]++;
				row[(i/10+10-1)%10]++;
				y=i;
			}
			if(num>=2) break;
		}
		
		if(num==1) {
			cout<<(y+10)%100<<endl;
			cin>>x;
		}
		else {
			FOR(i,100) {
				if(ask<11 && did[i]==0 && col[i%10]==0 && row[i/10]==0) {
					ask++;
					did[i]++;
					cout<<i<<endl;
					cin>>x;
				}
			}
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
