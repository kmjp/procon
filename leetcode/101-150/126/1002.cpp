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


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
		int cnt[26];
		int i,x,j;
		FOR(i,26) cnt[i]=100;
		FORR(a,A) {
			int C[26]={};
			FORR(c,a) C[c-'a']++;
			FOR(i,26) cnt[i]=min(cnt[i],C[i]);
		}
		vector<string> R;
		FOR(i,26) FOR(j,cnt[i]) {
			R.push_back("a");
			R.back()[0]+=i;
		}
        return R;
    }
};
