#include <stdio.h>
#include <stdlib.h>

void menu(int *v, int n)
{
    int escolha,x,bin;
    printf("Faca suas escolhas :\n");
    printf("Crescentes : Bubble com aritimetica = 1 / Bubble sem aritimetica = 2\n");
    printf("             Insertion com aritimetica = 3 / Insertion sem aritimetica = 4\n");
    printf("             Selection sem aritimetica = 5 / Selection com aritimetica = 6\n\n");
    printf("Decrescentes : Bubble com aritimetica = 7 / Bubble sem aritimetica = 8\n");
    printf("             Insertion com aritimetica = 9 / Insertion sem aritimetica = 10\n");
    printf("             Selection sem aritimetica = 11 / Selection com aritimetica = 12\n");
    printf("\n             Busca Sequencial = 13\n");
    scanf("%d", &escolha);

    switch(escolha){

        case 1:
            bubble_crescente_art(v,n);
            break;
        case 2:
            bubble_crescente(v,n);
            break;
        case 3:
            insertion_crescente_art(v,n);
            break;
        case 4:
            insertion_crescente(v,n);
            break;
        case 5:
            selection_crescente(v,n);
            break;
        case 6:
            selection_crescente_art(v,n);
            break;
        case 7:
                bubble_decrescente_art(v,n);
            break;
        case 8:
                bubble_decrescente(v,n);
            break;
        case 9:
                insertion_decrescente_art(v,n);
            break;
        case 10:
                insertion_decrescente(v,n);
            break;
        case 11:
                selection_decrescente(v,n);
            break;
        case 12:
                selection_decrescente_art(v,n);
            break;
        case 13:
            printf("Qual elemento deseja encontrar ?\n");
            scanf("%d", &x);
                if (buscaSeq(v,n,x))
                    printf("O elemento %d esta no vetor!\n", x);
                else
                    printf("O elemento %d NAO esta no vetor!\n", x);
            break;
        default:
            printf("Valor indisponivel!\n\n");
            main();
            break;
    }
    //  Vetor ordenado crescente
    if ((escolha>=1)&&(escolha<7))
    {
        printf("Deseja fazer uma busca binaria ? sim = 1 / nao = 2\n");
        scanf("%d", &bin);
        if (bin==1)
        {
            printf("Qual elemento deseja encontrar ?\n");
            scanf("%d", &x);
                    if (buscaBin_cresc(v,n,x))
                        printf("O elemento %d esta no vetor!\n", x);
                    else
                        printf("O elemento %d NAO esta no vetor!\n", x);
        }
        else if (bin==2)
        {
            return 0;
        }
        else {
            printf("Valor indisponivel");
            return 0;
        }
    }
    // Vetor ordenado decrescente

    if ((escolha>=7)&&(escolha<13))
    {
        printf("Deseja fazer uma busca binaria ? sim = 1 / nao = 2\n");
        scanf("%d", &bin);
        if (bin==1)
        {
            printf("Qual elemento deseja encontrar ?\n");
            scanf("%d", &x);
                    if (buscaBin_decresc(v,n,x))
                        printf("O elemento %d esta no vetor!\n", x);
                    else
                        printf("O elemento %d NAO esta no vetor!\n", x);
        }
        else if (bin==2)
        {
            return 0;
        }
        else {
            printf("Valor indisponivel");
            return 0;
        }
    }
}

void aloc(int *v,int n)
{
    v=malloc(n*sizeof(int));
}

void testeMALLOC(int *v)
{
    if(v==NULL){
		printf("Memoria Insuficiente!");
		exit (1);
	}
}

void ler(int *v, int n)
{
    int i;
    aloc(v,n);
    testeMALLOC(v);
    printf("Faça a leitura do vetor : \n");
    for (i=0;i<n;i++)
    {
        scanf("%d", (v+i));
    }
}

void print(int *v, int n)
{
    int i;
    printf("Seu vetor: ");
    for (i=0;i<n;i++)
    {
        printf("%d\t", *(v+i));
    }
    printf("\n");
}

int bubble_crescente_art(int *v, int n)
{

    int i,j,aux;
    for (i=0;i<(n-1);i++)
    {
        for (j=0;j<(n-i-1);j++)
        {
            if (*(v+j)>*(v+j+1))
            {
                aux=*(v+j);
                *(v+j)=*(v+j+1);
                *(v+j+1)=aux;
            }
        }
    }

    return 0;
}

