#include <stdio.h>

#define MAX_PRODUCTS 100

int afficher(int code[], int quantite[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("code : %d avec quantite : %d \n", code[i], quantite[i]);
    }
    return 0;
}

int supprimer(int code[], int quantite[], int *n) {
    int codes, quantites;
    int i;
    printf("donne moi le code \n");
    scanf("%d", &codes);
    for (i = 0; i < *n; i++) {
        if (code[i] == codes) {
            printf("donne moi la quantite \n");
            scanf("%d", &quantites);
            if (quantite[i] < quantites) {
                printf("pas de quantite dans le stock\n");
            } else {
                quantite[i] -= quantites;
                printf("supprimer avec succe\n");
            }
            return 0;
        }
    }
    printf("code n'existe pas \n");
    return 0;
}

void ajoute(int code[], int quantite[], int *n) {
    int codes, quantites;
    printf("Entrer le code ");
    scanf("%d", &codes);
    printf("Entrer la quantite ");
    scanf("%d", &quantites);
    int i;
    for (i = 0; i < *n; i++) {
        if (code[i] == codes) {
            printf("le code existe deja \n");
            quantite[i] += quantites;
            return;
        }
    }
    code[*n] = codes;
    quantite[*n] = quantites;
    (*n)++;
    printf("ajouter avec succe!!!!!! \n");
}

void menu() {
    int code[MAX_PRODUCTS];
    int quantite[MAX_PRODUCTS];
    int n = 0;
    int choix = 1;
    while (choix >= 1 && choix <= 4) {
        printf("1--------------Afficher les produits---------------- \n");
        printf("2--------------Ajouter un produit-------------------\n");
        printf("3--------------Supprimer un produit-----------------\n");
        printf("4--------------Fermer-------------------------------\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("voila le tableau\n");
                afficher(code, quantite, n);
                break;

            case 2:
                printf("ajouter dans le tableau\n");
                ajoute(code, quantite, &n);
                break;

            case 3:
                printf("supprimer dans le tableau\n");
                supprimer(code, quantite, &n);
                break;

            case 4:
                printf("Fermeture demandée. Au revoir!\n");
                return;

            default:
                printf("Option non valide \n");
        }
    }
}

int main() {
    menu();
    return 0;
}
