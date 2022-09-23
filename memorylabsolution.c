#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct author_t{
    char name[20];
    int birthYear;
    int publishings;
};

struct book_t {
    char name[20];
    int year;
    int numAuthors;
    struct author_t * authors;
};

int main() {
    int nbooks;
    scanf("%d\n", &nbooks);

    struct book_t *books = (struct book_t *)calloc(nbooks, sizeof(struct book_t));

    for (int ib = 0; ib <nbooks; ib++) {
        scanf("%s %d %d", books[ib].name, &books[ib].year, &books[ib].numAuthors);

        struct author_t *authors = (struct author_t*)calloc(books[ib].numAuthors, sizeof(struct author_t));
        books[ib].authors = authors;

        for (int ia = 0; ia< books[ib].numAuthors; ia++) {
            scanf("%s %d %d", authors[ia].name, &authors[ia].birthYear, &authors[ia].publishings);
        }
    }

    for (int ib = 0; ib<nbooks; ib++) {
        printf("%s %d %d\n", books[ib].name, books[ib].year, books[ib].numAuthors);
        for (int ia = 0; ia<books[ib].numAuthors; ia++) {
            printf("%s %d %d", books[ib].authors[ia].name, books[ib].authors[ia].birthYear, books[ib].authors[ia].publishings);
        }
    }

    for (int ib = 0; ib <nbooks; ib++) {
        free(books[ib].authors);
        books[ib].authors = NULL;
    }

    return 0;

}