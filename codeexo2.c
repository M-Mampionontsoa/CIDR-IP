#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1000
#include <unistd.h>
#include <math.h>

void animation(char *message)
{
    int str=0;
    int i;
    str=strlen(message);
    for(i=0;i<str;i++)
    {
        putchar(message[i]);
        fflush(stdout);
        usleep(60000);
        
    }

}


void calc_byte(int byte, char *output)
{
    int i;
    for ( i = 7; i >= 0; i--) {
        output[7-i] = (byte & (1 << i)) ? '1' : '0';
    }
    output[8] = '\0';
}

void calc_ip(const char *ip, char *output)
{
    int octet;
    int i;
    char octe_bin[MAX_LENGTH];
    char ip_bin[MAX_LENGTH] = "";

    for ( i = 0; i < 4; i++)
    {
        sscanf(ip, "%d", &octet);
        calc_byte(octet,octe_bin);
        strcat(ip_bin, octe_bin);
        ip = strchr(ip, '.') + 1;
    }

    strcpy(output, ip_bin);
    animation("Votre adresse Ip en binaire:");
    printf("%s\n",output);

}

void calc_ad_res(char *output, int net, char *network_address, int *bit_reseau)
{
    strncpy(network_address, output, *bit_reseau);
    
    // Remplir les bits restants avec des '0'
    for (int i = *bit_reseau; i < 32; i++) 
    {
        network_address[i] = '0';
    }
    network_address[32] = '\0';  

    animation("Votre adresse reseau en binaire:");
    printf("%s\n", network_address);
}

void calc_ad_broad(char *output, int net, char *broadcast_address, int *bit_reseau)
{
    strncpy(broadcast_address, output, *bit_reseau);

    // Remplir les bits restants avec des '1'
    for (int i = *bit_reseau; i < 32; i++) 
    {
        broadcast_address[i] = '1';
    }
    broadcast_address[32] = '\0';  

    animation("Votre adresse broadcast en binaire:");
    printf("%s\n", broadcast_address);
}


void calc_msr(int bit_reseau, char *output) 
{
    for (int i = 0; i < 32; i++) 
    {
        if (i < bit_reseau) 
        {
            output[i] = '1';
        } 
        else
        {
            output[i] = '0';
        }
    }
    output[32] = '\0';  

    animation("Votre masque de sous-reseau en binaire:");
    printf("%s\n", output);
}

void calc_host(int *bit_reseau) 
{
    int bit_host = 32 - *bit_reseau;
    int host = pow(2, bit_host) - 2;  // Calculer le nombre d'hôtes possibles

    animation("Le nombre d'hotes possible:");
    printf("%d\n", host);
}


void calc_dec(char *binary_ip) 
{
    char octet_str[9];  
    char decimal_ip[16] = "";  
    int octet;

    for (int i = 0; i < 4; i++) 
    {
        strncpy(octet_str, binary_ip + (i * 8), 8);
        octet_str[8] = '\0';
        octet = strtol(octet_str, NULL, 2);  // Convertir le binaire en décimal
        sprintf(decimal_ip + strlen(decimal_ip), "%d", octet);
        if (i < 3) 
        {
            strcat(decimal_ip, ".");
        }
    }

    printf("%s\n", decimal_ip);
}

void entry_ip(char *ip, int *bit_reseau)
{
    char output[MAX_LENGTH];
    char network_address[MAX_LENGTH];
    char broadcast_address[MAX_LENGTH];
    char subnet_mask[MAX_LENGTH];
    int net = *bit_reseau;

    animation("\t***IP PLATEFORM***\n");
    printf("---------------------------------------------------------------------------------------\n");
    animation("Entrez une adresse IP au format x.x.x.x: ");
    scanf("%s", ip);
    printf("---------------------------------------------------------------------------------------\n");
    animation("Entrer le nombre de bit reseau:");
    scanf("%d", bit_reseau);
    printf("---------------------------------------------------------------------------------------\n");
    calc_ip(ip, output);
    printf("---------------------------------------------------------------------------------------\n");
    calc_ad_res(output, net, network_address, bit_reseau);
    printf("---------------------------------------------------------------------------------------\n");
    calc_ad_broad(output, net, broadcast_address, bit_reseau);
    printf("---------------------------------------------------------------------------------------\n");
    calc_msr(*bit_reseau, subnet_mask);
    printf("---------------------------------------------------------------------------------------\n");
    animation("votre adresse reseau en decimal:");
    calc_dec(network_address);
    printf("---------------------------------------------------------------------------------------\n");
    animation("Votre adresse broadcast en decimal:");
    printf("---------------------------------------------------------------------------------------\n");
    calc_dec(broadcast_address);
    printf("---------------------------------------------------------------------------------------\n");
    animation("Votre masque de sous-reseau en decimal:");
    printf("---------------------------------------------------------------------------------------\n");
    calc_dec(subnet_mask);
    printf("---------------------------------------------------------------------------------------\n");
    calc_host(bit_reseau);
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t***      ****\n");
}


