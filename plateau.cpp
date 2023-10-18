#include "plateau.h"
#include <iostream>
plateau::plateau()
{
	for(int i=2;i<=5;i++)
	{
		for(int j=0;j<=7;j++)
		{
			tj[i][j]=0;
		}	
	}
	
	for(int j=0;j<=7;j++)
	{
		tj[1][j]=1;
		tj[6][j]=-1;		
	}	
	
	tj[0][0]=6;
	tj[0][1]=5;
	tj[0][2]=2;
	tj[0][3]=4;
	tj[0][4]=3;
	tj[0][5]=2;
	tj[0][6]=5;
	tj[0][7]=6;


	tj[7][0]=-6;
	tj[7][1]=-5;
	tj[7][2]=-2;
	tj[7][3]=-4;
	tj[7][4]=-3;
	tj[7][5]=-2;
	tj[7][6]=-5;
	tj[7][7]=-6;	
}

plateau::afficherPlateau()
{
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			switch(tj[i][j])
			{
				case -6: std::cout<<"TB |";
						break;
				case -5: std::cout<<"CB |";
						break;
				case -4: std::cout<<"QB |";
						break;
				case -3: std::cout<<"KB |";
						break;
				case -2: std::cout<<"FB |";
						break;
				case -1: std::cout<<"PB |";
						break;
				case 0: std::cout<<"   |";
						break;
				case 6: std::cout<<"TN |";
						break;
				case 5: std::cout<<"CN |";
						break;
				case 4: std::cout<<"QN |";
						break;
				case 3: std::cout<<"KN |";
						break;
				case 2: std::cout<<"FN |";
						break;
				case 1: std::cout<<"PN |";
						break;																																										
				default :break;
			}
		}		
		std::cout<<std::endl;	
		std::cout<<"--------------------------------"<<std::endl;
	}
}

plateau::~plateau()
{
	
}

bool plateau::finPartie()
{
	return true;
}

plateau::saisirD(int &x,int &y,char J)
{
	bool b=false;
	do{
	std::cout<<"Veuillez saisir une position de depart: ";
	std::cin>>x;
	std::cin>>y;
	if(J=='N')
	{
		if(tj[x][y]>0)
		{
			b=true;
		}
	}
	else
	{
		if(tj[x][y]<0)
		{
			b=true;
		}
	}
	}while(((x<0)||(x>7)) || ((y<0)||(y>7)) || (b==false));
}

plateau::saisirA(int &x,int &y,char J)
{
	bool b=false;
	do{
	std::cout<<"Veuillez saisir une position d arrivee: ";
	std::cin>>x;
	std::cin>>y;
	if(J=='N')
	{
		if(tj[x][y]<=0)
		{
			b=true;
		}
	}
	else
	{
		if(tj[x][y]>=0)
		{
			b=true;
		}
	}
	}while(((x<0)||(x>7)) || ((y<0)||(y>7)) || (b==false));
}



