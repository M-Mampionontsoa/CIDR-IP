#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Fonction d'animation de l'affichage du texte
void animation(char *message);

///Entrée  de l'adresse ip 
void entry_ip(char *ip,int *bit_reseau);

// Fonction pour convertir un octet en binaire
void calc_byte(int byte, char *output);

// Fonction pour convertir une adresse IP en binaire
void calc_ip(const char *ip, char *output);


// Fonction pour calculer l'adresse réseau en binaire
void calc_ad_res( char *output, int net, char *network_address,int *bit_reseau);

///Fonction de calcul du masque de sous-reseau en binaire
void calc_msr(int bit_reseau, char *output);

///Fonction pour calculer le nombre d'hote
void calc_host(int *bit_reseau);

///Fonction de conversion de binaire en decimale
void calc_dec(char *binary_ip) ;