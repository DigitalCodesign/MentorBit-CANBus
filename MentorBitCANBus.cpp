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

void MentorBit_CANBus::begin(uint8_t i2c_addr = 0x05) {

    _i2c_address = i2c_addr;
    _frame_length = 0;
    Wire.begin(_i2c_address);

}

bool MentorBit_CANBus::configI2CAddress(uint8_t new_i2c_address) {

    Wire.beginTransmission();
    Wire.write(CHANGE_I2C_ADDRESS);
    Wire.write(new_i2c_address);
    return Wire.endTransmission();

}

bool MentorBit_CANBus::configCANBitrate(uint8_t new_can_bitrate) {

    Wire.beginTransmission();
    Wire.write(CHANGE_CAN_BITRATE);
    Wire.write(new_can_bitrate);
    return Wire.endTransmission();

}

bool MentorBit_CANBus::available() {

    Wire.beginTransmission();
    Wire.write(CONFIRM_BUFFER_BYTES);
    if(Wire.endTransmission() != 0) return false;
    uint8_t received_bytes = Wire.requestFrom(_i2c_address, (uint8_t)2);
    if(received_bytes < 2) return false;
    uint8_t available_flag = Wire.read();
    _frame_length = Wire.read();
    if(available_flag != I2C_BYTES_HEADER) return false;
    return true;

}

bool MentorBit_CANBus::readMessage(struct can_frame *frame){

    Wire.beginTransmission();
    Wire.write(SEND_I2C_BUFFER);
    if(Wire.endTransmission() != 0) return false;
    uint8_t received_bytes = Wire.requestFrom(_i2c_address, _frame_length);
    if(received_bytes < _frame_length) return false;
    frame->can_id = (Wire.read() << 8) | Wire.read();
    frame->can_dlc = Wire.read();
    for(uint8_t i = 0 ; i < _frame_length ; i++)
        frame->data[i] = Wire.read();
    return true;

}

bool MentorBit_CANBus::sendMessage(struct can_frame * frame) {

    Wire.beginTransmission();
    Wire.write(SEND_BYTES_TO_CAN);
    Wire.write(frame->can_id >> 8);
    Wire.write(frame->can_id & 0xFF);
    Wire.write(frame->can_dlc);
    for(uint8_t i = 0 ; i < frame->can_dlc ; i++)
        Wire.write(frame->data[i]);
    if(Wire.endTransmission() != 0) return false;
    return true;

}
