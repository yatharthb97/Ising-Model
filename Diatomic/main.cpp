//Calculate the Average Seperation of a Diatomic molecule
#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>



int main()
{
	cout<<"Calculation of Diatomic Bond Lenth without any restoring force"<<endl;

	#define KB 1.3807e-23
	#define m 2.6566962e-26
	double TFinal = 300;	
	double dT = 0.001;
	double dt = 0.0001;
	int Sweeps = TFinal/dT;
	cout<<"Sweeps: "<<Sweeps<<endl;

	double x1 = 0;
	double x2 = 1;
	double T = 0;
	double time = 0;
	double count = 0;

	cout<<setprecision(16)<<"Seperation at temperature "<<T<<" :"<<x2-x1<<endl;
	while( count < Sweeps)
	{
		 T = T + dT;
		 time = time + dt;
		 double dv = sqrt(T*3*KB/m);
		 x1 = x1 - dv*dt; // Velocity Verlet
		 x2 = x2 + dv*dt; //Velocity Verlet
		 count++;
	}
	 cout<<setprecision(16)<<"Seperation at temperature "<<T<<" :"<<x2-x1<<endl;




}//End of main