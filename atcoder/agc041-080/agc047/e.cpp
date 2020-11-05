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


ll A[202020];
vector<vector<int>> V;

ll X,Y;


void out() {
	int i;
	for(i=0;i<=10;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=1000;i<=1030;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=1100;i<=1130;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=1200;i<=1230;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=2000;i<=2030;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=2100;i<=2130;i++) cout<<A[i]<<" ";
	cout<<endl;
	cout<<" ";
	for(i=2200;i<=2230;i++) cout<<A[i]<<" ";
	cout<<endl;
}


void add(int i,int j,int k) {
	V.push_back({0,i,j,k});
	//cout<<"+ "<<i<<" "<<j<<" "<<k<<endl;
	A[k]=A[i]+A[j];
	//out();
}
void comp(int i,int j,int k) {
	V.push_back({1,i,j,k});
	//cout<<"< "<<i<<" "<<j<<" "<<k<<endl;
	A[k]=(A[i]<A[j]);
	//out();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	A[0]=X;
	A[1]=Y;
	// A[3]=X+Y
	add(0,1,3);
	// A[4]=1
	comp(2,3,4);
	// X++,Y++
	add(0,4,0);
	add(1,4,1);
	// A[1000]=1,A[1001]=2,....A[1030]=1<<30
	// A[2000]=1,A[2001]=2,....A[2030]=1<<30
	add(4,1000,1000);
	add(4,2000,2000);
	for(i=1001;i<=1030;i++) add(i-1,i-1,i);
	for(i=2001;i<=2030;i++) add(i-1,i-1,i);
	
	for(x=1000;x<=2000;x+=1000) {
		for(i=x+30;i>=x;i--) {
			// check 2^i<X
			comp(i,x/1000-1,i+100);
			comp(i,x/1000-1,i+200);
			// *2^i
			FOR(j,i-x) add(i+100,i+100,i+100);
			// add
			for(j=x;j<i;j++) add(j,i+100,j);
		}
	}
	
	FOR(x,30) FOR(y,30) {
		add(1200+x,2200+y,5);
		comp(4,5,5);
		FOR(i,x+y) add(5,5,5);
		add(5,2,2);
	}
	
	
	
	assert(A[2]==(X*Y));
	cout<<V.size()<<endl;
	FORR(v,V) {
		cout<<"+<"[v[0]]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
