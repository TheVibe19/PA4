//Implementation of Linear Congruence Method fo
//Generating Pseudo Random NUmbers


#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> randomNos(100);
vector<float> randomNos1(100);


ll linearCongruentialMethod(ll x0, ll m, ll a, ll c,  ll n)
{
	//Initializing the seed state
	randomNos[0] = x0;

	//Generating n random numbers
	//using tht formula
	// randomNos[i]=((randomNos[i-1]*a)+c)%m
	for (ll i = 1; i < n; i++)
	{
		randomNos[i] = ((randomNos[i - 1] * a) + c) % m;
	}
	for (ll i = 0; i < n; i++)
	{
		randomNos1[i] = float(randomNos[i]) / m;//Obtain each number in U[0,1) by diving X_i by m
	}



}

signed main() {


	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#ifdef NCR
	init();
#endif

	//defining the parameters of the method

	//vector<ll> randomNos(10), randomNostest2(10);


	//For testing

	ll x0 = 123496789; //Seed Value;
	ll m = 214743648; //Modulus Parameter=(2^31)
	ll a = 65559;//Multiplier term
	ll c = 0; //Increment term
	ll n = 100;
	linearCongruentialMethod(x0, m, a, c, n);






	std::ofstream outFile("output.txt");

	for (const auto &e : randomNos1) outFile << e << "\n";






	return 0;
}