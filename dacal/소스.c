#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int coefficient;
    int exponent;
} Term;


Term parseTerm(char* termStr) {
    Term term;
    char* coefficientStr = strtok(termStr, "x");
    char* exponentStr = strtok(NULL, "x");
    term.coefficient = atoi(coefficientStr);
    term.exponent = atoi(exponentStr);
    return term;
}


void calculateSum(char* poly1, char* poly2) {
    int maxSize = strlen(poly1) + strlen(poly2); 
    char* sumPoly = (char*)malloc(maxSize * sizeof(char));
    strcpy(sumPoly, ""); 

  
    char* term = strtok(poly1, "+");
    while (term != NULL) {
        Term t = parseTerm(term);
        char termStr[20];
        sprintf(termStr, "%dx%d+", t.coefficient, t.exponent);
        strcat(sumPoly, termStr);
        term = strtok(NULL, "+");
    }

  
    term = strtok(poly2, "+");
    while (term != NULL) {
        Term t = parseTerm(term);
        char termStr[20];
        sprintf(termStr, "%dx%d+", t.coefficient, t.exponent);
        strcat(sumPoly, termStr);
        term = strtok(NULL, "+");
    }


    sumPoly[strlen(sumPoly) - 1] = '\0';

    printf("Sum of the polynomials: %s\n", sumPoly);

    free(sumPoly);
}

int main() {
    char poly1[100];
    char poly2[100];

    printf("Enter polynomial 1: ");
    fgets(poly1, sizeof(poly1), stdin);
    poly1[strcspn(poly1, "\n")] = '\0';

    printf("Enter polynomial 2: ");
    fgets(poly2, sizeof(poly2), stdin);
    poly2[strcspn(poly2, "\n")] = '\0';

    calculateSum(poly1, poly2);

    return 0;
}

