# MentorBit-CANBus

Esta librería está diseñada para que puedas integrar tu placa MentorBit en **redes de comunicación CAN Bus**, el estándar utilizado en automoción y en multitud de sistemas industriales.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de Distancia Láser.](https://github.com/DigitalCodesign/MentorBit-CANBus/blob/main/assets/Laser_ranging_module.png)

Con esta librería, podrás enviar y recibir mensajes en una red CAN, permitiéndote crear proyectos que interactúen con vehículos, sistemas de control distribuido o robots complejos.

---

## Descripción

### ¿Qué es el CAN Bus?

El **CAN Bus (Controller Area Network)** es un protocolo de comunicación robusto diseñado para permitir que microcontroladores y dispositivos se comuniquen entre sí dentro de un vehículo o sistema automatizado sin necesidad de un ordenador central. Es conocido por su alta fiabilidad y resistencia a las interferencias, lo que lo hace ideal para entornos exigentes como el de un coche.

Gracias a este protocolo, diferentes partes de un sistema (como el motor, los frenos ABS, los sensores, etc.) pueden compartir información de forma eficiente.

---

### ¿Qué hace esta librería?

La librería **MentorBit-CAN-Bus** actúa como un puente entre tu placa MentorBit y el módulo CAN Bus. Simplifica enormemente la comunicación, gestionando los comandos I2C necesarios para enviar y recibir tramas CAN.

Te permite centrarte en la lógica de tu proyecto (qué hacer con los datos del coche, por ejemplo) sin preocuparte por los detalles de bajo nivel del protocolo de comunicación con el módulo.

---

### ¿Qué puedes construir con este módulo?

- Un lector de datos OBD-II para tu coche, mostrando la velocidad, las RPM o la temperatura del motor en una pantalla.
- Un salpicadero personalizado que muestre información del vehículo en tiempo real.
- Sistemas de control para proyectos de robótica donde varios componentes necesitan comunicarse de forma fiable.
- Proyectos de domótica o automatización industrial que utilicen CAN como bus de comunicación.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo CAN Bus al puerto marcado como I2C en la sección de comunicaciones de la placa MentorBit. El módulo utiliza el protocolo I2C para comunicarse con la placa.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-CANBus*** y haz clic en "Instalar".
- El IDE también instalará las dependencias necesarias automáticamente.

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-CANBus/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer mensajes CAN

Este ejemplo comprueba continuamente si se ha recibido un nuevo mensaje en el bus CAN y, si es así, lo imprime a través del monitor serie.

```cpp
#include <MentorBitCANBus.h>

// Creamos el objeto para nuestro módulo CAN Bus
MentorBit_CANBus miCAN;

// Creamos una estructura para almacenar los mensajes
struct can_frame miFrame;

void setup() {
    // Inicializamos el monitor serial
    Serial.begin(9600);
    
    // Inicializamos el módulo CAN Bus en su dirección I2C por defecto (0x05)
    miCAN.begin(); 
    
    Serial.println("Módulo CAN Bus listo. Escuchando mensajes...");
}

void loop() {
    // Preguntamos al módulo si hay algún mensaje disponible
    if (miCAN.available()) {
        // Si hay un mensaje, lo leemos y lo guardamos en nuestra estructura
        if (miCAN.readMessage(&miFrame)) {
            Serial.print("Mensaje Recibido -> ");
            Serial.print("ID: 0x");
            Serial.print(miFrame.can_id, HEX);
            Serial.print(" | DLC: ");
            Serial.print(miFrame.can_dlc);
            Serial.print(" | Datos: ");
            
            for (int i = 0; i < miFrame.can_dlc; i++) {
                Serial.print(miFrame.data[i], HEX);
                Serial.print(" ");
            }
            Serial.println();
        }
    }
}
```

---

## Funciones Principales

- `void begin(uint8_t i2c_addr = 0x05)`  
  Inicializa la comunicación I2C con el módulo. Opcionalmente, puedes especificar una dirección I2C si la has cambiado.

- `bool available()`  
  Devuelve <code>true</code> si hay una trama CAN disponible para leer en el buffer del módulo.

- `bool readMessage(struct can_frame *frame)`  
  Lee la trama CAN disponible y la almacena en la estructura <code>can_frame</code> que se le pasa como puntero. Devuelve <code>true</code> si la lectura fue exitosa.

- `bool sendMessage(struct can_frame *frame)`  
  Envía la trama CAN contenida en la estructura <code>can_frame</code> a través del bus. Devuelve <code>true</code> si el envío fue exitoso.

- `bool configI2CAddress(uint8_t new_i2c_address)`  
  Permite cambiar la dirección I2C del módulo por una nueva. (Función de configuración avanzada).

- `bool configCANBitrate(uint8_t new_can_bitrate)`  
  Permite cambiar la velocidad del bus CAN (bitrate). El valor <code>new_can_bitrate</code> suele ser una constante definida en el firmware del módulo. (Función de configuración avanzada).

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo CAN Bus]()
- [Manual de usuario del Módulo]()
- [Modelo 3D del Módulo CAN Bus en formato .STEP]()
