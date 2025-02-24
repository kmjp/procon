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

int Q;
ll I,A[2],B[2],X[2],Y[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>I;
		FOR(i,2) cin>>A[i]>>B[i]>>X[i]>>Y[i];
		
		FOR(i,2) if(A[i]*X[i]+B[i]*Y[i]!=I) break;
		if(i<2) {
			cout<<"No"<<endl;
			continue;
		}
		
		// X[0]�ł�Y[0]���Y[1]������
		if(A[1]*X[0]+B[1]*Y[0]<I&&A[0]*X[1]+B[0]*Y[1]<I) {
			cout<<"No"<<endl;
			continue;
		}
		//�Е�����_�p�^�[��
		if(A[0]*X[1]+B[0]*Y[1]==I&&A[1]*X[0]+B[1]*Y[0]<I) {
			cout<<"No"<<endl;
			continue;
		}
		if(A[0]*X[1]+B[0]*Y[1]<I&&A[1]*X[0]+B[1]*Y[0]==I) {
			cout<<"No"<<endl;
			continue;
		}
		
		cout<<"Yes"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
