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

int FA,FB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,100) {
		FOR(x,1<<i) {
			if(i%2==0) {
				cout<<"F A"<<endl;
				cin>>y;
				if(y) FA++;
			}
			else {
				cout<<"F B"<<endl;
				cin>>y;
				if(y) FB++;
			}
			cout<<"E"<<endl;
			cin>>y;
			if(y) goto out;
			
		}
	}
	out:
	
	ll ret=0;
	cout<<"R A"<<endl;
	cout<<"R B"<<endl;
	while(FA>FB) {
		cout<<"F A"<<endl;
		cin>>y;
		FA--;
		ret++;
	}
	while(FA<FB) {
		cout<<"F B"<<endl;
		cin>>y;
		FB--;
		ret++;
	}
	
	while(1) {
		cout<<"E"<<endl;
		cin>>x;
		if(x) break;
		cout<<"F A"<<endl;
		cin>>x;
		cout<<"F B"<<endl;
		cin>>x;
		ret+=2;
	}
	cout<<"A "<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
