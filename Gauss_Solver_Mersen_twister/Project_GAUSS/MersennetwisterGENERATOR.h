#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//Parameter for Mersenne Twister
#define	N (624)//n
#define	M (397)//m
#define	MATRIX_A (0x9908b0dfUL)	// vector a
#define	UP_MASK	(0x80000000UL)	//  w-r 
#define	LOW_MASK (0x7fffffffUL)	//  r 


class MersenneTwisterGENERATOR
{
private:
	
MersenneTwisterGENERATOR();
~MersenneTwisterGENERATOR();

public:
	static MersenneTwisterGENERATOR* getInstance();
	void release();
	float getFloat();
	void changeSeed(unsigned long a_ulSeed);

private:
	
	void init_genrand(unsigned long s);	// initialize x[N] with a seed
	unsigned long genrand_int32(void);	
	long genrand_int31(void);			
	double genrand_real1(void);			

	
private:
	
	static MersenneTwisterGENERATOR* s_pInstance;
	static unsigned long	x[N];	//!< array for the state vector
	static int				mti;	//!< mti==N+1 means x[N] is not initialized
};
