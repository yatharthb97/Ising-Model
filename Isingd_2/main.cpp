#include"classes.h"
#include<iostream>
using namespace std;
#include<sstream>

//Set the edge and the number of sweeps
#define SWEEPS 100000
#define EDGE 1000
#define REND_AFTER 1000

//Set the parent path for the output
static string parentpath = "";
string Box::energyfile = parentpath+"energy.dat";
int Site::sitecount = 0;

int main()
{

	cout<<"Ising Model d=2 Monte Carlo Simulator"<<endl<<endl<<endl;

	Box b(EDGE);
	b.Update_Energy();
	cout<<"Initial Energy of the box: "<<b.energy<<endl;

	int renderfile = 0;
	ostringstream in;
	in<<parentpath<<renderfile;
	b.RenderBox(in.str());
	renderfile++;

	//Trial Moves
	for (int i = 0; i < SWEEPS; ++i)
	{
		b.TrialMove();
		if(i%REND_AFTER==0 && i!=0)
		{
			ostringstream init;
			init<<parentpath<<renderfile;
			b.RenderBox(init.str());
			ostringstream gnu, gnu2, gnu3;
			/*gnu<<"to_plot="<<parentpath<<renderfile;
			gnu2<<"op=./Plots/"<<renderfile<<".png";
			gnu3<<"energy="<<b.energy;*/
			gnu<<parentpath<<renderfile;
			gnu2<<"./Plots/"<<renderfile<<".png";
			gnu3<<b.energy;
			renderfile++;

			
			ostringstream command;
			command<<"./renderscript.gnu "<<gnu.str()<<" "<<gnu2.str()<<" "<<gnu3.str();
			system(command.str().c_str());
			cout<<"rendered"<<flush;
		}

		
	}
	b.Update_Energy();
	cout<<endl<<"Final Energy: "<<b.energy<<endl<<"Accepted Moves: "<<b.accept<<endl<<"Rejected Moves: "<<b.reject<<endl;
}//End of main