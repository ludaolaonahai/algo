//-----------------------------------------------------------------------------
#include <vector>
#include <iostream>
#include <algorithm>
//-----------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------------
int best_prices (int n,const vector<int>& fix_prices);
//-----------------------------------------------------------------------------
int main() {
	vector<int> fix_prices = {0,1,5,8,9,10,17,17,20,24,30};
	cout<<best_prices(10,fix_prices)<<endl;
	return 0;
}
//-----------------------------------------------------------------------------
int best_prices (int n,const vector<int>& fix_prices) {
	vector<int> best_prices(n+1);
	for(auto& ele:best_prices)
		ele = -1;
	best_prices[0] = 0;
	int tmp = -1;
	for(int i=1;i<=n;++i) { 
		for(int j=1;j<=i;++j) {
			tmp = max(tmp,fix_prices[j]+best_prices[i-j]);
		}
		best_prices[i] = tmp;
		cout<<i<<":"<<best_prices[i]<<endl;
	}
	return best_prices[n];
}
//-----------------------------------------------------------------------------
