/*Implementation File: The member function definitions for a class are stored in a separate .cpp file, 
which is called the class implementation file. 
The file usually has the same name as the class, with the .cpp extension. 
For example the Time class member functions would be defined in the file Time.cpp.*/
#include <bits/stdc++.h>
#include "proper_motion.hpp"	

using namespace std;

const double f = 4.8481370e-9;
const double A = 0.2109495266;
const double PI  =3.141592653589793238463;
double declina;

double ProperMotion::ConvertRAToDegrees(double x, double y, double z)
{
	return (x + y/60  + z/3600)*15;
}

double ProperMotion::ConvertDecToDegrees(double a, double b, double c)
{
	if (a >= 0){
		declina = (a + b/60  + c/3600);
	}

	if (a < 0){
		declina = -1*(abs(a) + b/60  + c/3600);	
	}

	return declina;
}

std::vector<double> ProperMotion::CalculateProperMotion(double hourRA, double minuteRA,  \
	                                                    double secondRA, double degreDec,\
	                                                    double minuteDec, double secondDec)
{
	RA = ConvertRAToDegrees(hourRA, minuteRA, secondRA)*PI/180;
	DEC = ConvertDecToDegrees(degreDec, minuteDec, secondDec)*PI/180;

	//cout << setprecision (10) << "Initial Righ Ascention in degrees = " << RA*180/PI << "\n" << "Initial Declination in degrees = " << DEC*180/PI << "\n";

	m[0] = cos(DEC)*cos(RA);
	m[1] = cos(DEC)*sin(RA);
	m[2] = sin(DEC);

	n[0] = -1*sin(RA);
	n[1] = cos(RA);
	n[2] = 0;

	p[0] = -1*sin(DEC)*cos(RA);
	p[1] = -1*sin(DEC)*sin(RA);
	p[2] = cos(DEC);
	
	v[0] = m[0] + f*time*(A*radialVelocity*paralaxe*m[0] + muAlpha*n[0] + muDelta*p[0]);
	v[1] = m[1] + f*time*(A*radialVelocity*paralaxe*m[1] + muAlpha*n[1] + muDelta*p[1]);
	v[2] = m[2] + f*time*(A*radialVelocity*paralaxe*m[2] + muAlpha*n[2] + muDelta*p[2]);
	
	RAinDegree = atan2(v[1], v[0])*180/PI;

	if (RAinDegree < 0)
	{
		RAinDegree = RAinDegree + 360;
	}

	DECinDegree = atan2(v[2], sqrt(pow(v[0],2) + pow(v[1],2)))*180/PI;

	//cout << setprecision (10) << "Final Righ Ascention in degrees =" << RAinDegree << "\n" << "Final Declination in degrees =" << DECinDegree << "\n";

	return ConvertDegRAtoRAcoord(RAinDegree, DECinDegree);
} 

std::vector<double> ProperMotion::ConvertDegRAtoRAcoord(double RAinDegree, double DEinDegree)
{	
	double fracHourRA = modf(RAinDegree/15,  &intparthourRA);
	Final[0] = intparthourRA;   // RA hours
	double fracMinuRA = modf(fracHourRA*60,  &intpartminuteRA);
	Final[1] = intpartminuteRA; // RA minutes
 	Final[2] = fracMinuRA*60;   // RA seconds

 	if (DEinDegree > 0)
 	{
		double fracHourDE = modf(DEinDegree, &intparthourDE);
		Final[3] = intparthourDE;   // DE hours
		double fracMinuDE = modf(fracHourDE*60, &intpartminuteDE);
		Final[4] = intpartminuteDE; // DE minutes
	 	Final[5] = fracMinuDE*60;   // DE seconds
 	}
 	
 	if (DEinDegree < 0)
 	{
		double fracHourDE = modf(abs(DEinDegree), &intparthourDE);
		Final[3] = -1*intparthourDE;   // DE hours
		double fracMinuDE = modf(fracHourDE*60, &intpartminuteDE);
		Final[4] = intpartminuteDE; // DE minutes
	 	Final[5] = fracMinuDE*60;   // DE seconds
 	}

 	return Final;
}
