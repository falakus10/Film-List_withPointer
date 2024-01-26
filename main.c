#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum filmGenre {
    drama = 1, horror, thriller
} Genre;

typedef struct cinemaFilm {
    char filmName[100];
    int productionYear;
    float imdbRating;
    Genre filmGenre;
} Film;

void printFilmGenre(Genre filmGenre);
void printFilm(Film *ptrFilm, int arraySize);

int main() {
    Film *ptrFilm = (Film *)malloc(3 * sizeof(Film));

    strcpy((ptrFilm)->filmName, "Titanic");
    (ptrFilm)->productionYear = 1997;
    (ptrFilm)->imdbRating = 7.8;
    (ptrFilm)->filmGenre = drama;

    strcpy((ptrFilm + 1)->filmName, "Saw");
    (ptrFilm + 1)->productionYear = 2004;
    (ptrFilm + 1)->imdbRating = 7.6;
    (ptrFilm + 1)->filmGenre = horror;

    strcpy((ptrFilm + 2)->filmName, "Rebecca");
    (ptrFilm + 2)->productionYear = 1940;
    (ptrFilm + 2)->imdbRating = 8.1;
    (ptrFilm + 2)->filmGenre = thriller;

    printFilm(ptrFilm, 3);
    free(ptrFilm);

    return 0;
}

void printFilmGenre(Genre filmGenre) {
    switch (filmGenre) {
        case drama:
            printf("DRAMA");
            break;
        case horror:
            printf("HORROR");
            break;
        case thriller:
            printf("THRILLER");
            break;
        default:
            printf("ERROR!");
            break;
    }
}

void printFilm(Film *ptrFilm, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("Name: %s\n", (ptrFilm + i)->filmName);
        printf("Production Year: %d\n", (ptrFilm + i)->productionYear);
        printf("IMDB Rating: %.1f\n", (ptrFilm + i)->imdbRating);
        printf("Film Genre: ");
        printFilmGenre((ptrFilm + i)->filmGenre);
        printf("\n-----------------\n");
    }
}