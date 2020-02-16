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
ll K;
vector<ll> pos,neg;
ll zero;

ll num(ll v) {
	ll ret=0;
	int i,j;
	if(v>=0) {
		ret+=1LL*pos.size()*neg.size();
		ret+=zero*(pos.size()+neg.size())+zero*(zero-1)/2;
		
		for(i=j=pos.size()-1;i>=0;i--) {
			j=min(j,i-1);
			while(j<i-1 && pos[i]*pos[j+1]<=v) j++;
			while(j>=0 && pos[i]*pos[j]>v) j--;
			ret+=j+1;
		}
		for(i=j=neg.size()-1;i>=0;i--) {
			j=min(j,i-1);
			while(j<i-1 && neg[i]*neg[j+1]<=v) j++;
			while(j>=0 && neg[i]*neg[j]>v) j--;
			ret+=j+1;
		}
	}
	else {
		j=0;
		for(i=pos.size()-1;i>=0;i--) {
			while(j<neg.size() && pos[i]*neg[j]<-v) j++;
			ret+=neg.size()-j;
		}
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		if(x==0) zero++;
		if(x>0) pos.push_back(x);
		if(x<0) neg.push_back(-x);
	}
	sort(ALL(pos));
	sort(ALL(neg));
	
	ll ret=(1LL<<60);
	for(i=60;i>=0;i--) if(num(ret-(1LL<<i))>=K) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
