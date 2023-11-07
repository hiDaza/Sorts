#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define tam1 1000
#define tam2 5000
#define tam3 10000
#define tam4 15000
#define tam5 100000
#define tam6 500000

int *randomVet();
int *crescVet(int tam);
int *decrescVet(int tam);

void bubleSort(int vet[], int n);
void bubleSortMelhorado(int vet[], int n);
void barraDeProgresso(void *arg);
// void quickSortIniTime(int VET[], int Inicio,int Ifinal)
// void quickSortIni(int X[],int iInicio, int iFinal);
// void quickSortMeio(int VET[],int Iinicio,int Ifinal)
void insertionSort(int VET[], int tam);
void shellSort(int vet[], int n, int incrementos[], int numinc);
void selectionSort(int vet[], int tam);
void heapSort(int vetor[], int tam);
void mergeSort(int *vet, int ini, int fim);
void medirTempoOrdenacao(void (*funcaoOrdenacao)(int[], int), int vetor[], int tamanho, const char *nomeSort);

#endif // SORTS_H_INCLUDED
