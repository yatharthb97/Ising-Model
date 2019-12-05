#define SPIN_UP +1
#define SPIN_DOWN -1
#define IRJ 40

#pragma once
#include <iostream>
//#include "random.h"
using namespace std;
#include<fstream>
#include <vector>

extern int Rndm(int, int);
class Site
{
public:
	//Positions
	int x; int y;

	//Spin of the particle
	int spin;
	static int sitecount;

	//Default Constructor
	Site(int x, int y, int spin_m): x(x), y(y)
	{
		if(spin_m == +1 || spin_m==-1){spin = spin_m;}
		else
		{
			cerr<<"Improper value of spin at site: "<<sitecount<<endl;
			spin = 0;
		}
		sitecount++;
	}

}; //End of Class Site


class Box
{
public:

	int edge; //number of particles = edge*edge
	int particles;
	double energy;
	std::vector<Site> sitelist;


	int accept;
	int reject;
	int energywcount;

	static string energyfile;


	Box(int edge):edge(edge), energy(0.0), accept(0), reject(0), particles(0), energywcount(0)
	{
		//File the sitelist vector
		int spin = 0;
		for(unsigned int i = 0; i<edge; i++)
		{
			for(unsigned int j = 0; j<edge; j++)
			{
				spin = 0;
				if(Rndm(1,100) <=50) spin = -1;
				else spin = +1;
				sitelist.push_back(Site(i, j, spin));
				particles++;
				//cout<<"*"<<flush;
			}
			
		}

		if(particles< edge*edge){cout<<"Empty Sites Present: "<< edge*edge-particles<<endl;}
		else{cout<<"Box is filled with "<<particles<<" particles!"<<endl;}
	}

	~Box()
	{
		cout<<"The Box class destructor was called! The site box is destroyed."<<endl;
	}

	void Update_Energy()
	{
		extern double energy_calc(std::vector<Site> &partlist, int edge);
		energy = energy_calc(sitelist, edge);
		ofstream w;
		w.open(energyfile, ios::app);
		w<<energywcount<<"\t"<<energy<<endl;
		w.close();
	}

	void TrialMove()
	{
		unsigned int sid = Rndm(0, particles-1);
		cout<<sid<<endl;
		//Site temp = sitelist.at(sid);

		//Faster since only considering nearest neibhour interaction
		extern double Part_energy_calc(std::vector<Site> &partlist, unsigned int part_id, int edge);
		double partenergy = Part_energy_calc(sitelist, sid, edge);
		sitelist.at(sid).spin*-1; //Trial move;
		double newpartenergy = Part_energy_calc(sitelist, sid, edge);

		if(newpartenergy < partenergy)
		{
			energy = energy - partenergy + newpartenergy;
			accept++;
			//cout<<"-"<<flush;
		}

		else
		{
			if(Rndm(1,100)<= IRJ)
			{

				energy = energy - partenergy + newpartenergy;
				accept++;
				//cout<<"+"<<flush;
			}


			else
			{
				sitelist.at(sid).spin*-1; //To the original state
				reject++;
				//cout<<"/"<<flush;
			}
		}
	} //End of Trial Move

	void RenderBox(string filename)
	{
		ofstream w;
		w.open(filename, ios::app);
		for(unsigned int i=0; i<particles; i++)
		{
			w<<i<<":"<<sitelist.at(i).x<<":"<<sitelist.at(i).y<<":"<<sitelist.at(i).spin<<endl;
		}
		w.close();
	}



}; //End of class Box
