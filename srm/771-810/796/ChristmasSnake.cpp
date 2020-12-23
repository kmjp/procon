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

int D[8][8];
int from[8][8];

class ChristmasSnake {
	public:
	vector<string> nex(vector <string> game, char cmd) {
		vector <string> nex=game;
		int cy,cx;
		int y,x;
		char la='a';
		FOR(y,8) FOR(x,8) {
			if(game[y][x]>='a'&&game[y][x]<='z') la=max(la,game[y][x]);
			if(game[y][x]=='a') cy=y,cx=x;
		}
		FOR(y,8) FOR(x,8) {
			if(nex[y][x]==la) nex[y][x]='.';
			if(nex[y][x]>='a'&&nex[y][x]<la) nex[y][x]++;
		}
		if(cmd=='N') cy--;
		if(cmd=='S') cy++;
		if(cmd=='W') cx--;
		if(cmd=='E') cx++;
		nex[cy][cx]='a';
		return nex;
		
	}
	
	string turnAround(vector <string> S) {
		/*
		string C="WSSSSENNNNESEENNW";
		int y;
		FORR(c,C) {
			game=nex(game,c);
			FOR(y,8) cout<<game[y]<<endl;
			cout<<endl;
		}
		*/
		int y,x,sy,sx,i;
		queue<int> Q;
		char la='a';
		FOR(y,8) FOR(x,8) {
			D[y][x]=100;
			if(S[y][x]=='a') {
				D[y][x]=0;
				sy=y;
				sx=x;
				Q.push({y*8+x});
			}
			if(S[y][x]>='a'&&S[y][x]<='z') la=max(la,S[y][x]);
		}
		int cy,cx;
		while(Q.size()) {
			cy=Q.front()/8;
			cx=Q.front()%8;
			Q.pop();
			if(cy==0||cx==0||cy==7||cx==7) break;
			int i;
			FOR(i,4) {
				int d[4]={1,0,-1,0};
				int ty=cy+d[i];
				int tx=cx+d[i^1];
				if(S[ty][tx]=='.'&&D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					from[ty][tx]=cy*8+cx;
					Q.push(ty*8+tx);
				}
			}
		}
		string R,R2;
		cout<<cy<<cx<<endl;
		y=cy,x=cx;
		while(D[y][x]) {
			int ty=from[y][x]/8;
			int tx=from[y][x]%8;
			if(ty==y-1) R+='S',R2+='N';
			else if(ty==y+1) R+='N',R2+='S';
			else if(tx==x-1) R+='E',R2+='W';
			else if(tx==x+1) R+='W',R2+='E';
			y=ty;
			x=tx;
		}
		reverse(ALL(R));
		y=cy;
		x=cx;
		FOR(i,28) {
			if(y==0&&x<7) x++, R+='E';
			else if(x==7&&y<7) y++, R+='S';
			else if(y==7&&x>0) x--, R+='W';
			else y--,R+='N';
		}
		R+=R2;
		
		while(S[sy][sx]<la) {
			FOR(i,4) {
				int d[4]={1,0,-1,0};
				int ty=sy+d[i];
				int tx=sx+d[i^1];
				if(ty<0||ty>7||tx<0||tx>7) continue;
				if(S[ty][tx]==S[sy][sx]+1) {
					
					if(ty>sy) R+='S';
					if(ty<sy) R+='N';
					if(tx>sx) R+='E';
					if(tx<sx) R+='W';
					sy=ty;
					sx=tx;
					break;
				}
			}
		}
		
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"........",
 "....hg..",
 "..ab.f..",
 "...cde..",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WSSSSENNNNESEENNW"; verify_case(0, Arg1, turnAround(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 "........",
 "..a.....",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WSNNSE"; verify_case(1, Arg1, turnAround(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ChristmasSnake ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

