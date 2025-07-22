/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Enero de 2024
    Fecha de version: Enero de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-CANBus
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit CAN
    Metodos principales:
        MentorBitCANBus -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup
        configI2CAddress -> configura la dirección I2C del módulo
        configCANBitrate -> configura el bitrate para las comunicaciones CAN del módulo
        available -> comprueba si hay un nuevo mensaje CAN recibido
        readMessage -> lee un mensaje CAN del buffer
        sendMessage -> envía un mensaje CAN al bus

*/

#include <MentorBitCANBus.h>

MentorBit_CANBus::MentorBit_CANBus() {

}

void MentorBit_CANBus::begin(uint8_t i2c_addr = 0x05) {}
bool MentorBit_CANBus::configI2CAddress(uint8_t new_i2c_address) {}
bool MentorBit_CANBus::configCANBitrate(uint8_t new_can_bitrate) {}
bool MentorBit_CANBus::available() {}
bool MentorBit_CANBus::readMessage(struct can_frame *frame){}
bool MentorBit_CANBus::sendMessage(struct can_frame * frame) {}
