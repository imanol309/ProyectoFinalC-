#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ! Usar mas la clase Banco para que la maestra vea que es orientado a objeto 
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
        "Tiempo en demorara en pagar"};

public:
    int filasPersonas;
    int filasGuardad = 0;

    void incresarDatosPersonal();
    void mostrarCreditoPersonal();
    void opcionesMostrarDatos();
};

void forGuardar(int Filas, int filaGuardad, int filaRecorrer, string arrayPuede[100][100], string arrayGuardado[100][100])
{
    for (int I = 0; I < filaRecorrer; I++)
    {
        arrayPuede[filaGuardad][I] = arrayGuardado[Filas][I];
    };
};

// void capacidadPorEncima(int filaGuardad, string arrayGuardado[100][100]) {
//     int contadorEncima = 0;
//     for(int H = 0; H <filaGuardad; H++) {
//         if (stoi(arrayGuardado[H][6]) > 200) {
//             modeloMostrarDatos(filasGuardad, informacionesNecesarias, puedenRecibirCredito);

//         }
//     }
// }

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
                    datosCreditoPersonal[I][6] = to_string(stoi(datosCreditoPersonal[I][4]) - ((stoi(datosCreditoPersonal[I][5]) + 1) * 50));
                    int D6 = stoi(datosCreditoPersonal[I][6]);
                    datosCreditoPersonal[I][7] = (D6 > 140) ? "50" : (D6 <= 140 && D6 >= 121) ? "40"
                                                                 : (D6 <= 120 && D6 >= 100)   ? "30"
                                                                                              : "";
                    datosCreditoPersonal[I][8] = to_string(D6 / stoi(datosCreditoPersonal[I][7])) + " Meses";
                    forGuardar(I, filasGuardad, 9, puedenRecibirCredito, datosCreditoPersonal);
                    filasGuardad = filasGuardad + 1;
                };
            };
        };
    };
};

void modeloMostrarDatos(int filas, string informacionModelo[8], string arrayDeDatos[100][100])
{
    printf("+-----------------------------------------\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < 9; j++)
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

void CreditoPersonal::mostrarCreditoPersonal()
{
    modeloMostrarDatos(filasGuardad, informacionesNecesarias, puedenRecibirCredito);
    // printf("+-----------------------------------------\n");
    // for (int i = 0; i < filasGuadad; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cout << "|";
    //         std::cout
    //             << std::right << std::setw(43)
    //             << informacionesNecesarias[j] << ": " << puedenRecibirCredito[i][j] << '\t' << '\n';
    //     };
    //     printf("+-----------------------------------------\n");
    // };
    // cout << endl;
};

void CreditoPersonal::opcionesMostrarDatos()
{
    cout << "Opciones" << endl;
};

class CreditoEmpresa : public Banco
{
protected:
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
    int filasGuardadEmpresa = 0;
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
                // *TODO:  Tengo que refactorizar este codigo ante de entregar, LO PUEDO LOGAR CON EL OPERADOR TERNACION DE C++
                if (stoi(datosCreditoEmpresarial[I][3]) > 300 && stoi(datosCreditoEmpresarial[I][2]) >= 10000)
                {
                    forGuardar(I, filasGuardadEmpresa, 6, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                    filasGuardadEmpresa = filasGuardadEmpresa + 1;
                }
                if (stoi(datosCreditoEmpresarial[I][3]) < 300 && stoi(datosCreditoEmpresarial[I][2]) >= 5000)
                {
                    forGuardar(I, filasGuardadEmpresa, 6, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                    filasGuardadEmpresa = filasGuardadEmpresa + 1;
                }
                if (stoi(datosCreditoEmpresarial[I][3]) < 100 && stoi(datosCreditoEmpresarial[I][2]) >= 1000)
                {
                    forGuardar(I, filasGuardadEmpresa, 6, puedenRecibirCreditoEmpresarial, datosCreditoEmpresarial);
                    filasGuardadEmpresa = filasGuardadEmpresa + 1;
                }
            }
        };
    };
}

void CreditoEmpresa::mostrarCreditoEmpresa()
{
    modeloMostrarDatos(filasGuardadEmpresa, informacionesEmpresa, puedenRecibirCreditoEmpresarial);
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