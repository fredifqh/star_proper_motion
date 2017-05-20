/*Header File: Class declarations are stored in a separate file. 
A file that contains a class declaration is called header file. 
The name of the class is usually the same as the name of the class, with a .h extension. 
For example, the Time class would be declared in the file Time .h.*/

#ifndef PROPERMOTIONHEADERDEF
#define PROPERMOTIONHEADERDEF
 
    double ConvertRAToDegrees(double, double, double); // Functio to convert Right Ascention (hours, minutes and seconds) to degrees
	double ConvertDecToDegrees(double, double, double); // Functio to convert Declination (degrees, minutes and seconds) to degrees
	std::vector<double> ConvertDegRAtoRAcoord(double, double); // Function to convert Degrees in hours, minutes and seconds
//	std::vector<double> ConvertDegDEtoDEcoord(double); // Function to convert Degrees in Degrees, minutes and seconds
	std::vector<double> ProperMotion(double, double, double, double, double, double, double, double, double, double, double); // Function to get final proper motion

#endif

