#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <ios>
using namespace std;

class Banco
{
protected:
    string nombreDelSolicitante;
    int valorCredito;
    string direccion;

public:
    void forGuardar(int, int, int, string[100][100], string[100][100]);
    void modeloMostrarDatos(int, int, string[8], string[100][100]);
    void mensualidadesPagar();
    void tiempoParaPagar();
    void valorDestinadoCredito();
};

void Banco::forGuardar(int Filas, int filaGuardad, int filaRecorrer, string arrayPuede[100][100], string arrayGuardado[100][100])
{
    for (int I = 0; I < filaRecorrer; I++)
    {
        arrayPuede[filaGuardad][I] = arrayGuardado[Filas][I];
    };
};

void Banco::modeloMostrarDatos(int filas, int colunas, string informacionModelo[8], string arrayDeDatos[100][100])
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

void Banco::mensualidadesPagar(){

};

void Banco::tiempoParaPagar(){

};

void Banco::valorDestinadoCredito(){

};

class CreditoPersonal : public Banco
{
protected:
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

public:
    string datosCreditoPersonal[100][100];
    int filasPersonas = 0;
    int filasGuardadPersonas = 0;
    void incresarDatosPersonal();
    void mostrarCreditoPersonal();
    void opcionesMostrarDatos();
    void capacidadPorEncima();
} da;

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
    cout << "Listado con las personas con capacidad de pago por encima de los 200 pesos" << endl;
    modeloMostrarDatos(contadorEncima, 9, informacionesNecesarias, PorEncima);
}

void CreditoPersonal::incresarDatosPersonal()
{
    for (int I = 0; I < filasPersonas; I++)
    {
        cin.ignore();

        for (int J = 0; J < 6; J++)
        {
            cout << "Usuario " << I + 1 << ", Agregar " << informacionesNecesarias[J] << "[ " << I << " ] [ " << J << " ] : ";
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
};

void CreditoPersonal::mostrarCreditoPersonal()
{
    modeloMostrarDatos(filasGuardadPersonas, 9, informacionesNecesarias, puedenRecibirCredito);
};

void CreditoPersonal::opcionesMostrarDatos()
{
    char opcionesMostrar;
    cout << "--------------------Cual de las siguientes opciones quieres elegir--------------------" << endl;
    cout << "A) Un listado ordenado por el número de carné de identidad con todas las personas que puedan recibir el crédito" << endl;
    cout << "B) El valor total del dinero que se destinará al crédito." << endl;
    cout << "C) las mensualidades a pagar" << endl;
    cout << "D) Determine y visualice un listado con el número del carné de identidad y el tiempo que demorará en pagar el crédito" << endl;
    cout << "E) Listado con las personas con capacidad de pago por encima de los 200 pesos" << endl;

    cin >> opcionesMostrar;
    switch (opcionesMostrar)
    {
    case 'a':
        mostrarCreditoPersonal();
        break;
    case 'b':
        valorDestinadoCredito();
        break;
    case 'c':
        mensualidadesPagar();
        break;
    case 'd':
        tiempoParaPagar();
        break;
    case 'e':
        capacidadPorEncima();
        break;
    default:
        cout << "No elegiste ninguna de las anteriores, vuelve de nuevo" << endl;
        break;
    }
};

class CreditoEmpresa : public Banco
{
protected:
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
        "Mensualidades a pagar",
    };

public:
    string datosCreditoEmpresarial[100][100];
    int filasEmpresas;
    int filasGuardadEmpresa = 0;
    void incresarDatosEmpresarial();
    void opcionesMostrarDatosEmpresas();
    void mostrarCreditoEmpresa();
};

void CreditoEmpresa::incresarDatosEmpresarial()
{

    for (int I = 0; I < filasEmpresas; I++)
    {
        cin.ignore();
        for (int J = 0; J < 9; J++)
        {
            cout << "Usuario " << I << ", Agregar " << informacionesEmpresa[J] << "[ " << I << " ] [ " << J << " ] : ";
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
                    cout << ValorEnPorcentaje << endl;
                    forGuardar(I, filasGuardadEmpresa, 11, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                    filasGuardadEmpresa = filasGuardadEmpresa + 1;
                }
            }
        };
    };
}

