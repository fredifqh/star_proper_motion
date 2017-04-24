/*Client Code: client code, is the one that includes the main function. 
This file should be stored by the name main.cpp*/

#include <bits/stdc++.h>
#include "proper_motion.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); // These lines make input and output more efficient
	cin.tie(0);

	ProperMotion ProperMotionResult;

	ProperMotionResult.hourRA = 12;
	ProperMotionResult.minuteRA = 25;
	ProperMotionResult.secondRA = 32.1456;

	ProperMotionResult.degreDec = 87;
	ProperMotionResult.minuteDec = 43;
	ProperMotionResult.secondDec = 22.105;

	ProperMotionResult.radialVelocity = 50;
	ProperMotionResult.muAlpha = -350;
	ProperMotionResult.muDelta = 1270;
	ProperMotionResult.paralaxe = 150;
	ProperMotionResult.time = 200;

	std::vector<double> k = ProperMotionResult.CalculateProperMotion(ProperMotionResult.hourRA, ProperMotionResult.minuteRA,  \
		                                                             ProperMotionResult.secondRA, ProperMotionResult.degreDec,\
		                                                             ProperMotionResult.minuteDec, ProperMotionResult.secondDec);
	cout << k[0] << "\t" << k[1] << "\t" << k[2] << endl;
	//std::copy(begin(k), end(k), std::ostream_iterator<double>(std::cout, " "));
	return 0;
}