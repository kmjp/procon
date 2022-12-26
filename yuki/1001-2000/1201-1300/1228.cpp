#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int K;
ll X;
int Z;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>X;
	
	
	if(X==0) {
		cout<<"Yes"<<endl;
		cout<<1<<endl;
		cout<<(K^1)<<endl;
		return;
	}
	
	vector<int> V;
	if(K==0) {
		if(X&(X+1)) {
			cout<<"No"<<endl;
			return;
		}
		X++;
		while(X%2==0) X/=2, Z++;
		FOR(i,10) V.push_back(1<<i);
		for(i=1;i<=Z;i++) V.push_back(i);
	}
	else {
		if(X&(X-1)) {
			cout<<"No"<<endl;
			return;
		}
		x=1;
		while((K&x)==0) x<<=1;
		y=1;
		V.push_back(K);
		FOR(i,9) {
			if(x==y) y<<=1;
			V.push_back(y);
			y<<=1;
		}
		while(X%2==0) X/=2, Z++;
		y=1;
		for(i=1;i<=Z;i++) {
			while(x&y) y++;
			V.push_back(y);
			y++;
		}
		
	}
	cout<<"Yes"<<endl;
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	return;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
