#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    FILE *pArquivo;
    char email[201]={},nome[201]={},senha[201]={},cpf[12]={};
    int idade=0,opc=0,pagina,paginaAnterior,registrados=0,logado=0,blsala[4]={30,30,30,30}; blsala1=30,blsala2=30,blsala3=30,blsala4=30;
    typedef struct {
    char email[201],nome[201],senha[201];
    int idade,cpf;
    }Visitante;
    Visitante visitante[1500];

int charVrificar(char var[300]){
    int i, vrd;
        for(i =0; i < strlen(var);i++){}
        if(!isdigit(var[i])){
            vrd=0;
        }else{
            vrd=1;
        }
    return vrd;
}
int menuInicial(){
    pagina=0;

    if(logado!=0){
        do{

        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t_________________________________________");
        printf("\n\t|       Bem vindo ao nosso sistema      |");
        printf("\n\t_________________________________________");
        printf("\n\t| Escolha uma das seguintes opções      |");
        printf("\n\t| [0] Sair                              |");
        printf("\n\t| [1] Ver as exibições do museu         |");
        printf("\n\t| [2] Comprar bilhetes para as exibições|");
        printf("\n\t| [3] Se registrar no nosso sistema     |");
        printf("\n\t_________________________________________\n\t");
        scanf("%d",&opc);
        printf("\t_________________________________________");
        if(opc<0||opc>3){
            system("cls");
            printf("Escolha uma das opções listadas");
        }
        switch(opc){

            case(0):
                system("cls");
                printf("\n\n\t\tAté a próxima.\n\n");
                break;
            case(1):
                system("cls");
                menuPrincipal();
                break;
            case(2):
                system("cls");
                paginaAnterior=0;
                bilhetesSala();
                break;
            case(3):
                system("cls");
                registrar();
                break;
            default: system("cls"); printf("Escolha uma das opções listadas"); break;
        }
    }while(opc<0||opc>3);


    }else{
        do{

        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",visitante[registrados].nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t_________________________________________");
        printf("\n\t|       Bem vindo ao nosso sistema      |");
        printf("\n\t_________________________________________");
        printf("\n\t| Escolha uma das seguintes opções      |");
        printf("\n\t| [0] Sair                              |");
        printf("\n\t| [1] Ver as exibições do museu         |");
        printf("\n\t| [2] Se registrar no nosso sistema     |");
        printf("\n\t_________________________________________\n\t");
        scanf("%d",&opc);
        printf("\t_________________________________________");
        if(opc<0||opc>2){
            system("cls");
            printf("Escolha uma das opções listadas");
        }
        switch(opc){
            case(0):
                system("cls");
                printf("\n\n\t\tAté a próxima.\n\n");
                break;
            case(1):
                system("cls");
                menuPrincipal();
                break;
            case(2):
                system("cls");
                registrar();
                break;

        }
    }while(opc<0||opc>2);

    }


return 0;
}

