#include <cstdlib>
#include <iostream>
#include <time.h>  



using namespace std;


void insertionSort(int a[], int n);
void intercambia(int *xp, int *yp);
void selectionSort(int aa[], int n) ;
void merge(int a[], int l, int m, int r) ;
void mergeSort(int a[], int l, int r) ;

void MejorCasoInsertion(int n);
void PeorCasoInsertion(int n);
void CasoPromedioInsertion(int n);

void MejorCasoSelection(int n);
void PeorCasoSelection(int n);
void CasoPromedioSelection(int n);

void MejorCasoMerge(int n);
void PeorCasoMerge(int n);
void CasoPromedioMerge(int n);




int main (){
	int enes[10] ={10000,30000,40000,50000,60000,70000,80000,90000,100000,200000 };

	srand(time(NULL));

	

	cout << "ALGORITMO INSERTION-SORT MEJOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		MejorCasoInsertion(enes[i]);
		

	}
	cout << "ALGORITMO INSERTION-SORT PEOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		PeorCasoInsertion(enes[i]);
		

	}
	cout << "ALGORITMO INSERTION-SORT CASO PROMEDIO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		CasoPromedioInsertion(enes[i]);
		

	}

	
	cout << "ALGORITMO SELECTION-SORT MEJOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		MejorCasoSelection(enes[i]);
		

	}
	cout << "ALGORITMO SELECTION-SORT PEOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		PeorCasoSelection(enes[i]);
		

	}
	cout << "ALGORITMO SELECTION-SORT CASO PROMEDIO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		CasoPromedioSelection(enes[i]);
		

	}
	
	cout << "ALGORITMO MERGE-SORT MEJOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		MejorCasoMerge(enes[i]);
		

	}
	cout << "ALGORITMO MERGE-SORT PEOR CASO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		PeorCasoMerge(enes[i]);
		

	}

	cout << "ALGORITMO MERGE-SORT CASO PROMEDIO"<<endl<<endl;
	for(int i = 0 ; i <10 ;++i){

		
		CasoPromedioMerge(enes[i]);
		

	}
	return 0;
}



void insertionSort(int a[], int n) 
{ 
    int i, x, j; 
    for (i = 1; i < n; i++) { 
        x = a[i]; 
        j = i - 1; 
  
        
        while (j >= 0 && a[j] > x) { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = x; 
    } 

  

} 
void intercambia(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

//Algoritmo tiene O(nˆ2)
void selectionSort(int a[], int n) 
{ 
    int i, j, min_idx; 
  

    for (i = 0; i < n-1; i++) 
    { 
 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (a[j] < a[min_idx]) 
            min_idx = j; 
  

        intercambia(&a[min_idx], &a[i]); 
    } 
} 

void merge(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  

    int L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int a[], int l, int r) 
{ 
    if (l < r) 
    { 


        int m = l+(r-l)/2; 
  

        mergeSort(a, l, m); 
        mergeSort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 
}


void MejorCasoInsertion(int n)
{

	int a[n];

	//clock_t t; 
	clock_t start, end;
	double cpu_time_used;
     
    

	for (int i =0 ; i < n ; i++){
		a[i]=i;
	}
	 start = clock();

	insertionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<<  cpu_time_used << " segundos en el mejor de los casos"<<endl<<endl;


}
void PeorCasoInsertion(int n)
{

	int a[n];

	//clock_t t; 
	clock_t start, end;
	double cpu_time_used;


	for (int i =0 ; i < n ; i++){
		a[i]=n-i;
	}

	start = clock();

	insertionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<<  cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


}
void CasoPromedioInsertion(int n)
{

	int a[n];

	clock_t start, end;
	double cpu_time_used;
	clock_t t; 
   

	for (int i =0 ; i < n ; i++){
		a[i]=rand()%n;
	}

	start = clock();

	insertionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<<cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


} 
void MejorCasoSelection(int n)

{

	int a[n];

	clock_t start, end;
	double cpu_time_used;
     
   

	for (int i =0 ; i < n ; i++){
		a[i]=i;
	}
	start = clock();

	selectionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo selection Sort para n = " << n << " tarda "<< cpu_time_used << " segundos en el mejor de los casos"<<endl<<endl;


}

void PeorCasoSelection(int n)
{

	int a[n];

	clock_t start, end;
	double cpu_time_used;

   

	for (int i =0 ; i < n ; i++){
		a[i]=n-i;
	}

	start = clock();

	selectionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<<cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


}
void CasoPromedioSelection(int n)
{

	int a[n];

	clock_t start, end;
	double cpu_time_used;
     
   

	for (int i =0 ; i < n ; i++){
		a[i]=rand()%n;
	}

	start = clock();

	selectionSort(a,n);
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<<  cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


} 
void MejorCasoMerge(int n)

{

	int a[n];

	clock_t start, end;
	double cpu_time_used;
     
   

	for (int i =0 ; i < n ; i++){
		a[i]=i;
	}
	start = clock();

	mergeSort(a,0,n-1);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Merge Sort para n = " << n << " tarda "<< cpu_time_used << " segundos en el mejor de los casos"<<endl<<endl;


}

void PeorCasoMerge(int n)
{

	int a[n];

	clock_t start, end;
	double cpu_time_used;
     
   

	for (int i =0 ; i < n ; i++){
		a[i]=n-i;
	}


	start = clock();

	mergeSort(a,0,n-1);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo merge Sort para n = " << n << " tarda "<<  cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


}

void CasoPromedioMerge(int n)
{

	int a[n];

	clock_t start, end;
	double cpu_time_used;

   

	for (int i =0 ; i < n ; i++){
		a[i]=rand()%n;
	}

	start = clock();

	mergeSort(a,0,n-1);

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	cout << "Algoritmo Insertion Sort para n = " << n << " tarda "<< cpu_time_used << " segundos en el peor de los casos"<<endl<<endl;


} 


