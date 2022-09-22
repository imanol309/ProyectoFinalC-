#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include<vector>
#include<ios>
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

class CreditoPersonal : public Banco
{
protected:
    string datosCreditoPersonal[100][100];
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
    int filasPersonas;
    int filasGuardadPersonas = 0;
    void incresarDatosPersonal();
    void mostrarCreditoPersonal();
    void opcionesMostrarDatos();
    void capacidadPorEncima();
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
    cout << "Listado con las personas con capacidad de pago por encima de los 200 pesos" << endl;
    modeloMostrarDatos(contadorEncima, 9, informacionesNecesarias, PorEncima);
}

void CreditoPersonal::incresarDatosPersonal()
{
    for (int I = 0; I < filasPersonas; I++)
    {
        for (int J = 0; J < 6; J++)
        {
            cout << "Usuario " << I + 1 << ", Agregar " << informacionesNecesarias[J] << "[ " << I << " ] [ " << J << " ] : ";
            // cin >> datosCreditoPersonal[I][J];
            cin.ignore();
            // string datos[I][J] = datosCreditoPersonal[I][J];
            getline(std::cin, datosCreditoPersonal[I][J]);
            // getline (cin, datosCreditoPersonal[i][j]);
            cout << datosCreditoPersonal[I][J] << endl;
            // if (datosCreditoPersonal[I][J] == datosCreditoPersonal[I][5])
            // {
            //     if (stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50) > 100)
            //     {
            //         datosCreditoPersonal[I][6] = to_string(stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50)) + "Pesos";
            //         int D6 = stoi(datosCreditoPersonal[I][6]);
            //         datosCreditoPersonal[I][7] = (D6 > 140) ? "50 Pesos" : (D6 <= 140 && D6 >= 121) ? "40 Pesos"
            //                                                            : (D6 <= 120 && D6 >= 100)   ? "30 Pesos"
            //                                                                                         : "";
            //         datosCreditoPersonal[I][8] = to_string(D6 / stoi(datosCreditoPersonal[I][7])) + " Meses";
            //         forGuardar(I, filasGuardadPersonas, 10, puedenRecibirCredito, datosCreditoPersonal);
            //         filasGuardadPersonas = filasGuardadPersonas + 1;
            //     };
            // };
        };
        printf("+--------------------------------------------------------+\n");
    };
};

void CreditoPersonal::mostrarCreditoPersonal()
{
    modeloMostrarDatos(filasGuardadPersonas, 10, informacionesNecesarias, datosCreditoPersonal);
};

void CreditoPersonal::opcionesMostrarDatos()
{
    cout << "Opciones" << endl;
};

class CreditoEmpresa : public Banco
{
protected:
    string datosCreditoEmpresarial[100][100];
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
    int filasEmpresas;
    int filasGuardadEmpresa = 0;
    void incresarDatosEmpresarial();
    void mostrarCreditoEmpresa();
};

void CreditoEmpresa::incresarDatosEmpresarial()
{

    for (int I = 0; I < filasEmpresas; I++)
    {
        for (int J = 0; J < 9; J++)
        {
            cout << "Usuario " << I << ", Agregar " << informacionesEmpresa[J] << "[ " << I << " ] [ " << J << " ] : " << endl;
            cin >> datosCreditoEmpresarial[I][J];

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

int main()
{
    int tipoCredito;
    CreditoPersonal usuarioPersonal;
    CreditoEmpresa UsuarioEmpresa;
    cout << "Bienvenido al Banco UAPA, que tipo de credito quieres:" << endl;
    while (tipoCredito != 3)
    {
        cout << "1 - Credito Personal" << endl;
        cout << "2 - Credito para una empresa" << endl;
        cout << "3 - Salir" << endl;
        cout << "Eligue uno: ";
        cin >> tipoCredito;
        if (tipoCredito == 1)
        {
            cout << "Necesitamos que increses algunas informaciones para tu credito personal" << endl;
            cout << "Cuantas Personas piensas agregar: ";
            cin >> usuarioPersonal.filasPersonas;
            // system("cls");
            usuarioPersonal.incresarDatosPersonal();
            usuarioPersonal.mostrarCreditoPersonal();
            usuarioPersonal.capacidadPorEncima();
            // usuarioPersonal.opcionesMostrarDatos();
        };
        if (tipoCredito == 2)
        {
            cout << "Necesitamos que increses algunas informaciones para tu credito empresarial:" << endl;
            cout << "Cuantas Empresas piensas agregar: " << endl;
            cin >> UsuarioEmpresa.filasEmpresas;
            UsuarioEmpresa.incresarDatosEmpresarial();
            UsuarioEmpresa.mostrarCreditoEmpresa();
        };
    };
    return 0;
};