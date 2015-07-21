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

/*
int N;
ll momo[4]={1000000007,1000000009,1000000021,1000000033};
typedef pair<pair<ll,ll>,pair<ll,ll> > pllll;
map<ll,pllll> memo[200];

int id(int x,int y) { return x+y*(N+1)-(y-1)*y/2;}

ll calchash(deque<int> v) {
	ll h=0;
	FORR(r,v) h=h*9+(r+2);
	return h;
}

int conn(deque<int>& pre,int id) { // ２点を連結
	if(pre[0]==-2 || pre[id]==-2) return 0; // 既に２点連結済み
	if(pre[0]==-1 && pre[id]==-1) {
		pre[0]=pre[id]=N+1; // 相互連結、新規パス生成
		return 1;
	}
	else if(pre[0]==-1) { // 0をidに連結
		pre[0]=pre[id];
		pre[id]=-2;
		return 1;
	}
	else if(pre[id]==-1) { // idを0に連結
		pre[id]=pre[0];
		pre[0]=-2;
		return 1;
	}
	else if(pre[0]==pre[id]) { //同じグループの終端
		// 他グループの終端があるか？
		pre[0]=pre[id]=-2;
		FORR(r,pre) if(r>=0) return 0;
		return 2; // 閉路完成
	}
	// 異なるパスの終端同士連結
	int tid=pre[id];
	FORR(r,pre) if(r==tid) r=pre[0];
	pre[0]=pre[id]=-2;
	return 1;
}

void regroup(deque<int>& pre) { // 残ったパスを0からまた連番にする
	int x=0;
	map<int,int> m;
	FORR(r,pre) if(r>=0) {
		if(!m.count(r)) m[r]=x++;
		r=m[r];
	}
}

pllll gogo(int y,int x,deque<int> pre) {
	
	pllll ret={{0,0},{0,0}};
	
	if(x>N-y) y++,x=0;
	if(y>N) return ret;
	while(y&&pre.size()>(N+2-y)) {
		if(pre.back()>=0) return ret;
		pre.pop_back();
	}
	
	int myid = id(x,y);
	ll h=calchash(pre);
	if(memo[myid].count(h)) return memo[myid][h];
	
	int i,j,pat,res;
	pre.push_front(-1);
	FOR(pat,7) { // 3方向連結はないので0-6まで
		deque<int> cur=pre;
		int fin=0;
		if(pat&1) { // 左連結
			if(x==0) continue;
			res = conn(cur,myid-id(x-1,y));
			if(res==0) continue;
			if(res==2) fin=1;
			regroup(cur);
		}
		if(pat&2) { // 左下連結
			if(y==0) continue;
			res = conn(cur,myid-id(x,y-1));
			if(res==0) continue;
			if(res==2) fin=1;
			regroup(cur);
		}
		if(pat&4) { // 右下連結
			if(y==0) continue;
			res = conn(cur,myid-id(x+1,y-1));
			if(res==0) continue;
			if(res==2) fin=1;
			regroup(cur);
		}
		
		if(fin) { // 閉路完成
			ret.first.first++;
			ret.first.second++;
			ret.second.first++;
			ret.second.second++;
		}
		else { // 次の頂点へ
			auto r = gogo(y,x+1,cur);
			ret.first.first  +=r.first.first  ;
			ret.first.second +=r.first.second ;
			ret.second.first +=r.second.first ;
			ret.second.second+=r.second.second;
		}
	}
	
	pre.pop_front();
	ret.first.first  %=momo[0];
	ret.first.second %=momo[1];
	ret.second.first %=momo[2];
	ret.second.second%=momo[3];
	return memo[myid][h]=ret;
}
*/

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	for(i=1;i<=12;i++) {
		N=i;
		_P("%d :",i);
		FOR(x,200) memo[x].clear();
		auto r = gogo(0,0,deque<int>());
		_P(" %lld %lld %lld %lld\n",r.first.first,r.first.second,r.second.first,r.second.second);
	}
	*/
	/*
上記コメントアウト欄のコードを実行すると下記の出力が得られる。
1 : 1 1 1 1
2 : 11 11 11 11
3 : 110 110 110 110
4 : 2402 2402 2402 2402
5 : 128967 128967 128967 128967
6 : 16767653 16767653 16767653 16767653
7 : 436906633 436906623 436906563 436906503
8 : 952701106 952692294 952639422 952586550
9 : 657618983 639979715 534144107 428308499
10 : 622300340 963605721 11445252 59297272
11 : 509031918 989378757 959195292 79415546
12 : 650337412 967055801 137335159 913160201

CRTで上記解から多倍長整数値を求めるpythonコード
上の処理で出てきた4つの数字A～Dを以下のように並べて食わせる
A 1000000007
B 1000000009
C 1000000021
D 1000000033

def ext_gcd(p,q): # px+qy=gcd
	if q==0:
		return (p,1,0)
	(g,y,x) = ext_gcd(q, p%q)
	return (g,x,y - (p//q)*x)

def crt(a1,mo1,a2,mo2): # return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	g,x,y=ext_gcd(mo1,mo2)
	a1%=mo1
	a2%=mo2
	if a1%g != a2%g:
		return (-1,0)
	lcm=mo1*(mo2/g)
	return ((a1+((a2-a1)%lcm)*x%lcm*(mo1/g)) % lcm,lcm)

import sys

x=0
y=1

for line in iter(sys.stdin.readline, ""):
	A,B=map(int,line.split(" "))
	(x,y)=crt(x,y,A,B)

print x,y
*/
	
	string rets[12]={
		"1",
		"11",
		"110",
		"2402",
		"128967",
		"16767653",
		"5436906668",
		"4406952731948",
		"8819634719356421",
		"43329348004927734247",
		"522235268182347360718818",
		"15436131339319739257518081878",
	};
	
	cin>>x;
	cout<<rets[x-1]<<endl;
	return;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
