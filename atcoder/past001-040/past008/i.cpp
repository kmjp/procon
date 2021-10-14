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

multiset<ll> A,B;
int N;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(x%2==0) A.insert(x);
		else B.insert(x);
	}
	A.insert(1LL<<60);
	B.insert((1LL<<60)+1);
	while(1) {
		ll a=*A.begin();
		if(a==1LL<<60) break;
		A.erase(A.begin());
		a/=2;
		if(a%2==0) A.insert(a);
		else B.insert(a);
		
		if(*A.begin()<*B.begin()) {
			A.insert(*A.begin()*3);
			A.erase(A.begin());
		}
		else {
			B.insert(*B.begin()*3);
			B.erase(B.begin());
		}
	}
	
	cout<<min(*A.begin(),*B.begin())<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
