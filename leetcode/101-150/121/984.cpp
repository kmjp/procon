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
    string strWithout3a3b(int A, int B) {
		int cnt[101]={};
		int i;
		string R;
        if(A>=B) {
			FOR(i,A) cnt[i%(B+1)]++;
			R=string(cnt[0],'a');
			FOR(i,B) {
				R+="b";
				R+=string(cnt[i+1],'a');
			}
		}
		else {
			FOR(i,B) cnt[i%(A+1)]++;
			R=string(cnt[0],'b');
			FOR(i,A) {
				R+="a";
				R+=string(cnt[i+1],'b');
			}
		}
		return R;
    }
};
