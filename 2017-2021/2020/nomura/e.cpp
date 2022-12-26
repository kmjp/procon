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


string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	
	vector<int> num;
	num.push_back(0);
	int C1=0;
	ll ret=0;
	int cur=0;
	int fix=0;
	FOR(i,T.size()) {
		if(T[i]=='0') {
			if(cur%2) num.push_back(0);
			fix+=cur/2;
			num.back()++;
			cur=0;
		}
		else {
			C1++;
			cur++;
			ret+=(C1+1)/2;
		}
	}
	fix+=cur/2;
	if(cur%2) num.push_back(0);
	
	ret+=1LL*count(ALL(T),'0')*fix;
	
	
	FOR(i,num.size()-1) if(i && num[i]) {
		num[i]--;
		ret+=i+(num.size()-1-i+1)/2;
	}
	fix=num.size()-1;
	int CC[2]={};
	for(i=num.size()-1;i>=0;i--) {
		while(num[i]) {
			swap(CC[0],CC[1]);
			ret+=fix+CC[1];
			num[i]--;
		}
		CC[1]++;
		fix--;
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
