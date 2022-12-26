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

int ask(vector<int> V) {
	cout<<"? "<<V.size();
	FORR(v,V) cout<<" "<<v;
	cout<<endl;
	string s;
	cin>>s;
	return s=="Rabbit";
}

void answer(int a,int b) {
	cout<<"! "<<a<<" "<<b<<endl;
	exit(0);
}

int N;


void hoge(int L,int R) {
	if(L+1==R) answer(L,R);
	vector<int> V;
	int i,x;
	int d=1;
	while(L+d*2<=R) d*=2;
	
	for(i=L;i<L+d;i++) V.push_back(i);
	if(ask(V)) hoge(L,L+d-1);
	V.clear();
	for(i=L+d;i<=R;i++) V.push_back(i);
	if(ask(V)) hoge(L+d,R);
	int M=L+d-1;
	
	int TR=M;
	for(i=12;i>=0;i--) if(TR+(1<<i)<R) {
		V.clear();
		for(x=L;x<=TR+(1<<i);x++) V.push_back(x);
		if(!ask(V)) TR+=1<<i;
	}
	TR++;
	int TL=M+1;
	for(i=12;i>=0;i--) if(TL-(1<<i)>L) {
		V.clear();
		for(x=TL-(1<<i);x<=TR;x++) V.push_back(x);
		if(!ask(V)) TL-=1<<i;
	}
	TL--;
	answer(TL,TR);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hoge(1,N);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
