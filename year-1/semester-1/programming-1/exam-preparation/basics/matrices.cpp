#include <iostream>
#include <iomanip>

using namespace std;

const int Dim = 10;

void read_matrix(float a[][Dim],int m, int n);
float min_matrix (const float a[][Dim],int d1,int d2);
float max_matrix (const float a[][Dim],int d1,int d2);
void sum  (const float a[][Dim],const float b[][Dim],float c[][Dim],int d1,int d2);
void diff (const float a[][Dim],const float b[][Dim],float c[][Dim],int d1,int d2);
void product  (const float a[][Dim],const float b[][Dim],float c[][Dim],int d1,int d2,int d3);
void print_matrix (const float a[][Dim],int d1,int d3);


float A[Dim][Dim] = 
  {
    {1, 2, 3}, {4, 5, 6}
  };
  
float B[Dim][Dim] = 
  {
    {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}
  };    

float C[Dim][Dim];


int main() 
{
  int na,nb,nc,ma,mb,mc;
  cout << "Dimensioni della prima matrice? ";
  cin >> na >> ma;
  cout << "Dimensioni della seconda matrice? ";
  cin >> nb >> mb;
  read_matrix(A,na,ma);
  read_matrix(B,nb,mb);
  if (na==nb&&ma==nb) {
    sum(A,B,C,na,nb);
    cout << "Somma di A e B: " << endl;
    print_matrix(C,na,ma);
    diff(A,B,C,na,nb);
    cout << "Differenza di A e B: " << endl;
    print_matrix(C,na,ma);
  }
  if (ma==nb){
    product(A,B,C,na,ma,mb);
    cout << "Prodotto di A e B: " << endl;
    print_matrix(C,na,mb);
  }
  cout << "Il valore minimo di A e' " 
       << min_matrix(A,na,ma) << endl;
  cout << "Il valore massimo di A e' " 
       << max_matrix(A,na,ma) << endl;
return 0;
}


void read_matrix(float a[][Dim],int m, int n)
{
  cout << "Enter " << n*m << " integers, " << n << " per row:\n";
  for (int i = 0; i < n; i++) {
    cout << "Row " << i << ": ";
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  }
}

float min_matrix (const float a[][Dim],int d1,int d2)
{
   float min = a[0][0];
   int i, j;

   for (i=0; i < d1; i++)
   	for (j=0; j < d2; j++)
	    if (a[i][j] < min) min = a[i][j];
	return min;
}

float max_matrix (const float a[][Dim],int d1,int d2)
{
   float max = a[0][0];
   int i, j;
  for (i=0; i < d1; i++)
   	for (j=0; j < d2; j++)
	    if (a[i][j] > max) 
               max = a[i][j];
	return max;
}

void sum  (const float a[][Dim],
	   const float b[][Dim],
	   float c[][Dim],
           int d1,int d2)
{
    for (int i=0; i < d1 ; i++)
       for (int j=0; j < d2 ; j++) {
       	   c[i][j] += a[i][j]+b[i][j];
	}
}

void diff (const float a[][Dim],
	   const float b[][Dim],
	   float c[][Dim],
           int d1,int d2)
{
    for (int i=0; i < d1 ; i++)
        for (int j=0; j < d2 ; j++) {
       	      c[i][j] += a[i][j]-b[i][j];
	}
}

void product  (const float a[][Dim],
	       const float b[][Dim],
	       float c[][Dim],
               int d1,int d2,int d3)
{
    for (int i=0; i < d1 ; i++)
        for (int j=0; j < d3 ; j++) {
           c[i][j]=0;
           for (int k=0; k < d2; k++)
       	      c[i][j] += a[i][k]*b[k][j];
	}
}

void print_matrix (const float a[][Dim],int d1,int d3)
{
  int i,j;
  
  for (i=0;i<d1;i++){
    for (j=0;j<d3;j++)
      cout << setw(4) << a[i][j];
    cout << endl;
  }
}

