#define J 5
#define B 1

#include"classes.h"
#include<iostream>
using namespace std;
#include<vector>


double Part_energy_calc(std::vector<Site> &partlist, unsigned int part_id, int edge)
{
	double Eij = 0;
	

	if(part_id<=(edge-1))
	{
	
	Eij+= -B*partlist.at(part_id).spin;

		if(part_id==0)
		{
			//cout<<"hereatzero"<<endl;
			Eij+= -J* partlist.at(part_id).spin * ( partlist.at(edge*edge-1).spin + partlist.at(1).spin + partlist.at(part_id + edge).spin + partlist.at(edge*(edge-1)).spin);
		}

		else
		{
			//cout<<"here1"<<endl;
			Eij+= -J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id + edge).spin + partlist.at((edge*(edge-1) + part_id)).spin);
		}
	}

	else if(part_id >= edge*(edge-1))
	{
	
	Eij+= -B*partlist.at(part_id).spin;

		if(part_id==(edge*edge-1))
		{
			//cout<<"here2"<<endl;
			Eij+= -J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(0).spin + partlist.at(edge-1).spin + partlist.at(part_id-edge).spin);
		}

		else
		{
			//cout<<"here3"<<endl;
			Eij+= -J* partlist.at(part_id).spin * (partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id/edge).spin + partlist.at(part_id-edge).spin);
		}

	}

	else
	{
	
	Eij+= -B*partlist.at(part_id).spin;

		Eij+= -J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id + edge).spin + partlist.at(part_id-edge).spin);
	}

	return Eij;

}


double energy_calc(std::vector<Site> &partlist, int edge_m)
{
	int edge=edge_m-1;
	double Eij = 0;
	int particles = edge*edge;

	for(unsigned int part_id = 0; part_id < particles; part_id++)
	{
			
		if(part_id<=(edge-1))
		{

		Eij+= -B*partlist.at(part_id).spin;

			if(part_id==0)
			{
				//cout<<"hereatzero"<<endl;
				Eij+= -0.5*J* partlist.at(part_id).spin * ( partlist.at(edge*edge-1).spin + partlist.at(1).spin + partlist.at(part_id + edge).spin + partlist.at(edge*(edge-1)).spin);
			}

			else
			{
				//cout<<"here1"<<endl;
				Eij+= -0.5*J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id + edge).spin + partlist.at((edge*(edge-1) + part_id)).spin);
			}
		}

		else if(part_id >= edge*(edge-1))
		{

		Eij+= -B*partlist.at(part_id).spin;

			if(part_id==(edge*edge-1))
			{
				//cout<<"here2"<<endl;
				Eij+= -0.5*J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(0).spin + partlist.at(edge-1).spin + partlist.at(part_id-edge).spin);
			}

			else
			{
				//cout<<"here3"<<endl;
				Eij+= -0.5*J* partlist.at(part_id).spin * (partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id/edge).spin + partlist.at(part_id-edge).spin);
			}

		}

		else
		{
			Eij+= -B*partlist.at(part_id).spin;

			Eij+= -0.5*J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id + edge).spin + partlist.at(part_id-edge).spin);
		}

	}

	return Eij;
}




/*Eij+= -B*partlist.at(part_id).spin;

			Eij+= 0.5*J* partlist.at(part_id).spin * ( partlist.at(part_id-1).spin + partlist.at(part_id+1).spin + partlist.at(part_id + edge).spin + partlist.at(part_id-edge).spin);*/