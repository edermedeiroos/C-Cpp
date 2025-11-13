#include <iostream>
using namespace std;

// Exercício 3

int vetor[5] = {5, 1, 4, 2, 8};

// Primeira passagem

int vetor[5] = {1, 5, 4, 2, 8};

// Segunda passagem

int vetor[5] = {1, 2, 4, 5, 8};

// O algoritmo fez ao todo 10 comparações (4 + 3 + 2 + 1)

// O algorítmo não é estável pois pode quebrar a ordem relativa de elementos do mesmo valor, ja que faz trocas de longa distância.

// Exercício 4

// O algoritmo sempre faz o mesmo número de comparações pois ele percorre o array inteiro para confirmar que aquele é o menor valor absoluto.
