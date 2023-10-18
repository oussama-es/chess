#ifndef PLATEAU_H
#define PLATEAU_H
#include<vector>
struct pia{
	int xd;
	int yd;
	int xa;
	int ya;
};
class plateau
{
	public:
		plateau();
		afficherPlateau();
		~plateau();
		bool finPartie();
		deplacerPiece(char);
		saisirA(int&,int&,char);
		saisirD(int&,int&,char);
		bool possible(int,int,int,int);
		DeplacerIA(plateau,int);
		scannerAT(plateau,int,int);
		scannerMov(plateau,int,int);
		DepAt(plateau,int,int);
		DepMpv(plateau,int,int);
		//CheckM(plateau,xd,yd);	
		bool CheminLibre(int,int,int,int);
		bool AttaquePossible(int,int,int,int,int);
		bool MovPossible(int tour,int xd, int yd);
	private:
		int tj[8][8];
		//vector <pia > tp;
		
};

#endif