bool plateau::possible(int xd,int yd,int xa,int ya)
{
	if((tj[xd][yd]==5)||(tj[xd][yd]==-5))
	{
		if(((xa==xd-2)&&(ya==yd+1))||((xa==xd-1)&&(ya==yd+2))||((xa==xd+1)&&(ya==yd+2))||((xa==xd+2)&&(ya==yd+1))||((xa==xd+2)&&(ya==yd-1))||((xa==xd+1)&&(ya==yd-2))||((xa==xd-1)&&(ya==yd-2))||((xa==xd-2)&&(ya==yd-1)))
		{
			return true;
		}
	}
	
	if ((tj[xd][yd]==1)||(tj[xd][yd]==-1))//le pion
	{
		if (xd==1||xd==6)
		{	 
			if (tj[xd][yd]==1)
			{
				if ((xa==xd+2)&&(ya==yd)||(xa==xd+1)&&(ya==yd))
				{
					if(CheminLibre(xd,yd,xa, ya)==true)
				{
					return true;	
				}
				}
				
			}
			else if(tj[xd][yd]==-1)
			{
				if((xa==xd-2)&&(ya==yd)||(xa==xd-1)&&(ya==yd))
				{
						if(CheminLibre(xd,yd,xa, ya)==true)
				{
					return true;	
				}
				}
		
		}
		}
		else
		{
			if (tj[xd][yd]==1)
			{
			if ((xa==xd+1)&&(ya==yd))// le cas normal
			{
				return true;	
			}
			}	
			else if(tj[xd][yd]==-1)
			{
				if ((xa==xd-1)&&(ya==yd))// le cas normal
			{
				return true;	
			}	
			}
				}	
			
		
		if(tj[xa][ya]==1) //cas exeptionnelle -->erreur
		{
			if (tj[xd+1][yd-1]>0||tj[xd+1][yd+1]>0)//besoin le contenu de case 
			{
				return true;
			}
		}
		else if (tj[xa][ya]==-1)
		{
			if (tj[xd-1][yd+1]<0||tj[xd-1][yd-1]<0)
			{
				
					return true;
				
			}
		}
	
	}
	if((tj[xd][yd]==3)||(tj[xd][yd]==-3))//la dame
	{
		for (int i=1;i<=7;i++)
		{
		if(((xa==xd+i)&&(ya==yd))||((xa==xd+i)&&(ya==yd-i))||((xa==xd)&&(ya==yd-i))||((xa==xd-i)&&(ya==yd-i))||((xa==xd-i)&&(ya==yd))||((xa==xd-i)&&(ya==yd+i))||((xa==xd)&&(ya==yd+i))||((xa==xd+i)&&(ya==yd+i)))
			{
			return true;
			}			
		}

	}
	if ((tj[xd][yd]==4)||(tj[xd][yd]==-4))//le roi+autre cas avec la tour
	{
		
		if(((xa==xd+1)&&(ya==yd))||((xa==xd+1)&&(ya==yd-1))||((xa==xd)&&(ya==yd-1))||((xa==xd-1)&&(ya==yd-1))||((xa==xd-1)&&(ya==yd))||((xa==xd-1)&&(ya==yd+1))||((xa==xd)&&(ya==yd+1))||((xa==xd+1)&&(ya==yd+1)))
		{
			return true;
		}
		
	}
	
	
	
	
	if ((tj[xd][yd]==6)||(tj[xd][yd]==-6))//la tour
	
	{		
		for (int i=1;i<=7;i++)
		{
			if((( xa==xd+i)&&(ya==yd))||(( xa==xd-i)&&(ya==yd))||(( xa==xd)&&(ya==yd+i))||(( xa==xd)&&(ya==yd-i)))
			{
				if(CheminLibre(xd,yd,xa, ya)==true)
				{
					return true;	
				}
				
			}	
		}
		
		}
		////////////////////////////////////////////
		if ((tj[xd][yd]==2)||(tj[xd][yd]==-2))//le fou
	
	{		
		for (int i=1;i<=7;i++)
		{
			if((( xa==xd+i)&&(ya==yd+i))||(( xa==xd-i)&&(ya==yd-i))||(( xa==xd+i)&&(ya==yd-i))||(( xa==xd-i)&&(ya==yd+i)))
			{
				if(CheminLibre(xd,yd,xa, ya)==true)
				{
					return true;	
				}	
			}	
		}
		
		}	
		

	return false;
}
bool plateau::CheminLibre(int xd,int yd,int xa,int ya)
{
	for(int i=xa;i<=xd;i++)
	{
		for(int j=ya;j<=yd;j++)
		{
			if ( tj[i][j]!=0)
			{
				return false;
			}
		}	
	}
	return true;
}
/*bool plateau::AttaquePossible(int tour,int xd, int yd,int xa,int ya)
{
	if (tour==0)
	{
	
			if (tj[xd][yd]==5)
			{
				if (tj[xd-2][yd+1]<0)
				{
					xa=xd-2;
					ya=yd+1;
				}
				else if(tj[xd-1][yd+2]<0)
				{
					xa=xd-1;
					ya=yd+2;
				}
				else if(tj[xd+1][yd+2]<0||tj[xd+2][yd+1]<0||tj[xd+2][yd-1]<0||tj[xd+1][yd-2]<0||tj[xd-1][yd-2]<0||tj[xd-2][yd-1]<0)
					{
						return true;
					}
			}
			if (tj[xd][yd]==2)
			{
				for (int i=1;i<=7;i++)
				{
				if( tj[xd+i][yd+i]<0|| tj[xd-i][yd-i]<0||tj[xd+i][yd-i]<0||tj[xd-i][yd+i]<0)
				{
					return true;
				}	
				}
			}
			if (tj[xd][yd]==4)
			{
				if(tj[xd+1][yd]<0||tj[xd+1][yd-1]<0||tj[xd][yd-1]<0||tj[xd-1][yd-1]<0||tj[xd-1][yd]<0||tj[xd-1][yd+1]<0||tj[xd][yd+1]<0||tj[xd+1][yd+1]<0)
				{ 
					return true;
				}
			}
			if (tj[xd][yd]==3)
			{	
				for (int i=1;i<7;i++)
				{
				if (tj[xd+i][yd]<0||tj[xd+i][yd-i]<0||tj[xd][yd-i]<0||tj[xd-i][yd-i]<0||tj[xd-i][yd]<0||tj[xd-i][yd+i]<0||tj[xd][yd+i]<0||tj[xd+i][yd+i]<0)
				{
					return true;
				}}
			}
			if  (tj[xd][yd]==6)
			{
				for (int i=1;i<7;i++)
					if(tj[xd+i][yd]<0||tj[xd-i][yd]<0||tj[xd][yd+i]<0||tj[xd][yd-i]<0)
					{
						return true;
					}}
			}
			if  (tj[xd][yd]==1)
			{
				{
					if (xd==1)
					{
						if (tj[xd+2][yd]<0||tj[xd+1][yd]<0||tj[xd+1][yd-1]<0||tj[xd+1][yd+1]<0)
						{
							return true;
						}
					}
					else
					{
						if (tj[xd+1][yd]<0||(tj[xd+1][yd-1]<0||tj[xd+1][yd+1]<0))
						{
							return true;
						}
					}
					
					}	
			}
		
		else
		{
				if (tj[xd][yd]==-5)
			{
				if (tj[xd-2][yd+1]>0||tj[xd-1][yd+2]>0||tj[xd+1][yd+2]>0||tj[xd+2][yd+1]>0||tj[xd+2][yd-1]>0||tj[xd+1][yd-2]>0||tj[xd-1][yd-2]>0||tj[xd-2][yd-1]>0)
					{
						return true;
					}
			}
			if (tj[xd][yd]==-2)
			{
				for (int i=1;i<=7;i++)
				{
				if( tj[xd+i][yd+i]>0|| tj[xd-i][yd-i]>0||tj[xd+i][yd-i]>0||tj[xd-i][yd+i]>0)
				{
					return true;
				}	
				}
			}
			if (tj[xd][yd]==-4)
			{
				if(tj[xd+1][yd]>0||tj[xd+1][yd-1]>0||tj[xd][yd-1]>0||tj[xd-1][yd-1]>0||tj[xd-1][yd]>0||tj[xd-1][yd+1]>0||tj[xd][yd+1]>0||tj[xd+1][yd+1]>0)
				{ 
					return true;
				}
			}
			if (tj[xd][yd]==-3)
			{
				for (int i=1;i<=7;i++)
				{
				if (tj[xd+i][yd]>0||tj[xd+i][yd-i]>0||tj[xd][yd-i]>0||tj[xd-i][yd-i]>0||tj[xd-i][yd]>0||tj[xd-i][yd+i]>0||tj[xd][yd+i]>0||tj[xd+i][yd+i]>0)
				{
					return true;
				}}
			}
			if  (tj[xd][yd]==-6)
			{
				for (int i=1;i<=7;i++)
				{
						if(tj[xd+i][yd]>0||tj[xd-i][yd]>0||tj[xd][yd+i]||tj[xd][yd-i]>0)
					{
						return true;
					}
			}}
			if(tj[xd][yd]==-1)
			{
				if (xd==5)
					{
						if (tj[xd-2][yd]>0||tj[xd-1][yd]||tj[xd-1][yd+1]>0||tj[xd-1][yd-1]>0)
						{
							return true;
						}
						
					}
					else
					{
						if (tj[xd-1][yd]>0||tj[xd-1][yd+1]>0||tj[xd-1][yd-1]>0)
						{
							return true;
						}
					}
			}
			
		}
			
			
			
		
}
bool plateau::MovPossible(int tour,int xd, int yd)
{
	if (tour==0)
	{
	
			if (tj[xd][yd]==5)
			{
				if (tj[xd-1][yd+2]==0||tj[xd+1][yd+2]==0||tj[xd+2][yd+1]==0||tj[xd+2][yd-1]==0||tj[xd+1][yd-2]==0||tj[xd-1][yd-2]==0||tj[xd-2][yd-1]==0)
					{
						return true;
					}
			}
			if (tj[xd][yd]==2)
			{
				for (int i=1;i<=7;i++)
				{
				if( tj[xd+i][yd+i]==0|| tj[xd-i][yd-i]==0||tj[xd+i][yd-i]==0||tj[xd-i][yd+i]==0)
				{
					return true;
				}	
				}
			}
			if (tj[xd][yd]==4)
			{
				if(tj[xd+1][yd]==0||tj[xd+1][yd-1]==0||tj[xd][yd-1]==0||tj[xd-1][yd-1]==0||tj[xd-1][yd]==0||tj[xd-1][yd+1]==0||tj[xd][yd+1]==0||tj[xd+1][yd+1]==0)
				{ 
					return true;
				}
			}
			if (tj[xd][yd]==3)
			{	
				for (int i=1;i<=7;i++)
				{
				if (tj[xd+i][yd]==0||tj[xd+i][yd-i]==0||tj[xd][yd-i]==0||tj[xd-i][yd-i]==0||tj[xd-i][yd]==0||tj[xd-i][yd+i]==0||tj[xd][yd+i]==0||tj[xd+i][yd+i]==0)
				{
					return true;
				}}
			}
			if  (tj[xd][yd]==6)
			{
				for (int i=1;i<=7;i++)
					if(tj[xd+i][yd]==0||tj[xd-i][yd]==0||tj[xd][yd+i]||tj[xd][yd-i]==0)
					{
						return true;
					}}
			
			if  (tj[xd][yd]==1)
			{
				{
					if (xd==1)
					{
						if (tj[xd+2][yd]||tj[xd+1][yd]||tj[xd+1][yd-1]==0||tj[xd+1][yd+1]==0)
						{
							return true;
						}
					}
					else
					{
						if (tj[xd+1][yd]==0||(tj[xd+1][yd-1]==0||tj[xd+1][yd+1]==0))
						{
							return true;
						}
					}
					
					}	
			}}
		
		else
		{
				if (tj[xd][yd]==-5)
			{
				if (tj[xd-2][yd+1]==0||tj[xd-1][yd+2]==0||tj[xd+1][yd+2]==0||tj[xd+2][yd+1]==0||tj[xd+2][yd-1]==0||tj[xd+1][yd-2]==0||tj[xd-1][yd-2]==0||tj[xd-2][yd-1]==0)
					{
						return true;
					}
			}
			if (tj[xd][yd]==-2)
			{
				for (int i=1;i<=7;i++)
				{
				if( tj[xd+i][yd+i]==0|| tj[xd-i][yd-i]==0||tj[xd+i][yd-i]==0||tj[xd-i][yd+i]==0)
				{
					return true;
				}	
				}
			}
			if (tj[xd][yd]==-4)
			{
				if(tj[xd+1][yd]==0||tj[xd+1][yd-1]==0||tj[xd][yd-1]==0||tj[xd-1][yd-1]==0||tj[xd-1][yd]==0||tj[xd-1][yd+1]==0||tj[xd][yd+1]==0||tj[xd+1][yd+1]==0)
				{ 
					return true;
				}
			}
			if (tj[xd][yd]==-3)
			{
				for (int i=1;i<=7;i++)
				{
				if (tj[xd+i][yd]==0||tj[xd+i][yd-i]==0||tj[xd][yd-i]==0||tj[xd-i][yd-i]==0||tj[xd-i][yd]==0||tj[xd-i][yd+i]==0||tj[xd][yd+i]==0||tj[xd+i][yd+i]==0)
				{
					return true;
				}}
			}
			if  (tj[xd][yd]==-6)
			{
				for (int i=1;i<=7;i++)
				{
						if(tj[xd+i][yd]==0||tj[xd-i][yd]==0||tj[xd][yd+i]==0||tj[xd][yd-i]==0)
					{
						return true;
					}
			}}
			if(tj[xd][yd]==-1)
			{
				if (xd==5)
					{
						if (tj[xd-2][yd]==0||tj[xd-1][yd]||tj[xd-1][yd+1]==0||tj[xd-1][yd-1]==0)
						{
							return true;
						}
						
					}
					else
					{
						if (tj[xd-1][yd]==0||tj[xd-1][yd+1]==0||tj[xd-1][yd-1]==0)
						{
							return true;
						}
					}
			}
			
		}
			
}
/*plateau::scannerAT(p,tour,tAt)
{
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if (AttaquePossible(tour,i,j)==true)
			{
				,
			}
		}	
	}
}
scannerMov(p,tour,tmov);
{
	int joueur;
	if(0) joueur = -1;
	int max = -10,min = 10,xd,yd,xa,ya;
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if (MovPossible(tour,i,j)==true)
			{
				for(int k=0;i<=7;i++)
				{
					for(int l=0;j<=7;j++)
					{
						if(possible(i, j, k,l) && )
						{
							if(tj[k][l] != 0 && tj[k][l] > max)
							{
								max = tj[k][l];
								xd = i;
								yd = j;
								xa = k;
								ya = l;
							}
							else
							{
								//min dyal  tj[i][j]
								if(tj[k][l]<min)
								{
									min = tj[k][l];
									xd = i;
									yd = j;
									xa = k;
									ya = l;
								} 
							}
						}
					}
				}
			}
		}
	}
	tj[xa][ya]=tj[xd][yd];
	tj[xd][yd]=0;
}
	
/*plateau::DeplacerIA(plateau p,int tour)
{
	scannerAT(p,tour,tAt);
	scannerMov(p,tour,tmov);
	if(tAt!=NULL)
	{
		DepAt(p,tour,tAt);
		
	}
	else
	{
		DepMpv(p,tour,tMax);
	}
}
*/




//joueur N-> Noir B->Blanc
plateau::deplacerPiece(char joueur)
{
	int xd,yd,ya,xa;
	do{
	saisirD(xd,yd,joueur);
	saisirA(xa,ya,joueur);
	}while(possible(xd,yd,xa,ya)==false);
	tj[xa][ya]=tj[xd][yd];
	tj[xd][yd]=0;
}
