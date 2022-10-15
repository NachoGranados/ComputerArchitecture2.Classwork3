### Instalación de dependencias

Antes de ejecutar los ejercicios, es necesario instalar las siguientes dependencias:
```bash
sudo apt update
sudo apt install gcc
sudo apt install build-essential
```

### Ejecución de los ejercios

Para ejecutar el archivo helloWorld.c, se deben colocar los siguientes comandos en la terminal:
```bash
gcc -o helloWorld helloWorld.c
./helloWorld
```

Para ejecutar el archivo maxColumnNumber.c, se deben colocar los siguientes comandos en la terminal:
```bash
gcc -o maxColumnNumber maxColumnNumber.c -msse4.1
./maxColumnNumber
```

Para ejecutar el archivo multMatrixVector.c, se deben colocar los siguientes comandos en la terminal:
```bash
gcc -o multMatrixVector multMatrixVector.c -msse4.1
./multMatrixVector
```
