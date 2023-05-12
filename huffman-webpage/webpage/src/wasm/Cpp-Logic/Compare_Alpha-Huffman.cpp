#include "Alphabet.h"
#include "HuffmanTree.h"

/*
La función "Alphabet_Huffman__Encode_Comparator" compara la longitud en bytes de dos codificaciones de texto: una codificación de Huffman y una codificación alfabética.
Si la codificación de Huffman es más corta que la codificación alfabética, se imprime un mensaje indicando que la codificación de Huffman mejoró la codificación alfabética y en cuántos bytes se ahorró al codificar el texto de entrada.
Si la codificación de Huffman es más larga que la codificación alfabética, se imprime un mensaje indicando que la codificación de Huffman no pudo mejorar la codificación alfabética y en cuántos bytes la codificación alfabética es mejor que la codificación de Huffman al codificar el texto de entrada.
Si ambas codificaciones tienen la misma longitud en bytes, se compara la diferencia gramatical-lexicográfica entre las dos codificaciones en relación con el texto de entrada. 
La función devuelve un entero que no está siendo utilizado en el código presentado.
*/

void Alphabet_Huffman__Encode_Comparator(const string& huffman_encode, const string& alpha_encode){
    int huffman_length = huffman_encode.length();
    int alpha_length = alpha_encode.length();

    if(huffman_length < alpha_length){
        cout<< "The huffman codification improved the alphabet codification in "<< huffman_length - alpha_length << "bytes at saving memory encoding the imput text.";
    }
    if(huffman_length > alpha_length){
        cout<< "The huffman codification in this case was not able to improve the alphabet codification. The alphabet is  "<< alpha_length - huffman_length << "bytes better at encoding this imput text";
    }
    else{
         //Si huffman y alpha son identicos en valor, se compara lxico-ramaticalmente en relacion al imput text
         cout<< "Both text weight the same amount of bytes but due to grammar-lexicographic comparation we can asssume that the difference between both encoding processes is:  "<< huffman_encode.compare(alpha_encode);
    }
}