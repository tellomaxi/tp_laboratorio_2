typedef  struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int inicializarEmployees(eEmployee list[], int len);
int findEmptyEmpleado(eEmployee list[],int len);
int findEmpleado(eEmployee list[],int len, int id);

int addEmpleado(eEmployee list[], int len);

void modificarEmpleado(eEmployee list[], int len);


//int removeEmpleado(eEmployee* list, int len);

int sortEmployees(eEmployee list[], int len);

void viewEmpleado(eEmployee sEmpleado);
void viewEmpleados(eEmployee list[], int len);

int funcionOpciones();
int funcionOpcionesModificacionEmpleado();
