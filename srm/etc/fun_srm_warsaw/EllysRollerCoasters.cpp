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

class SCC {
public:
	static const int MV = 25000;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV*2; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // x or y  k+0:normal k+NV:inverse
		sc.add_edge((x+NV/2)%NV,y); // not x->y
		sc.add_edge((y+NV/2)%NV,x); // not y->x
	}
	
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};

TwoSat ts;
class EllysRollerCoasters {
	public:
	vector <string> getPlan(vector <string> F) {
		int H=F.size(),W=F[0].size();
		int NV=4*H*W;
		int y,x;
		vector<string> ret;
		
		ts.init(NV);
		FOR(y,H) FOR(x,W) {
			char c=F[y][x];
			int ID=(y*W+x)*4;
			if(c=='.') {
				ts.add_edge(ID+NV,ID+NV);
				ts.add_edge(ID+1+NV,ID+1+NV);
				ts.add_edge(ID+2+NV,ID+2+NV);
				ts.add_edge(ID+3+NV,ID+3+NV);
			}
			//LRUD
			if(c=='L') {
				ts.add_edge(ID,ID);
				ts.add_edge(ID+1+NV,ID+1+NV);
				ts.add_edge(ID+2,ID+3);
				ts.add_edge(ID+2+NV,ID+3+NV);
			}
			if(c=='R') {
				ts.add_edge(ID+1,ID+1);
				ts.add_edge(ID+NV,ID+NV);
				ts.add_edge(ID+2,ID+3);
				ts.add_edge(ID+2+NV,ID+3+NV);
			}
			if(c=='U') {
				ts.add_edge(ID+2,ID+2);
				ts.add_edge(ID+3+NV,ID+3+NV);
				ts.add_edge(ID+0,ID+1);
				ts.add_edge(ID+0+NV,ID+1+NV);
			}
			if(c=='D') {
				ts.add_edge(ID+3,ID+3);
				ts.add_edge(ID+2+NV,ID+2+NV);
				ts.add_edge(ID+0,ID+1);
				ts.add_edge(ID+0+NV,ID+1+NV);
			}
			if(c=='S') {
				ts.add_edge(ID+0,ID+1+NV);
				ts.add_edge(ID+1,ID+0+NV);
				ts.add_edge(ID+2,ID+3+NV);
				ts.add_edge(ID+3,ID+2+NV);
				ts.add_edge(ID,ID+2);
				ts.add_edge(ID+NV,ID+2+NV);
			}
			
			if(x<W-1) {
				ts.add_edge(ID+1,ID+4+NV);
				ts.add_edge(ID+4,ID+1+NV);
			}
			if(y<H-1) {
				ts.add_edge(ID+3,ID+4*W+2+NV);
				ts.add_edge(ID+4*W+2,ID+3+NV);
			}
			if(x==0) ts.add_edge(ID+NV,ID+NV);
			if(x==W-1) ts.add_edge(ID+1+NV,ID+1+NV);
			if(y==0) ts.add_edge(ID+2+NV,ID+2+NV);
			if(y==H-1) ts.add_edge(ID+3+NV,ID+3+NV);
		}
		if(!ts.sat()) return ret;
		
		char hoge[17]=".**-*/\\**\\/*|***";
		FOR(y,H) {
			string s;
			FOR(x,W) {
				int ID=(y*W+x)*4;
				s+=hoge[ts.val[ID]+ts.val[ID+1]*2+ts.val[ID+2]*4+ts.val[ID+3]*8];
			}
			ret.push_back(s);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"RSSLRD",
 "SDDSSS",
 "SULUUS",
 "ULRLDL",
 "RLSSRL",
 "SDUSDL",
 "SRSLRD",
 "RSSSSL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"/--\\/\\", "|/\\|||", "|\\/\\/|", "\\\\/\\//", "//||\\\\", "|//|//", "|\\-/\\\\", "\\----/" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPlan(Arg0)); }
	void test_case_1() { string Arr0[] = {"RDL",
 "RLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPlan(Arg0)); }
	void test_case_2() { string Arr0[] = {"DSSSSLDSSSDRSSSDDSSDDSSDRDRSSSD",
 "USLRSUSDSSUSDSLSUSDSSDLSSSRSSDS",
 "..SS..SS...SS.SSRSUSSSSSSS...SS",
 "..SS..SS...SS.SSSDSUSSSSSS...SS",
 "..SS..SS...SS.SSSRSDSULSSS...SS",
 "..SS..SS...SS.SSUSSUUSSUUL...UL",
 "..SS..SRSSDSRSLSDSSSSSSSSSSSSSL",
 "..RU..RSSSURSSSURSSSSSSSSSSSSSU"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"/----\\/---\\/---\\/--\\/--\\/\\/---\\", "\\-\\/-/|/--/|/-\\|\\-\\||/\\|||\\--\\|", "..||..||...||.||/-/|||||||...||", "..||..||...||.|||/-/||||||...||", "..||..||...||.|||\\-\\|\\/|||...||", "..||..||...||.||\\--/\\--/\\/...\\/", "..||..|\\--\\|\\-/|/-------------\\", "..\\/..\\---/\\---/\\-------------/" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPlan(Arg0)); }
	void test_case_3() { string Arr0[] = {"DD.RSSSL.....DSSLRL.DSSLRL..RLDSD.DSSSSSSD",
 "SUSU...UDDSSLRSSLSS.UL.RUUSSURU.UDS.DSD.DU",
 "SRSL.RSSLUL.RDRD.RU..USD.RSSSLRSLSUSLRU.S.",
 "SS.RSU.DDRL..SSSDLDSSSDRDRL.RUS.RU.RDULRL.",
 "SRSDRSSUSS.DSURURLRD..UDULRSU.S.RSSLSRLRD.",
 "SRLSUD..UL.RLDSDDL.RD..SRLRL..S.S.DSUS..RD",
 "SSSS.S.RSSLDURLSUUDLUL.UU.RUDSL.SDU..S.RLS",
 "RUSS.S.S.DLSDDRL..RU.UD..RSSU.DLULRD.ULULS",
 "DSLS.RDRSLRLUURLRL.RDRLRDSDD..RURSURL.S..S",
 "S.RLRLUD.RURL.RURU.SUUDLSSUU.DD.S.DSL.USSL",
 "RSU.SS.S.S.RU.DSD..RL.RDSUSSSLRSU.S.DLDL..",
 "DSSSLRSL.S..DSU.RDDLRDDLS....RD...USLUURSD",
 "RLDSSSLRSUDDS.DSDSSSRLRDUSSLDLUSSSSL.DL..S",
 ".SSDDDUS..SSS.RDSULSRSLS.DDSRSDDLRLRDSUSSL",
 ".RURLUDSRLRLRSDUURLRSLSS.RLRL.SRLRU.UL.DSL",
 "RSSL.RUSSSRD..RSDRU.DLSS..RDULS.DSSDDL.USU",
 "SDLRSL.UUSSSRD.DUDDDU.RU.RUUDULRUDDRLS.RSL",
 "ULSDSSLRSURLRU.SRUUURSSSSL..S..S.SSRSU.ULS",
 ".RURDRUUL..RSDDLS..RUDSSSSL.RD.S.RUUSDRDSS",
 ".RSSUS..UL.S.RU.RL.UDRSSSSLDLUSUDSSSSLRUUU",
 "RL..RLRSLS.RSD.RSURDRSSSDDSUUSSSLRSSDDL.RD",
 "SRSLSRLRLSDL.S.RL.RLRLDSUUD..RL..RSSLSS.UU",
 "RSLULUSLRLRL.SDLSRSSUSUSSSU.DUS.DSD.RURL..",
 ".RLDSDRLRSLRDSUUSUL..RSSSSSSL.UDUDRLRSDUSL",
 ".RSU.SULRSUSSS.DL.S.DSSSD.RL..RL.SDUDDULDL",
 "RSSLRURDRD.RUSRUDLRSL.RDULUURSU.DUS.UL.SS.",
 "USSUSDUS.S.RDSRDSUD.RDUL.SRLS...SRLDD..SUL",
 ".RSSURLS.RLSSRSUUSL.SS...SULRL..RUDLSDLS.S",
 ".SDDDSUS.DLUU..DD..RURSSSUDSSURSSLRSUSULRU",
 ".SSSRSDRDS.RSD.UURLSRD.DSLRLRLS.RU.DSU.RL.",
 "RUSRSSLDURLULUL..SSSSUSL.S.SUUUSLRDUSL.SDD",
 "RSL..RLRD.UDS.S.RLRLUD.DDS.S.RSSSLUD.USURL",
 "DSSSDUL.S..SRDSDU....SDLRL.SDL..DSDUSSSSSL",
 "UDDSU.RDRSDSRUSRSD.DLSS.DL.ULRSLS.RLRSD.DL",
 ".UU.RLULDLRURSUDLS.RLUL.SS...SDURL.RLDU.S.",
 "RDDDSSDDSUSLDSLSSS...RSSLUSDDUS..S.DDRD.RL",
 "RUUURLULUSSLRSLUUUSSSL.....UL.USSL.UL.USSU"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"/\\./---\\...../--\\/\\./--\\/\\../\\/-\\./------\\", "|\\-/...\\\\/--\\\\--/||.\\\\.\\/\\--/\\/.\\\\|./-\\.//", "|/-\\./--/\\\\.\\\\/\\.\\/..\\-\\./---\\/-\\|\\-///.|.", "||.\\-/./\\//..|||/\\/---\\\\\\\\\\.//|.\\/./\\\\\\//.", "|\\-\\/--/||./-/\\/\\/\\\\..\\\\\\\\\\-/.|./--/|//\\\\.", "|/\\|\\\\..\\/.\\\\/-\\/\\.\\\\..|///\\..|.|./-/|..\\\\", "||||.|./--\\//\\\\|\\//\\\\\\.\\/.\\//-/.|//..|./\\|", "\\/||.|.|.//|/\\\\/..\\/.\\\\../--/./\\\\//\\.\\\\\\/|", "/-/|.\\\\\\-///\\//\\/\\./\\///\\|/\\..\\//-/\\\\.|..|", "|.///\\\\\\.///\\.\\/\\/.|\\///||\\/./\\.|./-/.\\--/", "\\-/.||.|.|.\\/./-\\..\\\\.\\\\|\\---/\\-/.|./\\/\\..", "/---/\\-/.|../-/.\\\\/\\\\\\//|..../\\...\\-/\\/\\-\\", "\\\\/---\\/-//\\|./-\\|||//\\\\\\--\\//\\----\\./\\..|", ".||/\\//|..|||.\\\\|\\/|\\-\\|./\\|\\-\\/\\/\\\\\\|\\--/", ".\\/\\/\\\\|/\\\\/\\-\\\\//\\\\-\\||.\\/\\\\.|\\/\\/.\\/./-\\", "/--\\.//|||/\\..\\-\\\\/.//||../\\\\\\|./--\\/\\.\\-/", "|/\\\\-/.\\/|||/\\.///\\//.\\/.//\\\\\\////\\\\/|./-\\", "\\/|/--\\/-/\\/\\/.|//\\//----/..|..|.||/-/.\\\\|", ".//\\\\//\\\\../-\\//|..///----\\.\\\\.|.\\/\\-\\/\\||", ".\\--/|..\\\\.|.\\/.\\\\.\\\\\\----//\\\\-//----/\\/\\/", "/\\..///-\\|.\\-\\./-//\\\\---\\/-/\\---//--\\/\\./\\", "|\\-\\|////|/\\.|.\\\\.\\//\\/-/\\\\../\\..\\--/||.\\/", "\\-\\\\/\\-///\\/.|/\\|/--/|\\---/.//|./-\\.//\\\\..", ".///-\\/\\\\-\\/\\|\\/|\\\\..\\------/.\\\\\\\\\\\\\\-\\\\-\\", ".\\-/.|\\//-/|||.//.|./---\\./\\..//.|///\\\\\\//", "/--\\///\\\\\\.\\/|///\\\\-/./\\\\\\\\//-/.//|.\\/.||.", "\\--/|//|.|./\\|\\\\|\\\\./\\\\/.|/\\|...|///\\..|\\\\", "./--/\\\\|.\\\\||\\-/\\-/.||...|\\/\\\\..\\///|/\\|.|", ".|/\\/-/|.//\\/../\\..//\\---//--//--\\\\-/|\\///", ".|||\\-\\\\\\|./-\\.\\//\\|/\\./-\\\\\\/\\|.//./-/.//.", "//|\\--///\\\\\\\\\\\\..||||\\-/.|.|\\/\\-//\\\\-\\.|/\\", "\\-/../\\\\\\.\\\\|.|.//\\/\\\\./\\|.|./---/\\\\.\\-/\\/", "/---\\\\/.|..|\\\\|//....|//\\/.|//../-\\\\-----\\", "\\\\/-/./\\\\-\\|//|\\-\\./\\||./\\.\\//-\\|.\\\\/-\\.//", ".\\/./\\\\//\\\\/\\-//\\|.\\/\\/.||...|//\\\\.\\///.|.", "/\\/\\||/\\|\\-\\/-\\|||.../--/\\-\\//|..|./\\\\\\.\\\\", "\\/\\/\\/\\/\\--/\\-/\\/\\---/.....\\/.\\--/.\\/.\\--/" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getPlan(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysRollerCoasters ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

