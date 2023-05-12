export class HuffmanNode {
    constructor(value, frequency, left = null, right = null) {
      this.value = value;
      this.frequency = frequency;
      this.left = left;
      this.right = right;
    }
  
    isLeaf() {
      return !this.left && !this.right;
    }
  }
  
  export class Huffman {
    static encode(text) {
      const frequencies = new Map();
  
      // Calculamos las frecuencias de cada carácter en el texto
      for (let i = 0; i < text.length; i++) {
        const char = text[i];
        if (char.match(/[a-zA-Z0-9]/)) {
          if (!frequencies.has(char)) {
            frequencies.set(char, 1);
          } else {
            frequencies.set(char, frequencies.get(char) + 1);
          }
        } else {
          throw new Error(`Error: el texto contiene un caracter especial "${char}"`);
        }
      }
  
      // Construimos el árbol de codificación de Huffman
      const nodes = [];
      frequencies.forEach((frequency, value) => {
        nodes.push(new HuffmanNode(value, frequency));
      });
  
      while (nodes.length > 1) {
        nodes.sort((a, b) => a.frequency - b.frequency);
  
        const left = nodes.shift();
        const right = nodes.shift();
  
        const parent = new HuffmanNode(null, left.frequency + right.frequency, left, right);
        nodes.push(parent);
      }
  
      const tree = nodes[0];
  
      // Construimos una tabla de búsqueda de codificación
      const encodingTable = new Map();
  
      function traverse(node, code) {
        if (node.isLeaf()) {
          encodingTable.set(node.value, code);
        } else {
          traverse(node.left, code + "0");
          traverse(node.right, code + "1");
        }
      }
  
      traverse(tree, "");
  
      // Codificamos el texto utilizando la tabla de búsqueda de codificación
      let encodedText = "";
      for (let i = 0; i < text.length; i++) {
        const char = text[i];
        if (char.match(/[a-zA-Z0-9]/)) {
          const code = encodingTable.get(char);
          if (code !== undefined) {
            encodedText += code;
          }
        } else {
          throw new Error(`Error: el texto contiene un caracter especial "${char}"`);
        }
      }
  
      return {encodedText, tree};
    }
  
    static decode(encodedText, tree) {
      let decodedText = "";
      let currentNode = tree;
  
      for (let i = 0; i < encodedText.length; i++) {
        const bit = encodedText[i];
        if (bit === "0") {
          currentNode = currentNode.left;
        } else if (bit === "1") {
          currentNode = currentNode.right;
        }
  
        if (currentNode.isLeaf()) {
          decodedText += currentNode.value;
          currentNode = tree;
        }
      }
  
      return decodedText;
    }
  }
  
export  function printHuffmanTree(root, prefix = "", isLeft = true) {
  let result = "";
  if (root) {
    const nodeValue = root.value ? `${root.value} (${root.frequency})` : `(${root.frequency})`;
    result += `${prefix}${isLeft ? "├──" : "└──"}${nodeValue}\n`;
    if (root.left || root.right) {
      const newPrefix = prefix + (isLeft ? "│   " : "    ");
      result += printHuffmanTree(root.left, newPrefix, true);
      result += printHuffmanTree(root.right, newPrefix, false);
    } else {
      result += `${prefix}${isLeft ? "├──" : "└──"}${root.binary}\n`;
    }
  }
  return result;
}
