
#include <iostream>

using namespace std;

int wybor=0;
int m,n;
int m1, n1, m2,n2;
void wypisywanie(int **C, int m, int n)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++){
			cout << C[i][j] << " ";
		}
		cout << endl;
	
	}
	
}

int **utworz(int m, int n)
{
	
		int **macierz;
		macierz = new int *[m];
		for(int j=0; j<m; j++)
		{
			macierz[j]= new int[n];
			
		}
		return macierz;

	}
void wypelnianie(int **macierz, int m, int n)
{	
	cout << "\nWypelniasz Macierz"<< endl;
	cout << "------------------"<< endl;
	for(int a=0; a <m; a++)
	{
		for(int b=0; b<n; b++)
		{
			
			cout << "Podaj macierz ["<< a << "][" << b<< "]"<< endl;
			cin >> macierz[a][b];
			
		}
	}

}

int **dod(int **A, int **B, int m,int n)
{
	int **C=utworz(m,n);
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			C[i][j]=A[i][j] + B[i][j];
		}
     }
	
	return C;
}

void dodawanie ()
{
	//n liczba wierszy m kolumn
	cout << "podaj ilosc wierszy"<< endl;
	cin >> n;
	cout << endl;
	cout << "podaj ilosc kolumn"<< endl;
	cin >> m;
	cout << endl;
	int **A=utworz(m,n);
	int **B=utworz(m,n);
	wypelnianie(A, m, n);
	wypelnianie(B, m, n);
	int **C=utworz(m,n);
	C=dod(A,B,m,n);
	wypisywanie(C, m, n);
	
	
}
int **odj(int **A, int **B, int m,int n)
{
	int **C=utworz(m,n);
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n; j++)
		{
			C[i][j]=A[i][j] - B[i][j];
		}
     }
	
	return C;
}

void odejmowanie()
{
	//n liczba wierszy m kolumn
	cout << "podaj ilosc wierszy"<< endl;
	cin >> n;
	cout << endl;
	cout << "podaj ilosc kolumn"<< endl;
	cin >> m;
	cout << endl;
	int **A=utworz(m,n);
	int **B=utworz(m,n);
	wypelnianie(A, m, n);
	wypelnianie(B, m, n);
	int **C=utworz(m,n);
	C=odj(A,B,m,n);
	wypisywanie(C,m,n);
	
}

int **multiplication(int **A, int **B, int m1,int n2, int n1)
{	

	cout << m1<< "m1 n2" <<n2<<endl;
	int **C=utworz(m1,n2);
	
	for(int i = 0; i < m1; i++){
		for(int j = 0; j < n2; j++){
			for(int k = 0; k < n1; k++){
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	
	return C;
}



void mnozenie()
{
	//n liczba wierszy m kolumn
	do{
	cout << "\npodaj ilosc wierszy 1 macierzy"<< endl;
	cin >> n1;
	cout << endl;
	cout << "\npodaj ilosc kolumn 1 macierzy"<< endl;
	cin >> m1;	
	cout << endl;
	cout << "\npodaj ilosc wierszy 2 macierzy"<< endl;
	cin >> n2;
	cout << endl;
	cout << "\npodaj ilosc kolumn 2 macierzy"<< endl;
	cin >> m2;	
	cout << endl;
	if(m1 != n2)
		cout << "Zla ilosc wierszy i kolumn";
	}
	while(m1 != n2);
	int **A=utworz(m1,n1);
	int **B=utworz(m2,n2);
	wypelnianie(A, m1, n1);
	wypelnianie(B, m2, n2);
	
	int **C=utworz(m1,n2);
	C=multiplication(A,B,m1,n2, n1);
	wypisywanie(C, m1, n2);
	//m1 n2
	
}

int **nmbMultip(int **A, int m1,int n2, int liczba)
{	
	

	int **C=utworz(m1,n2);
	for(int i=0; i< m1; i++)
	{
		for(int j=0; j< n2; j++)
		{
		
			C[i][j]=A[i][j]*liczba;	
		
		}
	}
	
	return C;
}


void numberMultiplication()
{
	//n liczba wierszy m kolumn

	cout << "\npodaj ilosc wierszy 1 macierzy"<< endl;
	cin >> n1;
	cout << endl;
	cout << "\npodaj ilosc kolumn 1 macierzy"<< endl;
	cin >> m1;	
	cout << endl;
	int liczba=0;
	
	int **A=utworz(m1,n1);

	wypelnianie(A, m1, n1);
	cout << "Podaj liczbe przez ktora ma byc pomnozone"<< endl;
	cin >> liczba;
	cout << endl;
	
	int **C=utworz(m1,n1);
	C=nmbMultip(A,m1,n1, liczba);
	wypisywanie(C, m1, n1);
	//m1 n2
	
}


//WK wiersz kolumn ;; *A macierz

int wyznacz(int **A,int w, int *wierszkolumn,int n)
{
	double suma;	
	int i,j,k,mnoznik, *nowywektorkolumn;
  

  if(n==1) //rekurencja

    return A[w][wierszkolumn[0]];                        

  else
  {
    nowywektorkolumn = new int[n - 1]; //nowy wektor kolumn
    suma=0;                             
    mnoznik=1;   // mnoznik na przemienno +/-                               
    for(i=0;i<n;i++)                   
    {
      k=0;                                   
      for(j=0; j<n-1; j++)              
      {
        if(k == i) {
			k++;
			}                        
        nowywektorkolumn[j] = wierszkolumn[k++];                       
      }

      suma= suma+(mnoznik * A[w][wierszkolumn[i]] * wyznacz(A, w+1,nowywektorkolumn, n-1));

      mnoznik=-mnoznik; //zmiana znaku mnoznika i dalej lecimy do kolejnej 

    }

   

    return suma; 

  }
	
}


void wyznacznik()
{
	
	cout << "\npodaj ilosc kolumn i wierszy macierzy np 3"<< endl;
	cin >> n1;
		
	cout << endl;
	int determin;
	int **A=utworz(n1,n1);
	wypelnianie(A, n1,n1);
	int *wierszkolumn = new int[n1];//wiersz kolumn tworzenie 

	for(int i = 0; i < n1; i++){                 
		wierszkolumn[i] = i; //wiersz kol
	}

	determin=wyznacz(A,0,wierszkolumn,n1);
	cout << "\nWyznacznik tej macierzy: " << determin<<endl;
}

int main()
{
	cout << "------------------"<< endl;
	cout << "Podaj swoj wybor:"<< endl;
	cout << "1-Dodawanie"<< endl;
	cout << "2-Odejmowanie"<< endl;
	cout << "3-Mnozenie"<< endl;
	cout << "4-Mnozenie przez liczbe"<< endl;
	cout << "5-wyznacznik"<< endl;	
	cout << "------------------"<< endl;
	cout << "Twoj Wybor: ";
	cin >> wybor;
	cout << "\n";
	switch(wybor){
		case 1:
			cout << "Wybrales Dodawanie"<< endl;
			dodawanie();
			break;
		case 2:
			cout << "Wybrales odejmowanie" << endl;
			odejmowanie();
			break;
		case 3:
			cout << "Wybrales mnozenie"<<endl;
			mnozenie();
			break;
		case 4:
			cout << "wybrales mnozenie przez liczbe"<<endl;
			numberMultiplication();
		case 5:
			cout<< "wybrales wyznacznik"<<endl;
			wyznacznik();
			
			
		default:
			cout << "Wybierz pomiedzy 1-4"<< endl;
			break;
	}	
			
	
}


