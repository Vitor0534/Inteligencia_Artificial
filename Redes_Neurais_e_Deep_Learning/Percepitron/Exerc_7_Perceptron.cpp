#include <iostream>
using namespace std;

int tamlinha = 8;
int tamColuna = 3;

int tabela(int i, int j)
{

	int tabela [8] [3] =
	{
		{0, 0, 0},
		{0, 0, 1},
		{0, 1, 0},
		{0, 1, 1},
		{1, 0, 0},
		{1, 0, 1},
		{1, 1, 0},
		{1, 1, 1},
	};
	return tabela[i][j];
}

double atualizaPeso(double w, int a, int x, double erro)
{

	return ( w + (a * x * erro ));

}

int valorEsperado (int i)
{
	return ( tabela(i, 0) + tabela(i, 1) + tabela(i, 2) );
}

int condicao(int y)
{
	if(y > 0)
		return 1;
	return 0;
}


int main(int argc, char** argv)
{

	double w1, w2, w3, w4, wb;
	double y1, y2;
	int e1, e2, a, bias;
	a = bias = 1;
	//incialização tug life (não façam isso em casa crianças)
	y1 = y2 = w1 = w2 = w3 = w4 = wb = 0;


	int epoca = 0;
	int cont = 0;
	int i, j;
	i = j = 0;
	int erros = 0;

	while(epoca < 100000 && erros < 20)
	{

		
		y1 = condicao(  tabela(i, 0) * w1 + tabela(i, 1) * w2 + tabela(i, 2) * w3 + bias * wb ) ;

		cout << "\ni= " << i << "\n\ty1= " << y1 << endl << endl;
		
		//************ atualiza pesos********************
		
		e1 = condicao( valorEsperado(i) ) - y1;
		w1 = atualizaPeso(w1, a, tabela(i, 0), e1);
		w2 = atualizaPeso(w2, a, tabela(i, 1), e1);
		w3 = atualizaPeso(w3, a, tabela(i, 2), e1);

		wb = atualizaPeso(wb, a, bias, e1);
		
		//***********************************************

		i++;


		if( e1 == 0)
		{

			erros++;

		}

		if(i == tamlinha)
		{
			epoca++;
			i = 0;
		}


		cout << "\n*******pesos atuais**********\n";
		cout << "\n\t R1= " << w1 << endl;
		cout << "\n\t R2= " << w2 << endl;
		cout << "\n\t R3= " << w3 << endl;
		
		cout << "\n\n\t erro1= " << e1 << endl << endl;



	}

	cout << "\n*******pesos finais***********\n";
	cout << "\n\t R1= " << w1 << endl;
	cout << "\n\t R2= " << w2 << endl;
	cout << "\n\t R3= " << w3 << endl;
	cout << "\n\t Rf= " << wb << endl;

	return 0;
}
