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

int H,W;

int ok[51][51];
int fil[51][51];

void get() {
	int x,y;
	cin>>y>>x;
	ok[y][x]--;
	fil[y][x]=1;
}

void test() {
	if(ok[H-1][W]==-1 || ok[H][W-1]==-1) {
		cout<<H<<" "<<W<<endl;
		get();
		exit(0);
	}
}

void go() {
	test();
	
	int y,x;
	for(y=1;y<=H;y++) {
		for(x=1;x<=W;x++) if(ok[y][x]==1) {
			if(y>1&&fil[y-1][x] ||
			   y<H&&fil[y+1][x] ||
			   x>1&&fil[y][x-1] ||
			   y<W&&fil[y][x+1]) {
				cout<<y<<" "<<x<<endl;
				ok[y][x]=0;
				fil[y][x]=1;
				return;
			}
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int left=0;
	for(y=1;y<=H;y++) {
		for(x=1;x<=W;x++) {
			if(y==1 && x==1) continue;
			if(y==H && x==W) continue;
			if(y==H && x==W-1) continue;
			if(y==H-1 && x==W) continue;
			ok[y][x]=1;
			left++;
		}
	}
	ok[1][1]=-1;
	fil[1][1]=1;
	
	if(H==1&&W==2 || H==2&&W==1) {
		cout<<"First"<<endl;
		cout<<H<<" "<<W<<endl;
		exit(0);
	}
	
	
	if(left%2==0) {
		cout<<"Second"<<endl;
		get();
	}
	else {
		cout<<"First"<<endl;
	}
	while(1) {
		go();
		get();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
