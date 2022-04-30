//Implementation of Blum Blum Shub Method fo
//Generating Pseudo Random NUmbers


#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> randomNos(10);

class BBS
{
private:
	long p, q, n, x0, decryptionExp;

public:
	BBS();
	~BBS();
	BBS(long p, long q, long seed);

	void setP(long p);
	void setQ(long q);
	void setSeed(long seed);

	long getRandNum();
	void setParams(long p, long q, long seed);
};



//default constructor
BBS::BBS()
{
	//default insecure params
	this->p = 11;
	this->q = 19;
	//seed
	this->x0 = 4;
	//product of P & Q
	this->n = p * q;
}

/*
    set object parameters
    @param blum prime number p
    @param blum prime number q
    @param integer seed
*/
void BBS::setParams(long p, long q, long seed)
{
	//choose p and q such that gcd(p, q) = 1
	this->p = p;
	this->q = q;
	//random seed should be netween 1 & n-1
	this->x0 = seed;
	//blum integer
	this->n = p * q;
}

/*
    overloaded constructor
    @param blum prime number p
    @param blum prime number q
    @param integer seed
*/
BBS::BBS(long p, long q, long seed)
{
	this->setParams(p, q, seed);
}

/*
    Get next random number
*/
long BBS::getRandNum()
{
	long nextRandNum = (this->x0 * this->x0) % this->n;
	this->x0 = nextRandNum;
	return nextRandNum;
}

/*
    Get next random bit
*/


void BBS::setP(long p)
{
	this->p = p;
}

void BBS::setQ(long q)
{
	this->q = q;
}

void BBS::setSeed(long seed)
{
	this->x0 = seed;
}

BBS::~BBS() {}


signed main() {


	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#ifdef NCR
	init();
#endif

	//For testing
	vector<float> randomNos;
	const ll P = 71;
	const ll Q = 67;
	const ll seed = 651;
	float n = P * Q;

	BBS numberGen(P, Q, seed);

	//generate 10 random numbers
	for (ll i = 0; i < 100; i++)
	{
		randomNos.push_back((float)numberGen.getRandNum() / n ); //Obtain each number in U[0,1) by diving X_i by m
	}
	std::ofstream outFile("output.txt");

	for (const auto &e : randomNos) outFile << e << "\n";


	return 0;
}