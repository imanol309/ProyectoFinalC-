#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <ios>
#include <bits/stdc++.h>
using namespace std;

// Estas es la clase padre de todos, todos enredan de ella algunas funciones
class Banco
{
protected:
public:
    void forGuardar(int, int, int, string[100][100], string[100][100]);
    void modeloMostrarDatos(int, int, string[8], string[100][100]);
};

// Estas funcion es la mas importante, porque se encargar de guadar los datos en los array que los datos complen

void Banco::forGuardar(int Filas, int filaGuardad, int filaRecorrer, string arrayPuede[100][100], string arrayGuardado[100][100])
{
    for (int I = 0; I < filaRecorrer; I++)
    {
        arrayPuede[filaGuardad][I] = arrayGuardado[Filas][I];
    };
};

void Banco::modeloMostrarDatos(int filas, int colunas, string informacionModelo[8], string arrayDeDatos[100][100])
{
    if (arrayDeDatos[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("+-----------------------------------------\n");
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacionModelo[j] << ": " << arrayDeDatos[i][j] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
}

class CreditoPersonal : public Banco
{
protected:
public:
    string puedenRecibirCredito[100][100];
    string informacionesNecesarias[9] = {
        "Nombre del solicitante",
        "Valor por el que pide el crédito",
        "Dirección",
        "Carné de identidad del cliente",
        "Salario total del núcleo",
        "Cantidad de personas bajo su sustento",
        "Capacidad de pago",
        "Mensualidades a pagar",
        "Tiempo en demorar en pagar"};
    string datosCreditoPersonal[100][100];
    int filasPersonas = 0;
    int filasGuardadPersonas = 0;
    int colunasPrincipal = 0;
    void incresarDatosPersonal();
    void mostrarCreditoPersonal();
    void capacidadPorEncima();
    void mensualidadesPagar(int, string[], string[][100], int);
    void valorDestinadoCredito(int, string[], string[][100], int);
};

void CreditoPersonal::capacidadPorEncima()
{
    int contadorEncima = 0;
    string PorEncima[100][100];
    for (int H = 0; H < filasGuardadPersonas; H++)
    {
        if (stoi(puedenRecibirCredito[H][6]) > 200)
        {
            forGuardar(H, contadorEncima, 9, PorEncima, puedenRecibirCredito);
            contadorEncima = contadorEncima + 1;
        }
    }
    cout << "---------------Listado con las personas con capacidad de pago por encima de los 200 pesos---------------" << endl;
    modeloMostrarDatos(contadorEncima, 9, informacionesNecesarias, PorEncima);
}

void CreditoPersonal::incresarDatosPersonal()
{
    for (int I = colunasPrincipal; I < (filasPersonas + colunasPrincipal); I++)
    {
        cin.ignore();
        for (int J = 0; J < 6; J++)
        {
            cout << "Tu eres el usuario " << I + 1 << ", Agregar " << informacionesNecesarias[J] << ": ";
            getline(cin, datosCreditoPersonal[I][J]);
            if (datosCreditoPersonal[I][J] == datosCreditoPersonal[I][5])
            {
                if (stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50) > 100)
                {
                    datosCreditoPersonal[I][6] = to_string(stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50)) + " Pesos";
                    int D6 = stoi(datosCreditoPersonal[I][6]);
                    datosCreditoPersonal[I][7] = (D6 > 140) ? "50 Pesos" : (D6 <= 140 && D6 >= 121) ? "40 Pesos"
                                                                       : (D6 <= 120 && D6 >= 100)   ? "30 Pesos"
                                                                                                    : "";
                    datosCreditoPersonal[I][8] = to_string(D6 / stoi(datosCreditoPersonal[I][7])) + " Meses";
                    forGuardar(I, filasGuardadPersonas, 10, puedenRecibirCredito, datosCreditoPersonal);
                    filasGuardadPersonas = filasGuardadPersonas + 1;
                };
            };
        };
        printf("+--------------------------------------------------------+\n");
    };
    colunasPrincipal = colunasPrincipal + filasPersonas;
};

