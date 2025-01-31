#include "compteepargne.h"

/*CompteEpargne::CompteEpargne(const float _solde, float _tauxInterets):
    solde(_solde),
    tauxInterets(_tauxInterets)
{

}
*/
float CompteEpargne::calculerInterets()
{
    return  solde * tauxInterets;
}
