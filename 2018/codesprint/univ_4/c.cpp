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

int Q;
int X1,Y1,X2,Y2;

int ok(int x1,int y1,int x2,int y2,vector<int> C) {
	int mask=0;
	
	FORR(c,C) {
		int x=c/8%8,y=c%8;
		if(x==x1&&y==y1) continue;
		if(x==x2&&y==y2) continue;
		if(x==x1 && (x2!=x1 || (y2-y)*(y2-y1)>0)) mask |= 1;
		if(y==y1 && (y2!=y1 || (x2-x)*(x2-x1)>0)) mask |= 1;
		if(x+y==x1+y1 && (x2+y2!=x1+y1 || (x2-x)*(x2-x1)>0)) mask |= 1;
		if(x-y==x1-y1 && (x2-y2!=x1-y1 || (x2-x)*(x2-x1)>0)) mask |= 1;
		
		if(x==x2 && (x1!=x2 || (y1-y)*(y1-y2)>0)) mask |= 2;
		if(y==y2 && (y1!=y2 || (x1-x)*(x1-x2)>0)) mask |= 2;
		if(x+y==x2+y2 && (x1+y1!=x2+y2 || (x1-x)*(x1-x2)>0)) mask |= 2;
		if(x-y==x2-y2 && (x1-y1!=x2-y2 || (x1-x)*(x1-x2)>0)) mask |= 2;
		
	}
	
	return mask==3;
}

vector<int> hoge(vector<int> C) {
	vector<int> ng={5};
	
	FORR(c,C) {
		int x=c/8%8,y=c%8;
		if(x==X1&&y==Y1) return ng;
		if(x==X2&&y==Y2) return ng;
	}
	
	for(int x=max(0,X1-1);x<=min(7,X1+1);x++) {
		for(int y=max(0,Y1-1);y<=min(7,Y1+1);y++) {
			if(x==X2&&y==Y2) continue;
			if(ok(x,y,X2,Y2,C)==0) return ng;
		}
	}
	for(int x=max(0,X2-1);x<=min(7,X2+1);x++) {
		for(int y=max(0,Y2-1);y<=min(7,Y2+1);y++) {
			if(x==X1&&y==Y1) continue;
			if(ok(x,y,X1,Y1,C)==0) return ng;
		}
	}
	
	C.push_back(C.size());
	reverse(ALL(C));
	return C;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>X1>>Y1>>X2>>Y2;
		
		vector<int> C={65},T;
		int a1,a2,a3;
		FOR(a3,64) {
			C=min(C,hoge({a3}));
			FOR(a2,a3) {
				C=min(C,hoge({a3,a2}));
				FOR(a1,a2) {
					C=min(C,hoge({a3,a2,a1}));
				}
			}
		}
		assert(C[0]==2 || C[0]==3);
		cout<<C[0]<<endl;
		FOR(j,C[0]) cout<<"Q "<<C[j+1]/8<<" "<<C[j+1]%8<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
