void mostrarListaProductos(const char* nombreArchivo);
void editarProducto(char nombres[][50], int cantidades[], float precios[], int *cantidadTipos);
void guardarProductosEnArchivo(char nombres[][50], int cantidades[], float precios[], int cantidadTipos, const char* nombreArchivo);
void leerProductosDeArchivo(char nombres[][50], int cantidades[], float precios[], int* cantidadTipos, const char* nombreArchivo);

void gestionarProducto(char nombres[][50], int cantidades[], float precios[], int *cantidadTipos);
void quitarProducto(char nombres[][50], int cantidades[], float precios[], int* cantidadTipos);

