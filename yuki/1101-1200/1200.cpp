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
int X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>Y;
		
		if(X>Y) swap(X,Y);
		ll ret=0;
		if(X==Y) {
			X+=Y;
			for(int a=1;a*a<=X;a++) if(X%a==0 && a>=2 && X/a>=2) {
				if(a==2) ret+=X/a-1;
				else if(X/a%2==0) ret++;
				if(a*a<X && a%2==0) ret++;
			}
		}
		else {
			vector<int> V;
			for(int a=1;a*a<=Y-X;a++) if((Y-X)%a==0) {
				V.push_back(a+1);
				if(a*a<Y-X) V.push_back((Y-X)/a+1);
			}
			FORR(a,V) {
				int Z=X+Y;
				if(Z%(a+1)==0) {
					int BpC=Z/(a+1);
					int BmC=(Y-X)/(a-1);
					if(BpC>BmC&&(BpC-BmC)%2==0) ret++;
				}
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
