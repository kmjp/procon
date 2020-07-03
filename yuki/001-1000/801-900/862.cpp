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

int N,X;
vector<int> V;

void hoge() {
	int i;
	for(i=4;i<=100000;i+=4) if(N) {
		if(X<i || i+4<=X) {
			V.push_back(i);
			V.push_back(i+1);
			V.push_back(i+2);
			V.push_back(i+3);
			N--;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	if(N%4==0) {
		N/=4;
		if(X>=4) {
			V.push_back(1);
			V.push_back(2);
			V.push_back(3);
			V.push_back(X);
			N--;
			hoge();
		}
		else {
			N--;
			hoge();
			if(X==1) {
				V.push_back(100000);
				V.push_back(100002);
				V.push_back(1);
				V.push_back(2);
			}
			if(X==2) {
				V.push_back(100000);
				V.push_back(100001);
				V.push_back(1);
				V.push_back(2);
			}
			if(X==3) {
				V.push_back(100000);
				V.push_back(100001);
				V.push_back(1);
				V.push_back(3);
			}
		}
	}
	else if(N%4==1) {
		N--;
		V.push_back(X);
		N/=4;
		hoge();
	}
	else if(N%4==2) {
		N/=4;
		hoge();
		if(X==1) {
			V.push_back(2);
			V.push_back(3);
		}
		else if(X==2) {
			V.push_back(1);
			V.push_back(3);
		}
		else if(X==3) {
			V.push_back(1);
			V.push_back(2);
		}
		else {
			V.push_back(X^1);
			V.push_back(1);
		}
	}
	else if(N%4==3) {
		if(X>=4) {
			N/=4;
			hoge();
			for(i=4;i<=100000;i+=4) {
				if(X>=i&&X<i+4) {
					if(i!=X) V.push_back(i);
					if(i+1!=X) V.push_back(i+1);
					if(i+2!=X) V.push_back(i+2);
					if(i+3!=X) V.push_back(i+3);
				}
			}
			
		}
		else {
			N/=4;
			hoge();
			if(X==1) {
				V.push_back(100000);
				V.push_back(100002);
				V.push_back(3);
			}
			if(X==2) {
				V.push_back(100000);
				V.push_back(100001);
				V.push_back(3);
			}
			if(X==3) {
				V.push_back(100000);
				V.push_back(100001);
				V.push_back(2);
			}
		}
	}
	sort(ALL(V));
	FORR(x,V) cout<<x<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