void CreditoPersonal::mostrarCreditoPersonal()
{
    if (puedenRecibirCredito[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("-------------------------Todas las personas que puedan recibir el crédito-------------------------\n");
        printf("+-----------------------------------------\n");
        cout << endl;
        for (int i = 0; i < filasGuardadPersonas; i++)
        {
            swap(puedenRecibirCredito[i][0], puedenRecibirCredito[i][3]);
            swap(informacionesNecesarias[0], informacionesNecesarias[3]);
            for (int j = 0; j < 9; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacionesNecesarias[j] << ": " << puedenRecibirCredito[i][j] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
};

void CreditoPersonal::mensualidadesPagar(int filasGuarda, string informacion[9], string arrayPuede[][100], int numero)
{
    if (arrayPuede[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("-------------------------las mensualidades a pagar por persona-------------------------\n");
        printf("+-----------------------------------------\n");
        cout << endl;
        for (int i = 0; i < filasGuarda; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacion[0] << ": " << arrayPuede[i][0] << '\t' << '\n'
                    << std::right << std::setw(43)
                    << informacion[numero] << ": " << arrayPuede[i][numero] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
};

void CreditoPersonal::valorDestinadoCredito(int filasGuarda, string informacion[9], string arrayPuede[][100], int numero)
{
    if (arrayPuede[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("-------------------------El valor total del dinero que se destinará al crédito.-------------------------\n");
        printf("+-----------------------------------------\n");
        cout << endl;
        for (int i = 0; i < filasGuarda; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacion[0] << ": " << arrayPuede[i][0] << '\t' << '\n'
                    << std::right << std::setw(50)
                    << "Dinero que se destinará al crédito: " << arrayPuede[i][numero] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
};

class CreditoEmpresa : public Banco
{
protected:
public:
    string puedenRecibirCreditoEmpresarial[100][100];
    string informacionesEmpresa[11] = {
        "Nombre del solicitante",
        "Valor por el que pide el crédito",
        "Dirección",
        "El nombre del director",
        "Dirección del mismo",
        "Ganancia anual promedio durante los últimos 5 años",
        "Cantidad de trabajadores",
        "Ministerio al cual pertenece",
        "Código",
        "Tiempo en demorar en pagar",
        "Mensualidades a pagar"};
    string datosCreditoEmpresarial[100][100];
    int filasEmpresas;
    int filasGuardadEmpresa = 0;
    int colunasPrincipalEmpresa = 0;
    void incresarDatosEmpresarial();
    void mostrarCreditoEmpresa();
};

void CreditoEmpresa::incresarDatosEmpresarial()
{
    for (int I = colunasPrincipalEmpresa; I < (filasEmpresas + colunasPrincipalEmpresa); I++)
    {
        cin.ignore();
        for (int J = 0; J < 9; J++)
        {
            cout << "Tu eres el usuario " << I + 1 << ", Agregar " << informacionesEmpresa[J] << ": ";
            getline(cin, datosCreditoEmpresarial[I][J]);
            if (datosCreditoEmpresarial[I][J] == datosCreditoEmpresarial[I][8])
            {
                int Cinco = stoi(datosCreditoEmpresarial[I][5]);
                int Seis = stoi(datosCreditoEmpresarial[I][6]);
                if (Seis > 300 && Cinco >= 10000 || Seis < 300 && Cinco >= 5000 || Seis < 100 && Cinco >= 1000)
                {
                    int ValorEnPorcentaje = (Seis > 300 && Cinco >= 10000) ? (Cinco * 40) / 100 : (Seis < 300 && Cinco >= 5000) ? (Cinco * 30) / 100
                                                                                              : (Seis < 100 && Cinco >= 1000)   ? (Cinco * 20) / 100
                                                                                                                                : 0;
                    datosCreditoEmpresarial[I][9] = to_string(stoi(datosCreditoEmpresarial[I][1]) / ValorEnPorcentaje) + " Meses";
                    datosCreditoEmpresarial[I][10] = to_string(ValorEnPorcentaje) + " Pesos";
                    forGuardar(I, filasGuardadEmpresa, 12, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                    filasGuardadEmpresa = filasGuardadEmpresa + 1;
                };
            };
        };
    };
    colunasPrincipalEmpresa = colunasPrincipalEmpresa + filasEmpresas;
};

void CreditoEmpresa::mostrarCreditoEmpresa()
{
    if (puedenRecibirCreditoEmpresarial[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("-------------------------Todas las empresas que puedan recibir el crédito-------------------------\n");
        printf("+-----------------------------------------\n");
        cout << endl;
        for (int i = 0; i < filasGuardadEmpresa; i++)
        {
            swap(puedenRecibirCreditoEmpresarial[i][0], puedenRecibirCreditoEmpresarial[i][7]);
            swap(puedenRecibirCreditoEmpresarial[i][1], puedenRecibirCreditoEmpresarial[i][8]);
            swap(informacionesEmpresa[0], informacionesEmpresa[7]);
            swap(informacionesEmpresa[1], informacionesEmpresa[8]);
            for (int j = 0; j < 11; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacionesEmpresa[j] << ": " << puedenRecibirCreditoEmpresarial[i][j] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
};

void tiempoPagarCredito(int filasGuarda, string informacion[9], string arrayPuede[][100], int numero)
{
    if (arrayPuede[0][0].empty())
    {
        cout << "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio. " << endl;
        cout << endl;
    }
    else
    {
        printf("+-----------------------------------------\n");
        cout << endl;
        for (int i = 0; i < filasGuarda; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                cout << "|";
                std::cout
                    << std::right << std::setw(43)
                    << informacion[3] << ": " << arrayPuede[i][3] << '\t' << '\n'
                    << std::right << std::setw(43)
                    << informacion[numero] << ": " << arrayPuede[i][numero] << '\t' << '\n';
            };
            printf("+-----------------------------------------\n");
        };
        cout << endl;
    }
};

int main()
{
    int tipoCredito;
    int filasP;
    int filasE;
    CreditoPersonal usuarioPersonal;
    CreditoEmpresa UsuarioEmpresa;

    cout << "-------------------- Bienvenido al Banco UAPA --------------------" << endl;
    while (tipoCredito != 4)
    {
        cout << "Que tipo de credito quieres:" << endl;
        cout << "1 - Credito Personal" << endl;
        cout << "2 - Credito para una empresa" << endl;
        cout << "3 - Las necesidades del Banco" << endl;
        cout << "4 - Salir" << endl;
        cout << "Eligue uno numero: ";
        cin >> tipoCredito;
        if (tipoCredito == 1)
        {
            cout << "Necesitamos que increses algunas informaciones ante para tu credito personal" << endl;
            cout << "Cuantas Personas piensas agregar: ";
            cin >> usuarioPersonal.filasPersonas;
            // system("cls");
            usuarioPersonal.incresarDatosPersonal();
        };
        if (tipoCredito == 2)
        {
            cout << "Necesitamos que increses algunas informaciones ante para tu credito empresarial:" << endl;
            cout << "Cuantas Empresas piensas agregar: ";
            cin >> UsuarioEmpresa.filasEmpresas;
            UsuarioEmpresa.incresarDatosEmpresarial();
        };

        if (tipoCredito == 3)
        {
            int opcionesMostrar;
            cout << "--------------------Cual de las siguientes opciones quieres elegir--------------------" << endl;
            cout << "1) Un listado ordenado por el número de carné de identidad con todas las personas que puedan recibir el crédito" << endl;
            cout << "2) Un listado ordenado por ministerio y código de todas las empresas que puedan recibir el crédito." << endl;
            cout << "3) El valor total del dinero que se destinará al crédito." << endl;
            cout << "4) las mensualidades a pagar" << endl;
            cout << "5) Determine y visualice un listado con el número del carné de identidad y el tiempo que demorará en pagar el crédito" << endl;
            cout << "6) Listado con las personas con capacidad de pago por encima de los 200 pesos" << endl;
            cout << "7) Determine y visualice un listado por empresa y el tiempo que demorará en pagar el crédito." << endl;
            cout << "Eligue uno numero: ";
            cin >> opcionesMostrar;
            switch (opcionesMostrar)
            {
            case 1:
                usuarioPersonal.mostrarCreditoPersonal();
                break;
            case 2:
                UsuarioEmpresa.mostrarCreditoEmpresa();
                break;
            case 3:
                usuarioPersonal.valorDestinadoCredito(usuarioPersonal.filasGuardadPersonas, usuarioPersonal.informacionesNecesarias, usuarioPersonal.puedenRecibirCredito, 6);
                break;
            case 4:
                usuarioPersonal.mensualidadesPagar(usuarioPersonal.filasGuardadPersonas, usuarioPersonal.informacionesNecesarias, usuarioPersonal.puedenRecibirCredito, 7);
                break;
            case 5:
                printf("------------Listado por carné de identidad y el tiempo que demorará en pagar el crédito.------------\n");
                tiempoPagarCredito(usuarioPersonal.filasGuardadPersonas, usuarioPersonal.informacionesNecesarias, usuarioPersonal.puedenRecibirCredito, 8);
                break;
            case 6:
                usuarioPersonal.capacidadPorEncima();
                break;
            case 7:
                printf("------------Listado por empresa y el tiempo que demorará en pagar el crédito.------------\n");
                tiempoPagarCredito(UsuarioEmpresa.filasGuardadEmpresa, UsuarioEmpresa.informacionesEmpresa, UsuarioEmpresa.puedenRecibirCreditoEmpresarial, 9);
                break;
            default:
                cout << "No elegiste ninguna de las anteriores, vuelve de nuevo" << endl;
                break;
            };
        };
    }
    return 0;
};