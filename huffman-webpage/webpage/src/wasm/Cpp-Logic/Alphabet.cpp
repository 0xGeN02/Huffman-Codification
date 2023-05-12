#include "Alphabet.h"

/* Constructor de la clase Alphabet
 Toma un texto como entrada y crea un alfabeto a partir de él
 El alfabeto es una lista de caracteres únicos en orden alfabético
 Se asigna a cada carácter un valor binario, comenzando desde el 0 hasta el 9 y luego de la a a la z (10 al 35)
 El valor binario se almacena en el mapa char_to_binary
*/ 

Alphabet::Alphabet(const string& text) {
    string sorted_text(text);
    sort(sorted_text.begin(), sorted_text.end());
    vector<char> unique_chars;
    for (char c : sorted_text) {
        if (find(unique_chars.begin(), unique_chars.end(), c) == unique_chars.end()) {
            unique_chars.push_back(c);
        }
    }
    alphabet = unique_chars;
    for (int i = 0; i < alphabet.size() + 10; i++) {
        if (i < 10) {
            char_to_binary['0' + i] = i;
        } else {
            char_to_binary[alphabet[i - 10]] = i;
        }
    }
}


/*
Destructor de la clase Alphabet
*/
Alphabet::~Alphabet(){
 //No hay memoria dinamica por lo que no es necesario el destructor de clase
}

/* Funcion Aphabet::encode*/
//Esta funcion tiene que coger un text y a cada letra y numero asignar un valor por orden alphabetico y numeral de la siguiente forma:
/*
    1- Leer el el texto 
    2- Asignar un valor en binario de menor a mayor empezando desde el 0 hasta el 9 y luego desde la letra a hasta la z
        Texto ej:
        Hola 12.
        Asignamos valores transformando numeros y letras en orden del 0 al 9 y de la a a la z  1= 00001 ; 2=00010; a=00111; h=10010; l=10110; o= 11001;
        Encoded text:
        10010 11001 10110 00111 00001 00010.
        Como ves se tienen en cuenta los espacios en blanco y los caracteres especiales como el punto no se codifican ni cambian pero no se desprecian

*/

string Alphabet::encode(const string& text) const {
    string encoded_text;
    for (char c : text) {
        if (char_to_binary.find(c) != char_to_binary.end()) {
            int binary_value = char_to_binary.at(c);
            string binary_string = bitset<6>(binary_value).to_string();
            encoded_text += binary_string;
            encoded_text += " ";
        } 
        else {
            encoded_text += c;
        }
    }
    return encoded_text;
}

/*Funcion Alphabet::decode*/
//Esta funcion tiene que leer el encoded text generado por la función Alphabet::encode o otro texto llegado por imput desde la pagina web con el funcionamiento:
/*
    1- Obtiene el codigo binario separado por espacios y los caracteres especiales los mantiene como caracter y no lo transforma en binario ni lo cambia de posicion
    2- Decodifica el codigo sabiendo que se le asignan los valores para 0 = 000000, 1 = 0000001... del 0 al 9 y tambien del 10 al 35 en binario para las letras del alfabeto.
        ej:
        Encoded text:
        10010 11001 10110 00111 00001 00010.
        Decoded text:
        Hola 12.
*/

string Alphabet::decode(const string& encoded_text) const {
    string decoded_text;
    string current_binary_string;
    for (char c : encoded_text) {
        if (c == ' ') {
            if (!current_binary_string.empty()) {
                int binary_value = stoi(current_binary_string, nullptr, 2);
                if (binary_value < 10) {
                    decoded_text += ('0' + binary_value);
                } else {
                    decoded_text += alphabet[binary_value - 10];
                }
            }
            current_binary_string.clear();
        } else {
            current_binary_string += c;
        }
    }
    if (!current_binary_string.empty()) {
        int binary_value = stoi(current_binary_string, nullptr, 2);
        if (binary_value < 10) {
            decoded_text += ('0' + binary_value);
        } else {
            decoded_text += alphabet[binary_value - 10];
        }
    }
    return decoded_text;
}


