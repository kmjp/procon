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
int p10[10];
int W[50],R[50];

int ask(vector<int> V) {
	cout<<"?";
	FORR(v,V) cout<<" "<<v;
	cout<<endl;
	int ans;
	cin>>ans;
	return ans;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	p10[1]=10;
	p10[2]=100;
	p10[3]=1000;
	p10[4]=10000;
	
	cin>>N;
	FOR(i,10) {
		vector<int> V;
		int tot=0;
		FOR(x,N) {
			if(x>=i*5&&x<(i+1)*5) V.push_back(p10[x%5]),tot=1;
			else V.push_back(0);
		}
		if(tot==0) continue;
		y=ask(V);
		FOR(x,N) {
			if(x>=i*5&&x<(i+1)*5) {
				W[x]=y%10;
				if(W[x]<=2) W[x]+=10;
				y-=W[x];
				y/=10;
			}
		}
		assert(y==0);
	}
	
	cout<<"!";
	FOR(x,N) cout<<" "<<(W[x]==9||W[x]==11);
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

