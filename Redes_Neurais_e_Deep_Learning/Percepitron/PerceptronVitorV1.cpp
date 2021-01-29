#include <iostream>
using namespace std;


int tabela(int i, int j)
{

	int tabela [4] [2] = { {1, 1} , {1, 0} , {0, 1} , {0, 0} };
	return tabela[i][j];
}

double atualizaPeso(double w, int a, int x, double erro)
{

	return ( w + (a * x * erro ));

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
		//profissão
		y1 = condicao(  tabela(i, 0) * w1 + tabela(i, 1) * w2 + bias * wb );

		//sexo
		y2 = condicao( tabela(i, 0) * w3 + tabela(i, 1) * w4  );



		cout << "\ni= " << i << "\n\ty1= " << y1 << "\n\ty2= " << y2 << endl << endl;

		if(i == 0)
		{
			e1 = 1 - y1;
			e2 = 0 - y2;
			w1 = atualizaPeso(w1, a, tabela(i, 0), e1);
			w2 = atualizaPeso(w2, a, tabela(i, 1), e1);
			w3 = atualizaPeso(w3, a, tabela(i, 0), e2);
			w4 = atualizaPeso(w4, a, tabela(i, 1), e2);

			wb = atualizaPeso(wb, a, bias, e1);
		}
		else
		{
			if(i == 1)
			{
				e1 = 0 - y1;
				e2 = 0 - y2;
				w1 = atualizaPeso(w1, a, tabela(i, 0), e1);
				w2 = atualizaPeso(w2, a, tabela(i, 1), e1);
				w3 = atualizaPeso(w3, a, tabela(i, 0), e2);
				w4 = atualizaPeso(w4, a, tabela(i, 1), e2);

				wb = atualizaPeso(wb, a, bias, e1);
			}
			else
			{
				if(i == 2)
				{
					e1 = 0 - y1;
					e2 = 1 - y2;
					w1 = atualizaPeso(w1, a, tabela(i, 0), e1);
					w2 = atualizaPeso(w2, a, tabela(i, 1), e1);
					w3 = atualizaPeso(w3, a, tabela(i, 0), e2);
					w4 = atualizaPeso(w4, a, tabela(i, 1), e2);

					wb = atualizaPeso(wb, a, bias, e1);
				}
				else
				{
					if(i == 3)
					{
						e1 = 0 - y1;
						e2 = 0 - y2;
						w1 = atualizaPeso(w1, a, tabela(i, 0), e1);
						w2 = atualizaPeso(w2, a, tabela(i, 1), e1);
						w3 = atualizaPeso(w3, a, tabela(i, 0), e2);
						w4 = atualizaPeso(w4, a, tabela(i, 1), e2);

						wb = atualizaPeso(wb, a, bias, e1);
					}
				}
			}
		}
		i++;
        

		if( e1==0 && e2 == 0)
		{
			
			erros++;

		}

		if(i == 3)
		{
			epoca++;
			i = 0;
		}


		cout << "\n*******pesos atuais**********\n";
		cout << "\n\t w1= " << w1 << endl;
		cout << "\n\t w2= " << w2 << endl;
		cout << "\n\t w3= " << w3 << endl;
		cout << "\n\t w4= " << w4 << endl << endl;
		cout << "\n\n\t erro1= " << e1 << endl << endl;
		cout << "\n\n\t erro2= " << e2 << endl << endl;
		

	}

	cout << "\n*******pesos finais***********\n";
	cout << "\n\t w1= " << w1 << endl;
	cout << "\n\t w2= " << w2 << endl;
	cout << "\n\t w3= " << w3 << endl;
	cout << "\n\t w4= " << w4 << endl;

	return 0;
}