void stampa_matrice_ric(int **mat, int R, int C)
{
    stampa_matrice_ric_impl(mat, R, C, 0);
}
void stampa_matrice_ric_impl(int **mat, int R, int C, int i)
{
    if (i < R)
    {
        stampa_matrice_ric_impl_riga(mat[i], C, 0);
        cout << endl;
        stampa_matrice_ric_impl(mat, R, C, i + 1);
    }
}
void stampa_matrice_ric_impl_riga(int *mat, int C, int j)
{
    if (j < C)
    {
        cout << mat[j] << "\t";
        stampa_matrice_ric_impl_riga(mat, C, j + 1);
    }
}

void dealloca_matrice_ric(int **mat, int R, int C)
{
    dealloca_matrice_ric_impl(mat, R, C, 0);
}
void dealloca_matrice_ric_impl(int **mat, int R, int C, int i)
{
    if (i < R)
    {
        delete[] mat[i];
        dealloca_matrice_ric_impl(mat, R, C, i + 1);
    }
    else if (i == R)
    {
        delete[] mat;
    }
}

int **generate_matrix(int R, int C)
{
    int **matrix = new int *[R];
    for (int i = 0; i < R; i++)
    {
        matrix[i] = new int[C];
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    return matrix;
}

int **generate_matrix_ric(int R, int C)
{
    int **matrix = new int *[R];
    generate_matrix_ric_impl(matrix, R, C, 0);
    return matrix;
}

void generate_matrix_ric_impl(int **mat, int R, int C, int i)
{
    if (i < R)
    {
        mat[i] = new int[C];
        generate_matrix_ric_impl(mat, R, C, i + 1);
    }
}

void riempi_matrice_ric(int **mat, int R, int C)
{
    riempi_matrice_ric_impl(mat, R, C, 0);
}
void riempi_matrice_ric_impl(int **mat, int R, int C, int i)
{
    if (i < R)
    {
        riempi_matrice_ric_impl_riga(mat[i], C, 0);
        riempi_matrice_ric_impl(mat, R, C, i + 1);
    }
}
void riempi_matrice_ric_impl_riga(int *mat, int C, int j)
{
    if (j < C)
    {
        mat[j] = rand() % 10;
        riempi_matrice_ric_impl_riga(mat, C, j + 1);
    }
}

void stampa_matrice(int **matrix, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void dealloca_matrice(int **matrix, int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void somma(int **mat1, int **mat2, int R1, int C1, int R2, int C2, int moltplicatore)
{
    if (R1 == R2 && C1 == C2)
    {
        int **mat = new int *[R1];
        for (int i = 0; i < R1; i++)
        {
            mat[i] = new int[C1];
        }
        for (int i = 0; i < R1; i++)
        {
            for (int j = 0; j < C1; j++)
            {
                mat[i][j] = mat1[i][j] + mat2[i][j] * moltplicatore;
            }
        }

        stampa_matrice(mat, R1, C1);
        dealloca_matrice(mat, R1, C1);
    }
    else
    {
        cout << "Le dimensioni sono diverse." << endl;
    }
}

void moltiplicazione(int **mat1, int **mat2, int R1, int C1, int R2, int C2)
{
    int temp;
    if (C1 == R2)
    {
        int **mat = new int *[R1];
        for (int i = 0; i < R1; i++)
        {
            mat[i] = new int[C2];
        }

        for (int i = 0; i < R1; i++)
        {
            for (int j = 0; j < C2; j++)
            {
                temp = 0;
                for (int w = 0; w < C1; w++)
                {
                    // cout << "mat1[" << i << "][" << j+w << "] * mat2[" << w << "][" << j << "]" << endl;
                    // cout.flush();
                    temp += mat1[i][w] * mat2[w][j];
                }
                mat[i][j] = temp;
                // cout << endl;
                // cout.flush();
            }
        }

        stampa_matrice(mat, R1, C2);
        dealloca_matrice(mat, R1, C2);
    }
    else
    {
        cout << "Le dimensioni non sono compatibili." << endl;
    }
}

// TODO: moltplicazione ricorsiva
void moltiplicazione_ric(int **mat1, int **mat2, int R1, int C1, int R2, int C2)
{
    if (C1 == R2)
    {
        int **ris = generate_matrix_ric(R1, C2);
        moltiplicazione_ric_impl(mat1, mat2, ris, R1, C1, R2, C2, 0);
        stampa_matrice_ric(ris, R1, C2);
        dealloca_matrice_ric(ris, R1, C2);
    }
    else
    {
        cout << "Le dimensioni non sono compatibili." << endl;
    }
}

void moltiplicazione_ric_impl(int **mat1, int **mat2, int **ris, int R1, int C1, int R2, int C2, int i)
{
    if (i < R1)
    {
        moltiplicazione_ric_impl_riga(mat1, mat2, ris, R1, C1, R2, C2, i, 0);
        moltiplicazione_ric_impl(mat1, mat2, ris, R1, C1, R2, C2, i + 1);
    }
}

void moltiplicazione_ric_impl_riga(int **mat1, int **mat2, int **ris, int R1, int C1, int R2, int C2, int i, int j)
{
    if (j < C2)
    {
        ris[i][j] = moltiplicazione_ric_impl_elemento(mat1, mat2, C1, 0, 0, i, j);
        moltiplicazione_ric_impl_riga(mat1, mat2, ris, R1, C1, R2, C2, i, j + 1);
    }
}

int moltiplicazione_ric_impl_elemento(int **mat1, int **mat2, int C1, int w, int somma, int i, int j)
{
    if (w < C1)
    {
        somma += mat1[i][w] * mat2[w][j];
        moltiplicazione_ric_impl_elemento(mat1, mat2, C1, w + 1, somma, i, j);
    }
    else if (w == C1)
    {
        return somma;
    }
}

void somma_ric(int **mat1, int **mat2, int R1, int C1, int R2, int C2, int moltplicatore)
{
    if (R1 == R2 && C1 == C2)
    {
        int **mat = new int *[R1];
        for (int i = 0; i < R1; i++)
        {
            mat[i] = new int[C1];
        }

        somma_ric_impl(mat1, mat2, mat, R1, C1, 1, 0);

        stampa_matrice(mat, R1, C1);
        dealloca_matrice(mat, R1, C1);
    }
    else
    {
        cout << "Le dimensioni sono diverse." << endl;
    }
}

void somma_ric_impl(int **mat1, int **mat2, int **ris, int R, int C, int molt, int i)
{
    if (i < R)
    {
        somma_ric_colonna(mat1[i], mat2[i], ris[i], C, 0);
        somma_ric_impl(mat1, mat2, ris, R, C, molt, i + 1);
    }
}

void somma_ric_colonna(int mat1[], int mat2[], int ris[], int C, int j)
{
    if (j < C)
    {
        ris[j] = mat1[j] + mat2[j];
        somma_ric_colonna(mat1, mat2, ris, C, j + 1);
    }
}

int **alloca_matrice(int R, int C)
{
    int **matrix = new int *[R];
    for (int i = 0; i < R; i++)
    {
        matrix[i] = new int[C];
    }

    return matrix;
}

int det(int** m, int car, int R)
{
    int determinante = 0;
    // Cardinalità uno
    if (car == 1)
        determinante = m[0][0];
    // Cardinalità due
    if (car == 2)
        determinante = m[1][1] * m[0][0] - m[0][1] * m[1][0];
    // Cardinalità > 2
    else
    {
        for (int row = 0; row < car; row++)
        {
            int **sub_m = alloca_matrice(R, R);
            // Sottomatrice di ordine car-1
            for (int i = 0; i < car - 1; i++)
            {
                for (int j = 0; j < car - 1; j++)
                {
                    // condition ? result_if_true : result_if_false
                    int sub_row = (i < row ? i : i + 1);
                    int sub_col = j + 1;
                    sub_m[i][j] = m[sub_row][sub_col];
                }
            }
            // Segno sottomatrice + per pari, - per dispari
            if (row % 2 == 0)
                determinante += m[row][0] * det(sub_m, car - 1, R);
            else
                determinante -= m[row][0] * det(sub_m, car - 1, R);
            dealloca_matrice(sub_m, R, R);
        }
    }
    return determinante;
}