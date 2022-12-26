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
string S;
ll p10[101010];
ll num[101010];
ll sum[101010];
ll mo;

int small(deque<int>& D,int first) {
	int v=0,ret=0;
	FORR(c,D) v=v*10+c;
	for(int i=first;i<=v;i++) {
		char buf[10];
		string a,b;
		if(first) {
			sprintf(buf,"%d",i);
			a=buf;
		}
		else {
			sprintf(buf,"%06d",i);
			a=buf;
			a=a.substr(a.size()-D.size());
		}
		b=a;
		reverse(ALL(b));
		if(a==b) ret++;
	}
	return ret;
}

ll gogo(deque<int>& D,int first=0) {
	int i,j,k,l,r,x,y;
	
	if(D.size()<=4) return small(D,first);
	
	ll ret=0;
	if(first) {
		ret += 9*sum[D.size()-1];
		(ret += (D[0]-1)*10*num[D.size()-2])%=mo;
	}
	else {
		(ret += D[0]*10*num[D.size()-2])%=mo;
	}
	
	int del=D[0]>D.back();
	D.pop_front();
	D.pop_back();
	for(i=D.size()-1;i>=0&&del;i--) {
		D[i]--;
		if(D[i]>=0) del=0;
		else D[i]=9;
	}
	if(del==0) ret += gogo(D);
	return ret%mo;
}

ll hoge() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,100001) {
		p10[i+1]=p10[i]*10%mo;
		if(i==0) num[i]=0;
		else num[i]=p10[(i-1)/2]%mo;
		sum[i]=((i==0)?0:sum[i-1])+num[i];
	}
	
	deque<int> T;
	FORR(c,S) T.push_back(c-'0');
	return gogo(T,1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	
	mo=1000000000;
	cout<<hoge()<<endl;
	mo=1000000007;
	cout<<hoge()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
