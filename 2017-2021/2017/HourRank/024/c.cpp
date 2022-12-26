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
int A,B,X;
int ok[10101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>X;
		ZERO(ok);
		for(x=A;x<=B;x++) ok[x]=1;
		for(x=B;x>=A;x--) {
			int num=0,p=-1;
			for(y=2*x;y<=B;y+=x) if(ok[y]) {
				p=y;
				num++;
			}
			if(num>=2) ok[x]=0;
			if(num==1) ok[p]=0;
		}
		vector<int> V;
		for(x=A;x<=B;x++) if(ok[x]) V.push_back(x);
		
		
		if(V.size()>=X) {
			FOR(i,X) _P("%d%c",V[i],(i==X-1)?'\n':' ');
		}
		else {
			_P("-1\n");
		}
		
		
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
