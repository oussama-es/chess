#ifndef PARTIE_H
#define PARTIE_H
#include "plateau.h"
class partie
{
	public:
		partie();
		~partie();
		jouer();
	private:
		plateau p;
		int tour;
};

#endif
