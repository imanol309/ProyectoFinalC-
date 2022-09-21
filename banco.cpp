#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Banco
{
protected:
    string nombreDelSolicitante;
    int valorCredito;
    string direccion;

public:
    void mostrarCredito();
};

void Banco::mostrarCredito()
{
    cout << "Nombre del solicitantes: " << nombreDelSolicitante << endl;
    cout << "Valor por el que pide el crédito: " << valorCredito << endl;
    cout << "Dirección: " << direccion << endl;
};

class CreditoPersonal : public Banco
{
protected:
    string carneDeIndetidad;
    int salarioTotal;
    int cantidadBajoSustento;
    string datosCreditoPersonal[100][100];
    string puedenRecibirCredito[100][100];
    string informacionesNecesarias[6] = {"Nombre del solicitante",
                                         "Valor por el que pide el crédito",
                                         "Dirección",
                                         "Carné de identidad del cliente",
                                         "Salario total del núcleo",
                                         "Cantidad de personas bajo su sustento"};

public:
    int filasPersonas;
    void incresarDatosPersonal();
    void mostrarCreditoPersonal();
    void opcionesMostrarDatos();
};

void forGuardar(int Filas, string arrayPuede[100][100], string arrayGuardado[100][100])
{
    for (int P = 0; P < Filas; P++)
    {
        for (int I = 0; I < 6; I++)
        {
            arrayPuede[P][I] = arrayGuardado[P][I];
        };
    };
};

void CreditoPersonal::incresarDatosPersonal()
{
    for (int I = 0; I < filasPersonas; I++)
    {
        for (int J = 0; J < 6; J++)
        {
            cout << "Usuario " << I + 1 << ", Agregar " << informacionesNecesarias[J] << "[ " << I << " ] [ " << J << " ] : ";
            cin >> datosCreditoPersonal[I][J];
            // getline (cin, datosCreditoPersonal[i][j]);
            if (datosCreditoPersonal[I][J] == datosCreditoPersonal[I][5])
            {
                if (stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50) > 100)
                {
                    cout << I << endl;
                    cout << "ENTRO" << endl;
                    forGuardar(I, puedenRecibirCredito, datosCreditoPersonal);
                };
            };
        };
    };
};

void CreditoPersonal::mostrarCreditoPersonal()
{
    printf("+-----------------------------------------\n");
    for (int i = 0; i < filasPersonas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << "|";
            std::cout
                << std::right << std::setw(43)
                << informacionesNecesarias[j] << ": " << puedenRecibirCredito[i][j] << '\t' << '\n';
        };
        printf("+-----------------------------------------\n");
    };
    cout << endl;
};

void CreditoPersonal::opcionesMostrarDatos()
{
    cout << "Opciones" << endl;
};

class CreditoEmpresa : public Banco
{
protected:
    string nombreDirector;
    string direccionDeEmpresa;
    int gananciaPromedioAnual;
    int cantidadTrabajadores;
    string ministerioPertence;
    string codigo;
    int contadorEmpresarial;
    string datosCreditoEmpresarial[100][100];
    string puedenRecibirCreditoEmpresarial[100][100];
    string informacionesEmpresa[6] = {
        "El nombre del director",
        "Dirección del mismo",
        "Ganancia anual promedio durante los últimos 5 años",
        "Cantidad de trabajadores",
        "Ministerio al cual pertenece",
        "Código"};

public:
    int filasEmpresas;
    void incresarDatosEmpresarial();
    void mostrarCreditoEmpresa();
};

void CreditoEmpresa::incresarDatosEmpresarial()
{

    for (int I = 0; I < filasEmpresas; I++)
    {
        for (int J = 0; J < 6; J++)
        {
            cout << "Usuario " << I << ", Agregar " << informacionesEmpresa[contadorEmpresarial++] << "[ " << I << " ] [ " << J << " ] : " << endl;
            cin >> datosCreditoEmpresarial[I][J];
            if (datosCreditoEmpresarial[I][J] == datosCreditoEmpresarial[I][5])
            {
                if (stoi(datosCreditoEmpresarial[I][3]) > 300 && stoi(datosCreditoEmpresarial[I][2]) >= 10000)
                {
                    forGuardar(I, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                }
                if (stoi(datosCreditoEmpresarial[I][3]) < 300 && stoi(datosCreditoEmpresarial[I][2]) >= 5000)
                {
                    forGuardar(I, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                }
                if (stoi(datosCreditoEmpresarial[I][3]) < 100 && stoi(datosCreditoEmpresarial[I][2]) >= 1000)
                {
                    forGuardar(I, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                }
            }
        };
    };
}

void CreditoEmpresa::mostrarCreditoEmpresa()
{
    for (int i = 0; i < filasEmpresas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << puedenRecibirCreditoEmpresarial[i][j] << " | ";
        };
        cout << endl;
    };
};

int main()
{
    int tipoCredito;

    CreditoPersonal usuarioPersonal;
    CreditoEmpresa UsuarioEmpresa;

    while (tipoCredito != 3)
    {
        cout << "Bienvenido al Banco UAPA, que tipo de credito quieres:" << endl;
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
            usuarioPersonal.opcionesMostrarDatos();
        };
        if (tipoCredito == 2)
        {
            cout << "Necesitamos que increses algunas informaciones para tu credito empresarial:" << endl;
            cout << "Cuantas empresas piensas agregar: " << endl;
            cin >> UsuarioEmpresa.filasEmpresas;
            UsuarioEmpresa.incresarDatosEmpresarial();
            UsuarioEmpresa.mostrarCreditoEmpresa();
        };
    };
    return 0;
};