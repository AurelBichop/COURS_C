#include <stdio.h>
#include <stdlib.h>

#define VERSION_PROGRAMME "0.1"
#define AUTEUR "Aurel Bichop"

#define A_PROPOS(titre) printf("\n%s \n", titre); \
printf("\t Version : %s (%s,%s)\n",VERSION_PROGRAMME,__DATE__,__TIME__); \
printf("\t Auteur : %s \n\n",AUTEUR);

#define LOG_CRITIC "CRITIC"
#define LOG_ERROR "ERROR"
#define LOG_DEBUG "DEBUG"


#ifdef DEBUG
    #define DEBUG_LOG(niveau,message) printf("[%s] %s (%s:%d) \n",niveau,message,__FILE__,__LINE__);
#else
    #define DEBUG_LOG(niveau,message);
#endif

int main()
{
    #ifndef DEBUG
        A_PROPOS("Le Preprocesseur\n")
    #endif // DEBUG

    DEBUG_LOG(LOG_ERROR,"test");

    return 0;
}
