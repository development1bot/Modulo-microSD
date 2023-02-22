//Incluye la libreria para el modulo SD 
#include <SD.h>
#include <SPI.h>

File myFile; //Crea un objeto para el uso de la libreria 

void setup()
{
  Serial.begin(9600); // Inicia la comunicacion serial 
  Serial.print("Iniciando SD ..."); //Imprime un mensaje de iniciacion de modulo SD
  if (!SD.begin()) {  //Inicia el modulo SD y escribe el numero de pin de CS dentro de los parentesis
    Serial.println("No se pudo inicializar"); //Si existe un error en la comunicacion entonces muestra un mensaje de "No se pudo inicializar"
    return; //Retorna de nuevo para volver a probar 
  }
  Serial.println("inicializacion exitosa"); //Imprime un mensaje de iniciacion exitosa
 
}

void loop()
{
  myFile = SD.open("datos.txt", FILE_WRITE); //abrimos  el archivo. le asignamos un nombre y el tipo de archivo. 
  
  if (myFile) {   //Si esta disponible "myFile" entonces empezamos a escribir ("Guardar") 
        Serial.print("Escribiendo SD: ");
        int sensor1 = analogRead(0); //Realiza una lectura analoga y almacena el valor "sensor1"
        int sensor2 = analogRead(1); //Realiza una lectura analoga y almacena el valor "sensor2"
        int sensor3 = analogRead(2); //Realiza una lectura analoga y almacena el valor "sensor3"
        myFile.print("Tiempo(ms)="); //Almacena el valor en "myFile" con el texto "Tiempo(ms)=" 
        myFile.print(millis());      //Almacena el valor en "myFile" con el valor de millis que es el tiempo recorrido 
        myFile.print(", sensor1=");  //Almacena el valor en "myFile" con el texto "sensor1="
        myFile.print(sensor1);       //Almacena el valor en "myFile" con el valor del sensor1
        myFile.print(", sensor2=");  //Almacena el valor en "myFile" con el texto "sensor2"
        myFile.print(sensor2);       //Almacena el valor en "myFile" con el valor de sensor2
        myFile.print(", sensor3=");  //Almacena el valor en "myFile" con el texto de sensor 3
        myFile.println(sensor3);     //Almacena el valor de "myFile" con el valor de sensor3 
        
        myFile.close(); //cerramos el archivo
        
        Serial.print("Tiempo(ms)="); //Imprime el texto "Tiempo(ms)=" en el puerto Monitor Serial
        Serial.print(millis());      //Imprime el valor tiempo en el puerto Monitor Serial
        Serial.print(", sensor1=");  //Imprime el texto "sensor1=" en el puerto Monitor Serial
        Serial.print(sensor1);       //Imprime el valor del sensor1 en el puerto Monitor Serial
        Serial.print(", sensor2=");  //Imprime el texto "sensor2" en el puerto Monitor Serial
        Serial.print(sensor2);       //Imprime el valor del sensor2 en el puerto Monitor Serial
        Serial.print(", sensor3=");  //Imprime el texto "sensor3" en el puerto Monitor Serial
        Serial.println(sensor3);     //Imprime el valor del sensor3 en el puerto Monitor Serial            
  }
   else { //Si no hay conexion exitosa entonces muestra este mensaje 
    Serial.println("Error al abrir el archivo"); //Imprime un mensaje de error si algo sale mal.
  }
  delay(1000); //Espera 100 milisegundos entre cada medicion. 
}