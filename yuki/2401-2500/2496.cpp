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

int N;
int A[2020],B[2020];

int ask(int a,int b) {
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	cin>>a;
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) {
		cout<<"! 1 1"<<endl;
		return;
	}
	
	int piv;
	for(i=N;i>=1;i--) {
		for(x=2;x<i;x++) if(i%x==0) break;
		if(x==i) {
			piv=i;
			break;
		}
		
	}
	
	vector<int> C;
	FOR(i,N) {
		B[i]=ask(0,i);
		if(B[i]%piv==0) C.push_back(i);
	}
	
	if(C.size()>1) {
		C.clear();
		FOR(i,N) {
			B[i]/=piv;
			if(B[i]==1) C.push_back(i);
		}
		x=ask(1,C[0]);
		y=ask(1,C[1]);
		if(x<y) {
			B[C[1]]=piv;
			x=C[0];
		}
		else {
			B[C[0]]=piv;
			x=C[1];
		}
		FOR(i,N) A[i]=ask(i,x);
	}
	else {
		x=C[0];
		C.clear();
		FOR(i,N) {
			A[i]=ask(i,x)/piv;
			if(A[i]==1) C.push_back(i);
		}
		x=ask(C[0],(x+1)%N);
		if(x%piv) {
			A[C[1]]=piv;
			x=C[0];
		}
		else {
			A[C[0]]=piv;
			x=C[1];
		}
		
		FOR(i,N) {
			vector<int> V;
			for(j=1;j<=N;j++) if(A[0]*j/__gcd(A[0],j)==B[i]) V.push_back(j);
			if(V.size()==1) {
				B[i]=V[0];
			}
			else {
				B[i]=ask(x,i);
			}
		}
		
		
	}
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i];
	FOR(i,N) cout<<" "<<B[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
