#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

class MagicTrickWithCuts {
	public:
	string solve(vector <string> queries) {
		string R;
		FORR(S,queries) {
			int a=0,b=0;
			char c='Z';
			int i;
			FOR(i,26) c=min(c,S[i]);
			R+=c;
			R+=S[52-10-(c-'A')];
		}
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_1() { string Arr0[] = {"KwuJpLzhRIoVeMxOlvnZymdPUtfTicjbsYSrWEqgFANGBkQaHDCX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IS"; verify_case(0, Arg1, solve(Arg0)); }

	void test_case_0() { string Arr0[] = {"VEKsclqLaHPFgMTeJIhGxdQbvnSyWzotZRpNiYwruCmjODAfBkXU", "yJkwLimhOPfuqVXgMvKxtQZzNrcnsdoaRElbIjSFDGYCUBHTAWep", "sTQLOJfceyGMKmINhHXPjpklazZRboUrSxnuwCtdYWqEFiDBVvAg", "YMLyStKRqIuHOJXVnlkaWcsbwQUvNrjpfZxBhegFzDPTCdoAiGmE", "XYlSbnUyLJhxcKMvWewamRrNoOqVupZtkGTszPCEHiQjIDAfgBFd", "FdILJMKOtneYEGglzHTwXhqiovbZUNWcmjRfSkDaCVyBsxrpAPQu", "dxSXMPmYJRKqfLaiyTgbVvZzuUwhkQlWOIFNArDjnCsEoBGptHce", "HiwWgJyfLRhKPIMUoGpeXSbmaNxdtjVruvnczEkQCFODlTYBqZsA", "dKnjckPLYVJMbSZyRIxNhtraovfQWeumwTzsUHglAFGBEXDpqOiC", "aeyWOjLhgzmSMNRpurPqViTwYlnoZUvDFBdcCHtsGKxXEIbQkfJA", "JRqIvezhoWVTLgMKfONrXawcbSdpyjimPnEBCuskZGAYUDtlQFHx", "GJglZWbLImOSdKHMFtPhoxrkcsvaRniTQpfXVewCAEyYDNzBUqju", "QJimRoLyIHKfjbsGaNWMFethUnYcwZvrpdlxPOgzAuDBVCXETSqk", "yZbxohMNLpJeKmkRvfuntOjaXUslQTYrwIgPHSAdDEBCVWqFziGc", "IGuiMxoZNqcTJzHRnKeLSQlkhjryavsXUtmpBEVYAfCODFWbgwPd", "oUafLMvJTdbKPRcWluSNQrhjVzqsXmnxgDYkGIOyZCwtFiBeApHE", "tTNdeMWQoKwPLVyxOgZuinsbSXhrjzpkaCUvRcDfJIAFqGYEHBlm", "kMLobYnKvROUNruxqtsfVzlZwTmWQipydeahHcPAEJGBXFSjgIDC", "YoKrHpatEsQewMIDFGJLmVSgfhbTqXiZzPcWjOkNxUAClRyBduvn", "LRJMqyaPkgjKioIVSZeUfXuTbplrxmdcwzNWADOsYEQCHtnvGhBF", "TLkxnHNMfIRzKcVhpJgeQsUbrdOmtjSlvwoGiYEXqFCAyWDaPuBZ", "LjMJvnIUpuWKPdxkTSczoeQbNqRslYiXtwDyCghFHVOBfmZGraAE", "IKzWwVclJSLXjhMxkorPuZqmgRtvbaNeyfYDnAGQOHEpdCBisTFU", "XLrSKdRwihujIWzOJMVZxnmeTvYPsNQgokHByGfbEqDctlaUCApF", "wuGqOkvlLyVJWPMIHUcNKnTZbrfazjQsXmotEdDexRpigCFYSABh", "NMLvpZxmKeYtalzcSbnfWsiQjoqPyuRrOUGgdCDFVXkTEJAHhwBI", "OKRMLIUeJiVlyqhcWgvsTkXnNmfYZbwaQuopxDCjtGSPAEFBdzHr", "uYMTrydbHjomkJIvaKxzLUlseNnwRWXhQpiEACGBPfSgqVZDctOF", "kIJFHdEKGMvnLmePrDguqhxUizwXWcYQNSlobTZOyaARBVpstjfC", "eOkylrcdSLMKsRxZqUWYhXztvNTpjfbinQGaJACFDPwouVmEHBIg", "JQgMmiodWsSKVLIZcqfybPROwpaTekrvXxFDHYAtNGlUnhuEjBCz", "HIRnMKhLOkuoJqZsSrcTXUbVlPiWdQfwNgjeYBvxCFyEpAzGtmDa", "SMIXuPJyUKVmLlrbvRwhftpzgqNaWxZiOdCBQTcGkeEsAnHFDjYo", "YfIaVmRNLJyunKMTdbchQzsqljkvZUOetpwgCiWHSXxoBAEFPDrG", "PyThMLYQaXvoWxlepnmquzcSwrUsVRfZdjGJENCkiFtbIHOABKgD", "quiJZSVYtLIMKGrwHmpPvNldWjXxRUzQcyoknDaeEfsCgATOFBbh", "fmKOJSgLYMNvHIcowprPXhdTWeqstiVZjnlRakyBEbAQFxUzCDGu", "XMvuonUaTciVZlmrWQRhYdfetNxpPzgKsJIkjbLDqASGBFHwECyO", "LIshRnjoGdvMUTHKVJlFbzfZYamckqwPQpStrWgDeuyxENiOBCAX", "ateSjJMHIOxvKLTronzkpwlNVhZXPQsbdUWGfAqCgDEyimucYBFR", "GQKTMnHJyxVLirIbtvhlRpokfNgdjzswXOcaPEWuDUYBmFCeZSAq", "fiLYlIMJscjaGdKeSrHNuvzZxRtqWphbyUwmkAXVBPTDoCnFEgQO", "ljPOQGJtvHWMeILpbKrNmuXUwidqhxkascyVnFAZgTRfBECYoDzS", "vMlOLKWdxQezmhtXVosqYTuipanwPUcrkjGHAyRZJgINCSBEbFDf", "fiISOGMJLdFlgKqkwHsjVxybhYPptrZoRnUcNeBvWECmTAuQXDaz", "bLqxciHNMFasGOhzXVKwJIYTSfnPrmplZUduvWyotAkjRCQegBDE", "HthxFeIXzbuMNdLUJKiGrknVpjqlcQOovWgsaPYCyfmTASBDRwEZ", "JKrkwcjHuzLRIGdTMNgfxayYlPqXtnhbmZsOFBpCiovEeWDAVQSU", "KvYuHIoMieNgWbLanJxSQRmtVXTzUcwjOrqfsdACkGByhlDPFZEp", "KJvHMYNIxWjuspkfLbwUinhqVymecXrRglZEGaFoTSAPOBtCQDdz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "IS"; verify_case(0, Arg1, solve(Arg0)); }
// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicTrickWithCuts ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

