#pragma once

typedef struct
{
	int val;
	int parent;
}cell;

int lis_r(int arr[], int n);
cell lis(int arr[], int n);
void printLIS(int parent, int * arr);