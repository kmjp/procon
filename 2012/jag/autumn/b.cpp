#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int card(string S) {
	int v=0;
	if(S[0]=='S') v=0;
	if(S[0]=='D') v=13;
	if(S[0]=='H') v=26;
	if(S[0]=='C') v=39;
	
	if(S[1]=='A') v+=12;
	else if(S[1]=='T') v+=8;
	else if(S[1]=='J') v+=9;
	else if(S[1]=='Q') v+=10;
	else if(S[1]=='K') v+=11;
	else v+=S[1]-'2';
	return v;
}

int hand(vector<int> V) {
	if(V[0]/13==V[4]/13) {
		FORR(r,V) r%=13; // remove suit
		if(V[0]+4==12) return 9000000; //royal straight flush
		if(V[0]+4==V[4]) return 8000000+V[4]; // straight
		if(V[0]==0 && V[3]==3 && V[4]==12) return 8000000+3;
		return 5000000+(((V[4]*13+V[3])*13+V[2])*13+V[1])*13+V[0];
	}
	else {
		FORR(r,V) r%=13; // remove suit
		sort(ALL(V));
		if(V[0]==V[3]) return 7000000+V[2]*13+V[4]; // four card
		if(V[1]==V[4]) return 7000000+V[2]*13+V[0];
		if(V[0]==V[2] && V[3]==V[4]) return 6000000+V[0]*13+V[4]; // full house
		if(V[0]==V[1] && V[2]==V[4]) return 6000000+V[4]*13+V[0];
		if(V[0]+1==V[1] && V[1]+1==V[2] && V[2]+1==V[3] && V[3]+1==V[4]) return 4000000+V[4]; // straight
		if(V[0]==0 && V[1]==1 && V[2]==2 && V[3]==3 && V[4]==12) return 4000000+3;
		if(V[0]==V[2]) return 3000000+V[2]*13*13+V[4]*13+V[3]; // three card
		if(V[1]==V[3]) return 3000000+V[2]*13*13+V[4]*13+V[0];
		if(V[2]==V[4]) return 3000000+V[2]*13*13+V[1]*13+V[0];
		if(V[0]==V[1]&&V[2]==V[3]) return 2000000+V[3]*13*13+V[1]*13+V[4]; // two pair
		if(V[0]==V[1]&&V[3]==V[4]) return 2000000+V[3]*13*13+V[1]*13+V[2];
		if(V[1]==V[2]&&V[3]==V[4]) return 2000000+V[3]*13*13+V[1]*13+V[0];
		if(V[4]==V[3]) return 1000000+V[3]*13*13*13+V[2]*13*13+V[1]*13+V[0]; // one pair
		if(V[3]==V[2]) return 1000000+V[2]*13*13*13+V[4]*13*13+V[1]*13+V[0];
		if(V[2]==V[1]) return 1000000+V[1]*13*13*13+V[4]*13*13+V[3]*13+V[0];
		if(V[1]==V[0]) return 1000000+V[0]*13*13*13+V[4]*13*13+V[3]*13+V[2];
		return (((V[4]*13+V[3])*13+V[2])*13+V[1])*13+V[0];
	}
}

int hand(int c1,int c2,int c3,int c4,int c5,int c6,int c7) {
	int ma=0,mask,i;
	
	vector<int> V={c1,c2,c3,c4,c5,c6,c7};
	sort(ALL(V));
	FOR(mask,1<<7) if(__builtin_popcount(mask)==5) {
		vector<int> V2;
		FOR(i,7) if(mask & (1<<i)) V2.push_back(V[i]);
		ma=max(ma,hand(V2));
	}
	return ma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		int my[2],op[2],com[5];
		int vis[60]={};
		cin>>s;
		if(s=="#") return;
		
		my[0]=card(s), vis[my[0]]=1;
		cin>>s; my[1]=card(s), vis[my[1]]=1;
		cin>>s; op[0]=card(s), vis[op[0]]=1;
		cin>>s; op[1]=card(s), vis[op[1]]=1;
		cin>>s; com[0]=card(s), vis[com[0]]=1;
		cin>>s; com[1]=card(s), vis[com[1]]=1;
		cin>>s; com[2]=card(s), vis[com[2]]=1;
		i=0;
		int win=0;
		FOR(y,52) FOR(x,y) if(vis[x]==0 && vis[y]==0)
			win += hand(my[0],my[1],com[0],com[1],com[2],x,y)>hand(op[0],op[1],com[0],com[1],com[2],x,y);
		
		_P("%.12lf\n",win/(45*44/2.0));
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
