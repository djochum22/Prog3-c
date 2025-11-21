
#include <stdio.h>

int main(void)
{
    #if DE 
        printf("Ohne Hoergeraet hoere ich nichts\n");
    #elif NL 
        printf("Zonder gehoorapparaat hoor ik niets\n");
    #elif FI
        printf("Ilman kuuloeitta en kuula mitaeaen\n");
    #elif SE
        printf("Jag hoer ingenting utan hoerselapparat\n");
    #elif IT
        printf("Senze l'apparecchio d'autito non sento niente\n");
    #elif CN
        printf("mei zhu ting qi jiu tingbuijan\n");
    #endif
    return 0;
}