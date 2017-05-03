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

	string program_name = argv[0];
   	ProperMotionResult.hourRA = atof(argv[1]);  
   	ProperMotionResult.minuteRA = atof(argv[2]);  
   	ProperMotionResult.secondRA = atof(argv[3]); 
   	ProperMotionResult.degreDec = atof(argv[4]); 
   	ProperMotionResult.minuteDec = atof(argv[5]);     
	ProperMotionResult.secondDec = atof(argv[6]); 
	ProperMotionResult.muAlpha = atof(argv[7]);
	ProperMotionResult.muDelta = atof(argv[8]);
	ProperMotionResult.radialVelocity = atof(argv[9]);
	ProperMotionResult.paralaxe = atof(argv[10]);
	ProperMotionResult.time = atof(argv[11]);

	string symHour = "º";	
	string symMinute = "'";
	string symSecond = "''";
	
	if (ProperMotionResult.degreDec <= 90 && ProperMotionResult.degreDec >= -90 && ProperMotionResult.hourRA >= 0 && ProperMotionResult.hourRA <= 24)
   	{
   		std::vector<double> k = ProperMotionResult.CalculateProperMotion(ProperMotionResult.hourRA, ProperMotionResult.minuteRA,  \
		                                                             ProperMotionResult.secondRA, ProperMotionResult.degreDec,\
		                                                             ProperMotionResult.minuteDec, ProperMotionResult.secondDec);
		cout << setprecision (12) << "Initial Right ascension = " << ProperMotionResult.hourRA << "h" << " " << ProperMotionResult.minuteRA << "m" << " " <<  ProperMotionResult.secondRA << "s" << "\n";
		cout << setprecision (12) << "Initial Declination = " << ProperMotionResult.degreDec << symHour << " " << ProperMotionResult.minuteDec << symMinute << " " <<  ProperMotionResult.secondDec << symSecond << "\n";
		cout << setprecision (6) << "Final Right ascension = " << k[0] << "h" << " " << k[1] << "m" << " " <<  k[2] << "s" << "\n";
		cout << setprecision (6) << "Final Declination = " << k[3] << symHour << " " << k[4] << symMinute << " " <<  k[5] << symSecond << "\n";
   	} else { cout << "Introduce the correct value for declination or for right ascension" << "\n";}
	//std::copy(begin(k), end(k), std::ostream_iterator<double>(std::cout, " "));
	return 0;
}