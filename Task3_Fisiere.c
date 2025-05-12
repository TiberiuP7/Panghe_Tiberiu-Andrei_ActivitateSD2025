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

void afisarevectorTapiserie(Tapiserie* tapiserie, int n) {
    for(int i=0; i<n; i++) {
        afisareTapiserie(tapiserie[i]);
    }
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

Tapiserie* copiereTapiserie(Tapiserie* tapiserie, int n, int* nrCopiate) {
    Tapiserie* tapiserie2= NULL;
    int nr=0;
    //Parcurgem vectorul alocat dinamic cu cele 5 elemente de tip Tapiserie
    for(int i = 0; i < n; i++) {
        //Daca pretul tapiseriei este mai mare decat 199, o copiem in tapiserie2(noul vector)
        if(tapiserie[i].pret > 199) {
            tapiserie2= (Tapiserie*)realloc(tapiserie2, sizeof(Tapiserie)* (nr + 1));
            if(tapiserie2 == NULL) {
                printf("Eroare la alocarea memoriei\n");
                exit(1);
            }
            //Cream deep copy
            tapiserie2[nr].id= tapiserie[i].id;

            tapiserie2[nr].denumire= (char*)malloc(strlen(tapiserie[i].denumire) + 1);
            strcpy(tapiserie2[nr].denumire, tapiserie[i].denumire);
            tapiserie2[nr].culoare= (char*)malloc(strlen(tapiserie[i].culoare) + 1);
            strcpy(tapiserie2[nr].culoare, tapiserie[i].culoare);

            tapiserie2[nr].pret= tapiserie[i].pret;
            tapiserie2[nr].nrbucati= tapiserie[i].nrbucati;

            //Alocam memorie pentru dimensiuni
            tapiserie2[nr].dimensiuni= (float*)malloc(tapiserie[i].nrbucati * sizeof(float));
            for(int j=0; j<tapiserie[i].nrbucati; j++) {
                tapiserie2[nr].dimensiuni[j]= tapiserie[i].dimensiuni[j];
            }
            nr++;
        }
    }

    *nrCopiate= nr;
    return tapiserie2;
}

Tapiserie* copiereTapiserie2(Tapiserie* tapiserie, int n, int* nrCopiate) {
    Tapiserie* tapiserie2= NULL;
    int nr=0;
    //Parcurgem vectorul alocat dinamic cu cele n elemente de tip Tapiserie
    for(int i = 0; i < n; i++) {
        //Daca id ul tapiseriei este un numar par, o copiem in tapiserie2(noul vector)
        if(tapiserie[i].id % 2 == 0) {
            tapiserie2= (Tapiserie*)realloc(tapiserie2, sizeof(Tapiserie)* (nr + 1));
            if(tapiserie2 == NULL) {
                printf("Eroare la alocarea memoriei\n");
                exit(1);
            }
            //Cream deep copy
            tapiserie2[nr].id= tapiserie[i].id;

            tapiserie2[nr].denumire= (char*)malloc(strlen(tapiserie[i].denumire) + 1);
            strcpy(tapiserie2[nr].denumire, tapiserie[i].denumire);
            tapiserie2[nr].culoare= (char*)malloc(strlen(tapiserie[i].culoare) + 1);
            strcpy(tapiserie2[nr].culoare, tapiserie[i].culoare);

            tapiserie2[nr].pret= tapiserie[i].pret;
            tapiserie2[nr].nrbucati= tapiserie[i].nrbucati;

            //Alocam memorie pentru dimensiuni
            tapiserie2[nr].dimensiuni= (float*)malloc(tapiserie[i].nrbucati * sizeof(float));
            for(int j=0; j<tapiserie[i].nrbucati; j++) {
                tapiserie2[nr].dimensiuni[j]= tapiserie[i].dimensiuni[j];
            }
            nr++;
        }
    }

    *nrCopiate= nr;
    return tapiserie2;
}

Tapiserie* concateneazaVectori(Tapiserie* tapiserie1, int n1, Tapiserie* tapiserie2, int n2, int* nConcatenat) {
    *nConcatenat= n1 + n2;
    //Alocam memorie pentru vectorul concatenat
    Tapiserie* vectorConcatenat= (Tapiserie*)malloc(sizeof(Tapiserie) * (*nConcatenat));
    if(vectorConcatenat == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    //Copiem tapiseriile din tapiserie1 in vectorul concatenat
    //Cream deep copy
    for(int i=0; i<n1; i++) {
        vectorConcatenat[i].id= tapiserie1[i].id;

        //Alocam memorie pentru denumire si culoare si le copiem
        //in vectorul concatenat
        vectorConcatenat[i].denumire= (char*)malloc(strlen(tapiserie1[i].denumire) + 1);
        strcpy(vectorConcatenat[i].denumire, tapiserie1[i].denumire);
        vectorConcatenat[i].culoare= (char*)malloc(strlen(tapiserie1[i].culoare) + 1);
        strcpy(vectorConcatenat[i].culoare, tapiserie1[i].culoare);

        vectorConcatenat[i].pret= tapiserie1[i].pret;
        vectorConcatenat[i].nrbucati= tapiserie1[i].nrbucati;

        //Alocam memorie pentru dimensiuni
        vectorConcatenat[i].dimensiuni= (float*)malloc(tapiserie1[i].nrbucati * sizeof(float));
        for(int j=0; j<tapiserie1[i].nrbucati; j++) {
            vectorConcatenat[i].dimensiuni[j]= tapiserie1[i].dimensiuni[j];
        }
    }

    //Copiem tapiseriile din tapiserie2 in vectorul concatenat
    //Cream deep copy
    for(int i=0; i<n2; i++) {
        int index= i + n1;
        vectorConcatenat[index].id = tapiserie2[i].id;

        //Alocam memorie pentru denumire si culoare si le copiem
        //in vectorul concatenat
        vectorConcatenat[index].denumire = (char*)malloc(strlen(tapiserie2[i].denumire) + 1);
        strcpy(vectorConcatenat[index].denumire, tapiserie2[i].denumire);   
        vectorConcatenat[index].culoare = (char*)malloc(strlen(tapiserie2[i].culoare) + 1);
        strcpy(vectorConcatenat[index].culoare, tapiserie2[i].culoare);

        vectorConcatenat[index].pret = tapiserie2[i].pret;
        vectorConcatenat[index].nrbucati = tapiserie2[i].nrbucati;

        //Alocam memorie pentru dimensiuni
        vectorConcatenat[index].dimensiuni = (float*)malloc(tapiserie2[i].nrbucati * sizeof(float));
        for(int j=0; j<tapiserie2[i].nrbucati; j++) {
            vectorConcatenat[index].dimensiuni[j] = tapiserie2[i].dimensiuni[j];
        }
    }

    return vectorConcatenat;
}

Tapiserie* citiredinFisier(char* numeFisier, int* n) {
    FILE* file = fopen(numeFisier, "r");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(1);
    }
    int count = 0;
    //Numaram cate tapiserii sunt in fisier, optional
    int id, nrbucati;
    char denumire[50], culoare[50];
    float pret, dimensiune;
    while(fscanf(file, "%d %s %s %f %d", &id, denumire, culoare, &pret, &nrbucati) == 5) {
        for(int i=0; i< nrbucati; i++) {
            fscanf(file, "%f", &dimensiune);
        }
        count++;
    }
        
    rewind(file);

    Tapiserie* tapiserii= NULL;
    tapiserii = (Tapiserie*)malloc(sizeof(Tapiserie) * (*n));
    if (tapiserii == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }

    //while (!feof(file)) {
    //Am primit dimensiunea fisierului prin parametrul n, alternativ putem prin variabila count
    for(int i=0; i< *n; i++) {
            
        //Citirea tapiseriei din fisier
        fscanf(file, "%d", &tapiserii[i].id);
        //Alocam memorie pentru denumire si culoare
        tapiserii[i].denumire = (char*)malloc(50 * sizeof(char));
        tapiserii[i].culoare = (char*)malloc(50 * sizeof(char));
        if(tapiserii[i].denumire == NULL || tapiserii[i].culoare == NULL) {
            printf("Eroare la alocarea memoriei\n");
            exit(1);
        }

        fscanf(file, "%s", tapiserii[i].denumire);
        fscanf(file, "%s", tapiserii[i].culoare);

        fscanf(file, "%f", &tapiserii[i].pret);
        fscanf(file, "%d", &tapiserii[i].nrbucati);

        //Alocam memorie pentru dimensiuni
        tapiserii[i].dimensiuni = (float*)malloc(tapiserii[i].nrbucati * sizeof(float));
        if(tapiserii[i].dimensiuni == NULL) {
            printf("Eroare la alocarea memoriei\n");
            exit(1);
        }

        //Citirea dimensiunilor din fisier
        for (int j = 0; j < tapiserii[i].nrbucati; j++) {
            fscanf(file, "%f", &tapiserii[i].dimensiuni[j]);
        }
    }
    fclose(file);
    return tapiserii;
}

void scriereobiectInFisier(char* numeFisier, Tapiserie tapiserie) {
    FILE* file = fopen(numeFisier, "a");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(1);
    }
    fprintf(file, "%d %s %s %.2f %d ", tapiserie.id, tapiserie.denumire, tapiserie.culoare, tapiserie.pret, tapiserie.nrbucati);
    for(int j=0; j<tapiserie.nrbucati; j++) {
        fprintf(file, "%.2f ", tapiserie.dimensiuni[j]);
    }
    fprintf(file, "\n");
    fclose(file);
}

