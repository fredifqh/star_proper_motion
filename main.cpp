/*Client Code: client code, is the one that includes the main function. 
This file should be stored by the name main.cpp*/

#include <bits/stdc++.h>
#include "proper_motion.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); // These lines make input and output more efficient
	cin.tie(0);

	string program_name = argv[0];
    double hourRA = atof(argv[1]);  
   	double minuteRA = atof(argv[2]);  
   	double secondRA = atof(argv[3]); 
    double degreDec = atof(argv[4]); 
    double minuteDec = atof(argv[5]);     
    double secondDec = atof(argv[6]); 
    double muAlpha = atof(argv[7]);
    double muDelta = atof(argv[8]);
    double radialVelocity = atof(argv[9]);
    double paralaxe = atof(argv[10]);
    double time = atof(argv[11]);

	string symHour = "º";	
	string symMinute = "'";
	string symSecond = "''";
	
	if (degreDec <= 90 && degreDec >= -90 && hourRA >= 0 && hourRA <= 24)
   	{
   		std::vector<double> k = ProperMotion(hourRA, minuteRA, secondRA, degreDec, minuteDec, secondDec, muAlpha, muDelta,radialVelocity, paralaxe, time);
		cout << setprecision (12) << "Initial Right ascension = " << hourRA << "h" << " " << minuteRA << "m" << " " <<  secondRA << "s" << "\n";
		cout << setprecision (12) << "Initial Declination = " << degreDec << symHour << " " << minuteDec << symMinute << " " <<  secondDec << symSecond << "\n";
		cout << setprecision (6) << "Final Right ascension = " << k[0] << "h" << " " << k[1] << "m" << " " <<  k[2] << "s" << "\n";
		cout << setprecision (6) << "Final Declination = " << k[3] << symHour << " " << k[4] << symMinute << " " <<  k[5] << symSecond << "\n";
   	} else { cout << "Introduce correct values for declination or for right ascension" << "\n";}
	//std::copy(begin(k), end(k), std::ostream_iterator<double>(std::cout, " "));
	return 0;
}