int bubble_crescente(int v[], int n)
{
    int i,j,aux;
    for (i=0;i<(n-1);i++)
    {
        for (j=0;j<(n-i-1);j++)
        {
            if (v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }

    return 0;
}

int bubble_decrescente_art(int *v, int n)
{

    int i,j,aux;
    for (i=0;i<(n-1);i++)
    {
        for (j=0;j<(n-i-1);j++)
        {
            if (*(v+j)<*(v+j+1))
            {
                aux=*(v+j);
                *(v+j)=*(v+j+1);
                *(v+j+1)=aux;
            }
        }
    }

    return 0;
}

int bubble_decrescente(int v[], int n)
{
    int i,j,aux;
    for (i=0;i<(n-1);i++)
    {
        for (j=0;j<(n-i-1);j++)
        {
            if (v[j]<v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }

    return 0;
}

void insertion_crescente(int v[], int n )
{
    int i,j,aux;
    for (i=1;i<n;i++)
    {
        aux=v[i];
        j=i-1;
        while((j>=0)&&(v[j]>aux))
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

void insertion_crescente_art(int *v, int n )
{
    int i,j,aux;
    for (i=1;i<n;i++)
    {
        aux=*(v+i);
        j=i-1;
        while((j>=0)&&(*(v+j)>aux))
        {
            *(v+j+1)=*(v+j);
            j--;
        }
        *(v+j+1)=aux;
    }
}
void insertion_decrescente(int v[], int n )
{
    int i,j,aux;
    for (i=1;i<n;i++)
    {
        aux=v[i];
        j=i-1;
        while((j>=0)&&(v[j]<aux))
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

void insertion_decrescente_art(int *v, int n )
{
    int i,j,aux;
    for (i=1;i<n;i++)
    {
        aux=*(v+i);
        j=i-1;
        while((j>=0)&&(*(v+j)<aux))
        {
            *(v+j+1)=*(v+j);
            j--;
        }
        *(v+j+1)=aux;
    }
}

void selection_crescente(int v[],int n)
{
    int i,j,menor,aux=0;
    for (i=0; i<(n-1); i++)
    {
        menor=i;
        for (j=(i+1); j<n; j++)
        {
            if (v[j]<v[menor])
            {
                menor=j;
            }
        }

        if (i!=menor)
        {
            aux=v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
    }
}
void selection_crescente_art(int *v,int n)
{
    int i,j,menor,aux=0;
    for (i=0; i<(n-1); i++)
    {
        menor=i;
        for (j=(i+1); j<n; j++)
        {
            if (*(v+j)<*(v+menor))
            {
                menor=j;
            }
        }

        if (i!=menor)
        {
            aux=*(v+i);
            *(v+i)=*(v+menor);
            *(v+menor)=aux;
        }
    }
}
void selection_decrescente(int v[],int n)
{
    int i,j,menor,aux=0;
    for (i=0; i<(n-1); i++)
    {
        menor=i;
        for (j=(i+1); j<n; j++)
        {
            if (v[j]>v[menor])
            {
                menor=j;
            }
        }

        if (i!=menor)
        {
            aux=v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
    }
}

void selection_decrescente_art(int *v,int n)
{
    int i,j,menor,aux=0;
    for (i=0; i<(n-1); i++)
    {
        menor=i;
        for (j=(i+1); j<n; j++)
        {
            if (*(v+j)>*(v+menor))
            {
                menor=j;
            }
        }

        if (i!=menor)
        {
            aux=*(v+i);
            *(v+i)=*(v+menor);
            *(v+menor)=aux;
        }
    }
}

int buscaSeq(int *v, int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if (v[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

int buscaBin_cresc(int *v, int n, int x)
{
    int i,m,f;
    i=0;
    f=n-1;
    while (i<=f)
    {
        m=(i+f)/2;
        if (x==*(v+m))
        {
            return 1;
        }
        else if (x<*(v+m))
        {
            f=m-1;
        }
        else
            i=m+1;
    }
    return 0;
}

int buscaBin_decresc(int *v, int n, int x)
{
    int i,m,f;
    i=0;
    f=n-1;
    while (i<=f)
    {
        m=(i+f)/2;
        if (x==*(v+m))
        {
            return 1;
        }
        else if (x>*(v+m))
        {
            f=m-1;
        }
        else
            i=m+1;
    }
    return 0;
}
int main()
{

    int n,i,again;
    printf("Qual o tamanho do seu vetor?\n");
    scanf("%d", &n);
    int v[n],adm;
    ler(v,n);
    menu(v,n);
    print(v,n);
    free(v);
    *v=NULL;
    printf("Deseja fazer outra operacao ? sim = 1 / nao = 2\n");
    scanf("%d", &again);
    system("cls"); // limpa a tela para iniciar novamente
    again==1 ? main() : exit(0);
    return 0;
}



