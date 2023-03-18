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
int A[8080],B[8080],C[8080],D[8080];
vector<int> p2,p3,p4;

int bestA[8080];
int bestB[8080];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int num1=0,psum=0;
	int cx=0,cy=0;
	
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		
		if(A[i]!=C[i]&&B[i]!=D[i]) {
			if(A[i]!=B[i]) {
				num1++;
				psum+=i+1;
			}
			else {
				p2.push_back(i+1);
			}
			
		}
		else {
			if(A[i]==C[i]) {
				if(A[i]==2) psum+=i+1, cx++;
			}
			else {
				p3.push_back(i+1);
			}
			if(B[i]==D[i]) {
				if(B[i]==2) psum+=i+1, cy++;
			}
			else {
				p4.push_back(i+1);
			}
		}
	}
	
	reverse(ALL(p2));
	reverse(ALL(p3));
	reverse(ALL(p4));
	FOR(i,N+1) {
		bestA[i]=-i*(i+1)/2;
		int sum=0;
		FOR(j,p3.size()) {
			sum+=p3[j];
			bestA[i]=max(bestA[i],sum-(i+j+1)*(i+j+2)/2);
		}
		bestB[i]=-i*(i+1)/2;
		sum=0;
		FOR(j,p4.size()) {
			sum+=p4[j];
			bestB[i]=max(bestB[i],sum-(i+j+1)*(i+j+2)/2);
		}
	}
	int ret=0;
	FOR(i,num1+1) {
		int sum=0;
		FOR(j,p2.size()+1) {
			x=i+j+cx;
			y=num1-i+j+cy;
			ret=max(ret,psum+sum+bestA[x]+bestB[y]);
			if(j<p2.size()) sum+=2*p2[j];
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
