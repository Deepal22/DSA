class Solution {
public:
	int dp[10001][5];
	string digit;
	string s;
	int mod = 1e9+7;
	//Get a palindrome string when first two digit equals to x
	string getDigit(int x){
		string s = to_string(x);
		if(s.size()==1)s = '0'+s; // if x<10 we add a 0 in front of it.
		string t = s;
		s+='.';
		reverse(t.begin(),t.end());
		s+=t;
		return s;
	}
	int call(int pos,int id){
		if(id==5) return 1;
		if(pos==s.size()) return 0;
		if(dp[pos][id]+1) return dp[pos][id];
		int ret = 0;
		ret = call(pos+1,id);
		//if id==2 we can take any digit.
		if(id==2 || s[pos] == digit[id] ) ret = (ret+call(pos+1,id+1))%mod;
		return dp[pos][id] = ret;
	}
	int countPalindromes(string t) {
		s = t;
		long long ans = 0;
		for(int i=0;i<100;i++){
			memset(dp,-1,sizeof dp);
			digit = getDigit(i);
			ans = ans+call(0,0);
			ans = (ans%mod);
		}
		return ans;
	}
};