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
int C[5];
ll sum=0;

void hogemin(int a,int b) {
	int mi=min(C[a],C[b]);
	sum+=(a+b)/5*5*mi;
	C[a]-=mi;
	C[b]-=mi;
	C[(a+b)%5]+=mi;
}

void hogemul(int a,int v) {
	int mi=C[a]/v;
	sum+=(a*v)/5*5*mi;
	C[a]-=mi*v;
	C[(a*v)%5]+=mi;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int num=0;
	FOR(i,N) {
		cin>>x;
		sum+=x/5*5;
		C[x%5]++;
	}
	
	hogemin(3,4);
	hogemul(4,3);
	hogemul(4,2);
	hogemul(3,2);
	hogemin(2,3);
	hogemin(2,4);
	hogemin(1,3);
	hogemin(1,4);
	hogemul(1,2);
	
	num=C[1]+C[2]+C[3]+C[4];
	sum+=5*(C[3]+C[4]);
	
	
	cout<<sum<<" "<<max(1,num)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
