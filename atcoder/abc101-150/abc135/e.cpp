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

int K,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>X>>Y;
	if(K%2==0 && (abs(X)+abs(Y))%2) {
		cout<<"-1"<<endl;
		return;
	}
	vector<pair<int,int>> V;
	if(K%2&&(abs(X)+abs(Y))%2) {
		V.push_back({X,Y});
		x=min(K,abs(X));
		if(X>0) X-=x;
		else X+=x;
		int lef=K-x;
		if(Y>0) Y-=lef;
		else Y+=lef;
	}
	
	while(abs(X)+abs(Y)>=2*K) {
		FOR(j,1+(K%2)) {
			V.push_back({X,Y});
			int lef=K;
			if(X>0) {
				i=min(X,lef);
				X-=i;
				lef-=i;
			}
			else if(X<0) {
				i=min(abs(X),lef);
				X+=i;
				lef-=i;
			}
			if(Y>0) {
				i=min(abs(Y),lef);
				Y-=i;
				lef-=i;
			}
			else if(Y<0) {
				i=min(abs(Y),lef);
				Y+=i;
				lef-=i;
			}
		}
	}
	
	if(abs(X)+abs(Y)==K) {
		V.push_back({X,Y});
	}
	else if(X||Y) {
		V.push_back({X,Y});
		if(abs(X)>abs(Y)) {
			x=(abs(X)+abs(Y))/2;
			y=K-abs(x);
			
			if(X>0) X=x;
			else X=-x;
			if(Y>=0) Y=-y;
			else Y=y;
		}
		else {
			y=(abs(X)+abs(Y))/2;
			x=K-abs(y);
			
			if(Y>0) Y=y;
			else Y=-y;
			if(X>=0) X=-x;
			else X=x;
		}
		V.push_back({X,Y});
	}
	
	reverse(ALL(V));
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
