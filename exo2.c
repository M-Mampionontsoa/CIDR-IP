#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codeexo2.c"
#include "exo2.h"

int main(int argc,char *argv[])
{
    char ip[MAX_LENGTH];
    int bit_reseau=0;
    entry_ip(ip,&bit_reseau);
    
    return (0);
}