void CreditoEmpresa::mostrarCreditoEmpresa()
{
    modeloMostrarDatos(filasEmpresas, 11, informacionesEmpresa, datosCreditoEmpresarial);
};

void CreditoEmpresa::opcionesMostrarDatosEmpresas()
{
    char opcionesMostrar;
    cout << "-------------------- Cual de las siguientes opciones quieres elegir --------------------" << endl;
    cout << "A) Un listado ordenado por ministerio y código de todas las empresas que puedan recibir el crédito" << endl;
    cout << "B) El valor total del dinero que se destinará al crédito." << endl;
    cout << "C) las mensualidades a pagar" << endl;
    cout << "D) Determine y visualice un listado por empresa y el tiempo que demorará en pagar el crédito." << endl;

    cin >> opcionesMostrar;
    switch (opcionesMostrar)
    {
    case 'a':
        mostrarCreditoEmpresa();
        break;
    case 'b':
        valorDestinadoCredito();
        break;
    case 'c':
        mensualidadesPagar();
        break;
    case 'd':
        tiempoParaPagar();
        break;
    default:
        cout << "No elegiste ninguna de las anteriores, vuelve de nuevo" << endl;
        break;
    };
};

int main()
{
    int tipoCredito;
    int filasP;
    int filasE;
    CreditoPersonal usuarioPersonal;
    CreditoEmpresa UsuarioEmpresa;
    // cout << usuarioPersonal.datosCreditoPersonal[0][0] << endl;
    cout << "-------------------- Bienvenido al Banco UAPA --------------------" << endl;
    cout << "Que tipo de credito quieres:" << endl;
    while (tipoCredito != 4)
    {
        cout << "1 - Credito Personal" << endl;
        cout << "2 - Credito para una empresa" << endl;
        cout << "3 - Las necesidades del Banco" << endl;
        cout << "4 - Salir" << endl;
        cout << "Eligue uno: ";
        cin >> tipoCredito;
        if (tipoCredito == 1)
        {
            cout << "Necesitamos que increses algunas informaciones ante para tu credito personal" << endl;
            cout << "Cuantas Personas piensas agregar: ";
            cin >> usuarioPersonal.filasPersonas;
            // usuarioPersonal.filasPersonas = usuarioPersonal.filasPersonas + filasP;
            // system("cls");
            usuarioPersonal.incresarDatosPersonal();
            usuarioPersonal.opcionesMostrarDatos();
            // usuarioPersonal.capacidadPorEncima();
        };
        if (tipoCredito == 2)
        {
            cout << "Necesitamos que increses algunas informaciones ante para tu credito empresarial:" << endl;
            cout << "Cuantas Empresas piensas agregar: " << endl;
            cin >> UsuarioEmpresa.filasEmpresas;
            UsuarioEmpresa.incresarDatosEmpresarial();
            UsuarioEmpresa.opcionesMostrarDatosEmpresas();
            // UsuarioEmpresa.mostrarCreditoEmpresa();
        };

        if (tipoCredito == 3)
        {
            char tipo;
            string noPermitido = "Tienes que incresar datos para poder ver estas necesidades del programa, vuelve al inicio.";
            cout << "Las necesidades del credito, A) Personal o B) Empresarial : " << endl;
            cin >> tipo;
            switch (tipo)
            {
            case 'a':
                if (usuarioPersonal.datosCreditoPersonal[0][0].empty())
                {
                    cout << noPermitido << endl;
                    break;
                }
                else
                {
                    usuarioPersonal.opcionesMostrarDatos();
                }
            case 'b':
                if (UsuarioEmpresa.datosCreditoEmpresarial[0][0].empty())
                {
                    cout << noPermitido << endl;
                    break;
                }
                else
                {
                    UsuarioEmpresa.opcionesMostrarDatosEmpresas();
                }
            default:
                cout << "No elegiste ninguna de las anteriores, vuelve de nuevo" << endl;
                break;
            };
        };
    };
    return 0;
};