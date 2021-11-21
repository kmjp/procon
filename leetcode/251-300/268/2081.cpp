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
    long long kMirror(int k, int n) {
		static vector<ll> V;
		int i,j;
		ll ret=0;
		if(V.empty()) {
			for(i=1;i<=700000;i++) {
				string s=to_string(i);
				string t=s;
				reverse(ALL(t));
				t=s+t;
				ll a=0;
				FORR(c,t) a=a*10+c-'0';
				V.push_back(a);
				
				t=s.substr(0,s.size()-1);
				reverse(ALL(t));
				t=s+t;
				a=0;
				FORR(c,t) a=a*10+c-'0';
				V.push_back(a);
			}
			sort(ALL(V));
		}
		FORR(v,V) {
			if(n==0) break;
			string s;
			ll a=v;
			while(a) {
				s+='0'+a%k;
				a/=k;
			}
			string t=s;
			reverse(ALL(t));
			if(s==t) {
				cout<<s<<" "<<v<<endl;
				ret+=v;
				n--;
			}
		}
		
		cout<<n<<endl;
		return ret;
    }
};
 