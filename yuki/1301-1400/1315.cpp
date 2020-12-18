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

int S,T;

pair<int,int> pos(int v) {
	int i;
	for(i=1;;i+=2) {
		int cur=i*i;
		int nex=(i+2)*(i+2);
		int x,y;
		if(cur==v) return {i/2,-i/2};
		if(v<nex) {
			y=-i/2;
			x=i/2+1;
			v-=cur+1;
			int step=i+1;
			if(v<=step-1) return{x,y+v};
			y+=step-1;
			v-=step-1;
			if(v<=step) return{x-v,y};
			x-=step;
			v-=step;
			if(v<=step) return{x,y-v};
			y-=step;
			v-=step;
			return {x+v,y};
		}
	}
}

string R;

void go(int sx,int sy,int tx,int ty) {
	while(sx!=tx||sy!=ty) {
		if(sx<tx) sx++, R+="RLR";
		else if(sx>tx) sx--, R+="LRL";
		else if(sy<ty) sy++, R+="UDU";
		else if(sy>ty) sy--, R+="DUD";
		if(sx==tx&&sy==ty) break;
		
		if(sx<tx) sx++, R+="R";
		else if(sx>tx) sx--, R+="L";
		else if(sy<ty) sy++, R+="U";
		else if(sy>ty) sy--, R+="D";
		
		
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	auto p=pos(S);
	auto q=pos(T);
	//cout<<p.first<<p.second<<endl;
	//cout<<q.first<<q.second<<endl;
	if(abs(p.first+p.second)%2==abs(q.first+q.second)%2) {
		if(abs(p.first+p.second)%2==0) {
			go(p.first,p.second,0,0);
			R+="RUL";
			p={0,1};
		}
		else {
			go(p.first,p.second,1,0);
			R+="DLURL";
			p={0,0};
		}
		//cout<<"#"+R<<endl;
	}
	//cout<<p.first<<p.second<<endl;
	go(p.first,p.second,q.first,q.second);
	cout<<0<<endl;
	cout<<R.size()<<endl;
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
