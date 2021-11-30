#include <time.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

int nb_participant;

class participant
{
	public :
                string nom;
                string prenom;
		string personne_cible;
		bool cadeau_recu = false;
		bool cadeau_donne = false;
                participant(){};
                participant(string, string);
		void affiche();
                //void asso();
                //~participant();
};

participant::participant(string cin_nom, string cin_prenom)
{
        nom=cin_nom;
        prenom=cin_prenom;
}

void participant::affiche()
{
        cout<<"nom : "<<nom<<"\n";
        cout<<"prenom : "<<prenom<<"\n";
}


int main()
{
srand(time(NULL));
cout<<"Entrez le nombre de participant : ";
cin>>nb_participant;
participant liste_donneur[nb_participant];
participant liste_receveur[nb_participant];

for(int i=0; i<nb_participant; i++)
{
string nom, prenom;
cout<<"\nInfo participant "<<i<<" :"<<"\nNom participant : ";
cin>>nom;
cout<<"Prenom participant : ";
cin>>prenom;
liste_donneur[i]={nom, prenom};
liste_receveur[i]={nom, prenom};
}

for(int i=0; i<nb_participant; i++)
{
cout<<"\n>>Participant "<<i<<" :\n";
liste_donneur[i].affiche();
}

for(int i=0; i<nb_participant; i++)
{
int asso = rand()%nb_participant;
if(asso==i || liste_receveur[asso].cadeau_recu==true || liste_receveur[asso].personne_cible == liste_donneur[i].prenom+" "+liste_donneur[i].nom)
{
//cout<<"\n-----ERREUR-----\n"<<"donneur : "<<liste_donneur[i].prenom<<"; receveur : "<<liste_receveur[asso].prenom<<"; receveur a deja recu = "<<liste_receveur[asso].cadeau_recu<<"; receveur est deja son donneur ? "<<liste_receveur[asso].personne_cible<<"\n";
i--;
}
else
{
cout<<"\n+++++NO ERROR+++++";
liste_donneur[i].personne_cible = liste_receveur[asso].prenom +" "+liste_receveur[asso].nom;
liste_receveur[i].personne_cible = liste_donneur[i].personne_cible;
liste_receveur[asso].cadeau_recu = true;
//cout<<liste_donneur[i].prenom<<" donne a "<<liste_receveur[asso].prenom;
}
}

for(int i=0; i<nb_participant; i++)
{
//cout<<"\n>>Participant "<<i<<" asso :\n";
//cout<<liste_donneur[i].prenom<<" donne a :"<<liste_donneur[i].personne_cible;
ofstream outfile(liste_donneur[i].prenom+".txt");
outfile << "tu dois donner à "+liste_donneur[i].personne_cible<<endl;
outfile.close();
}

}
