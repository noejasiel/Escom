    FILE *flujo = fopen("prueba.txt", "rb");
    if(flujo == NULL){
        printf("f bro error");
        return 1;
    }

    fseek(flujo, 0, SEEK_END); //se movera al final de elementos
    int num_elemetos = ftell(flujo);
    rewind(flujo); // se ira otra vez al inicio de mi archivo

    char* cadena = (char *) calloc(sizeof(char), num_elemetos);
    if(cadena == NULL){
        perror("error en la me,memoria");
        return 2;
    }

    //guardar
    int num_elemetos_leidos = fread(cadena, sizeof(char),num_elemetos, flujo);
    if(num_elemetos_leidos != num_elemetos){
        perror("error al leer memoria");
        return 3;
    }
    int* arr  = (int*) calloc(sizeof(int), num_elemetos);
    //int arr[num_elemetos];
    arr = ascii(cadena, num_elemetos);
   /* for (int i = 0; i < num_elemetos; ++i)
    {
        printf("%d ", arr[i]);
    }*/
    
    int* bin  = (int*) calloc(sizeof(int), num_elemetos);
    bin = binario(arr, num_elemetos);
     for (int i = 0; i < num_elemetos; ++i)
    {
        printf("%d j", bin[i]);
    }

    free(cadena);
    fclose(flujo);