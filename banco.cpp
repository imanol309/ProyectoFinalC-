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
    int contadorPersonal = 0;
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

void CreditoPersonal::incresarDatosPersonal()
{

    for (int i = 0; i < filasPersonas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << "Usuario " << i << ", Agregar " << informacionesNecesarias[contadorPersonal++] << "[ " << i << " ] [ " << j << " ] : " << endl;
            cin >> datosCreditoPersonal[i][j];
            // if(datosCreditoPersonal[i][j] == datosCreditoPersonal[i][5]) {
            //     if (datosCreditoPersonal[i][4] - (datosCreditoPersonal[i][5] * 50) > 100) {

            //     }
            //     cout << "Entro a" << datosCreditoPersonal[i][5] * 50 << endl;
            // };
        };
    };
};

void CreditoPersonal::mostrarCreditoPersonal()
{
    for (int i = 0; i < filasPersonas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << datosCreditoPersonal[i][j] << " | ";
            // std::cout
            //     << std::right << std::setw(26)
            //     << valor[i][j] << '\n';
        };
        cout << endl;
    };
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
    for (int i = 0; i < filasEmpresas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << "Usuario " << i << ", Agregar " << informacionesEmpresa[contadorEmpresarial++] << "[ " << i << " ] [ " << j << " ] : " << endl;
            cin >> datosCreditoEmpresarial[i][j];
        };
    };
}

void CreditoEmpresa::mostrarCreditoEmpresa()
{
    for (int i = 0; i < filasEmpresas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << datosCreditoEmpresarial[i][j] << " | ";
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
            cout << "Cuantas Personas piensas agregar: " << endl;
            cin >> usuarioPersonal.filasPersonas;
            system("cls");
            usuarioPersonal.incresarDatosPersonal();
            usuarioPersonal.mostrarCreditoPersonal();
            usuarioPersonal.opcionesMostrarDatos();
            // system("PAUSE");
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