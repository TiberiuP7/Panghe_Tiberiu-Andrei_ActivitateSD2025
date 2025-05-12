#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//T si P -> Articolul Tapiserie

struct Tapiserie {
    int id;
    char* denumire;
    char* culoare;
    float pret;
    float *dimensiuni;
    int nrbucati;
};
typedef struct Tapiserie Tapiserie;

Tapiserie citireTapiserie(Tapiserie tapiserie) {

    printf("Introduceti id-ul tapiseriei: ");
    scanf("%d", &tapiserie.id);
    tapiserie.denumire = (char*)malloc(50 * sizeof(char));
    printf("Introduceti denumirea tapiseriei: ");
    scanf("%s", tapiserie.denumire);
    tapiserie.culoare = (char*)malloc(50 * sizeof(char));
    printf("Introduceti culoarea tapiseriei: ");
    scanf("%s", tapiserie.culoare);
    printf("Introduceti pretul tapiseriei: ");
    scanf("%f", &tapiserie.pret);
    printf("Introduceti numarul de dimensiuni: ");
    scanf("%d", &tapiserie.nrbucati);
    tapiserie.dimensiuni = (float*)malloc(tapiserie.nrbucati * sizeof(float));
    for (int i = 0; i < tapiserie.nrbucati; i++) {
        printf("Introduceti dimensiunea %d: ", i + 1);
        scanf("%f", &tapiserie.dimensiuni[i]);
    }
    return tapiserie;
}

float sumaDimensiuni(Tapiserie tapiserie) {
    float suma = 0;
    for (int i = 0; i < tapiserie.nrbucati; i++) {
        suma += tapiserie.dimensiuni[i];
    }
    printf("Suma dimensiunilor: %.2f\n", suma);
}

void modificarePret(Tapiserie* tapiserie, float pretNou) {
    tapiserie->pret = pretNou;
    printf("Pretul a fost modificat la %.2f\n", tapiserie->pret);
}

void afisareTapiserie(Tapiserie tapiserie) {
    printf("Id: %d\n", tapiserie.id);
    printf("Denumire: %s\n", tapiserie.denumire);
    printf("Culoare: %s\n", tapiserie.culoare);
    printf("Pret: %.2f\n", tapiserie.pret);
    printf("Dimensiuni:");
    for(int i=0; i<tapiserie.nrbucati; i++) {
        printf("%.2f\n", tapiserie.dimensiuni[i]);
    }
    printf("Numar de dimensiuni: %d\n", tapiserie.nrbucati);
    printf("\n");
}

void eliberareMemorieTapiserie(Tapiserie* tapiserie) {
    free(tapiserie->denumire);
    free(tapiserie->culoare);
    free(tapiserie->dimensiuni);
    tapiserie->dimensiuni = NULL;
    tapiserie->denumire = NULL;
    tapiserie->culoare = NULL;
    tapiserie->nrbucati = 0;
    tapiserie->pret = 0;
    tapiserie->id = 0;
    printf("Memoria a fost eliberata\n");
}

int main() {
    Tapiserie tapiserie;
    tapiserie = citireTapiserie(tapiserie);
    afisareTapiserie(tapiserie);
    sumaDimensiuni(tapiserie);
    printf("Introduceti pretul nou: ");
    float pretNou;
    scanf("%f", &pretNou);
    modificarePret(&tapiserie, pretNou);
    afisareTapiserie(tapiserie);

    eliberareMemorieTapiserie(&tapiserie);

    return 0;
}





