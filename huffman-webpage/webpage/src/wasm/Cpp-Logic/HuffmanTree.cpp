#include "HuffmanTree.h"


/*
La función TreeNode::TreeNode(char v, int f) crea un nodo del árbol de Huffman con el caracter v y su frecuencia f.
 Siendo el nodo una hoja del árbol, se inicializan los punteros a los nodos hijo izquierdo y derecho como nullptr.
*/
HuffmanTree::TreeNode::TreeNode(char v, int f) : val(v), freq(f), left(nullptr), right(nullptr) {}

/*
La función TreeNode::TreeNode(int f) crea un nodo del árbol de Huffman con frecuencia f, pero sin valor para el caracter.
 Al igual que en la función anterior, se inicializan los punteros a los nodos hijo izquierdo y derecho como nullptr.
*/
HuffmanTree::TreeNode::TreeNode(int f) : val('\0'), freq(f), left(nullptr), right(nullptr) {}

/*
La función TreeNode::~TreeNode() es el destructor para un nodo del árbol de Huffman. 
Se encarga de liberar la memoria que se reservó en el heap para los nodos hijo izquierdo y derecho, en caso de que existan.
*/
HuffmanTree::TreeNode::~TreeNode() {
    delete left;
    delete right;
}

/*
La función TreeNodeComparator::operator() es un operador de comparación que se utiliza para comparar la frecuencia de dos nodos del árbol de Huffman.
Devuelve true si la frecuencia del nodo lhs es mayor que la del nodo rhs, lo que se utiliza para establecer el orden en la cola de prioridad.
*/
bool HuffmanTree::TreeNodeComparator::operator()(const TreeNode* lhs, const TreeNode* rhs) const {
    return lhs->freq > rhs->freq;
}

/*
La función HuffmanTree::HuffmanTree(const string& text) es el constructor para el árbol de Huffman.
Se crea un mapa con la frecuencia de cada caracter del texto, se crea una cola de prioridad de nodos del árbol de Huffman utilizando los pares de caracteres
y sus frecuencias del mapa y se construye el árbol de Huffman a partir de los nodos de la cola de prioridad.
*/
HuffmanTree::HuffmanTree(const string& text) : root(nullptr) {
    unordered_map<char, int> freqs = get_frequencies(text);
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeComparator> pq;
    for (const auto& pair : freqs) {
        pq.push(new TreeNode(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();
        TreeNode* parent = new TreeNode(left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    if (pq.size() == 1) {
        root = pq.top();
        pq.pop();
    }
}

/*
La función HuffmanTree::~HuffmanTree() es el destructor para el árbol de Huffman.
Se encarga de liberar la memoria que se reservó en el heap para los nodos del árbol.
*/
HuffmanTree::~HuffmanTree(){
    delete root;
}

/*
La función HuffmanTree::get_codes() devuelve un mapa que asocia a cada caracter del texto su correspondiente código de Huffman.
El mapa se construye mediante una llamada a la función traverse_tree, que recorre el árbol de Huffman y genera los códigos para cada hoja del árbol.
*/
unordered_map<char, string> HuffmanTree::get_codes() const {
    unordered_map<char, string> codes;
    if (root != nullptr) {
        traverse_tree(root, "", codes);
    }
    return codes;
}

/*
La función HuffmanTree::encode(const string& text) const toma una cadena de texto como entrada y la codifica usando un árbol de codificación Huffman.
Primero se obtienen los códigos correspondientes a cada carácter mediante la función HuffmanTree::get_codes().
Luego se itera sobre cada carácter de la cadena de entrada, se busca el código correspondiente en el mapa de códigos y se agrega al texto codificado.
*/
string HuffmanTree::encode(const string& text) const {
    string encoded_text = "";
    unordered_map<char, string> codes = get_codes();
    for (char c : text) {
        encoded_text += codes[c];
    }
    return encoded_text;
}

/*
La función HuffmanTree::decode(const string& code) const toma una cadena de texto codificada y la decodifica utilizando el árbol de codificación Huffman.
Comenzando desde la raíz del árbol, se itera sobre cada carácter de la cadena codificada.
Si se llega a un nodo hoja, se agrega el carácter decodificado a la cadena de salida y se vuelve a la raíz del árbol.
Si el carácter actual es "0", se mueve al nodo izquierdo del árbol, y si es "1", se mueve al nodo derecho.
*/
string HuffmanTree::decode(const string& code) const {
    string decoded_text = "";
    const TreeNode* node = root;
    for (char c : code) {
        if (node->left == nullptr && node->right == nullptr) {
            decoded_text += node->val;
            node = root;
        }
        if (c == '0') {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return decoded_text;
}

/*
La función HuffmanTree::get_tree_graphic() const devuelve una representación gráfica del árbol de codificación Huffman en forma de cadena de caracteres. 
Primero se inicializa un vector de pares que contiene nodos y su profundidad en el árbol.
Luego se itera sobre los nodos del árbol utilizando el vector, se construye la representación gráfica y se agrega a la cadena de salida.
*/
string HuffmanTree::get_tree_graphic() const {
    string graphic = "";
    if (root != nullptr) {
        vector<pair<const TreeNode*, int>> nodes;
        nodes.push_back(make_pair(root, 0));
        int current_depth = 0;
        while (!nodes.empty()) {
            const TreeNode* node = nodes.back().first;
            int depth = nodes.back().second;
            nodes.pop_back();
            if (depth > current_depth) {
                graphic += '\n';
                current_depth = depth;
            }
            if (node->left != nullptr) {
                nodes.push_back(make_pair(node->left, depth + 1));
            }
            if (node->right != nullptr) {
                nodes.push_back(make_pair(node->right, depth + 1));
            }
            if (node->val == '\0') {
                graphic += "*";
            }
            else {
                graphic += node->val;
            }
            graphic += ":" + to_string(node->freq) + " ";
        }
        graphic +=
        "\n";
    }
    return graphic;
}

/*
La función HuffmanTree::traverse_tree(const TreeNode* node, string code, unordered_map<char, string>& codes) const es una función auxiliar utilizada para obtener los códigos de Huffman para cada carácter en el árbol.
Recibe un nodo, una cadena de código parcial y un mapa de códigos, y actualiza el mapa con los códigos para cada nodo hoja en el árbol.
*/
void HuffmanTree::traverse_tree(const TreeNode* node, string code, unordered_map<char, string>& codes) const {
    if (node == nullptr) {
        return;
    }
        if (node->left == nullptr && node->right == nullptr) {
        codes[node->val] = code;
        return;
    }
    traverse_tree(node->left, code + "0", codes);
    traverse_tree(node->right, code + "1", codes);
}

/*
La función HuffmanTree::get_frequencies(const string& text) const devuelve un mapa que contiene la frecuencia de cada carácter en una cadena de texto.
Se itera sobre la cadena de entrada y se actualiza el mapa de frecuencias para cada carácter encontrado.
*/
unordered_map<char, int> HuffmanTree::get_frequencies(const string& text) const {
    unordered_map<char, int> freqs;
    for (char c : text) {
        freqs[c]++;
    }
    return freqs;
}
