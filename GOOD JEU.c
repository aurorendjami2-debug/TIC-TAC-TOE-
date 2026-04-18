#include <stdio.h>


// afficher la grille
void afficherGrille(int M[3][3]){
    int i, j;
    printf("\n---------\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("|");
            if(M[i][j]==1)
                // joueur
                printf("X");
            else if(M[i][j]==2)
            // ordinateur
                printf("O");
            else
                printf(" ");
        }
        printf("|\n---------\n");
    }
}

// vérifier victoire
int testGagnant(int M[3][3]){
    int i;

    // lignes
    for(i=0;i<3;i++){
        if(M[i][0]==M[i][1] && M[i][0]==M[i][2] && M[i][0]!=0)
            return 1;
    }

    // colonnes
    for(i=0;i<3;i++){
        if(M[0][i]==M[1][i] && M[0][i]==M[2][i] && M[0][i]!=0)
            return 1;
    }

    // diagonales
    if(M[0][0]==M[1][1] && M[0][0]==M[2][2] && M[0][0]!=0)
        return 1;

    if(M[0][2]==M[1][1] && M[0][2]==M[2][0] && M[0][2]!=0)
        return 1;

    return 0;
}

// jouer humain
void jouerHumain(int M[3][3]){
    int l, c;

    do{
        printf("Donner la ligne (1-3): ");
        scanf("%d", &l);
    }while(l < 1 || l > 3);

    do{
        printf("Donner la colonne (1-3): ");
        scanf("%d", &c);
    }while(c < 1 || c > 3);

    if(M[l-1][c-1] == 0){
        M[l-1][c-1] = 1;
    } else {
        printf("Case occupee ! Rejoue.\n");
        // rejouer
        jouerHumain(M);
    }
}

// jouer ordinateur
void jouerOrdinateur(int M[3][3]){
    int l, c;

    do{
        l = rand() % 3;
        c = rand() % 3;
    }while(M[l][c] != 0);

    printf("Ordinateur joue : (%d, %d)\n", l+1, c+1);
    M[l][c] = 2;
}

int main(){
    int M[3][3] = {0};
    int tours = 0;



    printf("=== TIC TAC TOE (Joueur vs Ordinateur) ===\n");

    while(tours < 9){
        // joueur
        jouerHumain(M);
        tours++;
        afficherGrille(M);

        if(testGagnant(M)){
            printf("Bravo ! Tu as gagne 🎉\n");
            break;
        }

        if(tours >= 9) break;

        // ordinateur
        jouerOrdinateur(M);
        tours++;
        afficherGrille(M);

        if(testGagnant(M)){
            printf("L'ordinateur a gagne 🤖\n");
            break;
        }
    }

    if(tours == 9 && !testGagnant(M)){
        printf("Match nul !\n");
    }

    return 0;
}