void scrierevectorInFisier(char* numeFisier, Tapiserie* tapiserie, int n) {
    FILE* file = fopen(numeFisier, "w");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(1);
    }
    for(int i=0; i<n; i++) {
        fprintf(file, "%d %s %s %.2f %d ", tapiserie[i].id, tapiserie[i].denumire, tapiserie[i].culoare, tapiserie[i].pret, tapiserie[i].nrbucati);
        for(int j=0; j<tapiserie[i].nrbucati; j++) {
            fprintf(file, "%.2f ", tapiserie[i].dimensiuni[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    int n = 10;
    Tapiserie* tapiserie;
    for(int i=0; i< n; i++) {
        tapiserie= citiredinFisier("fisier.txt", &n);
    }

    afisarevectorTapiserie(tapiserie, n);
    
    //Scriem un obiect de tip Tapiserie in fisier
    Tapiserie tapiserie1;
    tapiserie1 = citireTapiserie(tapiserie1);
    scriereobiectInFisier("obiect.txt", tapiserie1);
    //Verificam daca a fost scris corect in fisier
    FILE* f= fopen("obiect.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        exit(1);
    }

    tapiserie1.denumire = (char*)malloc(50 * sizeof(char));
    tapiserie1.culoare = (char*)malloc(50 * sizeof(char));
    if(tapiserie1.denumire == NULL || tapiserie1.culoare == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    
    fscanf(f, "%d %s %s %f %d", &tapiserie1.id, tapiserie1.denumire, tapiserie1.culoare, &tapiserie1.pret, &tapiserie1.nrbucati);
    tapiserie1.dimensiuni = (float*)malloc(tapiserie1.nrbucati * sizeof(float));
    if(tapiserie1.dimensiuni == NULL) {
        printf("Eroare la alocarea memoriei\n");
        exit(1);
    }
    for(int j=0; j<tapiserie1.nrbucati; j++) {
        fscanf(f, "%f", &tapiserie1.dimensiuni[j]);
    }
    fclose(f);
    printf("Tapiseria citita din fisier este:\n");
    afisareTapiserie(tapiserie1);

    //Scriem un vector de tip Tapiserie in fisier
    scrierevectorInFisier("vector.txt", tapiserie, n);

    //Eliberam memoria pentru vectorul de tapiserii
    for(int i=0; i<n; i++) {
        eliberareMemorieTapiserie(&tapiserie[i]);
    }
    free(tapiserie);
    tapiserie= NULL;

    //Eliberam memoria pentru tapiseria citita din fisier
    eliberareMemorieTapiserie(&tapiserie1);

    /*
    //Cream un vector alocat dinamic cu cel putin 5 tapiserii
    int n= 2;
    Tapiserie* tapiserii= (Tapiserie*)malloc(sizeof(Tapiserie) * n);
    for (int i = 0; i < n; i++) {
        tapiserii[i] = citireTapiserie(tapiserii[i]);
    }

    int nrCopiate= 0;
    Tapiserie* tapiserie2= copiereTapiserie(tapiserii, n, &nrCopiate);
    printf("Tapiseriile cu pretul mai mare de 199 sunt:\n");
    afisarevectorTapiserie(tapiserie2, nrCopiate);

    for(int j=0; j< nrCopiate; j++) {
        printf("eliberam memoria pentru tapiseriile copiate\n");
        //eliberam memoria pentru tapiseriile copiate
        eliberareMemorieTapiserie(&tapiserie2[j]);
        printf("\n");
    }

    Tapiserie* tapiserie3= copiereTapiserie2(tapiserii, n, &nrCopiate);
    printf("Tapiseriile cu id-ul par sunt:\n");
    afisarevectorTapiserie(tapiserie3, nrCopiate);

    printf("Tapiseriile initiale sunt:\n");
    afisarevectorTapiserie(tapiserii, n);

    int m;
    printf("Introduceti numarul de tapiserii pe care doriti sa le concatenati: ");
    scanf("%d", &m);
    //Alocam memorie pentru vectorul concatenat
    Tapiserie* vector2= (Tapiserie*)malloc(sizeof(Tapiserie) * m);
    for(int i=0; i<m; i++) {
        vector2[i] = citireTapiserie(vector2[i]);
    }
    int nConcatenat= 0;

    Tapiserie* vectorConcatenat= concateneazaVectori(tapiserii, n, vector2, m, &nConcatenat);
    printf("Tapiseriile concatenate sunt:\n");
    afisarevectorTapiserie(vectorConcatenat, nConcatenat);

    for(int i=0; i<nConcatenat; i++) {
        printf("eliberam memoria pentru tapiseriile concatenate\n");
        //eliberam memoria pentru tapiseriile concatenate
        eliberareMemorieTapiserie(&vectorConcatenat[i]);
    }

    for(int j=0; j< nrCopiate; j++) {
        printf("eliberam memoria pentru tapiseriile copiate\n");
        //eliberam memoria pentru tapiseriile copiate
        eliberareMemorieTapiserie(&tapiserie3[j]);
    }

    for(int i=0; i<n; i++) {
        printf("eliberam memoria pentru tapiseriile initiale\n");
        eliberareMemorieTapiserie(&tapiserii[i]);
    }


    free(tapiserii);
    tapiserii= NULL;
    free(tapiserie2);
    tapiserie2= NULL;
    free(tapiserie3);
    tapiserie3= NULL;
    free(vectorConcatenat);
    vectorConcatenat= NULL;

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
    */

    return 0;
}