int registrar(){
    pagina =1;

    pArquivo = fopen("RegistrosMuseu.txt","a");
    if(pArquivo==NULL){

        printf("Erro ao abrbir o banco de dados");
    }



    printf("\n\t______________________");
    printf("\n\t|Entre com seu E-mail|");
    printf("\n\t______________________\n");
    scanf("%s",&email);
    printf("\n\t______________________");
    printf("\n\t|Confirme seu E-mail |");
    printf("\n\t______________________\n");
    scanf("%s",&email);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua senha|");
    printf("\n\t_____________________\n");
    scanf("%s",&senha);
    printf("\n\t_____________________");
    printf("\n\t|Cofirme sua senha  |");
    printf("\n\t_____________________\n");
    scanf("%s",&senha);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua cpf  |");
    printf("\n\t_____________________\n");
    scanf("%s",&cpf);
    printf("\n\t_____________________");
    printf("\n\t|Cofirme sua cpf    |");
    printf("\n\t_____________________\n");
    scanf("%s",&cpf);

    printf("\n\t____________________");
    printf("\n\t|Entre com seu Nome|");
    printf("\n\t____________________\n");
    fflush (stdin);
    fgets(nome, sizeof(nome), stdin);

    printf("\n\t_____________________");
    printf("\n\t|Entre com sua idade|");
    printf("\n\t_____________________\n");
    scanf("%d",&idade);

    fprintf(pArquivo,"\n Email:%s; Senha:%s; CPF:%s; Nome:%s ; Idade:%d; ",email,senha,cpf,nome,idade);
    fclose(pArquivo);
    system("cls");
    printf("\n\tRegistrado com sucesso");


    registrados+=1;
    logado=1;
    trocarPagina(pagina);
    return 0;
}
int menuPrincipal(){
    pagina=2;
    if(logado!=0){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t___________________________________________");
        printf("\n\t|   Bem vindo ao nosso museu              |");
        printf("\n\t___________________________________________\n");
        printf("\n\t|Escolha uma das seguintes opções         |");
        printf("\n\t| [0] Sair                                |");
        printf("\n\t| [1] 100 anos da semana de arte moderna  |");
        printf("\n\t| [2] 150 anos de Santos Dumont           |");
        printf("\n\t| [3] Olímpiadas de 2024 em Paris         |");
        printf("\n\t| [4] 200 anos de independência do Brasil |");
        printf("\n\t| [5] Comprar bilhetes                    |");
        printf("\n\t___________________________________________\n");
        scanf("%d",&opc);
        printf("\n\t___________________________________________\n");
        switch(opc){
            case(0): system("cls"); trocarPagina(pagina); break;
            case(1): system("cls"); tema1(); break;
            case(2): system("cls"); tema2(); break;
            case(3): system("cls"); tema3(); break;
            case(4): system("cls"); tema4(); break;
            case(5): system("cls"); paginaAnterior=2; bilhetesSala(); break;
            default: system("cls"); menuPrincipal(); break;
        }
        if(opc<0||opc>5){
            system("cls");
            printf("\n\tEscolha uma das opções listadas!");
        }
    }while(opc<0 || opc>5);
    }else{
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
        printf("\n\t___________________________________________");
        printf("\n\t|   Bem vindo ao nosso museu              |");
        printf("\n\t___________________________________________\n");
        printf("\n\t|Escolha uma das seguintes opções         |");
        printf("\n\t| [0] Sair                                |");
        printf("\n\t| [1] 100 anos da semana de arte moderna  |");
        printf("\n\t| [2] 150 anos de Santos Dumont           |");
        printf("\n\t| [3] Olímpiadas de 2024 em Paris         |");
        printf("\n\t| [4] 200 anos de independência do Brasil |");
        printf("\n\t___________________________________________\n");
        scanf("%d",&opc);
        printf("\n\t___________________________________________\n");
        switch(opc){
            case(0): system("cls"); trocarPagina(pagina); break;
            case(1): system("cls"); tema1(); break;
            case(2): system("cls"); tema2(); break;
            case(3): system("cls"); tema3(); break;
            case(4): system("cls"); tema4(); break;
            default: system("cls"); menuPrincipal(); break;
        }
        if(opc<0||opc>4){
            system("cls");
            printf("\n\tEscolha uma das opções listadas!");
        }
    }while(opc<0 || opc>4);
    }
    return 0;
}
int bilhetesSala(int var){
    do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t________________________________________________");
            printf("\n\t|   Bem vindo ao nosso museu                   |");
            printf("\n\t________________________________________________\n");
            printf("\n\t|Para qual sala você deseja comprar um bilhete |");
            printf("\n\t| [0] Sair                                     |");
            printf("\n\t| [1] 100 anos da semana de arte moderna       |");
            printf("\n\t| [2] 150 anos de Santos Dumont                |");
            printf("\n\t| [3] Olímpiadas de 2024 em Paris              |");
            printf("\n\t| [4] 200 anos de independência do Brasil      |");
            printf("\n\t________________________________________________\n");
            scanf("%d",&opc);
            printf("\n\t________________________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): system("cls"); bilhetes(0); break;
                case(2): system("cls"); bilhetes(1); break;
                case(3): system("cls"); bilhetes(2); break;
                case(4): system("cls"); bilhetes(3); break;
            }
            if( opc<0||opc>4){
                system("cls");
                printf("\n\tEscolha uma das opções listadas!");
            }
        }while(opc<0 || opc>4);


}
int comprabilhetes(int sala, int qual){
    if(sala==0){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }

    }else if(sala==1){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    }else if(sala==2){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    } else if(sala==3){
        if(qual==1){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==2){
            if(blsala[sala]>5){
                blsala[sala]-=5;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==3){
            if(blsala[sala]>10){
                blsala[sala]-=10;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==4){
            if(blsala[sala]>15){
                blsala[sala]-=15;
            printf("\n Bilhetes comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
        if(qual==5){
            if(blsala[sala]>0){
                blsala[sala]-=1;
            printf("\n Bilhete para idoso comprado com sucesso");
            }else{
                printf("\n Bilhete indisponivel");
            }
        }
    }


}
int bilhetes(int var){
    pagina=3;


    if(idade>60){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t_______________________________________");
            printf("\n\t|   Bem vindo ao nosso museu          |");
            printf("\n\t_______________________________________\n");
            printf("\n\t|Escolha uma dos seguintes bilhetes   |");

            printf("\n\t| [0] Sair                            |");

            if(blsala[var]>0){
            printf("\n\t| [1] bilhete individual              |");
            }else if(blsala[var]<1){
            printf("\n\t| [1] bilhete individual(INDISPONIVEL)|");
            }

            if(blsala[var]>4){
            printf("\n\t| [2] 5 bilhetes                      |");
            }else if(blsala[var]<5){
            printf("\n\t| [2] 5 bilhetes(INDISPONIVEL)        |");
            }

            if(blsala[var]>9){
            printf("\n\t| [3] 10 bilhetes                     |");
            }else if(blsala[var]<10){
            printf("\n\t| [3] 10 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>14){
            printf("\n\t| [4] 15 bilhetes                     |");
            }else if(blsala[var]<15){
            printf("\n\t| [4] 15 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>0){
            printf("\n\t| [5] bilhete p/idosos                |");
            }else if(blsala[var]<1){
            printf("\n\t| [5] bilhete p/idosos(INDISPONIVEL)  |");
            }

            printf("\n\t_______________________________________\n");
            scanf("%d",&opc);
            printf("\n\t_______________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): comprabilhetes(var,1); system("cls"); trocarPagina(pagina);  break;
                case(2): comprabilhetes(var,2); system("cls"); trocarPagina(pagina);  break;
                case(3): comprabilhetes(var,3); system("cls"); trocarPagina(pagina); break;
                case(4): comprabilhetes(var,4); system("cls"); trocarPagina(pagina);  break;
                case(5): comprabilhetes(var,5); system("cls"); trocarPagina(pagina);  break;
                default: system("cls"); trocarPagina(pagina); break;
            }
            if( opc<0||opc>5){
                system("cls");
                printf("\n\tEscolha uma das opções listadas!");
            }
        }while(opc<0 || opc>5);


    }else if(idade<60){
        do{
        if(logado!=0){
            printf("\n\t_________________________________________");
            printf("\n\t usúario: [%s]",nome);
            printf("\n\t_________________________________________");
        }
            printf("\n\t_______________________________________");
            printf("\n\t|   Bem vindo ao nosso museu          |");
            printf("\n\t_______________________________________\n");
            printf("\n\t|Escolha uma dos seguintes bilhetes   |");

            printf("\n\t| [0] Sair                            |");


            if(blsala[var]>0){
            printf("\n\t| [1] bilhete individual              |");
            }else if(blsala[var]<1){
            printf("\n\t| [1] bilhete individual(INDISPONIVEL)|");
            }


            if(blsala[var]>4){
            printf("\n\t| [2] 5 bilhetes                      |");
            }else if(blsala[var]<5){
            printf("\n\t| [2] 5 bilhetes(INDISPONIVEL)        |");
            }

            if(blsala[var]>9){
            printf("\n\t| [3] 10 bilhetes                     |");
            }else if(blsala[var]<10){
            printf("\n\t| [3] 10 bilhetes(INDISPONIVEL)       |");
            }

            if(blsala[var]>14){
            printf("\n\t| [4] 15 bilhetes                     |");
            }else if(blsala[var]<15){
            printf("\n\t| [4] 15 bilhetes(INDISPONIVEL)       |");
            }

            printf("\n\t_______________________________________\n");
            scanf("%d",&opc);
            printf("\n\t_______________________________________\n");
            switch(opc){
                case(0): system("cls"); trocarPagina(pagina); break;
                case(1): comprabilhetes(var,1); system("cls"); trocarPagina(pagina);  break;
                case(2): comprabilhetes(var,2); system("cls"); trocarPagina(pagina);  break;
                case(3): comprabilhetes(var,3); system("cls"); trocarPagina(pagina); break;
                case(4): comprabilhetes(var,4); system("cls"); trocarPagina(pagina);  break;
                default: system("cls"); trocarPagina(pagina); break;
            }
            if( opc<0||opc>4){
                system("cls");
                printf("\n\tEscolha uma das opções listadas!");
            }
        }while(opc<0 || opc>4);
    }
    trocarPagina(pagina);
}


int trocarPagina(paginaNum){
    switch(paginaNum){
        case(1): system("cls"); printf("\n\tRegistrado com sucesso"); menuInicial(); break;
        case(2): system("cls"); menuInicial(); break;
        case(3): system("cls");
            if(paginaAnterior==0){
                menuInicial();
            }else if(paginaAnterior==2){
                menuPrincipal();
            } break;
        case(4): system("cls"); menuPrincipal(); break;
        case(5): system("cls"); menuPrincipal(); break;
        case(6): system("cls"); menuPrincipal(); break;
        case(7): system("cls"); menuPrincipal(); break;
        default: system("cls"); menuInicial(); break;
    }
}

void tema1(){
    pagina = 4;

    printf("\n\t\t\t\t 100 anos da semana de arte moderna:"
           "\n\n\tÉ possível que você já tenha ouvido falar sobre a Semana de Arte Moderna de 1922, principalmente nas aulas de português, história e artes, durante o ensino fundamental e médio. Mas o quanto e de quem você se lembra quando escuta sobre o assunto? Foi um movimento de artistas de todo o Brasil? Qual o motivo que levou essa semana ser considerada tão importante?"
           "\n\n\tA Semana de Arte Moderna aconteceu em fevereiro de 1922, na cidade de São Paulo, 100 anos após a Independência do Brasil, 34 anos após a abolição da escravidão e 4 anos após o fim da Primeira Guerra Mundial. Nesse contexto, uma questão importante para os considerados intelectuais brasileiros era como o Brasil tinha se saído desses processos históricos, principalmente comparando o país com os Estados Unidos da América, que saíram da Primeira Guerra Mundial como uma grande potência. Além disso, as questões sociais, principalmente a abolição da escravidão, recebiam pouco destaque nos trabalhos artísticos. Assim, a Semana de Arte Moderna se apoiava no pensamento nacionalista e na busca de uma identidade para o Brasil, além da procura por uma produção artística mais liberta, que rompesse com uma estética das academias de Belas Artes e das ideias parnasianistas. As ideias parnasianistas tratavam da arte pela arte, privilegiavam a busca pela perfeição e demonstravam pouca preocupação com os sentimentos humanos e os contextos sociais."
           "\n\n\tA Semana de Arte Moderna teve muitos envolvidos, como Anita Malfatti, Di Cavalcanti, Ferrignac (Inácio da Costa Ferreira), Zina Aita, Mário de Andrade, Martins Ribeiro, Oswaldo Goeldi, Regina Graz, Oswald de Andrade, entre outros artistas e intelectuais majoritariamente paulistas.  O evento se tornou um dos marcos da cena cultural brasileira anos depois do seu acontecimento. Apesar de o evento ter sido pensado para acontecer durante uma semana completa, de 11 a 18 de fevereiro, na verdade a Semana de Arte Moderna só esteve aberta ao público durante os dias 13, 15 e 17, respectivamente segunda, quarta e sexta, de fevereiro de 1922, com programação temática que passava pelas artes visuais, literatura e música. Vale ressaltar, que os trabalhos expostos na Semana não tiveram uma recepção positiva pelos intelectuais conservadores de São Paulo, pelo fato de romperem com as tradições artísticas do período. Porém, essas reações, bem como as notícias sobre a Semana, ocorreram majoritariamente em São Paulo, não ocorrendo grande repercussão a nível nacional."
           "\n\n\tApesar da celebração da Semana de Arte Moderna como um marco da arte no Brasil, é preciso olhá-la de forma também crítica. Pois, toda a ideia que temos em volta da Semana aconteceu principalmente por conta de uma construção posterior sobre o evento, a partir dos escritos de Lourival Gomes Machado no livro “Retrato Da Arte Moderna Do Brasil”, de 1946, que foi replicado, reconstruído e chegou ao que se é comumente falado hoje. Em resumo, a Semana não foi um grande sucesso na época, mas o modo como foi retratada posteriormente garantiu seu lugar dentro da história do Brasil."
           "\n\n\tTalvez o mais importante quando se pensa no assunto é considerar que esse evento não deu e não dá conta de quem somos enquanto Brasil e da complexidade e diversidade dos olhares sobre o país. A investida daqueles artistas foi interessante do ponto de vista formal, mas insuficiente no que se propôs, principalmente quanto à construção de uma identidade nacional nas artes. A Semana de Arte Moderna foi elaborada por uma elite branca, em São Paulo, que teve a oportunidade de estudar arte dentro e fora do Brasil, influenciados por ideais que vieram também de fora, principalmente da Europa. Como menciona Cardoso (2022), o próprio Mário de Andrade, que foi uma importante figura da Semana, criticou esse movimento em 1942 na conferência “O movimento modernista” , dizendo que os artistas da Semana não captaram de fato o que acontecia no Brasil e fez pouco para mudá-lo na sua estrutura. Reforçou, inclusive, que os artistas da Semana não devem servir de exemplo, mas de lição."
           "\n\n\tAtualmente, os campos artísticos buscam incorporar as pautas raciais, LGBTQIA+, de mulheres, indígenas e outros grupos minoritários em suas produções, a partir do ponto de vista dessas pessoas, e não pelo olhar do outro, que foi o que prevaleceu na Semana de Arte Moderna. Nesse sentido, a presença dessas pessoas, discussões e pautas na produção artística expande nossa representação nas artes, tornando-as mais fiéis à grande mistura de gente que é o Brasil, sejam os trabalhos dessas pessoas relacionados à identidade de forma direta ou não. Mais do que celebrar a Semana de Arte Moderna, é importante entendê-la como de fato foi e se aproximar do que vem sendo produzido hoje nas diversas artes, não só as visuais, mas também a dança, a música, no centro e na periferia. Afinal, a história é feita no agora. Artistas contemporâneos como Rosana Paulino, Priscila Resende, Sérgio Adriano, Rosa Luz, Ventura Profana, Uýra Sodoma, Denilson Baniwa, Isael Maxakali, Sallisa Rosa, Daiely Gonçalves e Yan Nicolas São Thiago são apenas alguns dos que merecem nossa atenção."
           "\n\n\t[Texto de autoria de Abraão Veloso Machado, aluno do curso de Artes Visuais  e estagiário do Núcleo de Ações Educativas do Espaço do Conhecimento UFMG]"
           "\n\tdados não foram elaborados por nossa equipe mas sim retirados do site: https://www.ufmg.br/espacodoconhecimento/100-anos-da-semana-de-arte-moderna-celebracao-ou-reflexao/");



    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }

}
void tema2(){
    pagina = 5;

     printf("\n\t\t\t\t 150 anos de Santos Dumont:"
        "\n\n\t\t\t\t Sua vida"
        "\n\n\t Há 150 anos, nascia no interior de Minas Gerais um dos maiores inventores brasileiros: o notável Alberto Santos Dumont, considerado um dos precursores da aviação e da criação de aeronaves no mundo."
        "\n\n\tA história de vida, as obras e os valores do Pai da Aviação e Patrono da Aeronáutica Brasileira são fontes de inspiração não só no nosso país, mas em várias regiões do planeta. Suas inovações e contribuições para a aviação são celebradas até hoje."
        "\n\n\tO homem que deu asas à humanidade nasceu no dia 20 de julho de 1873, no sítio Cabangu – local que, em 1890, passou a pertencer ao município de Palmyra (MG), um dos bens tombados sob tutela da Força Aérea Brasileira (FAB)."
        "\n\n\tFilho de Francisca Santos Dumont, de tradicional família portuguesa vinda para o Brasil com D. João VI, em 1808, e de Henrique Dumont, engenheiro civil de obras públicas e, mais tarde, cafeicultor em Ribeirão Preto (SP). Henrique Dumont, de ascendência francesa, teve papel fundamental na trajetória do filho Alberto, pois, percebendo nele o fascínio pelas máquinas – que existiam em grande quantidade na fazenda Arindiúva –, direcionou os estudos do rapaz para a mecânica, a física, a química e a eletricidade, não fazendo questão que ele se formasse em engenharia, como foi o caso dos outros filhos."
        "\n\n\tO sonho de voar de Alberto surgiu aos 15 anos quando ele teve uma visão: um balão livre nos céus de São Paulo. No caso, balões livres são aqueles que fazem sua ascensão sem possuir nenhum tipo de dirigibilidade, ficando ao sabor das correntes aéreas."
        "\n\n\tAos 18 anos, emancipado pelo pai, Alberto foi para Paris completar os estudos e perseguir o seu sonho de voar. Ao chegar à capital francesa, o jovem se admira com os motores de combustão interna a petróleo que começavam a aparecer impulsionando os primeiros automóveis e compra um para si, investigando todo o seu funcionamento. Logo estava promovendo e disputando as primeiras corridas de automóveis na Cidade-Luz."
        "\n\n\tEm 31 de julho de 1932, a cidade de Palmyra, em Minas Gerais, passou a denominar-se Santos Dumont, em homenagem ao Pai da Aviação."
        "\n\n\t\t\t\t Sua obra"
        "\n\n\t Um verdadeiro herói da engenhosidade. A obra do brasileiro Santos Dumont está diretamente vinculada a várias inovações. O filho de Francisca e Henrique Dumont viveu em um período de grandes revoluções na tecnologia e foi o nosso maior protagonista dos ares."
        "\n\n\tAos 24 anos, Santos Dumont tinha sua primeira decolagem bem sucedida a bordo de um balão livre alugado. Um ano depois, em 1898, projeta e constrói, com a ajuda de operários e construtores de balões franceses, seu primeiro balão livre: o Brasil, o menor balão tripulado já feito, homenageando sua pátria. Logo em seguida, associando os leves motores de combustão interna a petróleo a seus leves balões e construindo engenhosos lemes, Santos Dumont inventa os balões dirigíveis."
        "\n\n\tEm 1901, Santos Dumont pilotou seu balão, o Número 6, que era movido a gasolina, sobre Paris, e ganhou um prêmio de 100 mil francos por seu feito. As suas realizações foram frutos de sucesso na imprensa europeia, na imprensa norte-americana e no Brasil. O inventor, nesse momento, torna-se o centro das atenções, despertando o interesse militar para seus balões."
        "\n\n\tApós o sucesso com balões e dirigíveis, Santos Dumont partiu para outra linha de pesquisa: queria, agora, voar com um veículo mais pesado que o ar. O protótipo era composto por uma fuselagem longa, com a nacele do balão número 14 na parte de trás – um biplano com uma construção parecida com pipas japonesas, portando um motor de oito cilindros e sobre três rodas: o primeiro trem de pouso que se tem notícia. A inovação era pulsante desde os testes. O aviador construiu um sistema de cabos inclinados para testar a dirigibilidade do 14-Bis: um inovador simulador de voo."
        "\n\n\tEm 1905, na plateia de uma corrida de lanchas num quente verão no Rio Sena, Santos Dumont avista uma potente lancha com motor Antoinette de 24 HP e começa aí a planejar “o mais pesado que o ar”. Aproveitando o sucesso dos planadores e, em especial, o planador com células de Hargrave, o inventor constrói o primeiro avião, o 14-Bis, com o motor Antoinette, usando o balão nº 14 para testes de estabilidade."
        "\n\n\tFoi no dia 7 de setembro de 1906 que o 14-Bis deu um primeiro salto no ar, mas faltou potência. Já em 23 de outubro, com motor Antoinette de 50 HP, o 14 Bis voou, decolando, mantendo-se no ar por uma distância de 60 metros, a três metros de altura, e aterrissou. Era o primeiro voo homologado do “mais pesado que o ar” para uma multidão de testemunhas eufóricas no campo de Bagatelle, em Paris. No dia seguinte, toda a imprensa francesa louvou o fato histórico, o triunfo de um obstinado brasileiro, que, pelo feito, conquistou o prêmio Archdeacon oferecido pelo Aeroclube de França. O dinheiro do prêmio foi distribuído para seus operários e os pobres de Paris, como era o costume do inventor."
        "\n\n\tAssim, Santos Dumont se tornou uma celebridade conhecida mundialmente e continuou a trabalhar em aviões, tendo feito muitas outras contribuições importantes para a aviação. Em 1909, ele voou em seu avião Demoiselle, um dos primeiros aeroplanos do mundo, e que se tornou um sucesso comercial. Santos Dumont também trabalhou em melhorias no design do avião, como a adição de cauda vertical para melhor estabilidade e controle."
        "\n\n\tSantos Dumont recebeu diversas homenagens por toda a Europa, nos EUA, na América Latina e, em especial, no Brasil, onde foi recebido com festas e euforia. Seus projetos foram aperfeiçoados por outros aviadores e projetistas, já que ele não os patenteava e não desejava adquirir bens materiais com suas invenções, mas idealizava dotar a humanidade com meios de facilitar as comunicações, desgostando-se com o uso agressivo que o avião teve na Primeira Guerra Mundial."
        "\n\n\tComo podemos observar, Santos Dumont dedicou sua vida à aviação. Foi o primeiro aeronauta a alcançar, definitivamente, a dirigibilidade dos balões e a voar num aparelho mais pesado que o ar com propulsão própria. O desenvolvimento da aviação ensejou a criação do Ministério da Aeronáutica e, desde então, com o avanço da tecnologia, a Força Aérea Brasileira tem renovado seus vetores. Foram suas ideias e seus feitos que tornaram possível, hoje, nas Asas que protegem o País, a atuação da nossa Força em diversas missões nacionais e internacionais."
        "\n\n\tdados não foram elaborados por nossa equipe mas sim retirados do site: https://www.fab.mil.br/santosdumont150anos/");

    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}
void tema3(){
    pagina = 6;

    printf("\n\t\t\t\t Olímpiadas de 2024 em Paris:"
        "\n\n\tJogos Olímpicos de 2024 (em francês: Les Jeux olympiques d'été de 2024) conhecidos oficialmente como os Jogos da XXXIII Olimpíada, comumente chamado Paris 2024, é um evento multiesportivo futuro a ser realizado no segundo semestre de 2024, na cidade de Paris (capital da França). Será a terceira vez que a cidade será sede dos jogos (já o tinha sido em 1900 e 1924). No total esta será a sexta edição dos Jogos Olímpicos realizados na França. O país ainda sediou os Jogos Olímpicos de Inverno de 1924, em Chamonix, os Jogos Olímpicos de Inverno de 1968, em Grenoble e mais recentemente os Jogos Olímpicos de Inverno de 1992, na Savóia."
        "\n\n\tOs Jogos de 2024 serão a primeira edição fora de um pais do Extremo Oriente em seis anos e a primeira na União Europeia em doze anos - Londres sediou os Jogos Olímpicos de Verão de 2012 -, seguindo-se os Jogos Olímpicos de Inverno de 2018, em Pyeongchang, Coreia do Sul, aos Jogos Olímpicos de Verão de 2020, realizados em 2021, em Tóquio, capital do Japão, e os Jogos Olímpicos de Inverno de 2022, que realizados em Pequim, capital da República Popular da China. Paris e Los Angeles foram as cidades candidatas."
        "\n\n\t\t\t Candidatura de Paris:"
        "\n\n\tA capital francesa foi a primeira cidade a anunciar que estava interessada em receber os Jogos Olímpicos de Verão de 2024, e anunciou a sua intenção em 23 de junho de 2015, a data em que é celebrado o Dia Olímpico. O ex-ministro francês, Jean-Francois Lamour, percebeu que 2024 seria um ano chave para encaixar com o centenário da última vez em que os Jogos foram realizados na cidade e também o centenário dos Jogos Olímpicos de Inverno franceses gostariam muito disso. O tricampeão olímpico de canoagem slalom Tony Estanguet que é um dos presidentes do Comitê Organizador disse em uma entrevista ao canal RTL que a cidade iria vencer de qualquer jeito.[7] A cidade deve investir por volta de 35 milhões de euros na construção de novos locais de competição.[8][9][10]"
        "\n\n\tEm 8 de Novembro de 2014, a prefeita de Paris, Anne Hidalgo, percebeu que os Jogos de 2024 seriam muito caros para a cidade, alegando que, 'Nós não estamos em uma boa situação financeira e orçamental para garantir esta candidatura.' e que a estava sendo avaliada uma potencial candidatura para os Jogos Olímpicos de Verão de 2028."
        "\n\n\tEntretanto, cinco meses depois em Março de 2015, Hidalgo autorizou à candidatura. No dia 14 de abril do mesmo ano, os conselheiros da cidade de Paris aceitaram a proposta e a cidade assim se tornou a primeira cidade postulante aos Jogos de 2024. Desde então, Hidalgo se posicionou como uma das principais apoiadoras da candidatura. Ela e o então presidente da França, François Hollande, fizeram parte da comitiva da cidade durante os Jogos Olímpicos de Verão de 2016 no Rio de Janeiro ."
        "\n\n\tEm 26 de junho de 2015, a Federação Francesa de Vela anunciou que iria realizar um processo de seleção para a sede do esporte. Seis cidades?Le Havre (Seine-Maritime), La Rochelle, Brest, Hyères, Marselha,Bouches-du-Rhône e Quiberon manifestaram o seu interesse. Em 7 de setembro de 2015, foi anunciado que Marselha foi escolhida com a subsede da vela."
        "\n\n\tEm 9 de fevereiro de 2016, Paris revelou o logotipo de sua candidatura por meio de uma projeção no Arco do Triunfo, exatamente às 20:24, sendo o logotipo uma versão multicolorida da Torre Eifel com as inscrições Paris 2024, Cidade Candidata aos Jogos Olímpicos de Verão de 2024, e ao mesmo tempo ele foi revelado também na prefeitura de Marselha ."
        "\n\n\tEm 12 de novembro de 2016, Anne Hidalgo e o judoca multimedalhista Teddy Riner lideraram a delegação da cidade para uma apresentação de Paris para os membros de Comitê Olímpico Internacional e líderes desportivos durante a Feira SportAccord em Doha, Qatar."
        "\n\n\tEm janeiro de 2017, o Comitê de Paris propôs reduzir as suas emissões de carbono em mais de metade em comparação com Londres e ao Rio de Janeiro e assim realizar os 'Jogos mais sustentáveis da história '.. Para a apresentação da terceira e última parte do seu projeto, a Torre Eiffel foi adornada com as cores olímpicas em 3 de fevereiro de 2017. Essa iluminação especial foi feita para anunciar o slogan da candidatura da cidade: 'Feita para compartilhar'."
        "\n\n\tEm fevereiro de 2017, lideradas por Denis Coderre, prefeito de Montreal, mais de 50 cidades anunciaram seu apoio à candidatura de Paris 2024, incluindo sedes anteriores como Sydney, Atenas, Cidade do México, Barcelona e Tóquio."
        "\n\n\tNo final de fevereiro, a prefeita Hidalgo foi a Tóquio para conhecer a governadora da regiao metropolitana, Yuriko Koike com base a um intercambio entre os stakeholders das duas cidades ."
        "\n\n\tParis sediou anteriormente Jogos Olímpicos de Verão de 1900 e os Jogos Olímpicos de Verão de 1924. A cidade é segunda na história a receber os Jogos Olímpicos de Verão oficialmente três vezes (a primeira foi Londres em 1908, 1948 e 2012). O ano de 2024 também marca o centenário da última vez que a cidade tinha sediado os Jogos, e também o primeiro centenário dos Jogos Olímpicos de Inverno que foram disputados em Chamonix. Além disso, será a sexta vez que os Jogos serão disputados na França, sendo a terceira de verão. Os Jogos Olímpicos serão disputados de 26 de julho a 11 de agosto de 2024 e os Jogos Paralímpicos de 4 a 15 de setembro do mesmo ano."
        "\n\n\tdados não foram elaborados por nossa equipe mas sim retirados do site: https://pt.wikipedia.org/wiki/Jogos_Ol%C3%ADmpicos_de_Ver%C3%A3o_de_2024"
    );

    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}
void tema4(){
    pagina = 7;

    printf("\n\t\t\t\t 200 anos de independência do brasil:"
            "\n\n\tA independência do Brasil foi um processo iniciado a partir da Revolução Liberal do Porto, que levou ao rompimento entre Brasil e Portugal, no dia 7 de setembro de 1822."
            "\n\n\tA independência do Brasil aconteceu em 1822, tendo como grande marco o grito da independência que foi realizado por Pedro de Alcântara (D. Pedro I durante o Primeiro Reinado), às margens do Rio Ipiranga, no dia 7 de setembro de 1822. Com a independência do Brasil declarada, o país transformou-se em uma monarquia com a coroação de D. Pedro I."
            "\n\n\t\t\t Causas da independência do Brasil"
            "\n\n\t A independência do Brasil foi declarada em 1822 e esse acontecimento está diretamente relacionado com eventos que foram iniciados em 1808, ano em que a família real portuguesa, fugindo das tropas francesas que invadiram Portugal, mudou-se para o Brasil."
            "\n\n\tA chegada da família real no Brasil ocasionou uma série de mudanças que contribuiu para o desenvolvimento comercial, econômico e, em última instância, possibilitou a independência do Brasil. Além disso, o Brasil experimentou, em seus centros, um grande desenvolvimento resultado de uma série de medidas implementadas por D. João VI, rei de Portugal."
            "\n\n\tInstalado no Rio de Janeiro, o rei português autorizou a abertura dos portos brasileiros às nações amigas, permitiu o comércio entre os brasileiros e os ingleses como medidas de destaque no âmbito econômico."
            "\n\n\tEssas e outras medidas que foram tomadas pelo rei português demonstravam uma clara intenção de modernizar o país como parte de uma proposta que fizesse o Brasil deixar de ser apenas uma colônia portuguesa, tornando-se, de fato, parte integrante do Reino de Portugal. Isso foi confirmado quando, em 16 de dezembro de 1815, D. João VI decretou a elevação do Brasil para parte do Reino Unido."
            "\n\n\tIsso, na prática, significou que o Brasil deixava de ser uma colônia e transformava-se em parte integrante do Reino português, que agora passava a ser chamado de Reino Unido de Portugal, Brasil e Algarves. Essa medida era importante para o Brasil e, segundo as historiadoras Lilia Schwarcz e Heloísa Starling, a medida tinha como objetivo principal evitar que o Brasil seguisse pelo caminho da fragmentação revolucionária – como havia acontecido na relação entre EUA e Inglaterra"
            "\n\n\tA presença da família real no Brasil havia proporcionado grandes avanços, mas, ainda assim, demonstrações de insatisfação aconteceram por meio da Revolução Pernambucana de 1817. A mudança da família real para o Brasil havia resultado em grande aumento de impostos e interferido diretamente na administração da capitania."
            "\n\n\tA Revolução Pernambucana de 1817 foi reprimida violentamente. Três anos depois dessa repressão, o rei D. João VI teve de lidar com insatisfações em Portugal que se manifestaram em Revolução Liberal do Porto de 1820. Esse foi o ponto de partida do processo de independência do Brasil."
            "\n\n\tPortugal vivia uma forte crise, tanto política quanto econômica, em consequência da invasão francesa. Além disso, havia uma forte insatisfação em Portugal por conta das transformações que estavam acontecendo no Brasil, sobretudo com a liberdade econômica que o Brasil havia conquistado com as medidas de D. João VI."
            "\n\n\tA Revolução Liberal do Porto eclodiu em 1820 e foi organizada pela burguesia portuguesa inspirada em ideais liberais. Um dos grandes objetivos dos portugueses era o retorno do rei para Portugal. Na visão da burguesia portuguesa, Portugal deveria ser a sede do Império português."
            "\n\n\tOutra reivindicação importante dos portugueses foi a exigência de restabelecimento do monopólio comercial sobre o Brasil. Essa exigência causou grande insatisfação no Brasil, uma vez que demonstrava a intenção dos portugueses em permanecer com os laços coloniais em relação ao Brasil. O rei português, pressionado pelos acontecimentos em seu país, resolveu retornar para Portugal em 26 de abril de 1821."
            "\n\n\tNa viagem de D. João VI, cerca de quatro mil pessoas retornaram para Portugal. O rei português, além disso, levou para Portugal uma grande quantidade de ouro e diamantes que estavam nos cofres do Banco do Brasil. Com o retorno de D. João VI, Pedro de Alcântara tornou-se regente do Brasil."
            "\n\n\tdados não foram elaborados por nossa equipe mas sim retirados do site: https://brasilescola.uol.com.br/historiab/independencia-brasil.htm"

);


    printf("\n\n\tDeseja sair? [1]sim ");
    scanf("%d",&opc);
    switch(opc){
        case(1): trocarPagina(pagina); break;
        default: trocarPagina(pagina); break;
    }
}


int main(){
    pagina=0;
    setlocale(LC_ALL,"");


    menuInicial();
    return 0;
}
