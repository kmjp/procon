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

int X,Y;
int Q;
ll K;
multiset<ll> A,B;

ll XX(ll v) {
	if(v==1) return 1;
	ll cur=2;
	int s=0;
	while(1) {
		if(v<=cur+(1LL<<s)) return v-cur;
		if(v<=cur+(2LL<<s)) return cur+(2LL<<s)-v;
		cur+=2LL<<s;
		s++;
	}
	
}
ll YY(ll v) {
	if(v==1) return 0;
	if(v==2) return 1;
	ll cur=3;
	ll val=1;
	int s=1;
	while(1) {
		if(v<=cur+(1LL<<s)-val) {
			return v-cur+val;
		}
		cur+=(1LL<<s)-val;
		val<<=1;
		if(v<=cur+(1LL<<s)) return val;
		cur+=1LL<<s;
		s++;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Q;
	/*
	A.insert(X);
	B.insert(Y);
	
	for(i=3;i<=10000;i++) {
		if(A.size()==B.size()) {
			x=*A.rbegin()+*B.begin();
		}
		else {
			x=2**A.rbegin();
		}
		cout<<i<<" "<<x<<"  "<<YY(i)<<" "<<XX(i)<<endl;
		A.insert(x);
		y=*A.rbegin();
		A.erase(A.find(y));
		B.insert(y);
		if(B.size()>A.size()) {
			y=*B.begin();
			B.erase(B.begin());
			A.insert(y);
		}
	}
	*/
	while(Q--) {
		cin>>K;
		cout<<YY(K)*Y+XX(K)*X<<endl;
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
