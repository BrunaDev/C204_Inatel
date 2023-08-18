#include<iostream>
#include<iomanip>
#include <cstring>

using namespace std;


struct cadastro
{
	char nome[20];
	int idade;
	int matricula;

};

// complexidade o(n)
void buscandoMatricula(int mat, int n, cadastro aluno[])
{
	int j = 0; //caso j se mantenha em 0, a matricula não foi encontrada
	for(int i=0; i<n; i++)
	 { 
		//se mat for igual a matricula que eu pesquisar vai aparecer o cadastro do aluno
	 	if(mat == aluno[i].matricula)
		 {
		 	cout<< "Nome do aluno: "<< aluno[i].nome << endl;
		 	cout<< "Idade do aluno: "<< aluno[i].idade <<endl;
		 	cout<< "Matricula do aluno: "<< aluno[i].matricula <<endl;

			j++;
		 }
	 }
	 if (j == 0)
	 {
		cout<<"Matricula nao encontrada"<<endl;
		// Pergunta novamente pela matrícula
		cout << "Digite a matricula do aluno a ser buscado: ";
		cin >> mat;
		buscandoMatricula(mat, n, aluno);
	 }
}

// complexidade o(n)
// função que vai retornar as idades 
int buscaIdade(int id, int n, cadastro aluno[])
	{
    	int count = 0;

    	for (int i = 0; i < n; i++)
    	{
        	if (id >= aluno[i].idade)
        	{
            	count++;
        	}
    	}

    	return count;
	}

void buscaPorNome(const char nome[], int n, cadastro aluno[])
{
    bool alunoEncontrado = false; //retorna true se encontrado e false se n�o

    for (int i = 0; i < n; i++)
    {
        if (strcmp(nome, aluno[i].nome) == 0)
        {
            cout << "Nome do aluno: " << aluno[i].nome << endl;
            cout << "Idade do aluno: " << aluno[i].idade << endl;
            cout << "Matricula do aluno: " << aluno[i].matricula << endl;

            alunoEncontrado = true;
            break;
        }
    }
    
    if (!alunoEncontrado)
    {
        cout << "Aluno nao encontrado." << endl;
        // Pergunta novamente pelo nome
        char novoNome[20];
        cout << "Digite o nome do aluno a ser buscado: ";
        cin.ignore();
        cin.getline(novoNome, 20);
        buscaPorNome(novoNome, n, aluno);
    }
}

int main ()
{
	int i; // contador    
	int n; // numero de cadastro
	int mat; // variavel que vai ser usada para achar o cadastro dos alunos 
	int id;
	int tipoBusca; // variavel que sera usada para diferenviar a busca de aluno

  struct cadastro aluno[10];

  cout<< "Digite a quantidade de alunos a serem cadastrados: ";
  cin>> n;
  
  cout << "\n";
  cout << "--------x--------\n";

  for(i=0;i<n;i++)
  {
  	cout<< "Digite o nome do aluno(a): ";
  	cin.ignore();
  	cin.getline(aluno[i].nome,20); 

    cout<< "Digite a idade do aluno(a): ";
    cin >> aluno[i].idade;

    cout<< "Digite o numero da matricula do aluno(a): ";
    cin >> aluno[i].matricula;
    cout<<" "<< endl;
    cin.ignore();
  }

  cout << "\n";
  cout << "--------x--------\n";

    do {
		cout << "Como deseja procurar o aluno? Digite 1 para buscar por nome e 2 para buscar por matricula.\n";
	    cin >> tipoBusca;
	
		if (tipoBusca == 1)
		{
    		cin.ignore();
    		char nomeBusca[20];
    		cout << "Digite o nome do aluno a ser buscado: ";
    		cin.getline(nomeBusca, 20);
    		buscaPorNome(nomeBusca, n, aluno);
    		cout << " " << endl;
		}

		else if (tipoBusca == 2)
		{
		   	cout << "Digite a matricula do aluno a ser buscado: ";
            cin>> mat;
            buscandoMatricula(mat,n,aluno);
            cout<< " "<<endl;
    	   	
		}
		else {
		    cout << "Tipo de busca invalido!" << endl;
		}
	} while (tipoBusca < 1 || tipoBusca > 2);

    cout<<" "<<endl;

    cout << "Qual idade deseja pesquisar? O retorno sera menor ou igual: ";
	cin >> id;
	

	cout << "Quantidade de alunos com idade igual ou menor: " << buscaIdade(id, n, aluno) << endl;

	cout << " " << endl;


	return 0;
}